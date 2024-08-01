.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_joystick:

Módulo Joystick
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/joystick_ps2_uno.html#joystick-uno


Descripción general
------------------------

Un joystick es un dispositivo de entrada que consiste en un palo que pivota sobre una base y reporta su ángulo o dirección al dispositivo que está controlando. Los joysticks se utilizan a menudo para controlar videojuegos y robots. Aquí se utiliza un Joystick PS2.

Componentes necesarios
--------------------------

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

Conexión
----------------------

.. image:: img/20-joystick_bb.png
    :align: center
    :width: 70%

Diagrama esquemático
-----------------------

Este módulo tiene dos salidas analógicas (correspondientes a los desplazamientos biaxiales X,Y). 

En este experimento, utilizamos la placa Uno para detectar la dirección de movimiento del mando del joystick.

.. image:: img/20_joystick_schematic.png
    :align: center 
    :width: 70%

Código
----------

.. note::

    * Puedes abrir el archivo ``20-joystick.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\20-joystick``.
    * O copiar este código en Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ac0f9910-e53e-43a3-a5ae-ec4d3a3f4aa1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ahora, cuando empujes el joystick, las coordenadas de los ejes X e Y mostradas en el Monitor Serie cambiarán en consecuencia. Al presionar el botón, también se mostrará la coordenada Z=0.


Análisis del código
-----------------------

El código usa el monitor serie para imprimir el valor de los pines VRX y VRY del joystick PS2.

.. code-block:: arduino

    void loop()
    {
        Serial.print("X: "); 
        Serial.print(analogRead(xPin), DEC);  // imprime el valor de VRX en DEC
        Serial.print("|Y: ");
        Serial.print(analogRead(yPin), DEC);  // imprime el valor de VRY en DEC
        Serial.print("|Z: ");
        Serial.println(digitalRead(swPin));  // imprime el valor de SW
        delay(50);
    }