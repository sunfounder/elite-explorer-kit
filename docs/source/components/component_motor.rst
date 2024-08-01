.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_motor:

Motor DC
===================

.. image:: img/motor.jpeg
    :align: center

Este es un motor de corriente continua (DC) de 3V. Cuando aplicas un nivel alto y un nivel bajo a cada uno de los dos terminales, el motor comenzará a girar.

* **Longitud**: 25mm
* **Diámetro**: 21mm
* **Diámetro del eje**: 2mm
* **Longitud del eje**: 8mm
* **Voltaje**: 3-6V
* **Corriente**: 0.35-0.4A
* **Velocidad a 3V**: 19000 RPM (Revoluciones Por Minuto)
* **Peso**: Aproximadamente 14g (por unidad)

Un motor de corriente continua (DC) es un actuador continuo que convierte la energía eléctrica en energía mecánica. Los motores DC hacen funcionar bombas rotativas, ventiladores, compresores, impulsores y otros dispositivos al producir una rotación angular continua.

Un motor DC consta de dos partes, la parte fija del motor llamada **estator** y la parte interna del motor llamada **rotor** (o **armadura** de un motor DC) que gira para producir movimiento.
La clave para generar movimiento es posicionar la armadura dentro del campo magnético del imán permanente (cuyo campo se extiende desde el polo norte hasta el polo sur). La interacción del campo magnético y las partículas cargadas en movimiento (el cable portador de corriente genera el campo magnético) produce el par que hace girar la armadura.

.. image:: img/motor_sche.png
    :align: center

La corriente fluye desde el terminal positivo de la batería a través del circuito, pasando por los cepillos de cobre hasta el conmutador, y luego a la armadura.
Pero debido a los dos huecos en el conmutador, este flujo se invierte a la mitad de cada rotación completa.
Esta inversión continua esencialmente convierte la energía DC de la batería en AC, permitiendo que la armadura experimente el par en la dirección correcta en el momento adecuado para mantener la rotación.

**Ejemplo**

* :ref:`basic_motor` (Basic Project)
* :ref:`fun_smart_fan` (Fun Project)