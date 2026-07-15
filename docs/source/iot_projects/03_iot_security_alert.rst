.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte Experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances Exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _iot_security_system_ifttt:

Sistema de Seguridad con IFTTT
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/03_iot_security_alert.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Con este proyecto, creamos un dispositivo de seguridad que emplea un Sensor PIR para detectar intrusos o animales que ingresan a tu hogar. En caso de una intrusión, recibirás una alerta por correo electrónico.

Utilizaremos Webhooks como el servicio fundamental. Se envía una solicitud POST al servicio de IFTTT desde el UNO R4. 

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Conexiones**

.. image:: img/03-ifttt_pir_bb.png
    :width: 90%
    :align: center


**Esquemático**

.. image:: img/03-ifttt_pir_schematic.png
   :width: 50%
   :align: center

**Configurando IFTTT**

IFTTT es un servicio gratuito que ofrece varios métodos para vincular diferentes servicios de datos.

Vamos a crear un Applet que responda a un webhook (URL personalizada) enviando datos a IFTTT, que luego te enviará un correo electrónico.

Por favor sigue los pasos a continuación en IFTTT.

1. Visita |link_ifttt| para iniciar sesión o crear una cuenta.

   .. image:: img/03_ifttt_1.png
       :width: 90%

2. Haz clic en **Create**.

   .. image:: img/03_ifttt_2.png
       :width: 90%

3. Agrega un evento **If This**.

   .. image:: img/03_ifttt_3.png
       :width: 70%

4. Busca **Webhooks**.

   .. image:: img/03_ifttt_4.png
       :width: 70%

5. Selecciona **Receive a web request**.

   .. image:: img/03_ifttt_5.png
       :width: 90%

6. Rellena el nombre del evento (por ejemplo, SecurityWarning), y haz clic en **Create trigger**.

   .. image:: img/03_ifttt_6.png
       :width: 70%

7. Agrega un evento **Then That**.

   .. image:: img/03_ifttt_7.png
       :width: 70%

8. Busca Email.

   .. image:: img/03_ifttt_8.png
       :width: 80%

9. Elige **Send me an email**.

   .. image:: img/03_ifttt_9.png
       :width: 80%

10. Introduce el **Asunto** y el **Cuerpo**, luego haz clic en **Create action**.

   .. image:: img/03_ifttt_10.png
       :width: 70%

11. Haz clic en **Continue** para finalizar la configuración.

   .. image:: img/03_ifttt_11.png
       :width: 70%

12. Ajusta el nombre del título según sea necesario.

   .. image:: img/03_ifttt_12.png
       :width: 80%

13. Serás redirigido automáticamente a la página de detalles del Applet, donde podrás ver que el Applet está actualmente conectado y puedes activar/desactivar el interruptor.

   .. image:: img/03_ifttt_13.png
       :width: 70%

14. Ahora que hemos creado el Applet de IFTTT, también necesitamos la clave de webhooks, que se puede obtener de |link_webhooks| para permitir que tu dispositivo acceda a IFTTT.

   .. image:: img/03_ifttt_14.png

15. Copia la clave de webhooks en "arduino_secrets.h" y completa con tu SSID y contraseña.

    .. code-block:: arduino
    
        #define SECRET_SSID "your_ssid"        // tu SSID de red (nombre)
        #define SECRET_PASS "your_password"        // tu contraseña de red (usada para WPA, o como clave para WEP)
        #define WEBHOOKS_KEY "your_key"

**Ejecutar el Código**

.. note::

    * Puedes abrir el archivo ``03_ifttt_pir.ino`` bajo la ruta ``elite-explorer-kit-main\iot_project\03_ifttt_pir`` directamente.
    * O copia este código en el IDE de Arduino.

.. note::
    En el código, SSID y contraseña se almacenan en ``arduino_secrets.h``. Antes de subir este ejemplo, necesitas modificarlos con tus propias credenciales de WiFi. Adicionalmente, por motivos de seguridad, asegúrate de mantener esta información confidencial al compartir o almacenar el código.


.. warning::

   Para evitar que tu buzón de correo se inunde, por favor depura el :ref:`cpn_pir` previamente antes de ejecutar el código para este proyecto.

.. literalinclude:: /_code/03_iot_security_alert_secrets.h
   :language: cpp
   :caption: arduino_secrets.h

.. literalinclude:: /_code/03_iot_security_alert.ino
   :language: cpp
   :linenos:
   :caption: 03_ifttt_pir.ino
 
**¿Cómo funciona?**

1. Incluye las bibliotecas y archivos de encabezado necesarios:

   * ``"WiFiS3.h"``: Utilizado para gestionar conexiones Wi-Fi.
   * ``"arduino_secrets.h"``: Contiene el nombre de la red Wi-Fi y la contraseña para proteger la información sensible.

2. Define algunas variables globales y constantes:

   * ``ssid``: Nombre de la red Wi-Fi.
   * ``pass``: Contraseña de la red Wi-Fi.
   * ``status``: Estado de la conexión Wi-Fi.
   * ``client``: Cliente utilizado para comunicarse con el servidor Wi-Fi.
   * ``server``: Dirección del servidor de Webhook de IFTTT.
   * ``event``: Nombre del evento de Webhook de IFTTT.
   * ``webRequestURL``: URL construida para enviar solicitudes HTTP, incluyendo el nombre del evento de Webhook y la clave.
   * ``pirPin``: Pin digital al que está conectado el sensor PIR.
   * ``motionDetected``: Variable de bandera para rastrear la detección de movimiento.

3. Función ``setup()``:

   * Inicializa la comunicación serial.
   * Verifica la presencia del módulo Wi-Fi y muestra su versión de firmware.
   * Intenta conectarse a la red Wi-Fi, con reintentos si no tiene éxito.
   * Configura el pin conectado al sensor PIR en modo de entrada.

4. Función ``readResponse()``:

   * Lee los datos de respuesta HTTP del servidor de IFTTT y los imprime en la consola serial.

5. Función ``loop()``:

   * Llama a la función ``readResponse()`` para leer los datos de respuesta HTTP.
   * Verifica la presencia de movimiento usando el sensor PIR. Si se detecta movimiento y no se había detectado previamente:
       * Imprime "¡Movimiento detectado!" en la consola.
       * Llama a la función ``triggerIFTTTEvent()`` para enviar una solicitud HTTP al servidor de IFTTT, activando el evento de Webhook.
       * Establece la bandera ``motionDetected`` a ``true`` para indicar que se ha detectado movimiento.
   * Si no se detecta movimiento, establece la bandera ``motionDetected`` a ``false``.

6. Función ``triggerIFTTTEvent()``:

   * Establece una conexión con el servidor de IFTTT.
   * Envía una solicitud HTTP GET, incluyendo la URL del evento de Webhook y otros encabezados HTTP.

7. Función ``printWifiStatus()``:

   * Muestra información sobre la red Wi-Fi conectada, incluyendo SSID, dirección IP y potencia de la señal (RSSI) en la consola serial.

