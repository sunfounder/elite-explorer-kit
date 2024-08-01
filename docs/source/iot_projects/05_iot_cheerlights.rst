.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte Experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances Exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _iot_cheerlights:

CheerLights
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/05_iot_cheerlights.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

CheerLights es una red global de luces sincronizadas que pueden ser controladas por cualquiera. Únete a la comunidad de cambio de color de LEDs de |link_cheerlights|, que permite a los LEDs de todo el mundo cambiar de color simultáneamente. Coloca tus LEDs en una esquina de tu oficina para recordarte que no estás solo.

En este caso, también utilizamos MQTT, pero en lugar de publicar nuestros propios mensajes, nos suscribimos al tema "cheerlights". Esto nos permite recibir mensajes enviados por otros al tema "cheerlights" y usar esa información para cambiar el color de nuestra tira de LEDs en consecuencia.

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
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Conexiones**

.. image:: img/05_cheerlight_bb.png
    :width: 100%
    :align: center

**Esquemático**

.. image:: img/05_cheerlight_schematic.png
    :width: 50%
    :align: center

.. raw:: html

   <br/>

**Instalar la Biblioteca**

Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca "ArduinoMqttClient" y "FastLED" e instálalas.

``ArduinoMqttClient.h``: Utilizada para la comunicación MQTT.

``FastLED.h``: Utilizada para controlar la tira de LEDs RGB.

.. important::
    Con el lanzamiento de |link_fastled_3_7_0|, la biblioteca FastLED ahora admite oficialmente el Arduino UNO R4. Por lo tanto, ya no necesitas instalar manualmente la versión de desarrollo. Simplemente actualiza o instala la biblioteca FastLED utilizando el Administrador de Bibliotecas de Arduino.

.. warning::
    **[Desactualizado]** Dado que la biblioteca |link_FastLED_lib| aún no ha lanzado una versión que admita oficialmente el Arduino R4, necesitarás descargar :download:`el último código de desarrollo de la biblioteca FastLED <https://codeload.github.com/FastLED/FastLED/zip/refs/heads/master>` y sobrescribir los archivos existentes de la biblioteca FastLED. Para obtener instrucciones detalladas sobre cómo hacer esto, consulta la sección :ref:`manual_install_lib`. (Esta note se retirará cuando la biblioteca FastLED lance oficialmente una actualización que admita el Arduino UNO R4.)

**Ejecutar el Código**


.. note::

    * Puedes abrir el archivo ``05_cheerlight.ino`` bajo la ruta ``elite-explorer-kit-main\iot_project\05_cheerlight`` directamente.
    * O copia este código en el IDE de Arduino.

.. note::
    En el código, SSID y contraseña se almacenan en ``arduino_secrets.h``. Antes de subir este ejemplo, necesitas modificarlos con tus propias credenciales de WiFi. Adicionalmente, por motivos de seguridad, asegúrate de mantener esta información confidencial al compartir o almacenar el código.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/9d7ad736-9725-499f-a6ea-91602120d53e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>




**Controla dispositivos globales @CheerLights**

#. Únete al |link_discord_server| y utiliza el bot de CheerLights para configurar el color. Simplemente escribe ``/cheerlights`` en cualquiera de los canales del **Servidor de Discord de CheerLights** para activar el bot.

   .. image:: img/05_iot_cheerlights_1.png

#. Sigue las instrucciones proporcionadas por el bot para configurar el color. Esto te permitirá controlar los dispositivos de CheerLights a nivel global.

   .. image:: img/05_iot_cheerlights_2.png

**¿Cómo funciona?**

Aquí están las principales partes del código y sus explicaciones:

1. Incluir las bibliotecas requeridas:

   * ``WiFiS3.h``: Utilizada para manejar las conexiones Wi-Fi.
   * ``ArduinoMqttClient.h``: Utilizada para manejar las conexiones MQTT.
   * ``FastLED.h``: Utilizada para controlar las tiras de LEDs NeoPixel.

2. Definir algunas constantes:

   * ``NUM_LEDS``: El número de LEDs en la tira de LEDs.
   * ``DATA_PIN``: El pin de datos conectado a Arduino para controlar la tira de LEDs.
   * ``arduino_secrets.h``: Archivo de encabezado que contiene el nombre y la contraseña de la red Wi-Fi para proteger la información sensible.
   * ``broker``: Dirección del servidor MQTT.
   * ``port``: Puerto del servidor MQTT.
   * ``topic``: El tema MQTT al que suscribirse.

3. Definir algunas variables globales:

   * ``CRGB leds[NUM_LEDS]``: Una matriz para almacenar los datos de color de los LEDs.
   * ``colorName``: Una matriz de nombres de colores compatibles con el proyecto CheerLights.
   * ``colorRGB``: Una matriz de códigos de color RGB correspondientes a los nombres de colores.

4. Función ``setup()``:

   * Inicializa la comunicación serial.
   * Verifica si el módulo Wi-Fi está presente y muestra su versión de firmware.
   * Intenta conectarse a la red Wi-Fi; si falla, espera 10 segundos y reintenta.
   * Una vez conectado, conéctate al broker MQTT (servidor) y suscríbete al tema especificado.
   * Inicializa la tira de LEDs NeoPixel.

5. Función ``loop()``:

   * Llama periódicamente a la función ``mqttClient.poll()`` para recibir mensajes MQTT y enviar señales de mantenimiento de conexión MQTT.
   * Agrega un retraso de 5 segundos para evitar una conexión continua.

6. Las funciones ``printWifiData()`` y ``printCurrentNet()`` se utilizan para mostrar información sobre la red Wi-Fi y la conexión.

7. La función ``printMacAddress()`` se utiliza para mostrar la dirección MAC en formato hexadecimal.

8. La función ``onMqttMessage()`` es una función de callback que se activa cuando se recibe un mensaje MQTT. Muestra el tema del mensaje recibido y su contenido, convirtiendo el contenido del mensaje a minúsculas. Si el tema es "cheerlights", llama a la función ``setColor()`` para establecer el color de la tira de LEDs.

9. La función ``setColor()`` toma un nombre de color como parámetro, luego busca un color coincidente en la matriz ``colorName``. Si se encuentra un color coincidente, establece el color de la tira de LEDs al valor RGB correspondiente y actualiza el color de la tira de LEDs usando la función ``FastLED.show()``.

