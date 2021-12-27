Tilt Switch
==================

This is a ball tilt-switch with a metal ball inside. It is used to detect inclinations of a small angle.

Wiring
-------------

.. image:: img/tilt0.png

1. Connect the 3V3 pin of the Pico to the positive power bus of the breadboard.
#. Connect the anode lead of the LED to the GP15 through a jumper wire, and connect the cathode lead to the same row through the middle gap of the breadboard.
#. Connect the LED cathode to the negative power bus of the breadboard through a 220Ω resistor.
#. Insert the tilt switch into the breadboard.
#. Use a jumper to connect one end of the tilt switch pin to the negative bus.
#. Use a jumper to connect the other pin of the tilt switch to GP14.
#. Use a 1k resistor to connect the end pin of the tilt switch to GP14 to the positive bus.
#. Connect the negative power bus of the breadboard to the GND of Pico.
#. When you place the tilt switch vertically or horizontally, the circuit will switch between closed and open.


Code
------------

After clicking Start in the upper left corner, the code starts to run. When the tilt switch is placed horizontally, the LED will be lit, and when placed vertically, the LED will be off.

.. image:: img/slide_switch.png
    :width: 300

Code explanation
-------------------

In the loop, judge the level of GP14. When it is low, it means that the tilt switch is placed vertically. At this time, turn off GP15 (low level), and the led will not light up.
When GP14 is at high level, it means that the tilt switch is placed horizontally. At this time, turn on GP15 (high level), and the LED will light up.   

.. note::
    Similar to the previous project, you can refer to :ref:`Button`