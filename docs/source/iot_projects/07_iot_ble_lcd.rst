.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte Experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y Comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances Exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos Especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones Festivas y Sorteos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _iot_Bluetooth_lcd:

Caja de Mensajes Bluetooth
================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/07_iot_ble_lcd.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Este proyecto recibe mensajes y los muestra en una pantalla LCD.

Puedes usarlo como un tablero de mensajes familiar, recordando a los miembros de la familia que no han salido aún, que recuerden llevar sus llaves.

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

**Conexiones**

.. image:: img/07_lightblue_lcd_bb.png
    :width: 100%
    :align: center

**Esquemático**

.. image:: img/07_lightblue_lcd_schematic.png
   :width: 80%
   :align: center

.. raw:: html

   <br/>

**Generar el UUID**

Los UUIDs juegan un papel crucial en la comunicación BLE, asegurando la unicidad de los dispositivos y la precisión del intercambio de datos entre ellos. Necesitas personalizar los UUIDs para crear tus propios servicios y características BLE para satisfacer requisitos específicos de la aplicación. (Aquí, necesitamos crear una característica que soporte entrada de texto).

1. Usa la `Herramienta Generadora de UUIDs en Línea <https://www.uuidgenerator.net/version4>`_ para crear UUIDs únicos para ti y evitar conflictos de UUIDs.

2. Genera dos UUIDs de versión 4.

   .. image:: img/07_uuid_1.png
      :width: 70%

   .. raw:: html

      <br/><br/>

3. Cópialos y reemplaza los dos UUIDs en tu código.

   .. code-block:: arduino
   
       #define SERVICE_UUID "uuid1"
       #define CHARACTERISTIC_UUID "uuid2"

**Instalar la Biblioteca**

``ArduinoBLE.h``: Usada para manejar la comunicación Bluetooth Low Energy (BLE).
``LiquidCrystal_I2C.h``: Usada para controlar una pantalla LCD de 16x2 caracteres con interfaz I2C.

**Ejecutar el Código**

.. note::

    * Puedes abrir el archivo ``07_lightblue_lcd.ino`` bajo la ruta ``elite-explorer-kit-main\iot_project\07_lightblue_lcd`` directamente.
    * O copiar este código en el IDE de Arduino.

.. note:: 
      Para instalar la biblioteca, usa el Administrador de Bibliotecas de Arduino para buscar e instalar **"ArduinoBLE"** y **"LiquidCrystal I2C"**.

.. literalinclude:: /_code/07_iot_ble_lcd.ino
   :language: cpp
   :linenos:
   :caption: 07_lightblue_lcd.ino


**¿Cómo jugar?**

Para interactuar con los servicios y características creados en este sketch, deberías usar una aplicación central genérica de Bluetooth® Low Energy como LightBlue (disponible para iOS y Android) o nRF Connect (para Android).

Vamos a usar LightBlue como ejemplo para demostrar cómo controlar el LED del Arduino vía Bluetooth.

1. Descarga la aplicación LightBlue desde la App Store (para iOS) o Google Play (para Android).

   .. image:: img/07_lightblue.png

2. Conectando el Arduino con tu Smartphone vía Bluetooth

   Ve a la configuración de Bluetooth y localiza el dispositivo llamado "UNO R4 BLE". Conéctate a él.

   .. image:: img/07_iot_ble_01.jpg
      :width: 50%

   .. raw:: html

      <br/><br/>

3. Interactuando con Arduino vía Bluetooth usando LightBlue

   Abre LightBlue y toca en la pestaña **Bonded** en la parte inferior de la interfaz. Aquí verás una lista de dispositivos BLE con los que tu smartphone se ha emparejado previamente. Localiza **UNO R4 BLE** y toca **CONNECT**.

   .. image:: img/07_iot_ble_02.jpg

   Una vez conectado, tendrás acceso a información detallada sobre el dispositivo Bluetooth. Desplázate hacia abajo para encontrar tu UUID de servicio y tu UUID de Característica.

   Toca en la Característica. noterás que esta Característica es tanto legible como escribible, permitiéndote leer y escribir en ella.

   Continúa desplazándote hasta la sección "Formato de datos" y cámbiala a Cadena UTF-8.
   Ingresa texto en el cuadro de texto y haz clic en escribir. El mensaje que ingresaste aparecerá en el LCD.

   .. image:: img/07_iot_ble_03.jpg

**¿Cómo funciona?**

Aquí están las partes principales del código y explicaciones de sus funciones:

1. Incluir las bibliotecas necesarias:

   * ``ArduinoBLE.h``: Usada para manejar la comunicación BLE.
   * ``Wire.h``: Usada para la comunicación I2C.
   * ``LiquidCrystal_I2C.h``: Usada para controlar una pantalla LCD de 16x2 caracteres con interfaz I2C.

2. Definir un servicio BLE y una característica BLE:

   * Usa la clase ``BLEService`` para definir un servicio BLE y asignarle un UUID único.
   * Usa la clase ``BLECharacteristic`` para definir una característica BLE, asignarle un UUID único, y darle permisos de lectura (``BLERead``) y escritura (``BLEWrite``).
   * Crea un array de caracteres ``stringValue`` como el valor inicial de la característica.

3. Inicializar una pantalla LCD de 16x2 caracteres (LCD):

   * Usa la clase ``LiquidCrystal_I2C`` para inicializar una LCD, especificando la dirección I2C (0x27) y el número de filas y columnas (16x2).
   * Enciende la luz de fondo de la LCD, limpia la pantalla, mueve el cursor al inicio de la primera fila, y muestra "Bluetooth LCD."

4. Realizar la inicialización en la función ``setup()``:

   * Inicializa la comunicación serial.
   * Inicializa el módulo BLE, y si la inicialización falla, entra en un bucle infinito.
   * Establece el nombre local y el UUID del servicio para el periférico BLE.
   * Agrega la característica BLE al servicio BLE.
   * Comienza a anunciar el servicio BLE para que los dispositivos centrales puedan descubrirlo y conectarse a él.
   * Inicializa la LCD.

5. La función ``loop()``:

   * Verifica si hay un dispositivo central conectado al periférico BLE llamando a ``BLE.central()``. Si hay un dispositivo central conectado, entra en la lógica de manejo de conexión.
   * En el estado conectado, verifica si se han escrito datos en la característica BLE comprobando ``boxCharacteristic.written()``.
   * Si se han escrito datos, obtiene la longitud de los datos escritos usando ``boxCharacteristic.valueLength()`` y crea un array de bytes ``buffer`` para almacenar los datos escritos.
   * Usa ``boxCharacteristic.readValue()`` para leer datos de la característica BLE en el ``buffer``.
   * Agrega un carácter nulo ``'\0'`` al final del ``buffer`` para convertirlo en una cadena.
   * Imprime el mensaje recibido en el monitor serial y lo muestra en la LCD.
   * Continúa esperando a que el próximo dispositivo central se conecte después de que el dispositivo central se desconecte.

