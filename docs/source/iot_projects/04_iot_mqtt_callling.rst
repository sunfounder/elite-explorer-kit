.. _iot_mqtt_publish:

Cloud Calling System with MQTT
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/04_iot_mqtt_callling.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Message Queuing Telemetry Transport (MQTT) is a straightforward messaging protocol. It is also the most widely used messaging protocol in the realm of the Internet of Things (IoT).

MQTT protocols define how IoT devices exchange data. They operate in an event-driven manner and are interconnected using the Publish/Subscribe model. The sender (Publisher) and the receiver (Subscriber) communicate through Topics. A device publishes a message on a specific topic, and all devices subscribed to that topic receive the message.

In this section, we'll create a service bell system using UNO R4, HiveMQ (a free public MQTT broker service), and four buttons. Each of the four buttons corresponds to a restaurant table, and when a customer presses a button, you'll be able to see which table needs service on HiveMQ.

**Wiring**

.. image:: img/04_mqtt_button_bb.png
   :width: 70%
   :align: center

* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_button`

**Schematic**

.. image:: img/04_mqtt_button_schematic.png
   :width: 50%
   :align: center

**How to play?**

HiveMQ is an MQTT broker and client-based messaging platform that facilitates fast, efficient, and reliable data transfer to IoT devices.

1. Open |link_hivemq| in your web browser.

2. Connect the client to the default public proxy.

   .. image:: img/04_mqtt_1.png

3. Click on **Add New Topic Subscription**.

   .. image:: img/04_mqtt_2.png

4. Enter the topics you wish to follow and click **Subscribe**. Make sure the topics you set here are unique to avoid receiving messages from other users, and pay attention to case sensitivity. 

   In this example code, we set the topic as ``SunFounder MQTT Test``. If you have made any changes, ensure that the topic in the code matches the subscribed topic on the webpage.

   .. image:: img/04_mqtt_3.png


**Install the Library**

``ArduinoMqttClient.h``: Used for MQTT communication.

**Run the Code**

.. note::

    * You can open the file ``04_mqtt_button.ino`` under the path of ``Elite-Explorer-Kit-main\iot_project\04_mqtt_button`` directly.
    * Or copy this code into Arduino IDE.

.. note::
    In the code, SSID and password are stored in ``arduino_secrets.h``. Before uploading this example, you need to modify them with your own WiFi credentials. Additionally, for security purposes, ensure that this information is kept confidential when sharing or storing the code.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/7a4acdf8-beed-47d4-ada8-cbaab0f3477f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

After running the code, go back to |link_hivemq|, and when you press one of the buttons on the breadboard, you will see the Messages prompt on HiveMQ.

    .. image:: img/04_mqtt_4.png
  
**How it works?**

This code is for an Arduino-based project that connects to Wi-Fi and communicates with an MQTT broker using the MQTT protocol. Additionally, it can detect whether four buttons are pressed and send the corresponding messages to the MQTT broker.

Here is a detailed explanation of the code:

1. **Include Relevant Libraries**:

   .. code-block:: Arduino
       
       #include <WiFiS3.h>
       #include <ArduinoMqttClient.h>

2. **Include Sensitive Information**:

   * The ``arduino_secrets.h`` file contains the SSID and password for the Wi-Fi network.
   
   .. code-block:: Arduino
       
       #include "arduino_secrets.h" 
       char ssid[] = SECRET_SSID;   
       char pass[] = SECRET_PASS;   

3. **Initialize Variables**:

   * Variables for managing Wi-Fi and MQTT connections.
   * Initialize button pins and button states.

4. ``setup()``:

   * Initialize serial communication.
   * Check for the presence of the Wi-Fi module and attempt to connect to Wi-Fi.
   * Print network data.
   * Attempt to connect to the MQTT broker.
   * Subscribe to MQTT topics.
   * Set buttons to input mode.

5. ``loop()``:

   * Keep the MQTT connection active.
   * Check if each button is pressed, and if so, send MQTT messages.

6. **Other Utility Functions**:

   * ``printWifiData()``: Prints information about the currently connected Wi-Fi network.
   * ``printCurrentNet()``: Prints relevant data about the current network.
   * ``printMacAddress(byte mac[])``: Prints the MAC address.
   * ``onMqttMessage(int messageSize)``: Callback function triggered when a message is received from the MQTT broker. It prints the received message topic and content.
   * ``sendButtonMessage(int buttonNumber)``: Use this function to send MQTT messages when a button is pressed.
