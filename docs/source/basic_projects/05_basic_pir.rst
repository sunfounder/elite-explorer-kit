.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _basic_pir:

Módulo Sensor de Movimiento PIR
======================================

.. https://docs.sunfounder.com/projects/kepler-kit/en/latest/cproject/ar_pir.html#ar-pir


Descripción general
-------------------------

En esta lección, aprenderás sobre el módulo sensor de movimiento PIR. El sensor de movimiento pasivo infrarrojo (PIR) es un sensor que detecta movimiento. Se usa comúnmente en sistemas de seguridad y sistemas de iluminación automática. El sensor tiene dos ranuras que detectan la radiación infrarroja. Cuando un objeto, como una persona, pasa frente al sensor, detecta un cambio en la cantidad de radiación infrarroja y activa una señal de salida.


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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

Cableado
----------------------

.. image:: img/05-pir_bb.png
   :align: center
   :width: 100%


Diagrama esquemático
-----------------------

.. image:: img/05-pir_schematic.png
   :align: center
   :width: 50%


Código
---------------

.. note::

    * Puedes abrir el archivo ``05-pir_motion_sensor.ino`` en la ruta ``elite-explorer-kit-main\basic_project\05-pir_motion_sensor`` directamente.
    * O copiar este código en Arduino IDE.

.. literalinclude:: /_code/05_basic_pir.ino
   :language: cpp
   :linenos:
   :caption: 05-pir_motion_sensor.ino

Después de subir el código a la placa Arduino Uno, puedes abrir el monitor serial para observar la salida del sensor. Cuando el sensor de movimiento PIR (infrarrojo pasivo) detecta movimiento, el monitor serial mostrará el mensaje "¡Alguien está aquí!" para indicar que se ha detectado movimiento. Si no se detecta movimiento, se mostrará el mensaje "Monitoreando..." en su lugar.

El sensor PIR emite una señal digital ALTA o BAJA, correspondiente a movimiento detectado o no detectado, respectivamente. A diferencia de un sensor analógico que proporciona un rango de valores, la salida digital de este sensor PIR será ALTA (típicamente representada como '1') o BAJA (típicamente representada como '0').

Ten en cuenta que la sensibilidad y el rango de detección reales pueden variar según las características del sensor PIR y las condiciones ambientales. Por lo tanto, es recomendable calibrar el sensor según tus necesidades específicas.
