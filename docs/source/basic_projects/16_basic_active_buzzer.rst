.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete más en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_active_buzzer:

Zumbador activo
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_active_buzzer.html#ar-beep

Descripción general
----------------------

El zumbador activo es un dispositivo típico de salida digital que es tan fácil de usar como encender un LED.

En el kit se incluyen dos tipos de zumbadores.
Necesitamos usar el zumbador activo. Gíralos, el reverso sellado (no el PCB expuesto) es el que queremos.

.. image:: img/16_buzzer.png
    :align: center
    :width: 70%

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_buzzer`
        - \-

Conexión
----------------------

.. note::
    Al conectar el zumbador, asegúrate de verificar sus pines. El pin más largo es el ánodo y el más corto es el cátodo. Es importante no mezclarlos, ya que hacerlo impedirá que el zumbador produzca sonido.

.. image:: img/16-active_buzzer_bb.png
    :align: center
    :width: 70%

Diagrama esquemático
-----------------------

.. image:: img/16_active_buzzer_schematic.png
    :align: center
    :width: 80%

Código
---------------

.. note::

    * Puedes abrir el archivo ``16-active_buzzer.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\16-active_buzzer``.
    * O copia este código en Arduino IDE.

.. literalinclude:: /_code/16_basic_active_buzzer.ino
   :language: cpp
   :linenos:
   :caption: 16-active_buzzer.ino

Después de que el código se cargue con éxito, escucharás un pitido cada segundo.
