Hello LED! 
=======================================

Just as printing "Hello, world!" is the first step in learning a programming language, getting an LED to light up is the traditional entry to learning physical computing.

There is a small LED on the top of the Pico. Like any other LED, it will glow when power is on, and turn off when power is out.


.. image:: img/led_onboard.png

Code
----------------

Let's copy this code into Thonny and click "Run Current Script" (or press F5) to run it to make the LED blink!

Don't forget to left click on the bottom right corner and switch the python version name to MicroPython (Raspberry Pi Pico).

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

The onboard LED is connected to the GP25 pin. If you carefully observe the Pico pinout, you will find that GP25 is one of the hidden GPIO pins, which means that we cannot use this pin (even if GP25 is used in exactly the same way as the other GPIO pins). The advantage of this design is that you can still have an OUTPUT to test a program, even if there aren't any external components connected.

Importing the machine library is required to use GPIO.

.. code-block:: python

    import machine

This library contains all the instructions needed to communicate between MicroPython and Pico. Without this line of code, we will not be able to control any GPIOs (including GP25).

The next thing will be creating an object in this line:

.. code-block:: python

    led_onboard = machine.Pin(25, machine.Pin.OUT)

An object named ``led_onboard`` is defined here. Technically, it can be any name like x, y, banana, Michael_Jackson, or any other string of characters, but it is best to use a name that describes the purpose of the object to ensure that your program is easy to read.

The second part of this line after the equal sign calls the Pin() function in the machine library. It is used to tell Pico's GPIO pins what to do.
The Pin function has two parameters separated by a comma: the first parameter (25) means the pin you want to set; the second parameter after the comma (machine.Pin.OUT) tells that the pin should be used as an output instead of an input.

The above code has "set" the pin, but it will not light up the LED. To do this, we also need to "use" the pin.

.. code-block:: python

    led_onboard.value(1)

So far we have set up the GP25 pin on the on-board LED, and named it led_onboard. The function of the .value() statement is to set the value of ``led_onboard`` to 1, which will turn the on-board LED on. A value of .value(0) would turn the LED off.

All in all, to use GPIO, these steps are necessary:

* **import machine library**: This is necessary, and it is only executed once in the entire program.
* **Set GPIO**: Each pin should be set before use.
* **Use**: Assign a value to the pin, each assignment will change the working state of the pin.

Following the steps above, you will have code like this:

.. code-block:: python

    import machine
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    led_onboard.value(1)

Run it and you will be able to light up the onboard LED.

Next, we try to add the "extinguished" statement to turn off the LED:

.. code-block:: python

    import machine   
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    led_onboard.value(1)
    led_onboard.value(0)

According to the code line, this program will make the onboard LED turn on first and then turn off. But when the program is ran, you will find that this is not the case. The onboard LED never seems to light up. This is because the execution speed between the two .value() lines is very fast. Much faster than the reaction time of the human eye, the moment the onboard LED lights up is not enough to make us perceive the light. To fix this, we will need to slow down the program.

Insert the following statement into the second line of the program:

.. code-block:: python

    import utime

Like machine, the ``utime`` library is introduced here, which handles all time-related function in MicroPython, including the two-second delay function we need to use: ".sleep(). Insert a delay function between ``led_onboard.value(1)`` and ``led_onboard.value(0)``, and set the delay to 2 seconds:

.. code-block:: python

    utime.sleep(2)

Now, the code should look like this. Run it, and we will be able to see that the onboard LED first turns on, and then turns off:

.. code-block:: python

    import machine 
    import utime  
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    led_onboard.value(1)
    utime.sleep(2)
    led_onboard.value(0)

Finally, we should try making the LED blink. Using a while statement, rewrite the program with a loop. The Hello LED program will now be what you saw at the beginning of this chapter.

.. code-block:: python

    import machine
    import utime
    
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    while True:
        led_onboard.value(1)
        utime.sleep(2)
        led_onboard.value(0)
        utime.sleep(2)


Want More?
-------------------------

Usually, a MicroPython library will have a corresponding API (Application Programming Interface) file. This is a concise reference manual that contains all the information needed to use this library, detailed introduction to functions, classes, return types, parameters, etc., and even comes with a tutorial.

In this article, we used MicroPython's ``machine`` and ``utime`` libraries, and we can find more ways to use them here:

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_

* `utime <https://docs.micropython.org/en/latest/library/utime.html>`_

The following is another example of how to also to make the  ``led_onboard`` LED blink. Try reading the API files to understand how this version works!

.. code-block:: python

    import machine
    import utime

    led_onboard = machine.Pin(25, machine.Pin.OUT)
    while True:
        led_onboard.toggle()
        utime.sleep(1)
