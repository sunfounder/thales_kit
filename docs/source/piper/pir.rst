PIR Module
=================

In the previous chapters, we used simple electronic components (such as LED, button). This time we will use the sensor module - PIR.

Passive infrared sensor (PIR sensor) is a common sensor that can measure infrared (IR) light emitted by objects in its field of view.
Simply put, it will receive infrared radiation emitted from the body, thereby detecting the movement of people and other animals.
More specifically, it tells the main control board that someone has entered your room.

:ref:`PIR Motion Sensor`

Now, let's use PIR module and LED to build an Intruder Alarm, when an object passes through the PIR, the LED will light up.

**Wiring**

.. image:: img/pir0.png

* The PIR module will output a high level signal when it detecwts people or other animals passing by.

**Code**

After connecting Pico, click the **Start** button and the code starts to run. When an object passes through the PIR, the LED will light up.

.. image:: img/pir.png
    :width: 300

.. note::
    This project code is exactly the same as the previous project :ref:`Button`. 