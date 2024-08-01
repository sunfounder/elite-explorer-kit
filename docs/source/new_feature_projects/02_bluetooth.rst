.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte Experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances Exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _new_bluetooth:

Bluetooth
========================================

Equipado con el módulo ESP32, la placa UNO R4 WiFi ofrece funcionalidades de Bluetooth® LE y Bluetooth® 5, soportando velocidades de hasta 2 Mbps. El módulo ESP32 viene con una antena de traza integrada, eliminando la necesidad de una antena externa para aprovechar las características de conectividad de la placa.

.. note::
    La antena de traza en el módulo ESP32 se comparte con el módulo Bluetooth®, lo que significa que no se puede usar Bluetooth® y Wi-Fi® al mismo tiempo.

Conceptos Básicos de BLE
++++++++++++++++++++++++++++

**Bluetooth Low Energy (BLE)** es una tecnología de comunicación inalámbrica de baja potencia, diseñada específicamente para interacciones de corto alcance. A diferencia del Bluetooth clásico, BLE se enfoca en la eficiencia energética y la conexión rápida, lo que la hace ideal para una variedad de aplicaciones, incluidos los dispositivos del Internet de las Cosas (IoT) y los equipos de monitoreo de salud.

Las comunicaciones BLE se basan en dos protocolos clave: **GATT (Generic Attribute Profile)** y **GAP (Generic Access Profile)**. GATT se utiliza para el intercambio de datos, mientras que GAP se encarga del descubrimiento de dispositivos y la conexión.

.. image:: img/02_ble_relationships.png
 :width: 100%


Dispositivos Periféricos (Normalmente Servidores GATT)
----------------------------------------------------------

En la red BLE, los **dispositivos periféricos** principalmente transmiten datos para ser descubiertos y accesados por dispositivos centrales (que suelen actuar como clientes GATT). Estos dispositivos son usualmente sensores o hardware pequeño como monitores de ritmo cardíaco, sensores de temperatura o bombillas inteligentes.

En el modelo de comunicación BLE, los dispositivos periféricos suelen proporcionar uno o más **servicios**, cada uno de los cuales contiene un conjunto de **características**. Estos servicios y características colaboran para habilitar funcionalidades específicas o casos de uso, permitiendo que los dispositivos centrales lean o manipulen los datos relevantes.

- **Servicios**

  En BLE, los servicios actúan como abstracciones de alto nivel utilizadas para organizar y encapsular características relacionadas. Los servicios en BLE pueden categorizarse en servicios estándar y servicios personalizados según su origen y propósito.

  - Servicios Estándar: Definidos por el SIG de Bluetooth (Special Interest Group), están destinados a funciones específicas. Por ejemplo, el servicio de ritmo cardíaco para monitores de ritmo cardíaco, el servicio de información del dispositivo que proporciona detalles del fabricante, modelo y versión, y el servicio de batería que indica el nivel y estado de la batería.
  - Servicios Personalizados: Definidos por desarrolladores o fabricantes de dispositivos para satisfacer las necesidades de aplicaciones o dispositivos específicos. Por ejemplo, un fabricante de dispositivos para el hogar inteligente podría definir un servicio personalizado para controlar el color y el brillo de la luz.

- **Características**

  Las características en BLE son las unidades fundamentales de datos expuestas por los dispositivos periféricos. Están contenidas dentro de un servicio y definen varios tipos de datos y las operaciones que se pueden realizar sobre ellos. Cada característica está identificada por un UUID y tiene un conjunto de atributos asociados como valor, descriptor y permisos.

  - Permisos: En BLE, cada característica está asociada con un conjunto de permisos que dictan si la característica es legible, escribible o notificable. Esto ayuda a proteger los datos y definir cómo interactuar con ellos.

- **UUID**

  Los servicios, características y descriptores se identifican colectivamente como atributos, cada uno con un UUID único. El SIG de Bluetooth ha reservado un conjunto de UUIDs para atributos estándar. Estos UUIDs generalmente se representan como identificadores de 16 bits o 32 bits en el protocolo BLE por eficiencia, en lugar de los 128 bits requeridos para un UUID completo. Por ejemplo, el servicio de información del dispositivo se representa con el código corto 0x180A.



Dispositivos Centrales (Normalmente Clientes GATT)
----------------------------------------------------

Los **dispositivos centrales** en la red BLE escanean dispositivos periféricos cercanos y establecen conexiones para adquirir o controlar datos. Estos dispositivos son generalmente más complejos y ricos en funciones, como teléfonos inteligentes, tabletas o hardware de puerta de enlace especializado. Son responsables de descubrir dispositivos periféricos, conectarse a ellos y acceder o suscribirse a los servicios y características ofrecidos por los periféricos para servir diversas aplicaciones o resolver problemas específicos.

Los dispositivos centrales interactúan con las características de las siguientes maneras:

- **Leer**: Solicita al dispositivo periférico que envíe el valor actual de una característica. Esto se usa comúnmente para características que no cambian a menudo, como configuraciones o números de versión.
- **Escribir**: Modifica el valor de una característica, típicamente utilizado para operaciones de comando, como instruir a un dispositivo periférico para encender o apagar un motor.
- **Suscribirse**: Solicita al dispositivo periférico que envíe continuamente valores actualizados de una característica, eliminando la necesidad de que el dispositivo central solicite repetidamente estos datos.



Ejemplo: LED Controlado por Bluetooth
++++++++++++++++++++++++++++++++++++++++++++++++++++++++

