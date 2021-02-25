Custom tone
==========================================


在前面的章节我们已经使用过了有源蜂鸣器，这次我们将会使用无源蜂鸣器。

与有源蜂鸣器相同，无源蜂鸣器也是利用了电磁感应现象工作的，区别在于无源的要少一个震荡电路，以至于不能直接通电发声。
但这也使得无源蜂鸣器可以调节自己的震动频率，拥有更宽的声音频率范围，可以发出“doh, re, mi, fa, sol, la, ti”等不同音节。

让无源蜂鸣器来发出一段旋律吧！

Wiring
-------------------------

.. image:: img/buzzer.png

在套件里面包含了两种蜂鸣器，我们需要用的是无源蜂鸣器，将它们反过来，背后是裸露PCB的是我们所要的那个。

蜂鸣器是工作时需要用到三极管，在这里我们使用S8050。

.. image:: img/wiring_custom_tone.png

1. 将 Pico 的 3V3 和 GND 连接至面包板的电源总线。
#. 让蜂鸣器的阳极pin连接至正极电源总线。
#. 将蜂鸣器的阴极pin连接至三极管的 **collector** lead。
#. 将三极管的 **base** lead 经由 1kΩ 电阻器连接至 GP15 引脚。
#. 将三极管的 **emitter** lead 连接负极电源总线。


Code
--------------------

.. code-block:: python

    import machine
    import utime

    buzzer = machine.PWM(machine.Pin(15))
    buzzer.freq(0)

    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty_u16(30000)
        utime.sleep_ms(duration)
        pin.duty_u16(0)

    tone(buzzer,440,250)
    utime.sleep_ms(500)
    tone(buzzer,494,250)
    utime.sleep_ms(500)
    tone(buzzer,523,250)


How it works?
--------------------

我们定义了一个 ``tone()`` 函数让buzzer发出声音。

无源蜂鸣器在每接收到高电平的时候会推动振荡片，如果给予数字信号，振荡片一直被推动，却没产生振动，无法发声。
在这里我们使用PWM的方式来制造振动。

这个函数的拥有三个parameter：

* pin，控制蜂鸣器的GPIO引脚。
* frequency，蜂鸣器的音高由频率决定，频率越高，音调也就越高。
* duration，音调的持续时间。

我们将蜂鸣器振动时的duty_u16设为30000，约为50%，事实上是多少都可以，只需借助不连续的电信号产生振动即可。



What more？
-----------------------------

我们可以根据钢琴的基音频率来模拟具体的音调，从而弹奏出一首完整的乐曲。

* `Piano key frequencies - Wikipedia <https://en.wikipedia.org/wiki/Piano_key_frequencies>`_


.. code-block:: python

    import machine
    import utime

    NOTE_C4 = 262
    NOTE_G3 = 196
    NOTE_A3 = 220
    NOTE_B3 = 247

    melody =[NOTE_C4,NOTE_G3,NOTE_G3,NOTE_A3,NOTE_G3,NOTE_B3,NOTE_C4]

    buzzer = machine.PWM(machine.Pin(15))

    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty_u16(30000)
        utime.sleep_ms(duration)
        pin.duty_u16(0)

    for note in melody:
        tone(buzzer,note,250)
        utime.sleep_ms(150)


