Variables
==========
变量是用于存储数据值得容器。

创建一个变量很简单，只需要起个名，给他赋予一个值，在赋值的时候不需要指定变量的数据类型，因为变量是一个引用，它通过赋值来访问不同数据类型的对象。

给变量命名必须遵循以下规则：

* 变量名只能包含数字、字母、下划线
* 变量名的第一个字符必须是字母或下划线
* 变量名区分大小写

Create Variable
------------------
MicroPython中没有用于声明变量得命令，变量是在您首次为它分配值时创建的，它不需要使用任何特定类型声明，甚至可以在设置变量后更改类型。

**Example**

.. code-block:: python

    x = 8       # x is of type int
    x = "lily" # x is now of type str
    print(x)

>>> %Run -c $EDITOR_CONTENT
lily


Casting
-------------
如果你想为变量制定数据类型，可通过强制转换来完成。

**Example**

.. code-block:: python

    x = int(5)    # y will be 5
    y = str(5)    # x will be '5'
    z = float(5)  # z will be 5.0
    print(x,y,z)

>>> %Run -c $EDITOR_CONTENT
5 5 5.0

Get the Type
-------------------
You can get the data type of a variable with the `type()` function.

**Example**

.. code-block:: python

    x = 5
    y = "hello"
    z = 5.0
    print(type(x),type(y),type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'int'> <class 'str'> <class 'float'>

Single or Double Quotes?
---------------------------

在MicroPython中，可用单引号或者双引号来定义字符串变量。

**Example**

.. code-block:: python

    x = "hello"
    # is the same as
    x = 'hello'

Case-Sensitive
---------------------
Variable names are case-sensitive.

**Example**

.. code-block:: python

    a = 5
    A = "lily"
    #A will not overwrite a
    print(a, A)

>>> %Run -c $EDITOR_CONTENT
5 lily


