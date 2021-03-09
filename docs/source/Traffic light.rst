Traffic Light
==============================================

In addition to home electronic devices, many microcontrollers can also be found in the social environment, including traffic lights.
Traffic lights are used to direct traffic operation and are generally composed of red, green, and yellow lights.
Building a huge traffic management system is a fairly advanced project, but using Pico to drive a miniature traffic light is a project we can try.

Let's make a mini pedestrian crossing system with a few LEDs and a button!

Wiring
------------------------------------------------

.. image:: img/wiring_traffic_light.png

1. Connect 3V3 and GND of Pico to the breadboard power bus.
#. Insert the red, yellow, and green LEDs on the breadboard.
#. GP13, GP14, GP15 are each connected to a 220Ω resistor and then connected to the anode of the LED.
#. Connect the cathodes of the LEDs to the negative power bus of the breadboard.
#. Insert the Button, connect one side of it to the GP16 pin, and connect a 10kΩ resistor in series to the negative power bus, and the other side to the positive power bus.

.. note::
    The color ring of 220 ohm resistor is red, red, black, black and brown.
    The color ring of the 10k ohm resistor is brown, black, black, red and brown.


Code
---------------------------------------------------

When the program is started, the traffic light will switch in the order of red for 5 seconds, yellow for 2 seconds, green for 5 seconds, and yellow for 2 seconds.
If we (pedestrians) press the button, the next red light will be extended to 15 seconds, which will give us more time to cross the road.

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
            led_red.value(1)
            utime.sleep(10)
        global button_status
        button_status = 0

        led_red.value(1)
        utime.sleep(5)
        led_red.value(0)  

        led_yellow.value(1)
        utime.sleep(2)
        led_yellow.value(0)

        led_green.value(1)
        utime.sleep(5)
        led_green.value(0)

        led_yellow.value(1)
        utime.sleep(2)
        led_yellow.value(0)

How it works?
-----------------------------------------------

In the previous chapters, we have successfully made the LED blink. In other words, it is very simple for us to write a code that makes the traffic light cycle color. What we need to do is to add a judgment on the state of the button.
But if we directly write the statement that reads the button value in the main program, we will find that it doesn't fit anywhere. Even if we write it in, we can hardly read the value.
This is because the program is stuck when executing ``utime.sleep()'', and the statement to read the button value is not executed at this time.

Of course, we can read the key value through the IRQs of the previous lesson. But this time we take another approach-multithreading.

Multi-threading can be simply understood as dividing a thing into multiple parts, which are executed by different people (or processors).
Just like when the chef is frying the steak, the assistant chef will make the sauce so that the newly prepared sauce can be poured on the properly prepared steak to make the best cooking.

.. note:
    The RP2040 microcontroller which powers your Pico, however, has two processing cores. meaning you can run two threads at the same time to get more work done.

Look at these lines:

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
            led_red.value(1)
            utime.sleep(10)
        global button_status
        button_status = 0

        led_red.value(1)
        utime.sleep(5)
        led_red.value(0)

        led_yellow.value(1)
        utime.sleep(2)
        led_yellow.value(0)

        led_green.value(1)
        utime.sleep(5)
        led_green.value(0)

        led_yellow.value(1)
        utime.sleep(2)
        led_yellow.value(0)

Here, the ``_thread`` library is imported first. This module implements multithreading support.
Then define a thread ``button_thread()``, which is independent of the main thread. It is used here to read the state of the button.
Finally use ``_thread.start_new_thread(button_thread, ())`` to start the thread.


Let us use the following code to better understand multithreading:

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
        button_status = button.value()
        if button_status == 1:
            led_red.value(1)
        elif button_status == 0:
            led_red.value(0)

In the main thread, we can use buttons to control the red LED on and off. In the new thread, the yellow LED will change every 2 seconds. The two threads work independently of each other.


Let's go back to the traffic signal program. We let the main thread change the light and let the new thread read the button value.
However, the threads are independent of each other, and we need a way for the new thread to pass information to the main thread, which requires the use of global variables.

The variables we have used before are local variables and only work in one part of the program (variables declared in the main function cannot be used in sub-functions, and variables declared in the main thread cannot be used in the new thread).
The global variable can be used anywhere, we change it in one thread, and the other can get its updated value.

Global variables are in these places:


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
            led_red.value(1)
            utime.sleep(10)
        global button_status
        button_status = 0

        led_red.value(1)
        utime.sleep(5)
        led_red.value(0)

        led_yellow.value(1)
        utime.sleep(2)
        led_yellow.value(0)

        led_green.value(1)
        utime.sleep(5)
        led_green.value(0)

        led_yellow.value(1)
        utime.sleep(2)
        led_yellow.value(0)

* When the program is just running, ``button_status`` is assigned a value of 0, which means that the button has not been pressed.
* In the new thread, when the program detects that the button is pressed, ``button_status`` is assigned the value 1.
* In the loop of the main thread, ``button_status`` will be checked once before each traffic light change cycle. If the status is 1, it will execute an extra red light time, then switch to 0, and wait for the next button press.

The function of ``global button_status`` is to tell the program that we are about to modify the value of this global variable. If we want to read the value of a variable, this line is not needed; if we want to modify the value of a variable, we must add it.




  

