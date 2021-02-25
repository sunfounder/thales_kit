Light Theremin
=========================

特雷门琴是一种不需要身体接触的电子乐器，它通过感应演奏家的手部位置来发出不同的音调。
特雷门琴利用两个感应人体与大地的分布电容的LC 振荡器工作单元分别产生震荡的频率与大小变化而工作。
我们无法通过Pico复刻出相同的乐器，但是可以借助photoresistor和passive buzzer来实现相似的玩法。


Wiring
--------------------

.. image:: img/wiring_light_theremin.png

1. 将 Pico 的3V3和 GND 连接至面包板的电源总线。
#. 将photoresistor的一端接入负极电源总线，另一端串联一个10kΩ电阻器接入正极电源总线。
#. 用一根跳线从两个电阻器中间接入GP28。
#. 将LED插入面包板上，它的阳极pin串联一个220Ω电阻器接入GP16，阴极pin接入负极电源总线。
#. 将无源蜂鸣器和S8050三极管插入面包板。蜂鸣器阳极pin连接至正极电源总线，阴极pin连接至三极管的 **collector** lead，三极管的 **base** lead 经由 1kΩ 电阻器连接至 GP15 引脚。**emitter** lead 连接负极电源总线。

.. note::
    220欧姆的电阻器色环颜色为红红黑黑棕。
    10kΩ电阻器的色环颜色为棕黑黑红棕。

Code
--------------------

.. code-block:: python

    import machine
    import utime

    led = machine.Pin(16, machine.Pin.OUT)
    photoresistor = machine.ADC(28) 
    buzzer = machine.PWM(machine.Pin(15))

    light_low=65535
    light_high=0

    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty_u16(30000)
        utime.sleep_ms(duration)
        pin.duty_u16(0)

    # calibrate the photoresistor max & min values.
    timer_init_start = utime.ticks_ms()
    led.value(1)    
    while utime.ticks_diff(utime.ticks_ms(), timer_init_start)<5000:
        light_value = photoresistor.read_u16()
        if light_value > light_high:
            light_high = light_value
        if light_value < light_low:
            light_low = light_value   
    led.value(0)    

    # play
    while True:
        light_value  = photoresistor.read_u16()
        pitch = int(interval_mapping(light_value,light_low,light_high,50,6000))
        if pitch > 50 :
            tone(buzzer,pitch,20)
        utime.sleep_ms(10)

当程序运行后，LED会点亮，我们会有五秒的时间校准photoresistor的检测范围。这是因为在每次使用时，我们可能处于不同的光线环境（如正午和黄昏的光照强度并不相同）。
在此时我们需要用手在photoresistor上方上下摆动，手的移动范围将会被校准为这个乐器的演奏范围。
五秒过后，LED会熄灭，我们可以在photoresistor上摆手进行演奏。


