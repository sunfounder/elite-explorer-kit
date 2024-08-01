.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

El 74HC595 consiste en un registro de desplazamiento de 8 bits y un registro de almacenamiento con salidas paralelas de tres estados. Convierte la entrada serial en salida paralela para que puedas ahorrar puertos IO de un MCU.
Cuando MR (pin10) está en nivel alto y OE (pin13) está en nivel bajo, los datos se ingresan en el flanco de subida de SHcp y van al registro de memoria a través del flanco de subida de SHcp. Si los dos relojes están conectados juntos, el registro de desplazamiento siempre está un pulso antes que el registro de memoria. Hay un pin de entrada de desplazamiento serial (Ds), un pin de salida serial (Q) y un botón de reinicio asíncrono (nivel bajo) en el registro de memoria. El registro de memoria emite un bus con un paralelo de 8 bits y en tres estados. Cuando OE está habilitado (nivel bajo), los datos en el registro de memoria se envían al bus.

* |link_74hc595_datasheet|

.. image:: img/74hc595_pin.png
    :width: 600

Pines del 74HC595 y sus funciones:

* **Q0-Q7**: Pines de salida de datos paralelos de 8 bits, capaces de controlar directamente 8 LEDs o 8 pines de una pantalla de 7 segmentos.
* **Q7’**: Pin de salida en serie, conectado a DS de otro 74HC595 para conectar múltiples 74HC595 en serie.
* **MR**: Pin de reinicio, activo en nivel bajo.
* **SHcp**: Entrada de secuencia de tiempo del registro de desplazamiento. En el flanco de subida, los datos en el registro de desplazamiento se mueven sucesivamente un bit, es decir, los datos en Q1 se mueven a Q2, y así sucesivamente. En el flanco de bajada, los datos en el registro de desplazamiento permanecen sin cambios.
* **STcp**: Entrada de secuencia de tiempo del registro de almacenamiento. En el flanco de subida, los datos en el registro de desplazamiento se mueven al registro de memoria.
* **CE**: Pin de habilitación de salida, activo en nivel bajo.
* **DS**: Pin de entrada de datos seriales.
* **VCC**: Voltaje de suministro positivo.
* **GND**: Tierra.

**Ejemplo**

* :ref:`basic_74hc595` (Basic Project)
* :ref:`fun_digital_dice` (Fun Project)
