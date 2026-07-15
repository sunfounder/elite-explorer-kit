.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones festivas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _new_dac:

Convertidor Digital a Analógico (DAC)
=======================================

El Arduino Uno R4 WiFi viene equipado con una característica integrada de DAC (Convertidor Digital a Analógico). Un DAC es crucial para convertir señales digitales en sus contrapartes analógicas, una funcionalidad especialmente vital en aplicaciones como el procesamiento de audio, la generación de señales analógicas y otros escenarios que requieren una salida analógica precisa.

El DAC del Uno R4 WiFi cuenta con una resolución de hasta 12 bits, ofreciendo capacidades de salida analógica verdadera que superan a las de los pines PWM.

.. image:: img/07_dac.png
  :width: 70%

Reproducir Música con DAC
++++++++++++++++++++++++++++++

**Diagrama del Circuito**

.. image:: img/07_dac_bb.png
  :width: 100%
  :align: center

**Subir el Código**

Abre el archivo ``07-dac.ino`` ubicado en ``elite-explorer-kit-main\r4_new_feature\07-dac``, o copia el siguiente código en tu Arduino IDE.

.. note:: 
    Coloca el archivo ``pitches.h`` en el mismo directorio que el código para asegurar un funcionamiento adecuado.

.. literalinclude:: /_code/pitches.h
   :language: cpp
   :caption: pitches.h

.. literalinclude:: /_code/07_dac.ino
   :language: cpp
   :linenos:
   :caption: 07-dac.ino

Este proyecto utiliza Arduino y el DAC (Convertidor Digital a Analógico) para reproducir la icónica canción de Super Mario Bros. Utiliza una biblioteca llamada ``analogWave`` para la generación de ondas sinusoidales y otra biblioteca, ``pitches.h``, para definir las frecuencias de las notes.

- ``melody[]``: Este array contiene las notes que se van a tocar junto con sus duraciones. Las notes están representadas por tonos predefinidos (por ejemplo, ``NOTE_E5``) y las duraciones están representadas en términos de beats (por ejemplo, 4 significa una negra). Puedes intentar componer tu propia melodía cambiando las notes y duraciones en el array melody[]. Si te interesa, hay un repositorio en GitHub (|link_arduino_songs|) que proporciona código Arduino para tocar diferentes canciones. Aunque su enfoque puede ser diferente a este proyecto, puedes referirte a sus notes y duraciones. (Simplemente reemplaza la ``melody[]`` en la pista correspondiente con el código de este proyecto).

- ``tempo``: El tempo para este proyecto está configurado a 200 BPM (Beats Per Minute), lo que se usa para calcular la duración de cada note. Modificar este valor cambiará la velocidad de la interpretación de la canción.

- **Generador de Onda Sinusoidal**: La función ``sine`` de la biblioteca ``analogWave`` inicializa un generador de ondas sinusoidales de 10 Hz, que se utiliza para emitir las notes a través del DAC.

- **Duración de la note**: Basado en el tempo establecido y la cantidad de beats para cada note, se calcula la duración de cada note.

- **Reproducir y Pausar**: Cada note se reproduce durante el 85% de su duración calculada, seguida de una pausa del 15% para distinguir entre las notes.

- **Bucle**: Al completar la melodía, el código se reinicia automáticamente y comienza a reproducir nuevamente.

Este es un ejemplo que demuestra cómo usar Arduino y hardware externo (DAC) para generar música. También muestra cómo usar arrays y bucles para simplificar la lógica de la reproducción musical.


**Referencia**

- |link_r4_dac|
