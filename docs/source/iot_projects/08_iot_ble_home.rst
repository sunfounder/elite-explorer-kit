.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte Experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances Exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _iot_ble_home:

Monitor Ambiental con Bluetooth
=====================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/08_iot_ble_home.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Este proyecto utiliza una aplicación de Android creada con MIT App Inventor para recibir y mostrar datos ambientales desde una placa Arduino. La placa Arduino obtiene datos de un sensor DHT11 para medir la temperatura y la humedad. Una vez recopilados los datos, se transmiten por Bluetooth. La aplicación mostrará los datos en la pantalla una vez que los reciba.

La aplicación de Android se construirá utilizando una plataforma web gratuita conocida como |link_appinventor|. El proyecto presenta una excelente oportunidad para familiarizarse con la interfaz entre un Arduino y un smartphone.

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
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|

**1. Construye el Circuito**

.. image:: img/08-bluetooth_environmental_monitor_bb.png
    :width: 80%
    :align: center

.. image:: img/08_ble_home_schematic.png
    :width: 30%
    :align: center

.. raw:: html

   <br/>

**2. Crea la Aplicación de Android**

La aplicación de Android se desarrollará utilizando una aplicación web gratuita conocida 
como |link_appinventor|. MIT App Inventor es un excelente punto de partida para el 
desarrollo de Android, gracias a sus características intuitivas de arrastrar y soltar que 
permiten la creación de aplicaciones simples.

Ahora, vamos a empezar.

#. Ve a |link_appinventor_login| y haz clic en "herramienta en línea" para iniciar sesión. Necesitarás una cuenta de Google para registrarte en MIT App Inventor.

   .. image:: img/08_ai_signup.png
       :width: 90%
       :align: center

#. Después de iniciar sesión, navega a **Projects** -> **Import project (.aia) from my computer**. Posteriormente, sube el archivo ``ble_environmental_monitor.aia`` ubicado en la ruta ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor``.

   También puedes descargarlo directamente aquí: :download:`ble_environmental_monitor.aia</_static/other/ble_environmental_monitor.aia>`

   .. image:: img/08_ai_import.png
        :align: center

#. Al subir el archivo ``.aia``, verás la aplicación en el software MIT App Inventor. Esta es una plantilla preconfigurada. Puedes modificar esta plantilla después de haberte familiarizado con MIT App Inventor a través de los siguientes pasos.

#. En MIT App Inventor, tienes 2 secciones principales: el **Designer** y los **Blocks**. Puedes alternar entre estas dos secciones en la esquina superior derecha de la página.

   .. image:: img/08_ai_intro_1.png

#. El **Designer** te permite agregar botones, texto, pantallas y modificar la estética general de tu aplicación.

   .. image:: img/08_ai_intro_2.png
      :width: 100%
   
#. A continuación, está la sección de **Blocks**. Esta sección te permite crear funcionalidades personalizadas para tu aplicación, permitiéndote programar cada componente en la GUI de la aplicación para lograr las características deseadas.

   .. image:: img/08_ai_intro_3.png
      :width: 100%

#. Para instalar la aplicación en un smartphone, navega a la pestaña **Build**.

   .. image:: img/08_ai_intro_4.png

   * Puedes generar un archivo ``.apk``. Después de seleccionar esta opción, aparecerá una página que te permitirá elegir entre descargar un archivo ``.apk`` o escanear un código QR para la instalación. Sigue la guía de instalación para completar la instalación de la aplicación. 

     También puedes descargar nuestro APK precompilado aquí: :download:`ble_environmental_monitor.apk</_static/other/ble_environmental_monitor.apk>`

   * Si deseas subir esta aplicación a Google Play u otro mercado de aplicaciones, puedes generar un archivo ``.aab``.

**3. Sube el Código**

#. Abre el archivo ``08-bluetooth_environmental_monitor.ino`` bajo la ruta ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor``, o copia este código en **Arduino IDE**.
   
   .. note:: 
      Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino para buscar e instalar **"DHT sensor library"** y **"ArduinoBLE"**.

   .. raw:: html
       
      <iframe src=https://create.arduino.cc/editor/sunfounder01/53fd4af4-dcc6-439d-b52f-2f94f17c1263/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Después de seleccionar la placa y el puerto correctos, haz clic en el botón **Upload**.

#. Abre el monitor serial (configurado a una tasa de baudios de **9600**) para ver los mensajes de depuración. 

**4. Conexión de la Aplicación y el Módulo Bluetooth**

Asegúrate de que la aplicación creada anteriormente esté instalada en tu smartphone.

