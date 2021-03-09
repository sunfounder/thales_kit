Reading Button Value
==============================================

From the name of GPIO (General-purpose input/output), we can see that the pin should have two methods of input and output. In the LED, we used the output, in this chapter we use the keys to use the input.


Wiring
------------------------

.. image:: img/wiring_read_button_value.png


Let's follow the direction of the circuit to build the circuit!

1. Connect the 3V3 pin of Pico to the positive power bus of the breadboard.
#. Insert the button into the breadboard and straddle the central dividing line.

    .. note::
        We can think of the four-legged button as an H-shaped button. Its left (right) two feet are connected, which means that after it straddles the central dividing line, it will connect the two half rows of the same row number together. (For example, in my circuit, E23 and F23 have been connected, as are E25 and F25).

        Before the button is pressed, the left and right sides are independent of each other, and current cannot flow from one side to the other.

#. Use a jumper to connect the positive bus of the power supply to a pin of the button (mine is the pin on the upper right).
#. Connect the other pin (upper left or lower left) to GP14 with a jumper wire.
#. Use a 10kΩ resistor to connect the pin on the side of GP14 to the negative power bus of the breadboard.

    .. note::
        The color ring of the 10kΩ resistor is brown, black, black, red, brown.

#. Connect the negative power bus of the breadboard to Pico's GND.

Code
-----------------------------------

When the button is pressed, the current will flow from 3V3 through the switch to GP14, in other words, GP14 will read a high-level signal ‘1’; otherwise, it will read a low-level signal ‘0’.

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

Buttons require pull-up resistors or pull-down resistors. If there is no pull-up or pull-down resistor, the main controller may receive a ‘noisy’ signal which can trigger even when you’re not pushing the button.

Set the pull-down resistor so that when the GPIO is not connected to a high level, the input value is stable to ‘0’; if it is set to pull up, it will make the GPIO stable to obtain an input value of 1 when the GPIO is not connected to a low level.

Next is the wiring and code when the button uses the pull-up working mode, please try it.

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
