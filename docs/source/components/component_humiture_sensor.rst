.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_dht11:

Módulo Sensor de Humedad y Temperatura
=============================================

El sensor digital de temperatura y humedad DHT11 es un sensor compuesto que contiene una salida de señal digital calibrada de temperatura y humedad. 
La tecnología de recolección de módulos digitales dedicados y la tecnología de sensores de temperatura y humedad se aplican para asegurar que el producto tenga alta fiabilidad y excelente estabilidad a largo plazo.

Solo hay tres pines disponibles para su uso: VCC, GND y DATA. 
El proceso de comunicación comienza con la línea DATA enviando señales de inicio al DHT11, y el DHT11 recibe las señales y devuelve una señal de respuesta. 
Luego, el host recibe la señal de respuesta y comienza a recibir datos de humedad de 40 bits (8 bits de humedad entera + 8 bits de humedad decimal + 8 bits de temperatura entera + 8 bits de temperatura decimal + 8 bits de suma de verificación).

.. image:: img/Dht11.png

* |link_dht11_datasheet|

**Ejemplo**

* :ref:`basic_humiture_sensor` (Basic Project)
* :ref:`fun_plant_monitor` (Fun Project)
* :ref:`iot_arduino_cloud` (IoT Project)
* :ref:`iot_ble_home` (IoT Project)