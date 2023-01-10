.. _py_room_temp:

2.19 Room Temperature Meter
======================================

Using a thermistor and an I2C LCD1602, we can create a room temperature meter.

This project is very simple, it is based on :ref:`py_thermometer` with I2C LCD1602 to display the temperature.


**Schematic**

.. image:: img/sch_room_temp.png


**Wiring**

.. image:: img/wiring_room_temp.png

**Code**

.. note::

    The ``lcd1602.py`` library is used here, please make sure you have it in your Raspberry Pi Pico, if not, please refer to :ref:`py_create_library`.

.. code-block:: python

    from lcd1602 import LCD
    import machine
    import utime
    import math

    thermistor = machine.ADC(28)
    lcd = LCD()

    while True:
        temperature_value = thermistor.read_u16()
        Vr = 3.3 * float(temperature_value) / 65535
        Rt = 10000 * Vr / (3.3 - Vr)
        temp = 1/(((math.log(Rt / 10000)) / 3950) + (1 / (273.15+25)))
        Cel = temp - 273.15
        #Fah = Cel * 1.8 + 32
        #print ('Celsius: %.2f C  Fahrenheit: %.2f F' % (Cel, Fah))
        #utime.sleep_ms(200)

        string = " Temperature is \n    " + str('{:.2f}'.format(Cel))+ " C"
        lcd.message(string)
        utime.sleep(1)
        lcd.clear()

The LCD will display the temperature value in the current environment after the program runs.

.. note:: 
    If the code and wiring are fine, but the LCD still does not display content, you can turn the potentiometer on the back to increase the contrast.

