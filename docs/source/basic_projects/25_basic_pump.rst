.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_pump:

Bomba de agua
==========================

Descripción general
----------------------

La bomba de agua también es un motor, que convierte la energía mecánica del motor u otra energía externa a través de una estructura especial para transportar el líquido.


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
    *   - :ref:`cpn_pump`
        - 
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_power`
        - \-


Conexión
------------

.. note::
    Para proteger el Power Pack del :ref:`cpn_power`, cárgalo completamente antes de usarlo por primera vez.

.. image:: img/25-pump_bb.png
    :align: center
    :width: 80%

.. raw:: html
  
  <br/> 

Diagrama esquemático
------------------------

.. image:: img/25_pump_schematic.png

Código
--------

.. note::

   * Puedes abrir el archivo ``25-pump.ino`` en la ruta ``elite-explorer-kit-main\basic_project\25-pump``. 
   * O copiar este código en **Arduino IDE**.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a530528-aa58-4306-acc9-01632ae5e99a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Coloca la manguera en la bomba y posiciónala en el recipiente. Una vez que el código se haya cargado correctamente, la bomba de agua se encenderá y permanecerá activa durante cinco segundos.
Al realizar este experimento, asegúrate de que el circuito se mantenga alejado del agua para evitar posibles cortocircuitos.


Análisis del código
------------------------

El motor puede ser impulsado proporcionando una diferencia de voltaje entre las láminas de cobre a ambos lados del motor.

.. code-block:: arduino
    
   digitalWrite(motorBI, HIGH);
   digitalWrite(motorFI, LOW);