Your First MicroPython Program
==================================

In MicroPython, there are two options/methods for running code:

   * :ref:`Interactive Mode`
   * :ref:`Script Mode`

The interactive mode involves running your codes directly on the Python shell which can be accessed from the terminal of the operating system. In the script mode, you have to create a file, save it a name with a .py the extension then runs your code. The interactive mode is suitable when running a few lines of code. The script mode is recommended when you need to create large applications and save them for the next use.

Interactive Mode
---------------------

Interactive mode, also known as the REPL provides us with a quick way of running blocks or a single line of Python code. The code executes via the Python shell, which comes with Python installation. Interactive mode is handy when you just want to execute basic Python commands or you are new to Python programming and just want to get your hands dirty with this beautiful language.

Click the Python Shell area, type the following command after >>>, and then Enter.

.. code-block:: python

    print(“Hello, World!”)

.. image:: img/hello_shell.png

.. note::

    If your program does not run, but prints a "syntax error" message to the Shell area, then there is an error in what you have written.
    MicroPython needs to write its instructions in a very specific way: miss parentheses or quotation marks, spell "print" errors, or give it a capital P, or add extra symbols somewhere in the instruction, and it won't run . Try to type the command again and make sure it is the same as this one, and then press Enter.

You will find that the message "hello world" will be printed out immediately in the Shell area.

Script Mode
---------------
If you need to write a long piece of Python code or your Python script spans multiple files, interactive mode is not recommended. Script mode is the way to go in such cases. In script mode, You write your code in a text file then save it with a .py extension which stands for "Python".

Enter the same command "print("Hello, World!")" in the script area, when you press the ENTER key, the program will not run, only one more blank line in the script area.

    .. image:: img/hello_world_script.png

You need click "Run Current Script" or simply press F5 to run it. If your code has not been saved, a window will pop up asking to save to This computer or Raspberry Pi Pico?

    .. image:: img/where_save.png

.. note::
    When you tell Thonny to save your program on the Raspberry Pi Pico, it means that the program is stored on the Pico itself. If you unplug your Pico, take it to your friend's house, a school event, or a coding club, and plug it into their computer, your programs are still where you saved them-right on yourself On the Pico.

Choose the location you want to save, then enter the file name "hello_world" and the extension ".py", and then click OK.

    .. image:: img/hello_world_save.png

.. note::
    You can save your code under any name, but it’s best to describe what kind of code it is, and don’t name it with meaningless names such as "abc.py".
    It is important to note that if you save the code file name as "main.py", it will run automatically when the power is turned on.

When your program is saved, it will run automatically and you will see 2 lines of information in the Shell area.

    >>> %Run -c $EDITOR_CONTENT 
    Hello, World!

The first of these lines is an instruction from Thonny telling the MicroPython interpreter on your Pico to run the contents of the script area – the‘EDITOR_CONTENT’. The second is the output of the program – the message you told MicroPython to print.

In Script mode, it is very easy for you to open the previously saved code again, but the code entered in Interactive Mode will not be saved and can only be re-entered.
Click the open icon in the Thonny toolbar, just like when you save the program, you will be asked whether you want to save it to "This Computer" or "Raspberry Pi Pico"-for example, click "Raspberry Pi Pico" and you will see A list of all programs you save to your Pico. Find hello_world.py in the list-if your Pico is new, it will be the only file there-and click it to select it, then click OK. Your program will be loaded into Thonny, ready to edit or run it again for you.