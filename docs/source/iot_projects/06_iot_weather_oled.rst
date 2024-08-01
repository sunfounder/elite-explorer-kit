.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte Experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances Exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _iot_weathertime_screen:

Pantalla WeatherTime
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/06_iot_weather_oled.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Este sketch se conecta a una red WiFi, obtiene datos meteorológicos de OpenWeatherMap cada minuto, recupera la hora actual de un servidor NTP y muestra el día, la hora y la información meteorológica en una pantalla OLED.

**Componentes Requeridos**

En este proyecto, necesitamos los siguientes componentes. 

Es definitivamente conveniente comprar un kit completo, aquí está el enlace: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - Ítems en este Kit
        - Enlace
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

También puedes comprarlos por separado desde los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - Introducción del Componente
        - Enlace de Compra

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

**Conexiones**

.. image:: img/06_weather_oled_bb.png
    :width: 100%
    :align: center

**Esquemático**

.. image:: img/06_weather_oled_schematic.png
    :width: 60%
    :align: center

**OpenWeather**

Obten las claves API de OpenWeather

.. .|link_openweather| es un servicio en línea, propiedad de OpenWeather Ltd, que proporciona datos meteorológicos globales a través de API, incluyendo datos meteorológicos actuales, pronósticos, ahora y datos meteorológicos históricos para cualquier ubicación geográfica.

`OpenWeather <https://openweathermap.org/>`_ es un servicio en línea, propiedad de OpenWeather Ltd, que proporciona datos meteorológicos globales a través de API, incluyendo datos meteorológicos actuales, pronósticos, ahora y datos meteorológicos históricos para cualquier ubicación geográfica.

#. Visita OpenWeather para iniciar sesión/crear una cuenta.

   .. image:: img/06_owm_1.png

#. Haz clic en la página de API desde la barra de navegación.

   .. image:: img/06_owm_2.png

#. Encuentra **Current Weather Data** y haz clic en Suscribirse.

   .. image:: img/06_owm_3.png

#. Bajo **Current weather and forecasts collection**, suscríbete al servicio apropiado. En nuestro proyecto, la opción Gratis es suficiente.

   .. image:: img/06_owm_4.png

#. Copia la clave de la página de **API keys**.

   .. image:: img/06_owm_5.png

#. Copia la clave en ``arduino_secrets.h``.

   .. code-block:: Arduino

       #define SECRET_SSID "<SSID>"        // tu SSID de red (nombre)
       #define SECRET_PASS "<PASSWORD>"        // tu contraseña de red 
       #define API_KEY "<OpenWeather_API_KEY>"
       #define LOCATION "<YOUR CITY>"

#. Establece la zona horaria de tu ubicación.

   Tomando como ejemplo la capital de Suecia, Estocolmo, busca "stockholm timezone" en Google.

   .. image:: img/06_weather_oled_01.png 

   En los resultados de búsqueda, verás "GMT+1", por lo que debes establecer el parámetro de la función a continuación en ``3600 * 1`` segundos.
   
   .. code-block:: Arduino

      timeClient.setTimeOffset(3600 * 1);  // Ajusta según tu zona horaria (esto es +1 hora)

**Instalar la Biblioteca**

Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca "ArduinoMqttClient", "FastLED", "Adafruit GFX" y "Adafruit SSD1306" e instálalas.

``ArduinoJson.h``: Usada para manejar datos JSON (datos obtenidos de openweathermap).

``NTPClient.h``: Usada para obtener la hora en tiempo real.

``Adafruit_GFX.h``, ``Adafruit_SSD1306.h``: Usadas para el módulo OLED.

**Ejecutar el Código**


.. note::

    * Puedes abrir el archivo ``06_weather_oled.ino`` bajo la ruta ``elite-explorer-kit-main\iot_project\06_weather_oled`` directamente.
    * O copia este código en el IDE de Arduino.

.. note::
    En el código, SSID y contraseña se almacenan en ``arduino_secrets.h``. Antes de subir este ejemplo, necesitas modificarlos con tus propias credenciales de WiFi. Adicionalmente, por motivos de seguridad, asegúrate de mantener esta información confidencial al compartir o almacenar el código.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/5f667ac1-bb24-4681-9fa1-db19fcfdd48a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**¿Cómo funciona?**


1. Bibliotecas y Definiciones:

   #. ``WiFiS3.h``: Probablemente una biblioteca específica para un módulo WiFi o placa para gestionar las conexiones WiFi.
   #. ``ArduinoJson.h``: Esta biblioteca se utiliza para decodificar (y codificar) datos JSON.
   #. ``arduino_secrets.h``: Un archivo separado donde se almacenan datos sensibles (como credenciales de WiFi). Es una buena práctica mantener las credenciales fuera del código principal.
   #. **NTPClient & WiFiUdp**: Se utilizan para obtener la hora actual de un servidor NTP (Network Time Protocol).
   #. **Bibliotecas de Adafruit**: Usadas para gestionar la pantalla OLED.
   #. **Varias variables globales**: Incluyen credenciales de WiFi, detalles del servidor y más, que se utilizarán en todo el script.

2. ``setup()``:

   #. Inicializa la comunicación serial.
   #. Verifica y muestra la versión del firmware del módulo WiFi.
   #. Intenta conectarse a la red WiFi utilizando el SSID y la contraseña proporcionados.
   #. Muestra el estado del WiFi conectado (SSID, IP, intensidad de señal).
   #. Inicializa la pantalla OLED.
   #. Inicia el cliente NTP para obtener la hora actual y establece un desfase horario (en este caso, 1 hora, que podría corresponder a una zona horaria específica).

3. ``read_response()``:

   #. Lee la respuesta del servidor, buscando específicamente datos JSON (denotedos por ``{`` y ``}``).
   #. Si se encuentran datos JSON, se decodifican para extraer detalles meteorológicos como temperatura, humedad, presión, velocidad del viento y dirección del viento.
   #. Llama a la función ``displayWeatherData`` para mostrar la información meteorológica en la pantalla OLED.

4. ``httpRequest()``:

   #. Cierra cualquier conexión existente para asegurar que el socket del módulo WiFi esté libre.
   #. Intenta conectarse al servidor de OpenWeatherMap.
   #. Si se conecta, envía una solicitud HTTP GET para obtener los datos meteorológicos de una ubicación específica definida por ``LOCATION`` (probablemente definida en ``arduino_secrets.h`` o en otro lugar).
   #. Registra la hora en que se hizo la solicitud.

5. ``loop()``:

   #. Llama a la función ``read_response`` para procesar cualquier dato entrante del servidor.
   #. Actualiza la hora desde el servidor NTP.
   #. Verifica si es momento de hacer otra solicitud al servidor meteorológico (basado en ``postingInterval``). Si es así, llama a la función ``httpRequest``.

6. ``printWifiStatus()``:

   #. El SSID de la red conectada.
   #. La dirección IP local de la placa.
   #. La intensidad de la señal (RSSI).

7. ``displayWeatherData()``:

   #. Borra la pantalla OLED.
   #. Muestra el día de la semana actual.
   #. Muestra la hora actual en formato HH:MM.
   #. Muestra los datos meteorológicos proporcionados (temperatura, humedad, presión y velocidad del viento).

