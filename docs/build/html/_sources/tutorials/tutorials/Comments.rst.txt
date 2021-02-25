Comments
=============

代码中的注释有助于我们理解代码，让整个代码可更具可阅读性以及可在测试的时候注释掉部分代码，让这部分代码不运行。

单行注释
---------

MicroPython中的单行注释以#开头，后面的文字直到行尾都算注释。注释可放在代码前面，也可放在代码后面。

**Example**

.. code-block:: python

    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

注释不一定都是解释代码的文本，也可以将部分代码注释掉，来阻止micropython运行代码。

**Example**

.. code-block:: python

    #print("Can't run it！")
    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

多行注释
---------

 如果要进行多行的注释，可以使用多个#号。

**Example**

.. code-block:: python

    #This is a comment
    #written in
    #more than just one line
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

或者，也可以不按预期使用多行字符串。

由于MicroPython会忽略未分配给变量的字符串文字，因此您可以在代码中添加多行字符串（三引号），并将注释放入其中：

**Example**

.. code-block:: python

    """
    This is a comment
    written in
    more than just one line
    """
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

只要未将字符串分配给变量，MicroPython就会读取该代码，但随后将其忽略，并且您已做出多行注释。