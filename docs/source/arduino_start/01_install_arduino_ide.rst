.. _install_arduino:

下载并安装 Arduino IDE 2.0
========================================

Arduino IDE，全称 Arduino Integrated Development Environment（Arduino 集成开发环境），提供了完成 Arduino 项目所需的所有软件支持。它是 Arduino 团队专为 Arduino 设计的一款编程软件，让我们能够编写程序并将其上传到 Arduino 开发板。

Arduino IDE 2.0 是一个开源项目。与其稳定的前身 Arduino IDE 1.x 相比，它是一个重大的进步，带来了全新的用户界面、改进的开发板与库管理器、调试器、自动补全功能以及更多其他特性。

在本教程中，我们将展示如何在 Windows、Mac 或 Linux 计算机上下载并安装 Arduino IDE 2.0。

系统要求
-------------------

* Windows - Win 10 及更新版本，64 位
* Linux - 64 位
* Mac OS Intel - 版本 10.14："Mojave" 或更新版本，64 位
* Mac OS Apple Silicon - 版本 11："Big Sur" 或更新版本，64 位

下载 Arduino IDE 2.0
-------------------------------

#. 访问 |link_download_arduino| 。

#. 根据你的操作系统版本下载 IDE。

   .. image:: img/sp_001.png

安装
------------------------------

Windows
^^^^^^^^^^^^^

#. 双击 ``arduino-ide_xxxx.exe`` 文件运行下载的文件。

#. 阅读许可协议并同意。

   .. image:: img/sp_002.png

#. 选择安装选项。

   .. image:: img/sp_003.png

#. 选择安装位置。建议将软件安装在系统盘以外的驱动器上。

   .. image:: img/sp_004.png

#. 然后点击完成。

   .. image:: img/sp_005.png

macOS
^^^^^^^^^^^^^^^^

双击下载的 ``arduino_ide_xxxx.dmg`` 文件，按照说明将 **Arduino IDE.app** 复制到 **应用程序** 文件夹中，几秒钟后你将看到 Arduino IDE 安装成功。

.. image:: img/macos_install_ide.png
    :width: 800

Linux
^^^^^^^^^^^^

关于在 Linux 系统上安装 Arduino IDE 2.0 的教程，请参考 |link_install_arduino_linux|


打开 IDE
--------------

#. 当你第一次打开 Arduino IDE 2.0 时，它会自动安装 Arduino AVR 开发板、内置库以及其他所需文件。

   .. image:: img/sp_901.png

#. 此外，你的防火墙或安全中心可能会多次弹出窗口，询问你是否要安装某些设备驱动程序。请全部安装。

   .. image:: img/sp_104.png

#. 现在你的 Arduino IDE 已经准备就绪！

   .. note::
     如果某些安装因网络问题或其他原因未能完成，你可以重新打开 Arduino IDE，它将继续完成剩余的安装。所有安装完成后，输出窗口不会自动打开，除非你单击"验证"或"上传"。




