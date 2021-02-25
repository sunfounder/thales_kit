Print()
=====================

The ``print()`` function prints the specified message to the screen, or other standard output device.
The message can be a string, or any other object, the object will be converted into a string before written to the screen.

打印多个对象：

**Example**

.. code-block:: python

    print("Welcome!", "Enjoy yourself!")

>>> %Run -c $EDITOR_CONTENT
Welcome! Enjoy yourself!

打印元组：

**Example**

.. code-block:: python

    x = ("pear", "apple", "grape")
    print(x)

>>> %Run -c $EDITOR_CONTENT
('pear', 'apple', 'grape')

打印两条消息，并指定分隔符：

**Example**

.. code-block:: python

    print("Hello", "how are you?", sep="---")

>>> %Run -c $EDITOR_CONTENT
Hello---how are you?