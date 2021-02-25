Indentation
=============

缩进指的是代码行开头的缩进。
与标准Python程序一样，MicroPython程序通常从上到下运行：
它依次遍历每一行，在解释器中运行它，然后继续进行下一行，
就像您在命令行管理程序中逐行键入它们一样。
只是逐行浏览指令列表的程序不是很聪明，不过–因此，MicroPython与Python一样，有自己的方法来控制其程序运行的序列：缩进。

**Example**

.. code-block:: python

    if 8 > 5:
        print("Eight is greater than Five!")

>>> %Run -c $EDITOR_CONTENT
Eight is greater than Five!

Python will give you an error message "invalid syntax" if you skip the indentation:

**Example**

.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

您必须在同一代码块中使用相同数量的空格，否则同样会出现错误信息"invalid syntax"：

**Example**

.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")
            print("Eight is greater than Five")
            
>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax
