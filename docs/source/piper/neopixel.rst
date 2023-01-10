Neopixel
=============

The kit is equipped with a WS2812 RGB LED Strip, which can display colorful colors, and each LED can be independently controlled. 

Here we try to use the tilt switch to control the flow direction of the LEDs on the WS2812 RGB LED Strip.

**Wiring**

.. image:: img/WS2812_Flow_friz.png

**Programming**


**Step 1**: Use the [setup neopixel pin() pixels()] block in the **Actions** palette to initialize the WS2812 RGB LED Strip. **0** means the connected pin is GP0 and **8** means there are 8 RGB LEDs on the WS2812 RGB LED Strip.

.. image:: img/neo1.png

**Step 2**: In the **Variables** palette, click the **Create variable** button to create a variable called **i** to represent the LEDs on the WS2812 RGB LED Strip. 

.. image:: img/neo2.png

**Step 3**: Set the initial value of variable **i** to 1 (the LED near the wires), then in [repeat forever] block, use [() mod ()] to set the value of i from 0 to 7. e.g. 1 mod 8 = 1... 8 mod 8 =0, 9 mod 8 =1, etc.

* [() mod ()]: This is the modulo operator block, from the **Loops** palette, drop down [() = ()] to select **mod**.

.. image:: img/neo3.png

**Step 4**: Set all neopixels to black to make all LEDs go off, then use [updates neopixels] to make this effect update to the WS2812 RGB LED Strip.

.. image:: img/neo4.png

* [set all neopixels to ()]: Use to set a color for all LEDs, there are 13*9 colors, the top right color is black to make LEDs to go off.
* [updates neopixels]: Update the effect to the WS2812 RGB LED Strip.

**Step 5**: If pin14 is read high, let the LEDs on the WS2812 RGB LED Strip light up one by one in green, otherwise light up green one by one in the opposite direction.

.. image:: img/neo5.png

* [change () by ()]: Used to increase (positive) or decrease (negative) the value of a variable by a specific step.


**Code**

After connecting Pico, click the **Start** button and the code starts to run.

When the tilt switch is placed vertically, it makes the LEDs on the WS2812 RGB LED Strip light up one by one in green, and when the tilt switch is placed horizontally, the LEDs light up one by one in the opposite direction in green.

.. image:: img/neopixel.png
    :width: 400



