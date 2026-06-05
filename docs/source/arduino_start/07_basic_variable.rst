变量
========

变量是程序中最强大和最关键的工��之一。它帮助我们存储和调用程序中的数据。

下面的项目文件使用了变量。它将板载 LED 的引脚号存储在变量 ``ledPin`` 中，将数字"500"存储在变量 ``delayTime`` 中。

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT);
    }

    void loop() {
        digitalWrite(ledPin,HIGH);
        delay(delayTime);
        digitalWrite(ledPin,LOW);
        delay(delayTime);
    }

等等，这和 ``#define`` 的功能重复了吗？答案是否定的。

* ``#define`` 的作用是简单直接的文本替换，编译器不认为它是程序的一部分。
* 而``变量``存在于程序内部，用于存储和调用值。变量还可以在程序内部修改其值，这是 define 无法做到的。

下面的项目文件对变量进行了自加操作，这将使板载 LED 每次闪烁后延时更长。

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT);
    }

    void loop() {
        digitalWrite(ledPin,HIGH);
        delay(delayTime);
        digitalWrite(ledPin,LOW);
        delay(delayTime);
        delayTime = delayTime+200; //每次执行将值增加200
    }

声明变量
-------------------

声明变量就是创建一个变量。

声明一个变量需要两样东西：数据类型和变量名。数据类型需要用空格与变量名隔开，变量声明需要以 ``;`` 结尾。

让我们以这个变量为例。

.. code-block:: C

    int delayTime;

**数据类型**

这里的 ``int`` 是一种称为整型的数据类型，可用于存储从 -32768 到 32766 的整数。它不能用于存储小数。

除了整数，变量还可以存储不同类型的数据。Arduino 语言（记住，它是 C++）内置了对以下几种数据类型的支持（这里只列出最常用和最有用的）：

* ``float``：存储小数，例如 3.1415926。
* ``byte``：存储 0 到 255 之间的数字。
* ``boolean``：只存储两个可能的值，``True`` 或 ``False``，即使它在内存中占用一个字节。
* ``char``：存储 -127 到 127 之间的数字。由于被标记为 ``char``，编译器会尝试将其匹配为 |link_ascii| 中的一个字符。
* ``string``：存储一个字符串，例如 ``Halloween``。


**变量名**

你可以将变量设为任何你想要的名称，例如 ``i``、``apple``、``Bruce``、``R2D2``、``Sectumsempra``，但需要遵循一些基本规则。

1. 描述其用途。在这里，我将变量命名为 delayTime，这样你可以轻松理解它的作用。如果我将其命名为 ``barryAllen``，它也能正常工作，但会让人查看代码时感到困惑。

2. 使用常规命名法。你可以像我一样使用驼峰命名法，将 ``delayTime`` 中的 T 大写，这样可以很容易看出变量由两个单词组成。你也可以使用下划线命名法，将变量写为 ``delay_time``。这不会影响程序的运行，但如果你使用自己偏好的命名法，将有助于程序员阅读代码。

3. 不要使用关键字。类似于我们输入"int"时发生的情况，Arduino IDE 会将其着色，以提醒你这是一个具有特殊用途的单词，不能用作变量名。如果变量名被着色了，请更改它。

4. 不允许使用特殊符号。例如，空格、#、$、/、+、% 等。英文字母（区分大小写）、下划线和数字（但数字不能用作变量名的第一个字符）的组合已经足够丰富。


**给变量赋值**

声明变量后，就需要存储数据了。我们使用赋值运算符（即 ``=``）将值放入变量中。

我们可以在声明变量的同时为其赋值。

.. code-block:: C

    int delayTime = 500;

也可以在某些时候为其赋一个新值。

.. code-block:: C

    int delayTime; // 没有值
    delayTime = 500; // 值为 500
    delayTime = delayTime +200; // 值为 700
