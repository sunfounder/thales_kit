Traffic light
==============================================

除了家庭的电子设备，在社会环境中也可以找到许多微控制器，其中就包括交通信号灯。
交通信号灯是指挥交通运行的信号灯，一般由红灯、绿灯、黄灯组成。
构建一个庞大的交通管理系统是一项相当高级的项目，但用Pico驱动一个微型的交通信号灯却是我们可以尝试的项目。

让我们用几个LED和按键制作一个迷你pedestrian crossing系统吧！

Wiring
------------------------------------------------

.. image:: img/wiring_traffic_light.png

1. 将Pico的3V3和GND连接至面包板电源总线。
#. 将红、黄、绿三个LED插在面包板上。
#. GP13、GP14、GP15各自连接一个电阻器后接续至LED的阳极。
#. 将LED们的阴极连接至面包板负极电源总线。
#. 插入Button，将其一侧连接至GP16，另一侧连接至正极电源总线。

Code
---------------------------------------------------

当程序启动时，交通信号灯会以红5秒，黄2秒，绿5秒，黄2秒的顺序循环切换。
如果我们（行人）按下按键，下一次红灯将会延长至15秒，这将会使我们有更长的时间过马路。

.. code-block:: python

    import machine
    import utime
    import _thread

    led_red = machine.Pin(15, machine.Pin.OUT)
    led_yellow = machine.Pin(14, machine.Pin.OUT)
    led_green = machine.Pin(13, machine.Pin.OUT)
    button = machine.Pin(16, machine.Pin.IN)

    global button_status
    button_status = 0

    def button_thread():
        global button_status 
        while True:
            if button.value() == 1:
                button_status = 1

    _thread.start_new_thread(button_thread, ())

    while True:
        if button_status == 1:
            led_red.on()
            utime.sleep(10)
        global button_status
        button_status = 0

    led_red.on()
    utime.sleep(5)
    led_red.off()  

    led_yellow.on()
    utime.sleep(2)
    led_yellow.off()

    led_green.on()
    utime.sleep(5)
    led_green.off()

    led_yellow.on()
    utime.sleep(2)
    led_yellow.off()

How it works?
-----------------------------------------------

在前面的章节，我们已经掌握了让LED闪烁的方法，换而言之编写一段让交通灯循环切换颜色的代码对我们来说完全不在话下，我们需要做的就是增加一个对按键状态的判断。
但是如果我们直接将读取按键值的语句写在主程序中，却会发现放在哪里都不合适，即便写进去也基本无法读取到值。
这是因为程序在执行 ``utime.sleep()`` 时是停滞的，这时候并没有在执行读取按键值的语句。

当然，我们可以通过上节课的IRQs来实现按键值的读取。但这次我们采取另外的方法 —— 多线程。

多线程可以简单理解为将一件事情分开成多个部分，交由不同的人（或处理器）来执行。
就像主厨在煎牛排的时候，副厨师会在旁边调酱汁，这样才能把刚调好的酱汁淋在处理得恰到好处的牛扒上，做出最佳的料理。

.. note:
    The RP2040 microcontroller which powers your Pico, however, has two processing cores. meaning you can run two threads at the same time to get more work done.

请看这几行：

.. code-block:: python
   :emphasize-lines: 3,13,19

    import machine
    import utime
    import _thread

    led_red = machine.Pin(15, machine.Pin.OUT)
    led_yellow = machine.Pin(14, machine.Pin.OUT)
    led_green = machine.Pin(13, machine.Pin.OUT)
    button = machine.Pin(16, machine.Pin.IN)

    global button_status
    button_status = 0

    def button_thread():
        global button_status 
        while True:
            if button.value() == 1:
                button_status = 1

    _thread.start_new_thread(button_thread, ())

    while True:
        if button_status == 1:
            led_red.on()
            utime.sleep(10)
        global button_status
        button_status = 0

    PASS
    # PASS means not to do anything. 
    # Used here to temporarily replace the unnecessary part.

在这里，首先 import 了 ``_thread`` 库。This module implements multithreading support.
然后定义一个线程 ``button_thread()`` ，它独立于主线程。在这里用来读取按键的状态。
最后用 ``_thread.start_new_thread(button_thread, ())`` 来开始线程。


让我们通过以下代码来更好的理解多线程：

.. code-block:: python

    import machine
    import utime
    import _thread

    led_red = machine.Pin(15, machine.Pin.OUT)
    led_yellow = machine.Pin(14, machine.Pin.OUT)
    button = machine.Pin(16, machine.Pin.IN)    

    def led_yellow_thread():
        while True:
            led_yellow.toggle()
            utime.sleep(2)

    _thread.start_new_thread(led_yellow_thread, ())

    while True:
        if button_status == 1:
            led_red.on()
        elif button_status == 0:
            led_red.off()

在主线程中，我们可以用按钮来控制红色LED亮灭。在新线程，黄色LED会每2秒变换一次。两个线程相互独立工作。



让我们回到交通信号灯程序。我们让主线程变换信号灯，让新线程读取按键值。但是，线程之间是相互独立的，我们需要一种使新线程将信息传递回主线程的方法，这便需要使用全局变量。

我们之前使用过的变量是局部变量，仅在程序中的一个部分起作用（在主函数中声明的变量无法在子函数中使用，在主线程声明的变量无法在新线程使用）。
而全局变量可以在任何地方使用，我们在一个线程中改变它，另一个也能得到它更新后的值。

全局变量在这里：


.. code-block:: python
   :emphasize-lines: 10,11,14,17,22,25,26

    import machine
    import utime
    import _thread

    led_red = machine.Pin(15, machine.Pin.OUT)
    led_yellow = machine.Pin(14, machine.Pin.OUT)
    led_green = machine.Pin(13, machine.Pin.OUT)
    button = machine.Pin(16, machine.Pin.IN)

    global button_status
    button_status = 0

    def button_thread():
        global button_status 
        while True:
            if button.value() == 1:
                button_status = 1

    _thread.start_new_thread(button_thread, ())

    while True:
        if button_status == 1:
            led_red.on()
            utime.sleep(10)
        global button_status
        button_status = 0

    PASS

* 在程序刚运行时，``button_status`` 被赋值为0，代表着按键未被按下。
* 在新线程中，当程序检测到按键被按下了， ``button_status`` 被赋值为1。
* 在主线程的循环里，每个交通信号灯变化周期前 ``button_status`` 都会被检测一次，如果状态为1，则执行一段额外的红灯时间，随后切换为0，等待下一次按键按下。 

``global button_status`` 的作用是告诉程序我们将要修改这个全局变量的值。如果我们想读取变量的值，不需要这行；如果想要修改变量的值，则必须加上它，否则将无法修改变量。




  

