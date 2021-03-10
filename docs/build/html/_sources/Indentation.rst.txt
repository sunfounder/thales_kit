Indentation
=============

Indentation refers to the indentation at the beginning of a line of code.
Like standard Python programs, MicroPython programs usually run from top to bottom:
It traverses each line in turn, runs it in the interpreter, and then continues to the next line,
Just like you type them line by line in the Shell.
A program that just browses the instruction list line by line is not very smart, but-therefore, MicroPython, like Python, has its own method to control the sequence of its program execution: indentation.

**Example**

.. code-block:: python

    if 8 > 5:
        print("Eight is greater than Five!")

>>> %Run -c $EDITOR_CONTENT
Eight is greater than Five!

Python will give you an error message "invalid syntax" if you skip the indentation.

**Example**

.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

You must put at least one space before print(), otherwise an error message "Invalid syntax" will appear. It is usually recommended to standardise spaces by pressing the Tab key uniformly.

**Example**

.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")
            print("Eight is greater than Five")
            
>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax
