.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_pir:

Módulo Sensor de Movimiento PIR
===================================

.. image:: img/pir_pic.png
    :width: 300
    :align: center

El sensor PIR detecta la radiación de calor infrarroja, que puede utilizarse para detectar la presencia de organismos que emiten esta radiación.

El sensor PIR está dividido en dos ranuras conectadas a un amplificador diferencial. Cuando un objeto estático se encuentra frente al sensor, ambas ranuras reciben la misma cantidad de radiación y la salida es cero. Cuando un objeto en movimiento se encuentra frente al sensor, una de las ranuras recibe más radiación que la otra, lo que hace que la salida fluctúe. Este cambio en el voltaje de salida es el resultado de la detección de movimiento.

.. image:: img/PIR_working_principle.jpg
    :width: 800

Después de cablear el módulo de detección, hay una inicialización de un minuto. Durante esta inicialización, el módulo emitirá señales de salida de 0 a 3 veces en intervalos. Luego, el módulo entrará en modo de espera. Mantén alejadas las interferencias de fuentes de luz y otras fuentes de la superficie del módulo para evitar operaciones incorrectas causadas por señales de interferencia. Incluso es mejor usar el módulo sin mucho viento, ya que el viento también puede interferir con el sensor.

.. image:: img/pir_back.png
    :width: 600
    :align: center


**Ajuste de Distancia**

Girando la perilla del potenciómetro de ajuste de distancia en el sentido de las agujas del reloj, el rango de distancia de detección aumenta, y el rango máximo es de aproximadamente 0-7 metros. Si se gira en sentido contrario, el rango de distancia de detección se reduce, y el rango mínimo es de aproximadamente 0-3 metros.

**Ajuste de Retardo**

Girando la perilla del potenciómetro de ajuste de retardo en el sentido de las agujas del reloj, también se puede ver un aumento en el retardo de detección. El retardo máximo puede llegar hasta 300 segundos. Por el contrario, si se gira en sentido antihorario, se puede acortar el retardo con un mínimo de 5 segundos.

**Dos Modos de Activación**

Elige diferentes modos utilizando el puente de configuración.

* **H**: Modo de activación repetible. Después de detectar el cuerpo humano, el módulo emite un nivel alto. Durante el período de retardo subsiguiente, si alguien entra en el rango de detección, la salida seguirá siendo de nivel alto.

* **L**: Modo de activación no repetible. Emite un nivel alto cuando detecta el cuerpo humano. Después del retardo, la salida cambiará automáticamente de nivel alto a nivel bajo.

**Ejemplo**

* :ref:`basic_pir` (Proyecto Básico)
* :ref:`fun_welcome` (Proyecto Divertido)
* :ref:`iot_security_system_ifttt` (Proyecto IoT)

