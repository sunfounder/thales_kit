Hello, LED! 
=======================================

Just as printing "Hello, world!" is the first step in learning programming, letting the LED light up is the traditional entry to learning physical programming.

There is a small LED on the top of the Pico. Like other LEDs, it will glow when power is on and go out when power is off.


.. image:: img/led_onboard.png

Code
----------------

Let's copy this code into Thonny and click "Run Current Script" or simply press F5 to run it to make the LED blink!

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

The onboard LED is connected to the GP25 pin, if you carefully observe the Pico pinout, you will find that GP25 is one of the hidden pins, which means that we cannot use this pin (even if GP25 is used in exactly the same way as other pins). The advantage of this design is that even if you don't connect any external components, you can still have an OUTPUT to test the program.

The machine library is required to use GPIO.

.. code-block:: python

    import machine

This library contains all the instructions needed to communicate between MicroPython and Pico. Without this line of code, we will not be able to control any GPIOs (Of course including GP25).

The next thing to notice is this line:

.. code-block:: python

    led_onboard = machine.Pin(25, machine.Pin.OUT)

An object named ``led_onboard`` is defined here. Technically, it can be any name, it can be x, y, banana, Micheal_Jackson, or any character, but it is best to use a name that describes the purpose to ensure that the program is easy to read.

The second part of this line (the part after the equal sign) calls the Pin function in the machine library. It is used to tell Pico's GPIO pins what to do.
The Pin function has two parameters: the first parameter (25) means the pin you want to set; the second parameter (machine.Pin.OUT) tells that the pin should be used as an output instead of an input.

The above code has "set" the pin, but it will not light up the LED. To do this, we also need to "use" the pin.

.. code-block:: python

    led_onboard.value(1)

We have set up the GP25 pin before and named it led_onboard. The function of this statement is to set the value of ``led_onboard`` to 1 to turn the on-board LED on.

All in all, to use GPIO, these steps are necessary:

* **import machine library**: This is necessary, and it is only executed once in the entire program.
* **Set GPIO**: Each pin should be set before use.
* **Use**: Assign a value to the pin, each assignment will change the working state of the pin.

If we follow the above steps to write an example, then you will get code like this:

.. code-block:: python

    import machine
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    led_onboard.value(1)

Run it and you will be able to light up the onboard LED.

Next, we try to add the "extinguished" statement:

.. code-block:: python

    import machine   
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    led_onboard.value(1)
    led_onboard.value(0)

According to the code line, this program will make the onboard LED turn on first and then turn off. But when you use it, you will find that this is not the case. The onboard LED never seems to light up. This is because the execution speed between the two lines is very fast, much faster than the reaction time of the human eye. The moment the onboard LED lights up is not enough to make us perceive the light. To fix that, we need to slow down the program.

Insert the following statement into the second line of the program:

.. code-block:: python

    import utime

Like machine, the ``utime`` library is introduced here, which handles all time-related things, including the delay we need to use. Let's insert a delay sentence between ``led_onboard.value(1)`` and ``led_onboard.value(0)``, let them be separated by 2 seconds:

.. code-block:: python

    utime.sleep(2)

Now, the code should look like this. Run it, we will be able to see that the onboard LED turns on first and then turns off:

.. code-block:: python

    import machine 
    import utime  
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    led_onboard.value(1)
    utime.sleep(2)
    led_onboard.value(0)

Finally, we should make the LED blink. Create a loop, rewrite the program, and it will be what you saw at the beginning of this chapter.

.. code-block:: python

    import machine
    import utime
    
    led_onboard = machine.Pin(25, machine.Pin.OUT)
    while True:
        led_onboard.value(1)
        utime.sleep(2)
        led_onboard.value(0)
        utime.sleep(2)


What More?
-------------------------

Usually, the library will have a corresponding API (Application Programming Interface) file. This is a concise reference manual that contains all the information needed to use this library, detailed introduction to functions, classes, return types, parameters, etc., and even comes with a tutorial.

In this article, we used MicroPython's ``machine`` and ``utime`` libraries, we can find more ways to use them here.

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_

* `utime <https://docs.micropython.org/en/latest/library/utime.html>`_

The following is also an example of making the LED blink, please try to read the API file to understand it!

.. code-block:: python

    import machine
    import utime

    led_onboard = machine.Pin(25, machine.Pin.OUT)
    while True:
        led_onboard.toggle()
        utime.sleep(1)
