FAQ
=========

Q1: NO MicroPython(Raspberry Pi Pico) Interpreter Option on Thonny IDE?
--------------------------------------------------------------------------

.. image:: img/interepter_thonny.png


* Check that your Pico is plugged into your computer via a USB cable.
* Check that you have installed MicroPython for Pico (:ref:`install_micropython_on_pico`).
* The Raspberry Pi Pico interpreter is only available in version 3.3.3 or higher version of Thonny. If you are running an older version, please update (:ref:`thonny_ide`).
* Plug in/out the micro USB cable sveral times.

Q2: Cannot open Pico code or save code to Pico via Thonny IDE?
------------------------------------------------------------------------

.. image:: img/save_to_pico.png

* Check that your Pico is plugged into your computer via a USB cable.
* Check that you have selected the Interpreter as **MicroPython (Raspberry Pi Pico)**.

Q3: Can Raspberry Pi Pico be used on Thonny and Arduino at the same time?
--------------------------------------------------------------------------------

NO, you need to do some different operations.

* If you used it on Arduino first, and now you want to use it on Thonny IDE, you need to :ref:`install_micropython_on_pico`.
* If you used it on Thonny first， and now you want to use it on Arduino IDE, you need to :ref:`setup_pico_arduino`.

Q4: Code upload failed in Arduino IDE?
-----------------------------------------
* Make sure you have installed the Pico board in the Arduino IDE.
* Check that the Board(Raspberry Pi Pico) or port（COMxx (Raspberry Pi Pico)）is selected correctly.
* Make sure you have plugged the Pico into your computer.
* If only COMxx (The complete one should be COMxx (Raspberry Pi Pico)) is displayed, it means that Pico is not correctly recognized by the computer. You need to refer to steps 5, 6, and 7 in :ref:`setup_pico_arduino`.

Q5: If your computer is win7 and pico cannot be detected.
----------------------------------------------------------
1. Download the USB CDC driver from  
   http://aem-origin.microchip.com/en-us/mindi-sw-library?swsearch=Atmel%2520USB%2520CDC%2520Virtual%2520COM%2520Driver
2. Unzip the amtel_devices_cdc.inf file to a folder named "pico-serial"
3. Change the name of amtel_devices_cdc.inf file to pico-serial.inf
4. Open/edit the pico-serial.inf in a basic editor like notepad
5. Remove and replace the lines under the following headings:

.. code-block::

    [DeviceList] 
    %PI_CDC_PICO%=DriverInstall, USB\VID_2E8A&PID_0005&MI_00

    [DeviceList.NTAMD64]
    %PI_CDC_PICO%=DriverInstall, USB\VID_2E8A&PID_0005&MI_00 

    [DeviceList.NTIA64]
    %PI_CDC_PICO%=DriverInstall, USB\VID_2E8A&PID_0005&MI_00 

    [DeviceList.NT]
    %PI_CDC_PICO%=DriverInstall, USB\VID_2E8A&PID_0005&MI_00

    [Strings] 
    Manufacturer = "ATMEL, Inc." 
    PI_CDC_PICO = "Pi Pico Serial Port" 
    Serial.SvcDesc = "Pi Pico Serial Driver"

6. Close and save and make sure your retain the name as pico-serial.inf
7. Go to your pc device list, find the pico under Ports, named something like CDC Device. A yellow exclamation mark indicates it.
8. Right click on the CDC Device and update or install driver choosing the file you created from the location you saved it at.

