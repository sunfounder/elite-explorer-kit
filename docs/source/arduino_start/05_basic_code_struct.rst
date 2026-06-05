Arduino 程序结构
===========================

让我们来看一下新建的项目文件。虽然它本身有几行代码，但实际上是一个"空"项目。
将此项目上传到开发板不会产生任何效果。

.. code-block:: C

    void setup() {
    // put your setup code here, to run once:

    }

    void loop() {
    // put your main code here, to run repeatedly:

    }

如果去掉 ``setup()`` 和 ``loop()``，让项目变成一个真正的"空白"文件，你会发现它无法通过验证。
它们相当于人体的骨架，是不可或缺的。

在项目中，先运行 ``setup()``，其中的代码（在 ``{}`` 内）在开发板上电或复位后运行，且只运行一次。
``loop()`` 用于编写主要功能，其中的代码在 ``setup()`` 执行后会循环运行。

为了更好地理解 setup() 和 loop()，让我们来看四个项目。它们的作用是让 Arduino 的板载 LED 闪烁。请依次运行每个实验并记录它们的具体效果。

* 项目 1：让板载 LED 持续闪烁。

.. code-block:: C
    :emphasize-lines: 8,9,10,11

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

* 项目 2：让板载 LED 只闪烁一次。

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // put your main code here, to run repeatedly:
    }

* 项目 3：让板载 LED 先慢闪一次，然后快闪。

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // put your main code here, to run repeatedly:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }

* 项目 4：报错。

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // put your setup code here, to run once:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // put your main code here, to run repeatedly:
    }

借助这些项目，我们可以总结出 ``setup-loop`` 的几个特点。

* ``loop()`` 在开发板上电后会重复运行。
* ``setup()`` 在开发板上电后只运行一次。
* 开发板上电后，先运行 ``setup()``，然后运行 ``loop()``。
* 代码需要写在 ``setup()`` 或 ``loop()`` 的 ``{}`` 作用域内，超出框架将会报错。

.. note::
    ``digitalWrite(13,HIGH)`` 等语句用于控制板载 LED，我们将在后续章节中详细介绍它们的用法。


