.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_mfrc522:

Módulo RFID-RC522
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.35_rfid-rc522_module.html

Descripción general
----------------------

En esta lección, aprenderás a usar un Módulo RFID. RFID significa Identificación por Radiofrecuencia. Su principio de operación implica la comunicación de datos sin contacto entre el lector y la etiqueta para identificar el objetivo. Las aplicaciones del RFID son extensas, incluyendo chips para animales, inmovilizadores, control de acceso, control de estacionamiento, automatización de la cadena de producción, gestión de materiales y más.

Componentes necesarios
-----------------------------

En este proyecto, necesitamos los siguientes componentes.

Es definitivamente conveniente comprar un kit completo, aquí está el enlace:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nombre	
        - ELEMENTOS EN ESTE KIT
        - ENLACE
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

También puedes comprarlos por separado desde los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|

Circuito Fritzing
---------------------

En este ejemplo, insertamos el RFID en la placa de pruebas. Conecta el 3.3V del RFID a 3.3V, GND a GND, RST al pin 2, SDA al pin 6, SCK al pin 5, MOSI al pin 4, MISO al pin 3 y IRQ al pin 7.

.. image:: img/08-rfid_bb.png
   :align: center

Diagrama esquemático
-------------------------

.. image:: img/08_mfrc522_schematic.png
   :align: center
   :width: 70%

Código
-----------

.. note::

    * Puedes abrir el archivo ``08-mfrc522.ino`` en la ruta de ``elite-explorer-kit-main\basic_project\08-mfrc522`` directamente.
    * La biblioteca ``RFID1`` se utiliza aquí. La biblioteca se puede encontrar en el directorio ``elite-explorer-kit-main/library/``, o puedes hacer clic aquí :download:`RFID1.zip </_static/RFID1.zip>` para descargarla. Consulta :ref:`manual_install_lib` para un tutorial sobre cómo instalarla.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9a4e9be9-78f5-4bf0-8b44-ca6e44092dc1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Subido el código a la placa Uno, puedes acercar tu tarjeta RFID (llave secreta) al lector RFID. El módulo leerá la información de la tarjeta y la imprimirá en el monitor serial.

Análisis del código
--------------------------

Las funciones del módulo están incluidas en la biblioteca ``rfid1.h``.

.. code-block:: arduino

    #include <rfid1.h>

**Funciones de la biblioteca:**

.. code-block:: arduino

    RFID1 rfid;

Crear una nueva instancia de la clase rfid1 que representa un módulo
RFID particular conectado a tu Arduino.

.. code-block:: arduino

    void begin(IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN,SDA_PIN,RST_PIN)

Configuración de pines.

* ``IRQ_PIN, SCK_PIN, MOSI_PIN, MISO_PIN``: los pines utilizados para la comunicación SPI.
* ``SDA_PIN``: Adaptador de datos sincrónicos.
* ``RST_PIN``: Los pines utilizados para el reinicio.

.. code-block:: arduino

    void init()

Inicializa el RFID.

.. code-block:: arduino

    uchar request(uchar reqMode, uchar *TagType);

Busca la tarjeta y lee el tipo de tarjeta, y la función devolverá el estado de lectura actual del RFID y devolverá MI_OK si tiene éxito.

* ``reqMode``: Métodos de búsqueda. PICC_REQIDL se define como bits de comando 0x26 (Buscar las tarjetas que no están en modo de reposo en el área de la antena).
* ``*TagType``: Se utiliza para almacenar el tipo de tarjeta, y su valor puede ser de 4 bytes (por ejemplo, 0x0400).

.. code-block:: arduino

    char * readCardType(uchar *TagType)

Esta función decodifica el número hexadecimal de cuatro dígitos de ``*tagType``
en el tipo específico de tarjeta y devuelve una cadena. Si se pasa 0x0400,
se devolverá "MFOne-S50".

.. code-block:: arduino

    uchar anticoll(uchar *serNum);

Evita conflictos y lee el número de serie de la tarjeta. La función
devolverá el estado de lectura actual del RFID. Devuelve MI_OK si
tiene éxito.

* ``*serNum``: Se utiliza para almacenar el número de serie de la tarjeta y devuelve el número de serie de la tarjeta de 4 bytes. El quinto byte es el byte de verificación (por ejemplo, mi tarjeta magnética tiene ID 5AE4C955).

