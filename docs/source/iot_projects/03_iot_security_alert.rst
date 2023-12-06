.. _iot_security_system_ifttt:

Security System via IFTTT
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/03_iot_security_alert.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

With this project, we create a security device that employs a PIR Sensor to detect intruders or stray animals entering your home. In case of a breach, you will receive an email alert.

We'll utilize Webhooks as the fundamental service. A POST request is sent to IFTTT's service from UNO R4. 

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Wiring**

.. image:: img/03-ifttt_pir_bb.png
    :width: 90%
    :align: center


**Schematic**

.. image:: img/03-ifttt_pir_schematic.png
   :width: 50%
   :align: center

**Setting up IFTTT**

IFTTT is a free service that offers various methods to link different data services together.

Let's create an Applet that responds to a webhook (custom URL) sending data to IFTTT, which will then send you an email.

Please follow the steps below on IFTTT.

1. Visit |link_ifttt| to log in or create an account.

   .. image:: img/03_ifttt_1.png
       :width: 90%

2. Click on **Create**.

   .. image:: img/03_ifttt_2.png
       :width: 90%

3. Add an **If This** event.

   .. image:: img/03_ifttt_3.png
       :width: 70%

4. Search for **Webhooks**.

   .. image:: img/03_ifttt_4.png
       :width: 70%

5. Select **Receive a web request**.

   .. image:: img/03_ifttt_5.png
       :width: 90%

6. Fill in the event name (e.g., SecurityWarning), and click **Create trigger**.

   .. image:: img/03_ifttt_6.png
       :width: 70%

7. Add a **Then That** event.

   .. image:: img/03_ifttt_7.png
       :width: 70%

8. Search for Email.

   .. image:: img/03_ifttt_8.png
       :width: 80%

9. Choose **Send me an email**.

   .. image:: img/03_ifttt_9.png
       :width: 80%

10. Enter the **Subject** and **Body**, then click **Create action**.

   .. image:: img/03_ifttt_10.png
       :width: 70%

11. Click **Continue** to finish the setup.

   .. image:: img/03_ifttt_11.png
       :width: 70%

12. Adjust the title name as needed.

   .. image:: img/03_ifttt_12.png
       :width: 80%

13. You'll be automatically redirected to the Applet details page, where you can see that the Applet is currently connected and you can toggle the switch to enable/disable it.

   .. image:: img/03_ifttt_13.png
       :width: 70%

14. Now that we've created the IFTTT Applet, we also need the webhooks key, which can be obtained from |link_webhooks| to allow your device to access IFTTT.

   .. image:: img/03_ifttt_14.png

15. Copy the webhooks key to "arduino_secrets.h" and fill in your SSID and password.

    .. code-block:: arduino
    
        #define SECRET_SSID "your_ssid"        // your network SSID (name)
        #define SECRET_PASS "your_password"        // your network password (used for WPA, or as a key for WEP)
        #define WEBHOOKS_KEY "your_key"

**Run the Code**

.. note::

    * You can open the file ``03_ifttt_pir.ino`` under the path of ``elite-explorer-kit-main\iot_project\03_ifttt_pir`` directly.
    * Or copy this code into Arduino IDE.

.. note::
    In the code, SSID and password are stored in ``arduino_secrets.h``. Before uploading this example, you need to modify them with your own WiFi credentials. Additionally, for security purposes, ensure that this information is kept confidential when sharing or storing the code.

.. warning::
   To prevent your mailbox from being flooded, please debug the :ref:`cpn_pir` beforehand before running the code for this project.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/adec1608-4642-4469-bdf4-8dc3e3e4ce4d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
 
**How it works?**

1. Include the necessary libraries and header files:

   * ``"WiFiS3.h"``: Used for managing Wi-Fi connections.
   * ``"arduino_secrets.h"``: Contains Wi-Fi network name and password to safeguard sensitive information.

2. Define some global variables and constants:

   * ``ssid``: Name of the Wi-Fi network.
   * ``pass``: Wi-Fi network password.
   * ``status``: Status of the Wi-Fi connection.
   * ``client``: Client used for communicating with the Wi-Fi server.
   * ``server``: Address of the IFTTT Webhook server.
   * ``event``: Name of the IFTTT Webhook event.
   * ``webRequestURL``: Constructed URL for sending HTTP requests, including the Webhook event name and key.
   * ``pirPin``: Digital pin to which the PIR sensor is connected.
   * ``motionDetected``: Flag variable to track motion detection.

3. ``setup()`` function:

   * Initializes serial communication.
   * Checks for the presence of the Wi-Fi module and outputs its firmware version.
   * Attempts to connect to the Wi-Fi network, with retries if unsuccessful.
   * Sets the pin connected to the PIR sensor to input mode.

4. ``readResponse()`` function:

   * Reads HTTP response data from the IFTTT server and prints it to the serial console.

5. ``loop()`` function:

   * Calls the ``readResponse()`` function to read HTTP response data.
   * Checks for motion using the PIR sensor. If motion is detected and was not detected previously:
       * Prints "Motion detected!" to the console.
       * Calls the ``triggerIFTTTEvent()`` function to send an HTTP request to the IFTTT server, triggering the Webhook event.
       * Sets the ``motionDetected`` flag to ``true`` to indicate motion has been detected.
   * If no motion is detected, sets the ``motionDetected`` flag to ``false``.

6. ``triggerIFTTTEvent()`` function:

   * Establishes a connection with the IFTTT server.
   * Sends an HTTP GET request, including the URL of the Webhook event and other HTTP headers.

7. ``printWifiStatus()`` function:

   * Outputs information about the connected Wi-Fi network, including SSID, IP address, and signal strength (RSSI) to the serial console.
