.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_gy87_bmp180:

BMP180
==========================


Descripción general
---------------------

En este tutorial, profundizamos en el módulo IMU GY-87, centrándonos en el sensor BMP180 para medir temperatura, presión y altitud. Ideal para aplicaciones como monitoreo meteorológico y seguimiento de altitud, esta lección cubre la interfaz del GY-87 con un Arduino Uno y el uso de la biblioteca Adafruit BMP085. Aprenderás cómo inicializar el sensor BMP180 y leer sus datos en el Monitor Serial de Arduino, una habilidad crucial para proyectos que requieren datos ambientales.

Componentes necesarios
-------------------------

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
    *   - :ref:`cpn_gy87`
        - \-


Cableado
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 75%

.. raw:: html

   <br/>

Diagrama esquemático
--------------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%

Código
-----------

.. note::

    * Puedes abrir el archivo ``09-gy87_bmp180.ino`` en la ruta de ``elite-explorer-kit-main\basic_project\09-gy87_bmp180`` directamente.
    * O copiar este código en el IDE de Arduino.

.. note:: 
    Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca **"Adafruit BMP085 Library"** e instálala. 

.. literalinclude:: /_code/09_basic_gy87_bmp180.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87_bmp180.ino


Análisis del código
------------------------

- ``initializeBMP180()``

  Inicializa el sensor BMP180.

  .. code-block:: arduino

     void initializeBMP180() {
       // Iniciar la inicialización del BMP180
       if (!bmp.begin()) {
         Serial.println("Could not find a valid BMP180 sensor, check wiring!");
         while (1)
           ;  // Detener si no se encuentra el sensor
       }
       Serial.println("BMP180 Found!");
     }

- ``printBMP180()``

  Imprime los valores leídos por el sensor BMP180.

  .. code-block:: arduino

     void printBMP180() {
       Serial.println();
       Serial.println("BMP180 ------------");
       Serial.print("Temperature = ");
       Serial.print(bmp.readTemperature());
       Serial.println(" *C");
     
       Serial.print("Pressure = ");
       Serial.print(bmp.readPressure());
       Serial.println(" Pa");
     
       // Calcular la altitud asumiendo una presión barométrica 'estándar'
       // de 1013.25 milibar = 101325 Pascal
       Serial.print("Altitude = ");
       Serial.print(bmp.readAltitude());
       Serial.println(" meters");
     
       Serial.print("Pressure at sealevel (calculated) = ");
       Serial.print(bmp.readSealevelPressure());
       Serial.println(" Pa");
       Serial.println("BMP180 ------------");
       Serial.println();
     }


