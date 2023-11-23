.. _iot_Bluetooth_lcd:

Bluetooth Message Box
=============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/07_iot_ble_lcd.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

This project receives messages and displays them on an LCD screen.

You can use it as a family message board, reminding family members who haven't left yet to remember to take their keys.

**Wiring**

.. image:: img/07_lightblue_lcd_bb.png
    :width: 100%
    :align: center

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_i2c_lcd1602`


**Schematic**

.. image:: img/07_lightblue_lcd_schematic.png
   :width: 80%
   :align: center

.. raw:: html

   <br/>

**Generate the UUID**

UUIDs play a crucial role in BLE communication, ensuring the uniqueness of devices and accuracy of data exchange between them. You need to customize UUIDs to create your own BLE services and characteristics to meet specific application requirements. (Here, we need to create a characteristic that supports text input.)

1. Use the `Online UUID Generator Tool <https://www.uuidgenerator.net/version4>`_ to create UUIDs unique to you to avoid UUID conflicts.

2. Generate two version 4 UUIDs.

   .. image:: img/07_uuid_1.png
      :width: 70%

   .. raw:: html

      <br/><br/>

3. Copy them and replace the two UUIDs in your code.

   .. code-block:: arduino
   
       #define SERVICE_UUID "uuid1"
       #define CHARACTERISTIC_UUID "uuid2"

**Install the Library**

``ArduinoBLE.h``: Used for handling Bluetooth Low Energy (BLE) communication.
``LiquidCrystal_I2C.h``: Used to control a 16x2 character LCD screen with an I2C interface.

**Run the Code**

.. note::

    * You can open the file ``07_lightblue_lcd.ino`` under the path of ``elite-explorer-kit-main\iot_project\07_lightblue_lcd`` directly.
    * Or copy this code into Arduino IDE.

.. note:: 
      To install the library, use the Arduino Library Manager to search for and install **"ArduinoBLE"** and **"LiquidCrystal I2C"**.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/958c37c2-a897-4c4c-b6c1-0e7fea67c7b1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**How to play?**

To interact with the services and characteristics created in this sketch, you should use a generic Bluetooth® Low Energy central app like LightBlue (available for iOS and Android) or nRF Connect (for Android).

Let's use LightBlue as an example to demonstrate how to control Arduino's LED via Bluetooth.

1. Download the LightBlue app from the App Store (for iOS) or Google Play (for Android).

   .. image:: img/07_lightblue.png

2. Connecting Arduino with Your Smartphone via Bluetooth

   Go to your Bluetooth settings and locate the device named "UNO R4 BLE." Connect to it.

   .. image:: img/07_iot_ble_01.jpg
      :width: 50%

   .. raw:: html

      <br/><br/>

3. Interacting with Arduino via Bluetooth Using LightBlue

   Launch LightBlue and tap on the **Bonded** tab at the bottom of the interface. Here, you'll see a list of BLE devices that your smartphone has previously paired with. Locate **UNO R4 BLE** and tap **CONNECT**.

   .. image:: img/07_iot_ble_02.jpg

   Once connected, you'll gain access to detailed information about the Bluetooth device. Scroll down to find your service UUID and your Characteristic UUID.

   Tap on the Characteristic. You'll notice that this Characteristic is both readable and writable, allowing you to both read from and write to it.

   Continue scrolling to the "Data format" section and change it to UTF-8 String.
   Enter text in the text box and click write. The message you entered will appear on the LCD.

   .. image:: img/07_iot_ble_03.jpg

**How it works?**

Here are the main parts of the code and explanations of their functions:

1. Include the required libraries:

   * ``ArduinoBLE.h``: Used for handling BLE communication.
   * ``Wire.h``: Used for I2C communication.
   * ``LiquidCrystal_I2C.h``: Used to control a 16x2 character LCD screen with I2C interface.

2. Define a BLE service and a BLE characteristic:

   * Use the ``BLEService`` class to define a BLE service and assign it a unique UUID.
   * Use the ``BLECharacteristic`` class to define a BLE characteristic, assign it a unique UUID, and give it read (``BLERead``) and write (``BLEWrite``) permissions.
   * Create a character array ``stringValue`` as the initial value of the characteristic.

3. Initialize a 16x2 character LCD screen (LCD):

   * Use the ``LiquidCrystal_I2C`` class to initialize an LCD, specifying the I2C address (0x27) and the number of rows and columns (16x2).
   * Turn on the backlight of the LCD, clear the screen, move the cursor to the start of the first row, and display "Bluetooth LCD."

4. Perform initialization in the ``setup()`` function:

   * Initialize serial communication.
   * Initialize the BLE module, and if initialization fails, enter an infinite loop.
   * Set the local name and service UUID for the BLE peripheral.
   * Add the BLE characteristic to the BLE service.
   * Start advertising the BLE service so that central devices can discover and connect to it.
   * Initialize the LCD.

5. The ``loop()`` function:

   * Check if there is a central device connected to the BLE peripheral by calling ``BLE.central()``. If a central device is connected, enter the connection handling logic.
   * In the connected state, check if data has been written to the BLE characteristic by checking ``boxCharacteristic.written()``.
   * If data has been written, get the length of the written data using ``boxCharacteristic.valueLength()`` and create a byte array ``buffer`` to store the written data.
   * Use ``boxCharacteristic.readValue()`` to read data from the BLE characteristic into the ``buffer``.
   * Add a null character ``'\0'`` to the end of the ``buffer`` to convert it to a string.
   * Print the received message to the serial monitor and display it on the LCD.
   * Continue waiting for the next central device to connect after the central device disconnects.
