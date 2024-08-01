.. note::

    Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de Expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y Compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances Exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

Simple Webserver
===========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/new_feature_projects/wifi.mp4"  type="video/mp4">
      Tu navegador no soporta el elemento de video.
   </video>

Este programa simple de Arduino está diseñado para crear un servidor web básico WiFi, permitiendo a los usuarios controlar el estado de encendido y apagado de un LED en la placa Arduino a través de un navegador web.

**Ejecutar el Código**

.. note::

    * Puedes abrir el archivo ``01_simple_webserver.ino`` en la ruta ``elite-explorer-kit-main\iot_project\01_simple_webserver`` directamente.
    * O copiar este código en el IDE de Arduino.

.. note::
    En el código, el SSID y la contraseña están almacenados en ``arduino_secrets.h``. Antes de subir este ejemplo, necesitas modificarlos con tus propias credenciales WiFi. Además, por razones de seguridad, asegúrate de mantener esta información confidencial al compartir o almacenar el código.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/7ed8f58d-2ed8-4dc9-82cb-7e49b6977ea1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de subir el código, podrás ver la dirección IP en el monitor serial. Puedes ingresar esta dirección IP en tu navegador web para encender/apagar el LED de la placa.

.. image:: img/01_webserver.png

**¿Cómo funciona?**

Aquí tienes una explicación del código:

1. Archivos de Cabecera y Variables Globales:

   * ``#include "WiFiS3.h"``: Incluye la librería WiFi para conectar y gestionar WiFi. Esta librería está incluida con Arduino UNO R4 Core, por lo que no es necesaria una instalación adicional.
   * ``#include "arduino_secrets.h"``: Incluye datos sensibles de conexión WiFi como SSID y contraseña.
   * ``ssid``, ``pass``, ``keyIndex``: Son las credenciales de red utilizadas para la conexión WiFi.
   * ``led``, ``status``, ``server``: Definen el pin del LED, el estado de WiFi y el objeto del servidor web.

2. ``setup()``:

   * Inicia la comunicación serial.
   * Verifica la presencia del módulo WiFi.
   * Comprueba si la versión del firmware del módulo WiFi está actualizada.
   * Intenta conectarse a la red WiFi.
   * Inicia el servidor web.
   * Imprime el estado del WiFi.

3. ``loop()``:

   * Verifica nuevas conexiones de clientes web.
   * Si hay conexiones de clientes, lee sus solicitudes HTTP entrantes.
   * Basado en las solicitudes, puedes controlar el estado de encendido/apagado del LED. Por ejemplo, si la solicitud es "GET /H", encenderá el LED; si es "GET /L", apagará el LED.
   * Envía una respuesta HTTP para instruir al usuario sobre cómo controlar el LED.
   * Desconecta al cliente.

4. ``printWifiStatus()``:

   * Imprime el SSID del WiFi conectado.
   * Imprime la dirección IP de la placa Arduino.
   * Imprime la intensidad de la señal recibida.
   * Explica cómo ver esta página en un navegador web.

