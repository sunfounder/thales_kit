Neopixel
=============

The kit is equipped with a WS2812 RGB 8 LED light bar, which can display colorful colors, and each LED can be independently controlled. Here we try to use the tilt switch to control the flow direction of the LEDs on the WS2812 light bar.

Wring
----------

.. image:: ../img/WS2812_Flow_friz.png


**Step 1**

Use the [setup neopixel pin(0) pixels(8)] code block to initialize the neopixel connected to pin0 and declare that it has eight led lights.

**Step 2**

Set a variable **i** to determine the serial number of the led light to be lit on neopixel.

* [set (i) to (1)] Initialize this variable to 1, which means that neopixel's first led will be lit first.

**Step 3**

Set a range of 0 to 7 for the variable i. We can divide the natural number by 8 and then assign the remainder to i, so that i can be equal to any number from 0 to 7.

* [i mod 8] means dividing i by 8 and then taking the remainder.

.. image:: img/step3.png

**Step 4**

Use the [set all neopixel to...] code block to preset the color effects of all led lights, black means to turn off the lights, usually used in conjunction with the [update neopixels] code block to apply the preset effect.

**Step 5**

Use the if code block to set the judgment condition. When pin 14 is high, the LED lamp with the serial number i is lit, and the serial number is increased by one to achieve the effect of the water lamp.
Perform the same operation when pin14 is low, but subtract one from the serial number to reverse the direction of light flow.

* [chang i by (1)/(-1)] increase or decrease i by one

.. note::
    The operations of step3, step4, and setp5 need to be executed in the same loop.

Code
---------

After clicking Start in the upper left corner, the code starts to run. When the tilt switch is placed vertically, the LED on the WS2812 Strip will light up from one side, and when placed horizontally, the WS2812 will light up from the other side.

.. image:: img/neopixel.png
    :width: 300