#. Inicialmente, enciende el **Bluetooth** en tu smartphone.

   .. image:: img/08_app_1.png
      :width: 60%
      :align: center

#. Ahora abre la **Environmental Monitor** APP recién instalada.

   .. image:: img/08_app_2.png
      :width: 25%
      :align: center

#. Cuando abras esta aplicación por primera vez, aparecerán dos solicitudes de autorización sucesivas. Estos son los permisos necesarios para usar Bluetooth.

   .. image:: img/08_app_3.png
      :width: 100%
      :align: center

   .. raw:: html

      <br/>

#. En la APP, haz clic en el botón **Connect** para establecer una conexión entre la APP y el módulo Bluetooth.

   .. image:: img/08_app_4.png
      :width: 55%
      :align: center

#. Esta página muestra una lista de todos los dispositivos Bluetooth emparejados. Elige la opción ``xx.xx.xx.xx.xx.xx UNO R4 Home`` de la lista. El nombre de cada dispositivo se lista junto a su dirección MAC.

   .. image:: img/08_app_5.png
      :width: 60%
      :align: center
   
   .. raw:: html

      <br/>

#. Si no ves ningún dispositivo en la página mostrada arriba, puedes intentar activar el interruptor de ubicación del dispositivo (algunas versiones del sistema Android combinan el interruptor de ubicación con la función Bluetooth).

   .. image:: img/08_app_6.png
      :width: 60%
      :align: center

   .. raw:: html

      <br/>

#. Después de una conexión exitosa, serás redirigido a la página principal donde se mostrarán la temperatura y la humedad.

   .. image:: img/08_app_7.png
      :width: 60%
      :align: center

**5. Explicación del Código**

1. Importar Bibliotecas y Definir Constantes

   - Importa las bibliotecas requeridas y define las constantes para el pin y tipo del sensor DHT.

   .. note:: 
      Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino para buscar e instalar **"DHT sensor library"** y **"ArduinoBLE"**.

   .. code-block:: arduino
   
       #include <DHT.h>
       #include <ArduinoBLE.h>
       #define DHTPIN 11
       #define DHTTYPE DHT11

2. Inicializar Servicios y Características BLE

   - Define los UUIDs para el Servicio de Sensado Ambiental BLE y las Características. Estamos utilizando los UUIDs predefinidos proporcionados por |link_bluetooth_sig|. El |link_sig_environmental_sensing| tiene asignado el ``0x181A``, mientras que ``0x2A6E`` y ``0x2A6F`` están reservados para |link_sig_temperature_humidity|, respectivamente.

   .. code-block:: arduino
   
       BLEService environmentalSensingService("181A");
       BLEShortCharacteristic temperatureCharacteristic("2A6E", BLERead | BLENotify);
       BLEUnsignedShortCharacteristic humidityCharacteristic("2A6F", BLERead | BLENotify);

3. Función de Configuración

   - Inicializa la comunicación Serial, el sensor DHT y el BLE.

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

4. Bucle Principal

   - Busca eventos BLE y actualiza los datos del sensor a intervalos regulares.

   - La línea ``millis() - lastUpdateTime > updateInterval`` asegura que los datos del sensor se actualicen cada milisegundos de updateInterval.

   .. code-block:: arduino
   
       void loop() {
         BLE.poll();
         if (millis() - lastUpdateTime > updateInterval) {
           // Leer datos del sensor y actualizar las características BLE
         }
       }

5. Funciones BLE y de Depuración

   Funciones para configurar BLE, imprimir información de depuración y gestionar eventos BLE.

   .. code-block:: arduino
   
       void printDHT(float h, float t) { /* ... */ }
       void setupBle() { /* ... */ }
       void blePeripheralConnectHandler(BLEDevice central) { /* ... */ }
       void blePeripheralDisconnectHandler(BLEDevice central) { /* ... */ }

   - ``printDHT(float h, float t)``: Utilizada para imprimir los datos de temperatura y humedad leídos por el DHT11 en el monitor serial. Esta función es para fines de depuración.

   - ``setupBle()``: Inicializa el Bluetooth, incluyendo el nombre de difusión, las características y los servicios.

   - ``blePeripheralConnectHandler(BLEDevice central)`` y ``blePeripheralDisconnectHandler(BLEDevice central)``: Estas funciones manejan eventos cuando el Bluetooth se conecta o desconecta. Cuando un dispositivo se conecta exitosamente con el UNO R4 vía Bluetooth, el LED integrado se enciende. Cuando el dispositivo se desconecta, el LED se apaga.
