Reaction Game
==========================================================

微控制器不仅出现在工业设备中，它还用来控制家庭中的大量电子设备，包括了玩具和游戏。在本章节，我们将使用“按键”和“LED”来搭建一个简单的反应计时游戏。

对反应时间的研究被称为mental chronometry，它是一门硬科学，同时也是许多游戏（包括您将要制作的游戏）的基础。Reaction time is the time that elapses between a person being presented with a stimulus and the person initiating a motor response to the stimulus，以毫秒为单位，人的平均反应时间约为200-250毫秒。反应时间短的人在游戏中拥有巨大的优势！

Wiring
-------------------------------

.. image:: img/wiring_reaction_game.png

1. 总的来说，这个电路就是将上两章节中的电路结合起来。
#. 再三确认面包板电源总线没有错接或短接！


Code
----------------------------------

当程序启动时，LED会在5~10秒内熄灭。你需要尽可能快的按下按键，程序会告诉你你的反应时间是多少。


.. code-block:: python

    import machine
    import utime
    import urandom

    led = machine.Pin(15, machine.Pin.OUT)
    button = machine.Pin(14, machine.Pin.IN)

    def button_press(pin):
        button.irq(handler=None)
        rection_time = utime.ticks_diff(utime.ticks_ms(), timer_light_off)
        print("Your reaction time was " + str(rection_time) + " milliseconds!")

    led.value(1)
    utime.sleep(urandom.uniform(5, 10))
    led.value(0)
    timer_light_off = utime.ticks_ms()
    button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_press)

How it works?
-----------------------------------------------

在前面的章节中，我们已经在主程序或单独的线程中使用了按钮。这一次，我们采用另一种更灵活的方法：中断请求，或者说是IRQs。

举个例子，假设您正在一页一页地阅读一本书，就如同程序正在执行线程，此时有人来找您问问题，打断了您的阅读。那么，该人正是在执行中断请求：要求您停止正在做的事情，回答他的问题，结束后再让您返回阅读书本。

MicroPython 中断请求也是相同的工作方式，它允许某些操作中断主程序，它是通过以下两个语句实现的:

.. code-block:: python
    :emphasize-lines: 8,17

    import machine
    import utime
    import urandom

    led = machine.Pin(15, machine.Pin.OUT)
    button = machine.Pin(14, machine.Pin.IN)

    def button_press(pin):
        button.irq(handler=None)
        rection_time = utime.ticks_diff(utime.ticks_ms(), timer_light_off)
        print("Your reaction time was " + str(rection_time) + " milliseconds!")

    led.value(1)
    utime.sleep(urandom.uniform(5, 10))
    led.value(0)
    timer_light_off = utime.ticks_ms()
    button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_press)

在这里，首先定义了一个中断处理程序，这称为callback function，它是触发中断时运行的代码。
然后，在主程序中set up an interrupt，它需要包含两个部分：``trigger`` 和 ``handler`` 。

* 在这个程序中，``trigger`` 是 ``IRQ_RISING`` ，这意味着引脚的值从低电平上升到高电平（也就是按下按键）。
* 而 ``handler`` 是由我们自定义的callback function，在这里是 ``button_press`` 。在这个示例中，你会发现callback function中有一句 ``button.irq(handler=None)`` ，它的可以将callback function设为None，相当于cancel了interrupt。

让我们通过以下代码来更好的理解IRQ吧！(直接使用本章的电路即可)

.. code-block:: python

    import machine
    import utime

    button = machine.Pin(14, machine.Pin.IN)
    count = 0

    def button_press(pin):
        print("You press the button!")
        utime.sleep(1)        

    button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_press)

    while True:
        count+=1
        print(count)
        utime.sleep(1)

程序在运行时会循环计数并输出，当我们按下按键，它会暂停主程序中的计数，进入callback function打印"You press the button!"。


回到原示例。我们需要让LED在5到10秒的随机时间内熄灭，这是通过以下两行实现的：

.. code-block:: python
    :emphasize-lines: 3,14

    import machine
    import utime
    import urandom

    led = machine.Pin(15, machine.Pin.OUT)
    button = machine.Pin(14, machine.Pin.IN)

    def button_press(pin):
        button.irq(handler=None)
        rection_time = utime.ticks_diff(utime.ticks_ms(), timer_light_off)
        print("Your reaction time was " + str(rection_time) + " milliseconds!")

    led.value(1)
    utime.sleep(urandom.uniform(5, 10))
    led.value(0)
    timer_light_off = utime.ticks_ms()
    button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_press)
    

在这里加载了 ``urandom`` 库。使用其中的 ``urandom.uniform(5,10)`` 函数生成了一个随机数，the ‘uniform’ part referring to a uniform distribution between those two numbers.

如果需要，尝试运行以下生成随机数的示例：

.. code-block:: python

    import machine
    import utime
    import urandom

    while True:
        print(urandom.uniform(1, 20))
        utime.sleep(1)

最后你需要了解的两个语句是 ``utime.ticks_ms()`` 和 ``utime.ticks_diff()``。

.. code-block:: python
    :emphasize-lines: 10,16

    import machine
    import utime
    import urandom

    led = machine.Pin(15, machine.Pin.OUT)
    button = machine.Pin(14, machine.Pin.IN)

    def button_press(pin):
        button.irq(handler=None)
        rection_time = utime.ticks_diff(utime.ticks_ms(), timer_light_off)
        print("Your reaction time was " + str(rection_time) + " milliseconds!")

    led.value(1)
    utime.sleep(urandom.uniform(5, 10))
    led.value(0)
    timer_light_off = utime.ticks_ms()
    button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_press)

* ``utime.ticks_ms()`` 函数将输出自 ``utime`` 库开始计数以来经过的毫秒数，在这里它被保存在变量 ``timer_light_off`` 中。
* ``utime.ticks_diff()`` 用来输出两个时间节点的时间差。在这里函数中的两个参数分别是 ``utime.ticks_ms()`` 当前（按下按键）程序时间与储存在变量 ``timer_light_off`` 的参考时间（灯灭）。

这两个函数通常一起使用，用来计算程序的执行时间。在这里我们用来计算从灯灭到按下按键的时间。

最后，这个时间会被打印出来。

.. code-block:: python

    print("Your reaction time was " + str(rection_time) + " milliseconds!")

Also see the reference here:

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_
* `urandom <https://www.sutron.com/micropython/html/library/urandom.html>`_
* `utime <https://docs.micropython.org/en/latest/library/utime.html>`_


What more?
------------------------
和小伙伴一同玩耍会更有乐趣，何不增加按键的数量，看谁能最快按下按键呢？

请尝试一下。

.. image:: img/wiring_reaction_game_2.png

.. code-block:: python

    import machine
    import utime
    import urandom

    led = machine.Pin(15, machine.Pin.OUT)
    left_button = machine.Pin(14, machine.Pin.IN)
    right_button = machine.Pin(16, machine.Pin.IN)

    def button_press(pin):
        left_button.irq(handler=None)
        right_button.irq(handler=None)
        rection_time = utime.ticks_diff(utime.ticks_ms(), timer_light_off)
        if pin == left_button:
            print("Left player is winner!")
        elif pin == right_button:
            print("Right player is winner!")
        print("Your reaction time was " + str(rection_time) + " milliseconds!")

    led.value(1)
    utime.sleep(urandom.uniform(5, 10))
    led.value(0)
    timer_light_off = utime.ticks_ms()    
    right_button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_press)
    left_button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_press)
    

