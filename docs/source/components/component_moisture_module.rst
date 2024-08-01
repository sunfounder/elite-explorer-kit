.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_soil_moisture:

Módulo de Humedad del Suelo
================================

.. image:: img/soil_mositure.png

* GND: Tierra
* VCC: Fuente de alimentación, 3.3v~5V
* AOUT: Salida del valor de humedad del suelo, cuanto más húmedo esté el suelo, menor será su valor.

Este sensor capacitivo de humedad del suelo es diferente de la mayoría de los sensores resistivos en el mercado, ya que utiliza el principio de inducción capacitiva para detectar la humedad del suelo. Esto evita el problema de que los sensores resistivos son altamente susceptibles a la corrosión y extiende significativamente su vida útil.

Está hecho de materiales resistentes a la corrosión y tiene una excelente vida útil. Insértelo en el suelo alrededor de las plantas y monitoree los datos de humedad del suelo en tiempo real. El módulo incluye un regulador de voltaje integrado que le permite operar en un rango de voltaje de 3.3 ~ 5.5 V. Es ideal para microcontroladores de bajo voltaje con suministros de 3.3 V y 5 V.

El esquema de hardware del sensor capacitivo de humedad del suelo se muestra a continuación.

.. image:: img/solid_schematic.png

Hay un oscilador de frecuencia fija, que se construye con un IC temporizador 555. La onda cuadrada generada se alimenta al sensor como un capacitor. Sin embargo, para la señal de onda cuadrada, el capacitor tiene una cierta reactancia o, para simplificar, un resistor con un resistor óhmico puro (resistor de 10k en el pin 3) para formar un divisor de voltaje.

Cuanto mayor sea la humedad del suelo, mayor será la capacitancia del sensor. Como resultado, la onda cuadrada tiene menos reactancia, lo que reduce el voltaje en la línea de señal, y menor será el valor de la entrada analógica a través del microcontrolador.

**Especificaciones**

* Voltaje de operación: 3.3 ~ 5.5 VDC
* Voltaje de salida: 0 ~ 3.0VDC
* Corriente de operación: 5mA
* Interfaz: PH2.0-3P
* Dimensiones: 3.86 x 0.905 pulgadas (L x A)
* Peso: 15g

**Ejemplo**

* :ref:`basic_moisture` (Basic Project)
* :ref:`fun_plant_monitor` (Fun Project)


