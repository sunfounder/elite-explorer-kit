.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _add_libraries:

How to add libraries? (Important)
======================================

A library is a collection of pre-written code or functions that extend the capabilities of the Arduino IDE. Libraries provide ready-to-use code for various functionalities, allowing you to save time and effort in coding complex features.


Using the Library Manager
-------------------------------

Many libraries are available directly through the Arduino Library Manager. You can access the Library Manager by following these steps:

#. In the **Library Manager**, you can search for the desired library by name or browse through different categories.

   .. note::

      In projects where library installation is required, there will be prompts indicating which libraries to install. Follow the instructions provided, such as "The DHT sensor library library is used here, you can install it from the Library Manager." Simply install the recommended libraries as prompted.

   .. image:: img/install_lib3.png

#. Once you find the library you want to install, click on it and then click the **Install** button.

   .. image:: img/install_lib2.png

#. The Arduino IDE will automatically download and install the library for you.

.. _manual_install_lib:

Manual Installation
-----------------------

Some libraries are not available through the **Library Manager** and need to be manually installed. To install these libraries, follow these steps:

#. Open the Arduino IDE and go to **Sketch** -> **Include Library** -> **Add .ZIP Library**.

   .. image:: img/add_lib_zip.png

#. Navigate to the directory where the library files are located, such as the ``elite-explorer-kit-main/library/`` folder, and select the library file and click **Open**.

   .. image:: img/rfid_choose.png

#. Once the installation is complete, you will receive a notification confirming that the library has been successfully added to your Arduino IDE. The next time you need to use this library, you won't need to repeat the installation process.

   .. image:: img/rfid_success.png

#. Repeat the same process to add other libraries.


Library Location
-----------------------

The libraries installed using either of the above methods can be found in the default library directory of the Arduino IDE, which is usually located at ``C:\Users\xxx\Documents\Arduino\libraries``.

If your library directory is different, you can check it by going to **File** -> **Preferences**.

.. image:: img/install_lib1.png



**Reference**

* |link_install_arduino_lib|