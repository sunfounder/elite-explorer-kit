
WeatherTime Screen
===============================


This sketch connects to a WiFi network, fetches weather data from OpenWeatherMap every minute, 
retrieves the current time from an NTP server, 
and displays the day, time, and weather information on an OLED screen.


**Wiring**

.. image:: img/06_weather_oled_bb.png
    :width: 100%
    :align: center


* :ref:`uno_r4_wifi`
* :ref:`cpn_wires`
* :ref:`cpn_breadboard`
* :ref:`cpn_oled`


**Schematic**

.. image:: img/06_weather_oled_schematic.png
    :width: 60%
    :align: center



**OpenWeather**

Get OpenWeather API keys

.. .|link_openweather| is an online service, owned by OpenWeather Ltd, that provides global weather data via API, including current weather data, forecasts, nowcasts and historical weather data for any geographical location.

`OpenWeather <https://openweathermap.org/>`_ is an online service, owned by OpenWeather Ltd, that provides global weather data via API, including current weather data, forecasts, nowcasts and historical weather data for any geographical location.


#. Visit OpenWeather to log in/create an account.

   .. image:: img/06_owm_1.png


#. Click into the API page from the navigation bar.

   .. image:: img/06_owm_2.png


#. Find **Current Weather Data** and click Subscribe.

   .. image:: img/06_owm_3.png


#. Under **Current weather and forecasts collection**, subscribe to the appropriate service. In our project, Free is good enough.

   .. image:: img/06_owm_4.png


#. Copy the Key from the **API keys** page.

   .. image:: img/06_owm_5.png

#. Copy it to the ``arduino_secrets.h``.

   .. code-block:: Arduino

       #define SECRET_SSID "<SSID>"        // your network SSID (name)
       #define SECRET_PASS "<PASSWORD>"        // your network password (use for WPA, or use as key for WEP)
       #define API_KEY "<OpenWeather_API_KEY>"
       #define LOCATION "<YOUR CITY>"        

**Install the Library**


``ArduinoJson.h`` ： Used for handling JSON data (data obtained from openweathermap).

``NTPClient.h``, ``WiFiUdp.h``: Used for obtaining real-time time.

``Adafruit_GFX.h``, ``Adafruit_SSD1306.h`` : Used for OLED module.

**Run the Code**


.. note::

    * You can open the file ``06_weather_oled.ino`` under the path of ``Elite-Explorer-Kit-main\iot_project\06_weather_oled`` directly.
    * Or copy this code into Arduino IDE.

.. note::
    In the code, SSID and password are stored in ``arduino_secrets.h``. Before uploading this example, you need to modify them with your own WiFi credentials. Additionally, for security purposes, ensure that this information is kept confidential when sharing or storing the code.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/5f667ac1-bb24-4681-9fa1-db19fcfdd48a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**How it works?**


1. Libraries and Definitions:

   #. ``WiFiS3.h``: This is likely a library specific to a certain WiFi module or board to manage WiFi connections.
   #. ``ArduinoJson.h``: This library is used for decoding (and encoding) JSON data.
   #. ``arduino_secrets.h``: A separate file where sensitive data (like WiFi credentials) are stored. This is a good practice to keep credentials out of the main code.
   #. **NTPClient & WiFiUdp**: These are used for fetching the current time from an NTP (Network Time Protocol) server.
   #. **Adafruit libraries**: Used for managing the OLED display.
   #. **Various global variables**: These include WiFi credentials, server details, and more, which will be used throughout the script.

2. ``setup()``:

   #. It initializes the serial communication.
   #. Checks and prints the WiFi module's firmware version.
   #. Tries to connect to the WiFi network using the provided SSID and password.
   #. Prints the connected WiFi's status (SSID, IP, Signal strength).
   #. Initializes the OLED display.
   #. Starts the NTP client to fetch the current time and sets a time offset (in this case, 8 hours which might correspond to a specific timezone).

3. ``read_response()``:

   #. Reads the response from the server, specifically looking for JSON data (denoted by ``{`` and ``}``).
   #. If JSON data is found, it decodes the data to extract weather details like temperature, humidity, pressure, wind speed, and wind direction.
   #. Calls the ``displayWeatherData`` function to display the weather information on the OLED screen.

4. ``httpRequest()``:

   #. Closes any existing connections to ensure the WiFi module's socket is free.
   #. Tries to connect to the OpenWeatherMap server.
   #. If connected, sends an HTTP GET request to fetch the weather data for a specific location defined by ``LOCATION`` (likely defined in ``arduino_secrets.h`` or elsewhere).
   #. Records the time the request was made.

5. ``loop()``:

   #. Calls the ``read_response`` function to process any incoming data from the server.
   #. Updates the time from the NTP server.
   #. Checks if it's time to make another request to the weather server (based on the ``postingInterval``). If so, it calls the ``httpRequest`` function.

6. ``printWifiStatus()``:

   #. The SSID of the connected network.
   #. The local IP address of the board.
   #. The signal strength (RSSI).

7. ``displayWeatherData()``:

   #. Clears the OLED screen.
   #. Displays the current day of the week.
   #. Displays the current time in HH:MM format.
   #. Displays the provided weather data (temperature, humidity, pressure, and wind speed).
