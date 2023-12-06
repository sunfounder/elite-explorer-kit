.. _iot_ble_home:

Bluetooth Environmental Monitor
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/08_iot_ble_home.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>


This project uses an Android app created with MIT App Inventor to receive and display environmental data from an Arduino board. The Arduino board fetches data from a DHT11 sensor to measure temperature and humidity. Once the data is collected, it's transmitted over Bluetooth. The app will display the data on the screen once it receives it.

The Android application will be constructed utilizing a complimentary web-based platform known as |link_appinventor|. The project presents an excellent opportunity to gain familiarity with the interfacing of an Arduino with a smartphone. 

**Required Components**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|

**1. Build the Cirduit**

.. image:: img/08-bluetooth_environmental_monitor_bb.png
    :width: 80%
    :align: center

.. image:: img/08_ble_home_schematic.png
    :width: 30%
    :align: center

.. raw:: html

   <br/>

**2. Create the Android App**

The Android application will be developed using a free web application known as |link_appinventor|. 
MIT App Inventor serves as an excellent starting point for Android development, owing to its intuitive drag-and-drop 
features allowing for the creation of simplistic applications.

Now, let's begin.

#. Go to |link_appinventor_login|, and click "online tool" to login. You will require a Google account to register with MIT App Inventor.

   .. image:: img/08_ai_signup.png
       :width: 90%
       :align: center

#. After logging in, navigate to **Projects** -> **Import project (.aia) from my computer**. Subsequently, upload the ``ble_environmental_monitor.aia`` file located in the path ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor``.

   You can also directly download here: :download:`ble_environmental_monitor.aia</_static/other/ble_environmental_monitor.aia>`

   .. image:: img/08_ai_import.png
        :align: center

#. Upon uploading the ``.aia`` file, you will see the application on the MIT App Inventor software. This is a pre-configured template. You can modify this template after you have familiarized yourself with MIT App Inventor through the following steps.

#. In MIT App Inventor, you have 2 primary sections: the **Designer** and the **Blocks**. You can switch between these two sections in the upper right corner of the page.

   .. image:: img/08_ai_intro_1.png

#. The **Designer** allows you to add buttons, text, screens, and modify the overall aesthetic of your application.

   .. image:: img/08_ai_intro_2.png
      :width: 100%
   
#. Next, there's the **Blocks** section. This section lets you craft custom functionalities for your app, allowing you to program each component on the app's GUI to achieve desired features.

   .. image:: img/08_ai_intro_3.png
      :width: 100%

#. To install the application on a smartphone, navigate to the **Build** tab.

   .. image:: img/08_ai_intro_4.png

   * You can generate a ``.apk`` file. After selecting this option, a page will appear allowing you to choose between downloading a ``.apk`` file or scanning a QR code for installation. Follow the installation guide to complete the application installation. 

     You also download our pre-compiled APK here: :download:`ble_environmental_monitor.apk</_static/other/ble_environmental_monitor.apk>`

   * If you wish to upload this app to Google Play or another app marketplace, you can generate a ``.aab`` file.


**3. Upload the Code**

#. Open the ``08-bluetooth_environmental_monitor.ino`` file under the path of ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor``, or copy this code into **Arduino IDE**.
   
   .. note:: 
      To install the library, use the Arduino Library Manager to search for and install **"DHT sensor library"** and **"ArduinoBLE"**.

   .. raw:: html
       
      <iframe src=https://create.arduino.cc/editor/sunfounder01/53fd4af4-dcc6-439d-b52f-2f94f17c1263/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After selecting the correct board and port, click the **Upload** button.

#. Open the Serial monitor(set baudrate to **9600**) to view debug messages. 

**4. App and Bluetooth moudule Connection**

Ensure that the application created earlier is installed on your smartphone.

#. Initially, turn on **Bluetooth** on your smartphone.

   .. image:: img/08_app_1.png
      :width: 60%
      :align: center

#. Now open the newly installed **Environmental Monitor** APP.

   .. image:: img/08_app_2.png
      :width: 25%
      :align: center

