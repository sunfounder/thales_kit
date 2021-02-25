Reading Button Value
==============================================

从GPIO（General-purpose input/output）的名字中我们可以看出，引脚应当具有输入和输出两种使用方法。在LED中我们使用了输出，在这章我们借助按键来使用输入。


Wiring
------------------------

.. image:: img/wiring_read_button_value.png


让我们顺着电路方向来搭建电路吧！

1. 将Pico的3V3引脚连接到面包板正极电源总线。
#. 将按键插入面包板的中间，使其跨在中央分割线上。

    .. note::
        我们可以将四足按键看作H形，它的左侧（右侧）两只脚是相连的，这意味着它跨在中央分割线后，会将同一行号的两组半行连接在一起（如在我的电路中，E22与F22已被接通，E24与F24也是如此）。

        在按下按键之前，左右两侧是相互独立的，电流并不能从一侧流向另一侧。

#. 用跳线将电源正极总线与按键的一个脚连接（我的是右上方的脚）。
#. 用跳线将另一侧的脚（左上方或左下方）连接到GP14。

Code
-----------------------------------

当按键被按下时，电流会从3V3流经电阻器和开关流入GP14，换而言之GPI14将会读取到高电平信号‘1’；反之，则会读取到低电平信号‘0’。

.. code-block:: python

    import machine
    import utime
    button = machine.Pin(14, machine.Pin.IN)
    while True:
        if button.value() == 1:
            print("You pressed the button!")
            utime.sleep(1)

What more?
------------------------

按键并不需要外接限流电阻器，但是仍需要一个电阻器 —— 上拉电阻器或者下拉电阻器，取决于电路的工作方式。如果没有上拉或下拉电阻，主控制器将可能接收到‘noisy’ signal which can trigger even when you’re not pushing the button.

那么为什么我们看不到它们呢？因为它们被集成到了Pico中，就如同Pico集成了板载LED一样。这些电阻是可以被编程的，通常被设置为下拉，这使得GPIO在未连通高电平的时候，输入值为‘0’；如果被设置为上拉，则会让GPIO在未接通低电平的时候获得输入值‘1’。

接下来是按键在使用上拉的工作方式时的接线和代码，请尝试一下。

.. image:: img/wiring_read_button_value_2.png

.. code-block:: python

    import machine
    import utime
    button = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_UP)
    # The third parameter specifies if the pin has a pull-up/down resistor attached.
    while True:
        if button.value() == 0:
            # When the button is pressed, GPIO will be connected to GND.
            print("You pressed the button!")
            utime.sleep(1)
    

Also see the reference here:  

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_
