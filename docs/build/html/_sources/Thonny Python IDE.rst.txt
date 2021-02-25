Thonny Python IDE
=======================

Before you can start to program Pico with MicroPython, 你需要一个integrated development environment (IDE)，这里推荐Thonny, 这是一个为Python初学者提供的IDE，它内置了Python 3.7，因此只需要一个简单的安装程序，您就可以学习编程了。

网页下载
-------------

可以通过访问Thonny网站: https://thonny.org/来进行下载。进入页面之后，您会在右上角看到一个浅灰色的框，单击适用于您的操作系统的链接。

    .. image:: img/download_thonny.png

命令行下载
--------------

您也可以通过系统的命令行安装Thonny。在Windows上，您可以通过启动一个名为Command Prompt的程序来执行此操作，而在macOS和Linux上，您可以启动一个名为Terminal的程序。完成此操作后，输入以下命令：

.. code-block:: shell

    pip install thonny

Introducting Thonny IDE
----------------------------------
    .. image:: img/thonny_ide.jpg

* A ：菜单栏，包含了文件的新建，保存，编辑，查看，运行，调试等。
* B：这个纸张图标可让您创建一个新文件。通常，在Python中，您要将程序分成单独的文件。
* C：打开文件夹图标可让您打开计算机上已经存在的文件。你可以选择打开你的电脑或者是Raspberry Pi Pico里面的代码，如果你的Pico已经插入到你的电脑的话。
* D：使用软盘图标可以保存代码。同样你可以选择将代码保存在你的电脑还是Raspberry Pi Pico。
* E：播放图标可让您运行代码。请记住，您编写的代码是要执行的。运行代码意味着您要告诉Python，“按照我告诉您的做！” （换句话说，“通读我的代码并执行我编写的内容。”）
* F：Debug图标可让您调试代码。在编写代码时不可避免地会遇到错误。错误是问题的代名词。错误可能以多种形式出现，有时在使用不当语法时出现，有时在逻辑不正确时出现。
* Thonny的错误按钮通常用于发现和调查错误。顺便说一句，如果您想知道为什么将它们称为bug，那么还有一个有趣的故事，它是如何产生的！https://www.computerhistory.org/tdih/september/9/
* GHI箭头图标使您可以逐步运行程序。这在调试或换句话说，试图在代码中查找那些讨厌的错误时非常有用。按下Debug图标后，将使用这些图标。当您击中每个箭头时，您会注意到黄色突出显示的栏将指示Python当前正在评估的行或部分：
    
    G: 告诉Python来采取了一大步，这意味着跳跃到下一行或块中的代码。

    H: 告诉Python来采取一小步，意味着潜水深入表达的每个组件。

    I: 告诉Python来退出调试出来。

* J：恢复图标可让您从调试模式返回播放模式。在您不想再逐步浏览代码，而又希望程序完成运行的情况下，这很有用。
* K：使用停止图标可以停止运行代码。假设您的代码运行一个打开新窗口的程序，而您想停止该程序，则此功能特别有用。
* L：Script Area, 你可以在这编写您的Python代码.
* M：Python Shell, 你可以在这键入单个指令，当您按入键时，单个指令就会运行，并提供关于运行程序的信息。这也被称为REPL，意思是“阅读、评估、打印和循环。”
* N：Interpreter, 这里显示的是当前用于运行程序的Python版本，你可以手动更改成其他版本。Thonny窗口的右下角显示并允许您更改当前的Python解释器–用于运行程序的Python版本。当你的Pico已经插入到你的电脑上时，为了能在您Pico上使用MicroPython运行您的程序，你可以将你现在的interpreter(Python x.x.x)切换成MicroPython(Raspberry Pi Pico)，。

.. note::

   **NO Raspberry Pi Pico Option?**

   * 检查下您的Pico是否已经通过一根USB 线插入到您的电脑上。

   * Raspberry Pi Pico解释器仅在3.3.3及以上版本（目前3.3.3是最新版本）Thonny中可用。 如果您正在运行一个旧版本，请更新到3.3.3及以上版本。
