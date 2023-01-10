Active Buzzer
==================

In this project, we will learn how to use a button to control the active buzzer.

**Wring**

.. image:: img/doorbell.png

* An active buzzer is a device that makes a sound by directly giving high and low levels. Since the current coming out of the Pico pin is small, an NPN transistor is used here to amplify the current to make the buzzer sound louder.

* The 1K resistor between the NPN transistor and GP15 is used for current limiting when the transistor is energized.

**Code**

After connecting Pico, click the **Start** button and the code starts to run. The buzzer will sound when the button is pressed.

.. image:: img/pir.png
    :width: 300

.. note::
    This project code is exactly the same as the previous project :ref:`Button`.