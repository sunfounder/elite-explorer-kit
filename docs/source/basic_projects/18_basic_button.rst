.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_button:

Botón
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/controlling_led_by_button_uno.html#button-uno


Descripción general
----------------------------

En esta lección, aprenderás a controlar un LED usando un botón con Arduino. Los botones y los LEDs son componentes fundamentales en una amplia gama de dispositivos electrónicos, como controles remotos, linternas e instalaciones interactivas. En esta configuración, se utiliza un botón como dispositivo de entrada para controlar el estado de un LED, que sirve como dispositivo de salida.

El botón está conectado al pin 12 en la placa Arduino Uno R4, y el LED está conectado al pin 13. Cuando se presiona el botón, se envía una señal al Arduino, activando el LED. Por el contrario, cuando se suelta el botón, el LED se apaga. Este mecanismo simple pero efectivo puede ser la base para proyectos más complejos, como sistemas de automatización del hogar, pantallas interactivas y mucho más.

Al final de esta lección, comprenderás cómo leer la entrada de un botón y usarla para controlar un LED, obteniendo así una comprensión básica de las operaciones de entrada/salida con Arduino.

Componentes necesarios
----------------------------

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|


Conexión
----------------------

.. image:: img/18-button_bb.png
    :align: center
    :width: 70%


Diagrama esquemático
------------------------

Conecta un extremo del botón al pin 12, que está conectado a una resistencia pull-down y un condensador de 0.1uF (104) (para eliminar el jitter y obtener un nivel estable cuando el botón está funcionando). Conecta el otro extremo de la resistencia a GND y uno de los pines del otro extremo del botón a 5V. Cuando se presiona el botón, el pin 12 recibe 5V (ALTO) y al mismo tiempo se configura el pin 13 (integrado con un LED) como ALTO. Luego, al soltar el botón (el pin 12 cambia a BAJO), el pin 13 se pone en BAJO. Así, veremos que el LED se enciende y apaga alternativamente cuando se presiona y suelta el botón.

.. image:: img/18_button_schematic.png
    :align: center
    :width: 70%


Código
---------------

.. note::

    * Puedes abrir el archivo ``18-button.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\18-button``.
    * O copia este código en Arduino IDE.




.. literalinclude:: /_code/18_basic_button.ino
   :language: cpp
   :linenos:
   :caption: 18-button.ino
    


Análisis del Código
-----------------------

#. Definir constantes y variables

   En este segmento, se definen los números de pin para el botón y el LED. Además, se declara una variable ``buttonState`` para almacenar el estado actual del botón.
 
   .. code-block:: arduino
 
     const int buttonPin = 12;
     const int ledPin = 13;
     int buttonState = 0;

#. Función de configuración

   La función ``setup()`` se ejecuta una vez cuando la placa Arduino se inicia. Se establecen los modos de pin para el botón y el LED utilizando la función ``pinMode``.
 
   .. code-block:: arduino
 
     void setup() {
       pinMode(buttonPin, INPUT);
       pinMode(ledPin, OUTPUT);
     }

#. Bucle principal

   La función ``loop()`` se ejecuta repetidamente. Dentro de este bucle, se utiliza la función ``digitalRead()`` para leer el estado del botón. Dependiendo de si el botón está presionado o no, el LED se enciende o apaga.
 
   .. code-block:: arduino
 
     void loop() {
       buttonState = digitalRead(buttonPin);
       if (buttonState == HIGH) {
         digitalWrite(ledPin, HIGH);
       } else {
         digitalWrite(ledPin, LOW);
       }
     }