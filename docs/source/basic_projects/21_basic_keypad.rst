.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_keypad:

Teclado
==========================

.. https://docs.sunfounder.com/projects/vincent-kit-de/en/latest/arduino/2.19_keypad.html#ar-keypad

Descripción general
-----------------------

En esta lección, aprenderás a usar un teclado. El teclado puede aplicarse en varios dispositivos, incluidos teléfonos móviles, máquinas de fax, microondas, entre otros. Es comúnmente utilizado para la entrada de datos del usuario.

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

También puedes comprarlos por separado en los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN A LOS COMPONENTES
        - ENLACE DE COMPRA

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_keypad`
        - |link_keypad_buy|

Conexión
----------------------

.. image:: img/21-keypad_bb.png
    :align: center

Diagrama esquemático
----------------------

.. image:: img/21_keypad_schematic.png
   :align: center
   :width: 70%

Código
-----------


.. note::

    * Puedes abrir el archivo ``21-keypad.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\21-keypad``.
    * Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca **"Adafruit Keypad"** y luego instálala. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/25fd4116-92d4-4ee4-b3ba-6707f4334629/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de subir el código a la placa UNO, en el monitor serie, podrás ver el valor de la tecla presionada en el teclado.

Análisis del código
----------------------

1. Incluir la biblioteca

   Comenzamos incluyendo la biblioteca ``Adafruit_Keypad``, que nos permite interfazar fácilmente con el teclado.

   .. code-block:: arduino

     #include "Adafruit_Keypad.h"

   .. note::

      * Para instalar la biblioteca, utiliza el Administrador de Bibliotecas de Arduino y busca **"Adafruit Keypad"** y luego instálala. 


2. Configuración del teclado

   .. code-block:: arduino

     const byte ROWS = 4;
     const byte COLS = 4;
     char keys[ROWS][COLS] = {
       { '1', '2', '3', 'A' },
       { '4', '5', '6', 'B' },
       { '7', '8', '9', 'C' },
       { '*', '0', '#', 'D' }
     };
     byte rowPins[ROWS] = { 2, 3, 4, 5 };
     byte colPins[COLS] = { 8, 9, 10, 11 };

   - Las constantes ``ROWS`` y ``COLS`` definen las dimensiones del teclado. 
   - ``keys`` es un array 2D que almacena la etiqueta de cada botón en el teclado.
   - ``rowPins`` y ``colPins`` son arrays que almacenan los pines de Arduino conectados a las filas y columnas del teclado.

   .. raw:: html

      <br/>


3. Inicializar el teclado

   Crear una instancia de ``Adafruit_Keypad`` llamada ``myKeypad`` e inicializarla.

   .. code-block:: arduino

     Adafruit_Keypad myKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

4. Función setup()

   Inicializar la comunicación Serial y el teclado personalizado.

   .. code-block:: arduino

     void setup() {
       Serial.begin(9600);
       myKeypad.begin();
     }

5. Bucle principal

   Verificar eventos de teclas y mostrarlos en el Monitor Serie.

   .. code-block:: arduino

     void loop() {
       myKeypad.tick();
       while (myKeypad.available()) {
         keypadEvent e = myKeypad.read();
         Serial.print((char)e.bit.KEY);
         if (e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
         else if (e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
       }
       delay(10);
     }

