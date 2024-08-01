.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_audio_speaker:

Módulo de Audio y Altavoz
=============================

**Módulo Amplificador de Audio**

.. image:: img/audio_module.jpg
    :width: 500
    :align: center

El Módulo Amplificador de Audio contiene un chip amplificador de audio HXJ8002. Este chip es un amplificador de potencia con baja fuente de alimentación, que puede proporcionar 3W de potencia de audio promedio para una carga BTL de 3Ω con baja distorsión armónica (bajo el umbral de distorsión del 10% a 1KHz) a partir de una fuente de alimentación de 5V DC. Este chip puede amplificar señales de audio sin ningún capacitor de acoplamiento o bootstrap.

El módulo puede ser alimentado por una fuente de energía de 2.0V a 5.5V DC con una corriente de operación de 10mA (0.6uA para corriente de modo de espera típico) y producir un sonido amplificado potente en un altavoz de impedancia de 3Ω, 4Ω o 8Ω. Este módulo tiene un circuito mejorado para reducir significativamente el ruido de transición en los momentos de encendido y apagado. Su tamaño pequeño junto con su alta eficiencia y bajo consumo de energía lo hacen aplicable en proyectos portátiles y alimentados por batería y microcontroladores.  

* **IC**: HXJ8002
* **Voltaje de Entrada**: 2V ~ 5.5V
* **Corriente en Modo de Espera**: 0.6uA (valor típico)
* **Potencia de Salida**: 3W (carga de 3Ω), 2.5W (carga de 4Ω), 1.5W (carga de 8Ω)
* **Impedancia de Altavoz de Salida**: 3Ω, 4Ω, 8Ω
* **Tamaño**: 19.8mm x 14.2mm

**Altavoz**

.. image:: img/speaker_pic.png
    :width: 300
    :align: center

* **Tamaño**: 20x30x7mm
* **Impedancia**: 8Ω
* **Potencia Nominal de Entrada**: 1.5W
* **Potencia Máxima de Entrada**: 2.0W
* **Longitud del Cable**: 10cm

.. image:: img/2030_speaker.png

El cuadro de tamaños es el siguiente:

* :download:`2030 Speaker Datasheet <https://github.com/sunfounder/sf-pdf/raw/master/datasheet/2030-speaker-datasheet.pdf>`


**Ejemplo**

* :ref:`basic_audio_speaker` (Basic Project)
* :ref:`fun_welcome` (Fun Project)
* :ref:`fun_fruit_piano` (Fun Project)
* :ref:`new_dac`

