.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_mpr121:

MPR121
===========================

.. image:: img/mpr121.png

* **3.3V**: Fuente de alimentación
* **IRQ**: Pin de salida de interrupción de colector abierto, activo bajo
* **SCL**: Reloj I2C
* **SDA**: Datos I2C
* **ADD**: Pin de selección de dirección I2C. Conecta el pin ADDR al VSS, VDD, SDA o SCL, las direcciones I2C resultantes son 0x5A, 0x5B, 0x5C y 0x5D respectivamente
* **GND**: Tierra
* **0~11**: Electrodo 0~11, el electrodo es un sensor táctil. Típicamente, los electrodos pueden ser simplemente un trozo de metal o un cable. Pero a veces, dependiendo de la longitud del cable o del material en el que esté el electrodo, puede resultar difícil activar el sensor. Por esta razón, el MPR121 permite configurar lo que se necesita para activar y desactivar un electrodo.

**VISIÓN GENERAL DEL MPR121**

El MPR121 es la segunda generación de controladores de sensores táctiles capacitivos después del lanzamiento 
inicial de los dispositivos de la serie MPR03x. El MPR121 presenta una mayor inteligencia interna, algunas de 
las principales adiciones incluyen un mayor número de electrodos, una dirección I2C configurable por hardware, 
un sistema de filtrado ampliado con rebote y electrodos completamente independientes con auto-configuración 
incorporada. El dispositivo también cuenta con un canal de detección simulado número 13 dedicado a la detección 
de proximidad cercana utilizando las entradas de detección multiplexadas.

* |link_mpr121_datasheet|

**Características**

* Operación de bajo consumo
    • Fuente de alimentación de 1.71 V a 3.6 V
    • Corriente de suministro de 29 μA a un intervalo de muestreo de 16 ms
    • Corriente en modo de parada de 3 μA
* 12 entradas de detección de capacitancia
    • 8 entradas son multifuncionales para controlador de LED y GPIO
* Detección táctil completa
    • Auto-configuración para cada entrada de detección
    • Auto-calibración para cada entrada de detección
    • Umbral de toque/liberación y rebote para la detección táctil
* Interfaz I2C, con salida de interrupción
* Paquete QFN de 20 pines de 3 mm x 3 mm x 0.65 mm
* Rango de temperatura de funcionamiento de -40°C a +85°C

**Ejemplo**

* :ref:`basic_mpr121` (Basic Project)
* :ref:`fun_fruit_piano` (Fun Project)