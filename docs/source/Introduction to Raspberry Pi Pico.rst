Introduction to Raspberry Pi Pico
===================================

.. image:: img/pico.jpg
    :width: 400

The Raspberry Pi Pico is a microcontroller board based on the Raspberry Pi RP2040 microcontroller chip.

Whether you want to learn the MicroPython programming language, take the first step in physical computing, or want to build a hardware project, Raspberry Pi Pico--and its amazing community--will support you every step of the way. In the project, it can control anything, from LEDs and buttons to sensors, motors, and even other items. Other microcontrollers.

Key Features
--------------
* RP2040 microcontroller chip designed by Raspberry Pi in the United Kingdom
* Dual-core Arm Cortex M0+ processor, flexible clock running up to 133 MHz
* 264KB of SRAM, and 2MB of on-board Flash memory
* Castellated module allows soldering direct to carrier boards
* USB 1.1 with device and host support
* Low-power sleep and dormant modes
* Drag-and-drop programming using mass storage over USB
* 26 × multi-function GPIO pins
* 2 × SPI, 2 × I2C, 2 × UART, 3 × 12-bit ADC, 16 × controllable PWM channels
* Accurate clock and timer on-chip
* Temperature sensor
* Accelerated floating-point libraries on-chip
* 8 × Programmable I/O (PIO) state machines for custom peripheral support

Pico's Pins
------------

.. image:: img/pico_pin.jpg
    :width: 400

.. list-table::
    :widths: 3 5 10
    :header-rows: 1

    *   - Name
        - Description
        - Function
    *   - GP0-GP28
        - General-purpose input/output pins
        - Act as either an input or an output and have no fixed purpose of their own
    *   - GND
        - 0 volts ground
        - Several GND pins around Pico to make wiring easier.
    *   - RUN
        - Enables or diables your Pico
        - Start and stop your Pico from another microcontroller.
    *   - GPxx_ADCx
        - General-purpose input/output or analogue input
        - Used as an analogue input as well as a digital input or output – but not both at the same time.
    *   - ADC_VREF
        - Analogue-to-digital converter (ADC) voltage reference
        - A special input pin which sets a reference voltage for any analogue inputs.
    *   - AGND
        - Analogue-to-digital converter (ADC) 0 volts ground
        - A special ground connection for use with the ADC_VREF pin.
    *   - 3V3(O)
        - 3.3 volts power
        - A source of 3.3V power, the same voltage your Pico runs at internally, generated from the VSYS input.
    *   - 3v3(E)
        - Enables or disables the power
        - Switch on or off the 3V3(O) power, can also switches your Pico off.
    *   - VSYS
        - ~2-5 volts power
        - A pin directly connected to your Pico’s internal power supply, which cannot be switched off without also switching Pico off.
    *   - VBUS
        - 5 volts power
        - A source of 5 V power taken from your Pico’s micro USB port, and used to power hardware which needs more than 3.3 V.

The best place to find everything you need to get started with your Raspberry Pi Pico is `here <https://www.raspberrypi.org/documentation/pico/getting-started/>`_

Or you can click on the links below: 

* `Raspberry Pi Pico Datasheet <https://datasheets.raspberrypi.org/pico/pico-datasheet.pdf>`_
* `RP2040 Datasheet <https://datasheets.raspberrypi.org/rp2040/rp2040-datasheet.pdf>`_
* `Hardware design with RP2040 <https://datasheets.raspberrypi.org/rp2040/hardware-design-with-rp2040.pdf>`_
* `Getting started with Raspberry Pi Pico <https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf>`_
* `Raspberry Pi Pico C/C++ SDK <https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-c-sdk.pdf>`_
* `Raspberry Pi Pico Python SDK <https://datasheets.raspberrypi.org/pico/raspberry-pi-pico-python-sdk.pdf>`_
