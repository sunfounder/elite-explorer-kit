.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_tilt_switch:

Interruptor de Inclinación
===============================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.17_tilt_switch.html#ar-tilt

Descripción general
---------------------------

En esta lección, aprenderás sobre el interruptor de inclinación. El interruptor de inclinación puede utilizarse para detectar si los objetos se inclinan, lo que tiene un gran valor en aplicaciones prácticas. Puede utilizarse para juzgar la inclinación de puentes, edificios, torres de líneas de transmisión, etc., por lo que tiene una función de guía importante en la realización de trabajos de mantenimiento.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_tilt_switch`
        - \-

Circuito Fritzing
---------------------

En este ejemplo, se utiliza el pin digital 2 para leer la señal del interruptor de inclinación.

.. image:: img/04-tilt_switch_bb.png
   :align: center
   :width: 85%

Diagrama esquemático
-----------------------

.. image:: img/04_tilt_switch_schematic.png
   :align: center
   :width: 70%


Código
----------

.. note::

    * Puedes abrir el archivo ``04-tilt_switch.ino`` en la ruta ``elite-explorer-kit-main\basic_project\04-tilt_switch`` directamente.
    * O copiar este código en Arduino IDE.

.. literalinclude:: /_code/04_basic_tilt_switch.ino
   :language: cpp
   :linenos:
   :caption: 04-tilt_switch.ino

Una vez que los códigos se cargan en la placa uno r4, puedes abrir el monitor serial para ver las lecturas del pin. Las lecturas mostrarán "1" o "0" dependiendo de si el interruptor de inclinación está en posición vertical (con la bola de metal interna haciendo contacto con los pines) o inclinado.
