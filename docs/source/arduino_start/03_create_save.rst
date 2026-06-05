如何创建、打开或保存项目？
=======================================


#. 当你第一次打开 Arduino IDE 或创建新项目时，你会看到一个这样的页面，Arduino IDE 会为你创建一个新文件，这被称为"项目"。

   .. image:: img/sp221014_173458.png

   这些项目文件有一个常规的临时名称，从中你可以看出文件创建的日期。``sketch_oct14a.ino`` 表示 10 月 14 日的第一个项目，``.ino`` 是该项目的文件格式。

#. 现在让我们尝试创建一个新项目。将以下代码复制到 Arduino IDE 中，替换原有代码。

   .. image:: img/create1.png

   .. code-block:: Arduino

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

#. 按下 ``Ctrl+S`` 或点击**文件** -> **保存**。项目默认保存在：``C:\Users\{你的用户名}\Documents\Arduino``，你可以重命名或选择新的路径进行保存。

   .. image:: img/create2.png

#. 保存成功后，你会看到 Arduino IDE 中的名称已经更新。

   .. image:: img/create3.png

请继续下一节，学习如何将创建的项目上传到你的 Arduino 开发板。
