.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte Experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances Exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _iot_mqtt_publish:

Sistema de Llamadas en la Nube con MQTT
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/04_iot_mqtt_callling.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Message Queuing Telemetry Transport (MQTT) es un protocolo de mensajería sencillo. También es el protocolo de mensajería más utilizado en el ámbito del Internet de las Cosas (IoT).

Los protocolos MQTT definen cómo los dispositivos IoT intercambian datos. Operan de manera impulsada por eventos y están interconectados utilizando el modelo Publicar/Suscribirse. El remitente (Publicador) y el receptor (Suscriptor) se comunican a través de Temas. Un dispositivo publica un mensaje en un tema específico, y todos los dispositivos suscritos a ese tema reciben el mensaje.

En esta sección, crearemos un sistema de timbre de servicio utilizando el UNO R4, HiveMQ (un servicio gratuito de broker público de MQTT) y cuatro botones. Cada uno de los cuatro botones corresponde a una mesa de restaurante, y cuando un cliente presiona un botón, podrás ver qué mesa necesita servicio en HiveMQ.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|


**Conexiones**

.. image:: img/04_mqtt_button_bb.png
   :width: 70%
   :align: center

**Esquemático**

.. image:: img/04_mqtt_button_schematic.png
   :width: 50%
   :align: center

**¿Cómo jugar?**

HiveMQ es una plataforma de mensajería basada en MQTT que facilita la transferencia rápida, eficiente y confiable de datos a dispositivos IoT.

1. Abre |link_hivemq| en tu navegador web.

2. Conecta el cliente al proxy público predeterminado.

   .. image:: img/04_mqtt_1.png

3. Haz clic en **Add New Topic Subscription**.

   .. image:: img/04_mqtt_2.png

4. Introduce los temas que deseas seguir y haz clic en **Subscribe**. Asegúrate de que los temas que configures aquí sean únicos para evitar recibir mensajes de otros usuarios y presta atención a la sensibilidad de mayúsculas y minúsculas.

   En este código de ejemplo, configuramos el tema como ``SunFounder MQTT Test``. Si has realizado algún cambio, asegúrate de que el tema en el código coincida con el tema suscrito en la página web.

   .. image:: img/04_mqtt_3.png


**Instalar la Biblioteca**

Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca "ArduinoMqttClient" e instálala.

``ArduinoMqttClient.h``: Utilizada para la comunicación MQTT.

**Ejecutar el Código**

.. note::

    * Puedes abrir el archivo ``04_mqtt_button.ino`` bajo la ruta ``elite-explorer-kit-main\iot_project\04_mqtt_button`` directamente.
    * O copia este código en el IDE de Arduino.

.. note::
    En el código, SSID y contraseña se almacenan en ``arduino_secrets.h``. Antes de subir este ejemplo, necesitas modificarlos con tus propias credenciales de WiFi. Adicionalmente, por motivos de seguridad, asegúrate de mantener esta información confidencial al compartir o almacenar el código.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/7a4acdf8-beed-47d4-ada8-cbaab0f3477f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de ejecutar el código, vuelve a |link_hivemq|, y cuando presiones uno de los botones en la protoboard, verás el mensaje en HiveMQ.

    .. image:: img/04_mqtt_4.png
  
**¿Cómo funciona?**

Este código es para un proyecto basado en Arduino que se conecta a Wi-Fi y se comunica con un broker MQTT utilizando el protocolo MQTT. Además, puede detectar si se presionan cuatro botones y enviar los mensajes correspondientes al broker MQTT.

Aquí tienes una explicación detallada del código:

1. **Incluir Bibliotecas Relevantes**:

   .. code-block:: Arduino
       
       #include <WiFiS3.h>
       #include <ArduinoMqttClient.h>

2. **Incluir Información Sensible**:

   * El archivo ``arduino_secrets.h`` contiene el SSID y la contraseña para la red Wi-Fi.
   
   .. code-block:: Arduino
       
       #include "arduino_secrets.h" 
       char ssid[] = SECRET_SSID;   
       char pass[] = SECRET_PASS;   

3. **Inicializar Variables**:

   * Variables para gestionar conexiones Wi-Fi y MQTT.
   * Inicializar pines de botones y estados de botones.

4. ``setup()``:

   * Inicializar la comunicación serial.
   * Verificar la presencia del módulo Wi-Fi e intentar conectarse a Wi-Fi.
   * Imprimir datos de la red.
   * Intentar conectarse al broker MQTT.
   * Suscribirse a temas MQTT.
   * Configurar los botones en modo de entrada.

5. ``loop()``:

   * Mantener activa la conexión MQTT.
   * Verificar si cada botón se presiona, y si es así, enviar mensajes MQTT.

6. **Otras Funciones Utilitarias**:

   * ``printWifiData()``: Imprime información sobre la red Wi-Fi actualmente conectada.
   * ``printCurrentNet()``: Imprime datos relevantes sobre la red actual.
   * ``printMacAddress(byte mac[])``: Imprime la dirección MAC.
   * ``onMqttMessage(int messageSize)``: Función de callback que se activa cuando se recibe un mensaje del broker MQTT. Imprime el tema del mensaje recibido y su contenido.
   * ``sendButtonMessage(int buttonNumber)``: Utiliza esta función para enviar mensajes MQTT cuando se presiona un botón.

