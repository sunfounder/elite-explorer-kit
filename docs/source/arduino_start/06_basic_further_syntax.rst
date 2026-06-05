项目编写规则
================================


如果你让朋友帮你开灯，你可以说"请开灯"，或者"兄弟，开灯"，你可以使用任何你想要的语气。

但是，如果你想让 Arduino 开发板为你做某事，你需要遵循 Arduino 程序编写规则来输入命令。

本章包含 Arduino 语言的基本规则，将帮助你理解如何将自然语言转换为代码。

当然，这是一个需要时间熟悉的过程，也是新手最容易出错的部分，所以如果经常犯错也没关系，多试几次就好了。


分号 ``;``
---------------

就像写信一样，你会在每句话的末尾写一个句号作为结束，Arduino 语言要求你使用 ``;`` 来告诉开发板命令的结束。

以熟悉的"板载 LED 闪烁"为例。一个正常的项目应该是这样的。

示例：

.. code-block:: C

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

接下来，让我们看看下面两个项目，在运行之前猜测它们能否被 Arduino 正确识别。

项目 A：

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

项目 B：

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,

        LOW);
                delay(500)
        ;
    }

结果是**项目 A** 报错，而 **项目 B** 可以运行。

* **项目 A** 的错误是缺少 ``;``，虽然看起来正常，但 Arduino 无法读取。
* **项目 B** 看起来反人类，但实际上，缩进、换行和空格在 Arduino 程序中是不存在的，因此对于 Arduino 编译器来说，它看起来和示例是一样的。

但是，请不要像**项目 B** 那样编写代码，因为通常是由人来编写和查看代码，所以不要给自己找麻烦。


花括号 ``{}``
------------------

``{}`` 是 Arduino 编程语言的主要组成部分，它们必须成对出现。
一个更好的编程习惯是，在输入左花括号后，立即输入右花括号，然后将光标移到花括号之间插入语句。



注释 ``//``
---------------

注释是编译器忽略的项目部分。它们通常用于告诉他人程序的工作原理。

如果我们在一行代码中写入两个相邻的斜杠，编译器将忽略该行之后的所有内容。

如果我们创建一个新项目，它会自带两个注释，如果删除这两个注释，项目不会受到任何影响。

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // put your setup code here, to run once:

    }

    void loop() {
        // put your main code here, to run repeatedly:

    }


注释在编程中非常有用，下面列出了几种常见用法。

* 用法 A：告诉你自己或他人这段代码的作用。

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //将引脚13设置为输出模式，它控制板载LED
    }

    void loop() {
        digitalWrite(13,HIGH); //通过将引脚13置高来点亮板载LED
        delay(500); //保持状态500毫秒
        digitalWrite(13,LOW); //关闭板载LED
        delay(500);//保持状态500毫秒
    }

* 用法 B：临时使某些语句失效（不删除它们），在需要使用时再取消注释，这样就不必重新编写。这在调试代码和尝试定位程序错误时非常有用。

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }

.. note::
    使用快捷键 ``Ctrl+/`` 可以快速注释或取消注释你的代码。

注释 ``/**/``
------------------

与 ``//`` 一样用于注释。这种类型的注释可以跨越多行，一旦编译器读取到 ``/*``，它会忽略之后的所有内容，直到遇到 ``*/``。

示例 1：

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Blink */

    void setup() {
        pinMode(13,OUTPUT);
    }

    void loop() {
        /*
        下面的代码将让板载LED闪烁
        你可以修改delay()中的数字来改变闪烁频率
        */
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }


``#define``
--------------

这是一个有用的 C++ 工具。

.. code-block:: C

    #define identifier token-string

当编译器读取到 ``identifier`` 时，会自动将其替换为 ``token-string``，这通常用于常量定义。

举个例子，下面是一个使用 define 的项目，它提高了代码的可读性。

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT);
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH);
        delay(DELAY_TIME);
        digitalWrite(ONBOARD_LED,LOW);
        delay(DELAY_TIME);
    }

对于编译器来说，它实际看起来是这样的。

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

我们可以看到，``identifier`` 被替换了，在程序内部并不存在。
因此，在使用它时需要注意几点。

1. ``token-string`` 只能手动修改，不能通过程序中的运算转换为其他值。

2. 避免使用 ``;`` 等符号。例如：

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT);
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH);
    }

编译器会将其识别为以下内容，这将会报错。

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT);
    }

    void loop() {
        digitalWrite(13;,HIGH);
    }

.. note::
    ``#define`` 的一个命名约定是将 ``identifier`` 大写，以避免与变量混淆。
