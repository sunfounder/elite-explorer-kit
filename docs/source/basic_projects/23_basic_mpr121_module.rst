.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_mpr121:

MPR121
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.24_mpr121_module.html#ar-mpr121


Descripción general
---------------------

En esta lección, aprenderás a usar el MPR121. Es una buena opción cuando deseas agregar muchos interruptores táctiles a tu proyecto. El electrodo del MPR121 se puede extender con un conductor. Si conectas un cable a un plátano, puedes convertir el plátano en un interruptor táctil, realizando así proyectos como un piano de frutas.

Componentes necesarios
---------------------------

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

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN A LOS COMPONENTES
        - ENLACE DE COMPRA

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_mpr121`
        - \-

Conexión
----------------------

En este ejemplo, insertamos el MPR121 en la placa de pruebas. Conecta el GND del MPR121 a GND, 3.3V a 3V3, IRQ al pin digital 2, SCL al pin SCL (A5) y SDA al pin SDA (A4). Hay 12 electrodos para la detección táctil. 

.. note::
    El MPR121 funciona con 3.3V, no con 5V.

.. image:: img/23-mpr121_bb.png
    :align: center
    :width: 70%

Diagrama esquemático
-----------------------

.. image:: img/23_mpr121_schematic.png
   :align: center
   :width: 70%

Código
--------

.. note::

    * Puedes abrir el archivo ``23-mpr121.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\23-mpr121``.
    * La biblioteca ``Adafruit MPR121`` se utiliza aquí, puedes instalarla desde el **Administrador de Bibliotecas**.

        .. image:: img/22_mpr121_lib.png
            :align: center

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/de0aa390-de85-43ab-87f7-f380c67c65e8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de cargar el código en la placa UNO, el estado táctil de los pines MPR121 "1" y "0" se registrará en una matriz booleana de 12 bits. Esta matriz se imprimirá luego en el monitor serial.

Análisis del código
--------------------
Este código facilita la comunicación y operación del sensor táctil MPR121. Puede detectar el estado de los electrodos táctiles e imprimir información sobre los electrodos tocados o liberados en la interfaz serial. Si se requieren datos detallados del sensor, se puede descomentar el código relevante.

Aquí tienes un análisis del código:

#. Importar bibliotecas:

   .. code-block:: arduino

       #include <Wire.h>
       #include "Adafruit_MPR121.h"

   * ``Wire.h``: Utilizada para la comunicación I2C.
   * ``Adafruit_MPR121.h``: Biblioteca MPR121 de Adafruit para operar el sensor táctil MPR121.

#. Definir la macro ``_BV``:

   .. code-block:: arduino

       #ifndef _BV
       #define _BV(bit) (1 << (bit)) 
       #endif
   
   ``_BV(bit)`` define una macro que convierte un bit dado en el valor binario correspondiente, similar a 1 << bit.

#. Inicializar la instancia de la clase ``Adafruit_MPR121``:

   .. code-block:: arduino

       Adafruit_MPR121 cap = Adafruit_MPR121();

   Crear una instancia de la clase ``Adafruit_MPR121`` llamada ``cap``. El objeto ``cap`` se utilizará para comunicarse y operar el sensor táctil MPR121.

#. Función ``setup()``:

   Inicializar la comunicación serial a una velocidad de 9600 baudios, luego inicializar el sensor táctil MPR121 con la dirección I2C predeterminada de 0x5A. Si la inicialización falla, imprimir un mensaje de error y entrar en un bucle infinito.

   .. code-block:: arduino

       void setup() {
           Serial.begin(9600);
           
           while (!Serial) { // Necesario para evitar que Leonardo/Micro arranque demasiado rápido
               delay(10);
           }
           
           Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
           
           // La dirección predeterminada es 0x5A, si está conectado a 3.3V es 0x5B
           // Si está conectado a SDA es 0x5C y si es a SCL es 0x5D
           if (!cap.begin(0x5A)) {
               Serial.println("MPR121 not found, check wiring?");
               while (1);
           }
           Serial.println("MPR121 found!");
       }

#. Función ``loop()``:

   * Obtener el estado táctil actual, devuelto como un entero de 16 bits.

     .. code-block:: arduino

         currtouched = cap.touched();

   * Iterar a través del estado de 12 electrodos (numerados del 0 al 11).

     .. code-block:: arduino

         for (uint8_t i=0; i<12; i++) {
             // si *está* tocado y *no estaba* tocado antes, alertar
             if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
                 Serial.print(i); Serial.println(" touched");
             }
             // if it *was* touched and now *isnt*, alert!
             if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
                 Serial.print(i); Serial.println(" released");
             }
         }

     * Si un electrodo está tocado y no estaba tocado antes, imprimir "x tocado," donde x es el número de electrodo.
     * Si un electrodo estaba tocado antes pero ahora no lo está, imprimir "x liberado."

   * Actualizar ``lasttouched`` para almacenar el estado táctil actual para comparación en la siguiente iteración.

     .. code-block:: arduino

         lasttouched = currtouched;

   * Información de depuración (sección opcional):

     .. code-block:: arduino

         // Información de depuración
         Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
         Serial.print("Filt: ");
         for (uint8_t i=0; i<12; i++) {
             Serial.print(cap.filteredData(i)); Serial.print("\t");
         }
         Serial.println();
         Serial.print("Base: ");
         for (uint8_t i=0; i<12; i++) {
             Serial.print(cap.baselineData(i)); Serial.print("\t");
         }
         Serial.println();
         
         // put a delay so it isn't overwhelming
         delay(100);
