What is MicroPython?
==============================

MicroPython is a full Python compiler and run time that runs on the microcontroller's hardware like Raspberry Pi Pico. 
The user is presented with an interactive prompt (the REPL) to excute supported commands immediately. 
Included are a selection of core Python libraries; MicroPython includes modules which give the programmer access to low-level hardware.

故事从这里开始
----------------------


2013年，达米安·乔治（Damien George）发起了众筹活动（Kickstarter）时，一切都改变了。Damien是剑桥大学的一名本科生，是一名狂热的机器人程序员。他想将Python的世界从容量在千兆字节的机器降到千字节。他的Kickstarter竞选活动是为了支持他的发展，同时他将其概念证明转化为完成的实现。
MicroPython得到了不同的Pythonista社区的支持，他们对看到该项目的成功有着浓厚的兴趣。除了测试和支持代码库本身之外，开发人员还提供了教程，代码库和硬件端口，使该项目远远超出了Damien单独完成的工作。


Why MicroPython？
------------------

虽然最初的Kickstarter活动以带有STM32F4的开发板“pyboard”发布了MicroPython，但MicroPython支持许多基于ARM的产品建筑。主线支持的端口是ARM Cortex-M（许多STM32板，TI CC3200 / WiPy，Teensy板，Nordic nRF系列，SAMD21和SAMD51），ESP8266，ESP32、16bit PIC，Unix，Windows，Zephyr和JavaScript。
其次，MicroPython允许快速反馈。这是因为您可以使用REPL交互式地输入命令并获得响应。您甚至可以调整代码并立即运行它，而不是遍历代码-编译-上传-执行周期。

虽然Python同样有以上的优点，但对于一些Microcontroller boards像Raspberry Pi Pico，它们很小，很简单并且只有少量内存，根本无法运行Python语言。这就是MicroPython能够发展起来的原因，它保留了Python主要的特性，同时增加了一系列新的特性，以便适用于这些Microcontroller boards.
接下来将学习install MicroPython into the Raspberry Pi Pico。


Installing MicroPython
------------------------------

1. Plug the Pico to your PC with a Micro USB cable.
#. Rush and hold the **BOOTSEL** button and plug the other end of Micro USB cable into the computer.
#. Release the BOOTSEL button after your Pico is mount as a Mass Storage Device called RPI-RP2.

    .. image:: img/bootsel_onboard.png

#. Open the drive, you'll see two files on your Pico: **INDEX.HTM** and **INFO_UF2.TXT**. Double click the first file, INDEX.HTM, to open it in your browser.

    * **INDEX.HTM** : This is a welcome page telling you all about your Pico.
    * **INFO_UF2.TXT** : Contains the version of the bootloader it's currently running.

        .. image:: img/index_htm.png

#. When the browser opens, click **Getting started with MicroPython** .

    .. image:: img/welcome_pico.png

#. Download the MicroPython firmware by clicking the **Download UF2 file** button.

    .. image:: img/download_uf2.png

#. Open the **Downloads** folder and find the file you just downloaded - it will be called 'pico_micropython_xxxx.uf2', then drag it to **RPI-RP2** storage drive. Your Pico will reboot and disappear from the File Manager.

    .. image:: img/move_uf2.png

.. note::

    Please ignore the warning that a drive was removed without being ejected, that's supposed to happen!
    
    When you dragged the MicroPython firmware file onto your Pico, you told it to flash the firmware onto its internal storage.
    To do that, your pico switches out of the special mode you put it in with the 'BOOTSEL' button, flashes the new firmware, and then load it (meaning that your Pico is now running MicroPython).

Congratulations: your're now ready to get started with MicroPython on your Raspberry Pi Pico!