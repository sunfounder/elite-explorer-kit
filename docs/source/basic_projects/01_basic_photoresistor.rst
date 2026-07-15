.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_photoresistor:

Fotorresistor
===========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.26_photoresistor.html

Descripción general
--------------------------

En esta lección, aprenderás sobre el fotorresistor. El fotorresistor se aplica en muchos productos electrónicos, como el medidor de la cámara, el reloj despertador, el dispositivo de alarma (como detector de haz), pequeñas luces nocturnas, relojes de exterior, lámparas solares de calle, etc. El fotorresistor se coloca en una lámpara de calle para controlar cuándo se enciende la luz. La luz ambiental que cae sobre el fotorresistor hace que las lámparas de calle se enciendan o apaguen.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Cableado
----------------------

En este ejemplo, usamos el pin analógico (A0) para leer el valor del fotorresistor. Un pin del fotorresistor está conectado a 5V, el otro está conectado a A0. Además, se necesita una resistencia de 10kΩ antes de que el otro pin esté conectado a GND.

.. image:: img/01-photoresistor_bb.png
    :align: center
    :width: 80%

Diagrama esquemático
--------------------------

.. image:: img/01_photoresistor_schematic.png
    :align: center
    :width: 70%

Código
-----------------

.. note::

    * Puedes abrir el archivo ``01-photoresistor`` directamente en la ruta ``elite-explorer-kit-main\basic_project\01-photoresistor``.
    * O copia este código en el IDE de Arduino.




.. literalinclude:: /_code/01_basic_photoresistor.ino
   :language: cpp
   :linenos:
   :caption: 01-photoresistor.ino

Después de subir el código a la placa uno, puedes abrir el monitor serial para ver el valor leído del pin. Cuando la luz ambiental se vuelva más fuerte, la lectura aumentará correspondientemente, y el rango de lectura del pin es de 「0」~「1023」. Sin embargo, según las condiciones ambientales y las características del fotorresistor, el rango de lectura real puede ser menor que el rango teórico.
