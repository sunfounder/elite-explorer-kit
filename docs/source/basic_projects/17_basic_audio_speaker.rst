.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_audio_speaker:

Módulo de Audio y Altavoz
==========================

Descripción general
---------------------

En esta lección, aprenderás sobre el módulo de audio y el altavoz cuando se usan con una placa Arduino Uno. Estos componentes se utilizan ampliamente en diversas aplicaciones electrónicas, incluyendo juguetes musicales, sistemas de sonido DIY, alarmas e incluso instrumentos musicales sofisticados. Combinando un Arduino con un módulo de audio y un altavoz, puedes crear un reproductor de melodías simple pero efectivo.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_audio_speaker`
        - \-

Conexión
----------------------

Dado que este es un amplificador mono, puedes conectar el pin 8 al pin L o R del módulo amplificador de audio.

La resistencia de 10K se utiliza para reducir el ruido de alta frecuencia y bajar el volumen del audio. Forma un filtro RC de paso bajo con la capacitancia parásita del DAC y el amplificador de audio. Este filtro disminuye la amplitud de las señales de alta frecuencia, reduciendo efectivamente el ruido de alta frecuencia. Por lo tanto, agregar la resistencia de 10K hace que la música suene más suave y elimina el ruido de alta frecuencia no deseado.

.. image:: img/17-audio_bb.png
    :align: center
    :width: 100%

Diagrama esquemático
-----------------------

.. image:: img/17-audio_schematic.png
    :align: center
    :width: 80%

Código
---------------

.. note::

    * Puedes abrir el archivo ``17-speaker.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\17-speaker``.
    * O copia este código en Arduino IDE.

.. literalinclude:: /_code/pitches.h
   :language: cpp
   :caption: pitches.h

.. literalinclude:: /_code/17_basic_audio_speaker.ino
   :language: cpp
   :linenos:
   :caption: 17-speaker.ino
    
Al terminar de cargar el código en la placa R4, escucharás una melodía que contiene siete notes.

Análisis del Código
------------------------

1. Incluir la biblioteca de tonos:
   Esta biblioteca proporciona los valores de frecuencia para varias notes musicales, permitiendo usar noteción musical en tu código.

   .. note::
      Coloca el archivo ``pitches.h`` en el mismo directorio que el código para asegurar un funcionamiento correcto. |link_pitches|

      .. image:: img/16_passive_buzzer_piches.png

   .. code-block:: arduino
       
      #include "pitches.h"

2. Definir constantes y arreglos:

   * ``speakerPin`` es el pin digital en el Arduino donde se conecta el altavoz.

   * ``melody[]`` es un arreglo que almacena la secuencia de notes a reproducir.

   * ``noteDurations[]`` es un arreglo que almacena la duración de cada note en la melodía.

   .. code-block:: arduino
   
      const int speakerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. Reproducir la melodía:

   * El bucle ``for`` itera sobre cada note de la melodía.

   * La función ``tone()`` reproduce una note en el altavoz por una duración específica.

   * Se añade una demora entre notes para distinguirlas.

   * La función ``noTone()`` detiene el sonido.



   .. code-block:: arduino
   
      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(speakerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(speakerPin);
        }
      }

4. Función de bucle vacía:
   Dado que la melodía se reproduce solo una vez en el setup, no hay código en la función loop.

5. Siéntete libre de experimentar con la alteración de las notes y duraciones en los arreglos ``melody[]`` y ``noteDurations[]`` para crear tus propias melodías. Si te interesa, hay un repositorio en GitHub (|link_arduino-songs|) que ofrece código Arduino para reproducir varias canciones. Aunque su enfoque puede diferir de este proyecto, puedes consultar sus notes y duraciones como referencia.
