.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_passive_buzzer:

Zumbador Pasivo
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_tone_notone.html#ar-passive-buzzer


Descripción general
-------------------------

En este proyecto, utilizaremos dos funciones para hacer vibrar el zumbador pasivo y producir sonido. La función ``tone()`` genera una onda cuadrada con una frecuencia especificada (y un ciclo de trabajo del 50%) en un pin. Se puede especificar una duración, o la onda continuará hasta que se llame a ``noTone()``.
Al igual que el zumbador activo, el zumbador pasivo también utiliza la inducción electromagnética para funcionar.
La diferencia es que un zumbador pasivo no tiene su propia fuente de oscilación, por lo que no emitirá sonido si se utilizan señales de CC. Sin embargo, esto permite que el zumbador pasivo ajuste su propia frecuencia de oscilación y produzca diferentes notes como "do, re, mi, fa, sol, la, ti".

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
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|


Conexión
----------------------

.. note::
    Al conectar el zumbador, asegúrate de verificar sus pines. El pin más largo es el ánodo y el más corto es el cátodo. Es importante no mezclarlos, ya que hacerlo impedirá que el zumbador produzca sonido.

.. image:: img/16-passive_buzzer_bb.png
    :align: center
    :width: 70%

Diagrama esquemático
-----------------------

.. image:: img/16_passive_buzzer_schematic.png
    :align: center
    :width: 80%

Código
---------------

.. note::

    * Puedes abrir el archivo ``16-passive_buzzer.ino`` directamente en la ruta ``elite-explorer-kit-main\basic_project\16-passive_buzzer``.
    * O copia este código en Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7936cad2-3605-40a0-a9fc-573f934ab6b1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
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

   * ``buzzerPin`` es el pin digital en el Arduino donde se conecta el zumbador.

   * ``melody[]`` es un arreglo que almacena la secuencia de notes a reproducir.

   * ``noteDurations[]`` es un arreglo que almacena la duración de cada note en la melodía.

   .. code-block:: arduino
   
      const int buzzerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. Reproducir la melodía:

   * El bucle ``for`` itera sobre cada note de la melodía.

   * La función ``tone()`` reproduce una note en el zumbador por una duración específica.

   * Se añade una demora entre notes para distinguirlas.

   * La función ``noTone()`` detiene el sonido.



   .. code-block:: arduino
   
      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(buzzerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(buzzerPin);
        }
      }

4. Función de bucle vacía:
   Dado que la melodía se reproduce solo una vez en el setup, no hay código en la función loop.

5. Siéntete libre de experimentar con la alteración de las notes y duraciones en los arreglos ``melody[]`` y ``noteDurations[]`` para crear tus propias melodías. Si te interesa, hay un repositorio en GitHub (|link_arduino-songs|) que ofrece código Arduino para reproducir varias canciones. Aunque su enfoque puede diferir de este proyecto, puedes consultar sus notes y duraciones como referencia.