En este ejemplo, el Arduino actúa como un dispositivo periférico en una red Bluetooth Low Energy (BLE). Ofrece un servicio BLE personalizado diseñado para controlar un LED integrado. Este servicio incluye una característica que puede ser leída y escrita por un dispositivo central, como un teléfono inteligente. Una vez que el dispositivo central se conecta al Arduino, puede cambiar el estado del LED escribiendo en esta característica. El monitor serial del Arduino muestra información de depuración, incluido el estado actual del LED y la dirección MAC del dispositivo central conectado.

**Cargar el Código**

Abre el archivo ``02-bluetooth.ino`` ubicado en ``elite-explorer-kit-main\r4_new_feature\02-bluetooth``, o pega el siguiente código en tu IDE de Arduino.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/44d76bb7-9f0a-4004-b3fe-9a88999c5f06/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Conectar Arduino R4 a través de Bluetooth**

Para interactuar con los servicios y características creados en este boceto, deberíamos utilizar una aplicación central genérica de Bluetooth® Low Energy como LightBlue (disponible para iOS y Android) o nRF Connect (para Android).

Tomemos LightBlue como ejemplo para demostrar cómo controlar el LED del Arduino a través de Bluetooth.

1. Descarga la aplicación **LightBlue** desde |link_lightblue_apple| (para iOS) o |link_lightblue_google| (para Android).

   .. image:: img/02_lightblue.png
    :width: 90%

   .. raw:: html

      <br/><br/>

2. Conectar Arduino con tu Smartphone vía Bluetooth
   
   Navega a la configuración de Bluetooth y localiza el dispositivo llamado "UNO R4 LED". Procede a conectarte a él.

   .. image:: img/02_connect.png
    :width: 90%

   .. raw:: html

      <br/>

3. Interactuar con Arduino vía Bluetooth Usando LightBlue

   Abre LightBlue y toca en la pestaña **Bonded** ubicada en la parte inferior de la interfaz. Aquí verás una lista de dispositivos BLE que tu smartphone ha emparejado previamente. Localiza **UNO R4 LED** y toca en **CONNECT**.

   .. image:: img/02_lightblue_1.png
    :width: 90%

   Una vez conectado, obtendrás acceso a información detallada sobre el dispositivo Bluetooth "UNO R4 LED". Desplázate hacia abajo para encontrar "ledService (**19B10000-E8F2-537E-4F6C-D104768A1214**)" y "switchCharacteristic (**19B10001-E8F2-537E-4F6C-D104768A1214**)".

   Toca en la Característica 19B10001-E8F2-537E-4F6C-D104768A1214. noterás que esta Característica es tanto legible como escribible, permitiéndote leer y escribir en ella.
  
   .. image:: img/02_lightblue_2.png
    :width: 90%

   Sigue desplazándote hasta la sección **WRITTEN VALUES**. Ingresa '**1**' en el cuadro de texto para establecer el valor de la Característica en 1, lo que **encenderá el LED integrado del Arduino R4**.

   .. image:: img/02_lightblue_3.png
    :width: 90%

   Del mismo modo, puedes establecer este valor en '**0**' para **apagar el LED integrado**.

   .. image:: img/02_lightblue_4.png
    :width: 90%



**Explicación del Código**

#. Inicializar BLE y LED

   .. note::
      Al definir servicios y características, necesitamos usar UUIDs para identificarlos. Para evitar conflictos de UUID y facilitarte su uso, puedes usar la herramienta de generación de UUID en |link_uuid_gen_tool|.

   .. code-block:: arduino
   
      #include <ArduinoBLE.h>
      BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); // Servicio de LED para Bluetooth® Low Energy
      BLEByteCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);
      const int ledPin = LED_BUILTIN; // pin para usar con el LED

   - Incluye la biblioteca ArduinoBLE.
   - Define el servicio BLE y la característica.
   - Asigna el pin del LED integrado a ``ledPin``.

   .. raw:: html

      <br/>

#. Función ``setup()``

   .. code-block:: arduino
   
      void setup() {
        Serial.begin(9600);
        while (!Serial);
        pinMode(ledPin, OUTPUT);
        if (!BLE.begin()) {
          Serial.println("starting Bluetooth® Low Energy module failed!");
          while (1);
        }
        BLE.setLocalName("UNO R4 LED");
        BLE.setAdvertisedService(ledService);
        ledService.addCharacteristic(switchCharacteristic);
        BLE.addService(ledService);
        switchCharacteristic.writeValue(0);
        BLE.advertise();
        Serial.println("BLE LED Peripheral");
      }

   - Inicializa la comunicación serial.
   - Configura el pin del LED como salida.
   - Inicializa BLE y agrega el servicio y las características.
   - Inicia la publicidad de BLE.

   .. raw:: html

      <br/>

#. Función ``loop()``

   .. code-block:: arduino
   
      void loop() {
        BLEDevice central = BLE.central();
        if (central) {
          Serial.print("Connected to central: ");
          Serial.println(central.address());
          while (central.connected()) {
            if (switchCharacteristic.written()) {
              if (switchCharacteristic.value()) {
                Serial.println("LED on");
                digitalWrite(ledPin, HIGH);
              } else {
                Serial.println("LED off");
                digitalWrite(ledPin, LOW);
              }
            }
          }
          Serial.print("Disconnected from central: ");
          Serial.println(central.address());
        }
      }
   

   - Escucha a dispositivos centrales BLE para conectarse.
   - Si un dispositivo central se conecta, lee el valor de la característica para controlar el LED. Si se recibe un valor distinto de 0, enciende el LED. Si se recibe 0, apaga el LED.


**Referencia**

- |link_r4_bluetooth|
