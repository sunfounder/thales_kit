Slide Switch
==================

In this project, we will learn how to use a slide switch. Usually,the slide switch is soldered on PCB as a power switch, but here we need to insert it into the breadboard, thus it may not be tightened. And we use it on the breadboard to show its function.

Wiring
-------------------------

.. image:: ../img/warning_light.png

1. Connect the 3V3 pin of Pico to the positive power bus of the breadboard.
#. Connect one end (either end) of the 220 ohm resistor to GP15, and insert the other end into the free row of the breadboard.
#. Insert the anode lead of the LED into the same row as the end of the 220Ω resistor, and connect the cathode lead across the middle gap of the breadboard to the same row.
#. Connect the LED cathode to the negative power bus of the breadboard.
#. Insert the slide switch into the breadboard.
#. Use a jumper wire to connect one end of slide switch pin to the negative bus.
#. Connect the middle pin to GP14 with a jumper wire.
#. Use a jumper wire to connect last end of slide switch pin to the positive bus
#. Use a 10K resistor to connect the middle pin of the slide switch and the negative bus.
#. Use a 104 capacitor to connect the middle pin of the slide switch and the negative bus to realize debounce that may arise from your toggle of switch.
#. Connect the negative power bus of the breadboard to Pico's GND.

When you toggle the slide switch, the circuit will switch between closed and open.


Code
---------

After clicking Start in the upper left corner, the code starts to run. Switch the slide switch to one side and the LED will flash. Switch to the other side and the LED will turn off.

.. image:: img/slide_switch.png
    :width: 300

Code explanation
-------------------

Judge the level of GP14 in the loop. When it is low, it means that the slide switch slides to the right. At this time, turn off GP15 (low level), and the led will not light up.
When GP14 is at high level, it means that the slide switch slides to the left. At this time, turn on GP15 (high level), and the led will light up. 

.. note::
    Similar to the previous project, you can refer to :ref:`Button`