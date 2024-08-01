.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_thermistor:

Termistor
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.27_thermistor.html#ar-thermistor

Descripción general
-----------------------

En esta lección, aprenderás a usar un termistor. El termistor puede usarse como componente de circuito electrónico para la compensación de temperatura de los circuitos de instrumentos. En el amperímetro, caudalímetro, analizador de gases y otros dispositivos. También puede usarse para protección contra sobrecalentamiento, relé sin contacto, temperatura constante, control automático de ganancia, arranque de motores, retardo de tiempo, desmagnetización automática de televisores en color, alarma de incendios y compensación de temperatura.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

Cableado
------------------------

En este ejemplo, usamos el pin analógico A0 para obtener el valor del termistor. Un pin del termistor está conectado a 5V, y el otro está conectado a A0. Al mismo tiempo, una resistencia de 10kΩ está conectada con el otro pin antes de conectarlo a GND.

.. image:: img/02-thermistor_bb.png
    :align: center
    :width: 70%

Diagrama esquemático
-------------------------

.. image:: img/02_thermistor_schematic.png
   :align: center
   :width: 70%

Código
-----------

.. note::

    * Puedes abrir el archivo ``02-thermistor.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\02-thermistor``.
    * O copiar este código en el IDE de Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/be5dbe68-b57d-41f0-9fc0-237b99acbe3f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Después de subir el código a la placa uno r4, puedes abrir el monitor serial para verificar la temperatura actual.

La temperatura en Kelvin se calcula utilizando la fórmula **T\ K\ =1/(ln(R\ T/R\ N)/B+1/T\ N)**. Esta ecuación se deriva del |link_steinhart_hart| y simplifica los cálculos. También puedes encontrar más información sobre esta fórmula en la página de introducción detallada del :ref:`cpn_thermistor`.
