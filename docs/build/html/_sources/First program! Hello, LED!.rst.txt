First program! Hello, LED! 
=======================================

正如同打印一句“Hello，world！”是学习编程的第一步一样，让LED亮起来正是学习physical programming的传统入门。

在Pico的顶部有一个小小的LED。它与其他的LED一样，会在通电的时候发光，断电时熄灭。


.. image:: img/led_onboard.png

Code
----------------

让我们把这个代码拷贝入Thonny中运行，让它闪烁！

.. code-block:: python

    import machine
    import utime
    
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    while True:
        led_onboard.value(1)
        utime.sleep(2)
        led_onboard.value(0)
        utime.sleep(2)

How it works?
-------------------------------

板载LED连接在了GP25引脚上 —— 如果你仔细观察过Pico的引脚序列，你会发现GP25正是被隐藏起来的几个引脚之一，这意味着我们无法通过这个引脚来使用其他元器件（即便GP25与其他引脚的使用方法完全一致）。这种设计的好处是，即便你没有接入任何外部元器件，也能拥有一个OUTPUT供你测试程序。

使用GPIO需要 machine 库。

.. code-block:: python

    import machine


这个library包含了MicroPython与Pico通信所需要的所有指令。如果没有这行代码，我们将无法控制任何一个GPIO，也就无法让板载LED亮起。

接下来需要注意到的是这一行：

.. code-block:: python

    led_onboard = machine.Pin(25, machine.Pin.OUT)


这里定义了一个名为 ``led_onboard`` 的对象。从技术上来讲，它可以是任意的名字，可以是x,y, banana, Micheal_Jackson, 或者任意字符 —— 但是最好使用能描述用途的名字，以确保程序能够易于阅读。

这一行的第二部分（等于号后面的部分）调用了machine库中的Pin函数。它用来告诉Pico的GPIO引脚应该做什么。
Pin函数拥有两个参数：第一个参数（25）意味着你要设置的引脚；第二个参数（machine.Pin.OUT）则告诉了该引脚应当作为输出而不是输入使用。

上述代码已经“设置”好了引脚，但是它不会点亮LED。要做到这一点，我们还需要“使用”引脚。如下：

.. code-block:: python

    led_onboard.value(1)

我们原先已经将GP25引脚设置好了，并命名为 ``led_onboard`` ，这一句的作用是将 ``led_onboard`` 的值设置为1，也就是turn it on； 如果设置为0，则会关闭它。

总而言之，要使用GPIO，这几个环节是必须的：

*   import machine library —— 这是必须的，在整个程序中仅执行一次。 
*   设置GPIO —— 每一个引脚在使用前都应当先完成设置。
*   使用 —— 为引脚赋值，每一次赋值都会改变引脚的工作状态。

如果我们按照上述的步骤编写示例，那么你将得到这样的代码：

.. code-block:: python

    import machine   
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    led_onboard.value(1)

烧录它，你将能点亮板载LED。

接下来，我们试着加入“熄灭”的语句：

.. code-block:: python

    import machine   
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    led_onboard.value(1)
    led_onboard.value(0)

从语句上看，这个程序会让板载LED先亮后灭，但是当你使用它时，却发现不是这样，板载LED似乎从未亮过。这是因为两个语句之间执行的速度非常快，远比人眼的反应时间快得多，板载LED亮起的那一刹那并不足以让我们察觉到光明。To fix that,我们需要让程序慢下来。

将以下语句插入到程序的第二行：

.. code-block:: python

    import utime

和machine一样，这里引入了 ``utime`` 库，这个库处理所有与时间相关的事情，包括我们需要用到的延时。让我们在 ``led_onboard.value(1)`` 与 ``led_onboard.value(0)`` 之间插入一句延时语句，让它们间隔2秒：

.. code-block:: python

    utime.sleep(2)

现在，代码看起来应该是这样的。运行它，我们将能看到板载LED先亮后灭：

.. code-block:: python

    import machine 
    import utime  
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    led_onboard.value(1)
    utime.sleep(2)
    led_onboard.value(0)


最后，我们该让LED闪烁起来了。创建一个循环，重写程序，它就成了本章节开头处看到的那样。

.. code-block:: python

    import machine
    import utime
    
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    while True:
        led_onboard.value(1)
        utime.sleep(2)
        led_onboard.value(0)
        utime.sleep(2)


What more?
-------------------------

通常，library都会有相应的API(Application Programming Interface) file。这是一个简明的参考手册，包含了使用这个library所需的所有信息，详细介绍了函数、类、返回类型、参数等，甚至附带有教程。

在本篇我们使用了MicroPython的 ``machine`` 和 ``utime`` 库，我们可以这里找到看到它们更多的使用方法。

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_

* `utime <https://docs.micropython.org/en/latest/library/utime.html>`_

下面是另外两种让LED闪烁的示例，请尝试翻阅API文件，读懂它们吧！

1.

   .. code-block:: python

      import machine
      import utime

      led_onboard = machine.Pin(25, machine.Pin.OUT)
      while True:
         led_onboard.toggle()
         utime.sleep(1)

#. 

   .. code-block:: python

      from machine import Pin
      import utime
      
      led_onboard = Pin(25, Pin.OUT)
      while True:
         led_onboard.on()
         utime.sleep_ms(500)
         led_onboard.off()
         utime.sleep_ms(500)



