Colorful Light
==============================================

As we know, light can be superimposed. For example, blue light plus green light will produce cyan light, and red light plus green light will produce yellow light.
This is called "The additive method of color mixing".

* `Additive color - Wikipedia <https://en.wikipedia.org/wiki/Additive_color>`_

Based on this method, we can use the three primary colors to mix the visible light of any color according to different specific gravity. For example, orange can be produced by more red and less green.

In this chapter, we will use RGB LED to explore the mystery of additive color mixing!

RGB LED is equivalent to encapsulating Red LED, Green LED, Blue LED under one lamp cap, and the three LEDs share one cathode pin.
Since the electric signal is provided for each anode pin, the light of the corresponding color can be displayed. By changing the electrical signal intensity of each anode, it can be made to produce various colors.

Wiring
-----------------------------------------------

Put the RGB LED flat on the table, we can see that it has 4 leads of different lengths.
Find the longest one (GND) and turn it sideways to the left.
Now, the order of the four leads is Red, GND, Green, Blue from left to right.

.. image:: img/wiring_colorful_light.png

1. Connect the GND pin of the Pico to the negative power bus of the breadboard.
#. Insert the RGB LED into the breadboard so that its four pins are in different rows.
#. Connect the red lead to the GP13 pin via a 330Ω resistor. When using the same power supply intensity, the Red LED will be brighter than the other two, and a slightly larger resistor needs to be used to reduce its brightness.
#. Connect the Green lead to the GP14 pin via a 220Ω resistor.
#. Connect the Blue lead to the GP15 pin via a 220Ω resistor.
#. Connect the GND lead to the negative power bus.
#. Connect the negative power bus to Pico's GND.

.. note::
    The color ring of the 220Ω resistor is red, red, black, black and brown.
    The color ring of the 330Ω resistor is orange, orange, black, black and brown.

Code
-----------------------------------------------

Here, we can choose our favorite color in drawing software (such as paint) and display it with RGB LED.

.. code-block:: python

    import machine
    import utime

    red = machine.PWM(machine.Pin(13))
    green = machine.PWM(machine.Pin(14))
    blue = machine.PWM(machine.Pin(15))
    red.freq(1000)
    green.freq(1000)
    blue.freq(1000)

    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    def color_to_duty(rgb_value):
        rgb_value = int(interval_mapping(rgb_value,0,255,0,65535))
        return rgb_value

    def color_set(red_value,green_value,blue_value):
        red.duty_u16(color_to_duty(red_value))
        green.duty_u16(color_to_duty(green_value))
        blue.duty_u16(color_to_duty(blue_value))

    color_set(255,128,0)

.. image:: img/edit_colors.png

Write the RGB value into color_set(), you will be able to see the RGB light up the color you want first


How it works?
--------------------

We defined a ``color_set()`` function to let the three primary colors work together.

At present, pixels in computer hardware usually adopt a 24-bit representation method. The three primary colors are divided into 8 bits, and the intensity of each primary color is based on the highest value of 8 bits to the 8th power of 2, which is 256 values. 
16777216 colors can be combined in this way.
The ``color_set()`` function also follows the 24-bit notation, which makes it easier for us to select the desired color.

And because the ``duty_u16()`` value range is 0~65535 (not 0~255) when the LED is output through PWM, in order to correspond to the RGB value, we define ``color_to_duty()`` and ``interval_mapping ()`` function to map the RGB value to the duty value.