#. When you first open this app, two authorization prompts will pop up in succession. These are the permissions required for using Bluetooth.

   .. image:: img/08_app_3.png
      :width: 100%
      :align: center

   .. raw:: html

      <br/>

#. In the APP, click on **Connect** button to establish a connection between the APP and Bluetooth module.

   .. image:: img/08_app_4.png
      :width: 55%
      :align: center

#. This page displays a list of all paired Bluetooth devices. Choose the ``xx.xx.xx.xx.xx.xx UNO R4 Home`` option from the list. The name of each device is listed next to its MAC address.

   .. image:: img/08_app_5.png
      :width: 60%
      :align: center
   
   .. raw:: html

      <br/>

#. If you don't see any devices on the page shown above, you can try turning on the location switch of the device (some Android system versions bundle the location switch with the Bluetooth function).

   .. image:: img/08_app_6.png
      :width: 60%
      :align: center

   .. raw:: html

      <br/>

#. After a successful connection, you will be redirected to the main page where it will display temperature and humidity.

   .. image:: img/08_app_7.png
      :width: 60%
      :align: center

**5. Code explanation**

1. Importing Libraries and Defining Constants

   - Import the required libraries and define constants for the DHT sensor pin and type.

   .. note:: 
      To install the library, use the Arduino Library Manager to search for and install **"DHT sensor library"** and **"ArduinoBLE"**.

   .. code-block:: arduino
   
       #include <DHT.h>
       #include <ArduinoBLE.h>
       #define DHTPIN 11
       #define DHTTYPE DHT11

2. Initializing BLE Services and Characteristics

   - Define the UUIDs for BLE Environmental Sensing Service and Characteristics. We are using the pre-defined UUIDs provided by |link_bluetooth_sig|. The |link_sig_environmental_sensing| is assigned ``0x181A``, while ``0x2A6E`` and ``0x2A6F`` are reserved for |link_sig_temperature_humidity|, respectively.

   .. code-block:: arduino
   
       BLEService environmentalSensingService("181A");
       BLEShortCharacteristic temperatureCharacteristic("2A6E", BLERead | BLENotify);
       BLEUnsignedShortCharacteristic humidityCharacteristic("2A6F", BLERead | BLENotify);

3. Setup Function

   - Initialize the Serial communication, DHT sensor, and BLE.

   .. code-block:: arduino
   
       void setup() {
         Serial.begin(9600);
         dht.begin();
         if (!BLE.begin()) {
           Serial.println("starting Bluetooth® Low Energy module failed!");
           while (1)
             ;
         }
         setupBle();
       }

4. Main Loop

   - Poll for BLE events and update sensor data at regular intervals.

   - The ``millis() - lastUpdateTime > updateInterval`` line ensures that the sensor data is updated every updateInterval milliseconds.

   .. code-block:: arduino
   
       void loop() {
         BLE.poll();
         if (millis() - lastUpdateTime > updateInterval) {
           // Read sensor data and update BLE characteristics
         }
       }

5. BLE and Debug Functions

   Functions for setting up BLE, printing debug information, and managing BLE events.

   .. code-block:: arduino
   
       void printDHT(float h, float t) { /* ... */ }
       void setupBle() { /* ... */ }
       void blePeripheralConnectHandler(BLEDevice central) { /* ... */ }
       void blePeripheralDisconnectHandler(BLEDevice central) { /* ... */ }

   - ``printDHT(float h, float t)``: Used to print the temperature and humidity data read by DHT11 on the serial monitor. This function is for debugging purposes.

   - ``setupBle()``: Initializes Bluetooth, including setting the broadcast name, characteristics, and services.

   - ``blePeripheralConnectHandler(BLEDevice central)`` and ``blePeripheralDisconnectHandler(BLEDevice central)``: These functions handle events when Bluetooth connects or disconnects. When a device successfully connects with UNO R4 via Bluetooth, the onboard LED lights up. When the device disconnects, the LED turns off.