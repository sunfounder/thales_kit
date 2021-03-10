Thonny Python IDE
=======================

Before you can start to program Pico with MicroPython, you need an integrated development environment (IDE), here we recommend Thonny, an It has Python 3.7 built in, so you can learn to program with just a simple installer.

Download from Web
------------------------

You can download it by visiting the Thonny website: https://thonny.org/. Once open the page, you will see a light gray box in the upper right corner, click on the link that applies to your operating system.

    .. image:: img/download_thonny.png

Download via Command Line
-------------------------------

You can also install Thonny from the command line of your system. On Windows, you can do this by starting a program called Command Prompt, and on macOS and Linux, you can start a program called Terminal. Once you have done this, enter the following command.

.. code-block:: shell

    pip install thonny

Introducing Thonny IDE
----------------------------------
    .. image:: img/thonny_ide.jpg

* **A**: The menu bar that contains the file New, Save, Edit, View, Run, Debug, etc.
* **B**: This paper icon allows you to create a new file. Usually, in Python, you want to split the program into separate files.
* **C**: The open folder icon lets you open a file that already exists on your computer or the Raspberry Pi Pico, if your Pico is already plugged into your computer.
* **D**: Click on the floppy disk icon to save the code. Again you can choose whether to save the code to your computer or to the Raspberry Pi Pico.
* **E**: The play icon allows you to run the code. If you have not saved the code, save the code before it can run.
* **F**: The Debug icon allows you to debug your code. Inevitably, you will encounter errors when writing code. Errors can appear in many forms, sometimes when improper syntax is used, sometimes when the logic is incorrect. debug is exactly what is used to find and investigate errors.
* The G, H, I arrow icons allow you to run the program step by step. This is very useful when debugging or in other words, trying to find those pesky bugs in your code. These icons will be used when you click the **Debug** icon. As you hit each arrow, you will notice that the yellow highlighted bar will indicate the line or section of Python currently being evaluated at:
    
    * **G**: Tell Python to take a big step, which means jumping to the next line or block of code.  
    * **H**: Telling Python to take a small step means expressing each component in depth.  
    * **I**: Tell Python to exit debugging.  

* **J**：The resume icon allows you to return from debug mode to play mode. This is useful in cases where you no longer want to step through the code and want the program to finish running.
* **K**：Use the stop icon to stop running code. This is especially useful if your code is running a program that opens a new window and you want to stop it.
* **L**：Script Area, where you can write your Python code.
* **M**：Python Shell, where you can type a single command, and when you press the Enter key, the single command will run and provide information about the running program. This is also known as REPL, which means "Read, Evaluate, Print, and Loop."
* **N**：Interpreter, where the current version of Python used to run your program is displayed, can be changed manually to another versionby clicking on it.

.. note::

   **NO Raspberry Pi Pico Option?**

   * Check that your Pico is plugged into your computer via a USB cable.

   * The Raspberry Pi Pico interpreter is only available in version 3.3.3 and higher version of Thonny. If you are running an older version, please update to version 3.3.3 and above.
