Swinging Servo
===================

本套件除了LED和无源蜂鸣器，另一个由PWM信号控制的设备是Servo。

舵机是一种位置（角度）伺服的驱动器，适用于那些需要角度不断变化并可以保持的控制系统。在高档遥控玩具，如飞机、潜艇模型，遥控机器人中已经得到了普遍应用。

让舵机摇摆起来吧！

Wiring
-------------------------

.. image:: img/wiring_swing_servo.png

1. 将Servo Arm 按到在Servo的输出轴上。如果有必要，使用螺丝将其固定。
#. 将 Pico 的 **VBUS** （不是3V3）和 GND 连接至面包板的电源总线。
#. 让舵机的红色引线用跳线连接至正极电源总线。
#. 让舵机的黄色引线用跳线连接 GP15 引脚。
#. 让舵机的黑色引线用跳线连接至负极电源总线。


Code
--------------------

.. code-block:: python

    import machine
    import utime

    servo = machine.PWM(machine.Pin(15))
    servo.freq(50)

    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    def servo_write(pin,angle):
        pulse_width=interval_mapping(angle, 0, 180, 0.5,2.5)
        duty=int(interval_mapping(pulse_width, 0, 20, 0,65535))
        pin.duty_u16(duty)

    while True:
        for angle in range(180):
            servo_write(servo,angle)
            utime.sleep_ms(20)
        for angle in range(180,-1,-1):
            servo_write(servo,angle)
            utime.sleep_ms(20)


当程序运行时，我们能看到Servo Arm从0°到180°来回摇摆。因为 ``while True`` 循环的原因程序会一直运行，我们需要按下Stop键来结束这个程序。

How it works?
--------------------
我们定义了 ``servo_write()`` 函数来让舵机动起来。

这个函数拥有两个parameter:

* pin，控制舵机的GPIO引脚。 
* angle，舵机轴输出的角度。 

在这个函数中调用了 ``interval_mapping()`` 将角度范围 0 ~ 180 映射为pulse width的范围 0.5 ~ 2.5ms。

.. code-block:: python

    pulse_width=interval_mapping(angle, 0, 180, 0.5,2.5)

为什么是0.5~2.5呢？这是由舵机的工作方式所决定的。

.. image:: img/servo1.png

It works like this: The microcontroller sends out PWM signals to the servo, and then the embedded board in the servo receives the signals through the signal pin and controls the motor inside to turn. 
As a result, the motor drives the gear system and then motivates the shaft after deceleration. 
The shaft and potentiometer of the servo are connected together. 
When the shaft rotates, it drives the potentiometer, so the potentiometer outputs a voltage signal to the embedded board. 
Then the board determines the direction and speed of rotation based on the current position, so it can stop exactly at the right position as defined and hold there.

.. image:: img/servo3.png

The angle is determined by the duration of a pulse that is applied to the control wire. The servo expects to see a pulse every 20 ms (That's why we set the pwm frequency to 50hz).

The length of the pulse will determine how far the motor turns. 
For example, a 1.5ms pulse will make the motor turn to the 90 degree position (neutral position). 
When a pulse is sent to a servo that is less than 1.5 ms, the servo rotates to a position and holds its output shaft some degrees counterclockwise from the neutral point. 
When the pulse is wider than 1.5 ms the opposite occurs. The minimal width and the maximum width of pulse that will command the servo to turn to a valid position are functions of each servo. 
Generally the minimum pulse will be about 0.5 ms wide and the maximum pulse will be 2.5 ms wide.

接下来将pulse width转化从周期转化为duty，由于duty_u16()在使用时不可以有小数（数值不能为float类型），我们使用了 ``int()`` 将duty强制转化为int类型。

.. code-block:: python

    duty=int(interval_mapping(pulse_width, 0, 20, 0,65535))

最后将duty值写入duty_u16()即可。