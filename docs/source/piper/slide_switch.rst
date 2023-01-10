Slide Switch
==================

In this project, we will learn how to use a slide switch. Usually,the slide switch is soldered on PCB as a power switch, but here we need to insert it into the breadboard, thus it may not be tightened. And we use it on the breadboard to show its function.

**Wiring**

.. image:: img/warning_light.png

* If the switch is toggled to the left, the 2 pins on the left are connected together; if it is toggled to the right, the 2 pins on the right are connected together.

* The purpose of connecting 10K resistor and capacitor on the toggle switch is to de-jitter and get a stable level.


**Code**

After connecting Pico, click the **Start** button and the code starts to run. Toggle the slide switch to the left and the LED will light up; otherwise, the LED will turn off.

.. image:: img/slide_switch.png
    :width: 300


.. note::
    This project code is exactly the same as the previous project :ref:`Button`.