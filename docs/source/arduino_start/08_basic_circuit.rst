.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

Cómo construir el circuito
==============================

Muchas de las cosas que usas todos los días están alimentadas por electricidad, como las luces de tu casa y la computadora que estás leyendo.

Para usar electricidad, debes construir un circuito eléctrico. Básicamente, un circuito es un camino por el cual fluye la electricidad, o un circuito electrónico, y está compuesto por dispositivos y componentes eléctricos (aparatos) que están conectados de una cierta manera, como resistencias, condensadores, fuentes de alimentación y interruptores.

.. image:: img/circuit.png
    :align: center
    :width: 250

.. raw:: html
    
    <br/>

Un circuito es un camino cerrado en el que los electrones se mueven para crear una corriente eléctrica. Para que fluya la corriente, debe haber un camino conductor entre el terminal positivo de la fuente de alimentación y el terminal negativo, lo que se llama un circuito cerrado (si está roto, se llama circuito abierto).

La placa Arduino tiene algunos pines de salida de energía (positivos) y algunos pines de tierra (negativos).
Puedes usar estos pines como los lados positivo y negativo de la fuente de alimentación conectando la fuente de energía a la placa.

.. image:: img/08_circuit_1.png
    :align: center
    :width: 70%

Con electricidad, puedes crear obras con luz, sonido y movimiento.
Puedes encender un LED conectando el pin largo al terminal positivo y el pin corto al terminal negativo.
Sin embargo, hacerlo directamente puede dañar rápidamente no solo el LED, sino también arriesgar dañar los pines de tu placa UNO R4. Para evitar esto, es esencial agregar una resistencia de 1kΩ en el circuito, protegiendo tanto el LED como los pines de la UNO R4.

El circuito que forman se muestra a continuación.

.. image:: img/08_circuit_2.png
    :align: center
    :width: 65%

.. raw:: html
    
    <br/>

En este momento puedes tener preguntas: ¿cómo construyo este circuito? ¿Sostengo los cables con la mano o pego los pines y los cables?

En esta situación, las protoboards sin soldadura serán tus mejores aliadas.

.. _bc_bb:


¡Hola, Protoboard!
------------------------------

Una protoboard es una placa de plástico rectangular con un montón de pequeños agujeros. 
Estos agujeros nos permiten insertar fácilmente componentes electrónicos y construir circuitos electrónicos. 
Las protoboards no fijan permanentemente los componentes electrónicos, por lo que podemos reparar fácilmente un circuito y comenzar de nuevo si algo sale mal.

.. note::
    No es necesario utilizar herramientas especiales para usar las protoboards. Sin embargo, muchos componentes electrónicos son muy pequeños, y un par de pinzas pueden ayudarnos a recoger mejor las piezas pequeñas.

En Internet, podemos encontrar mucha información sobre protoboards.


* `Cómo usar una Protoboard - Science Buddies <https://www.sciencebuddies.org/science-fair-projects/references/how-to-use-a-breadboard#pth-smd>`_

* `¿Qué es una PROTOBOARD? - Makezine <https://cdn.makezine.com/uploads/2012/10/breadboardworkshop.pdf>`_


Aquí hay algunas cosas que debes saber sobre las protoboards.

.. image:: ../components/img/breadboard_internal.png
    :align: center
    :width: 85%

.. raw:: html

   <br/>

#. Cada grupo de media fila (como la columna A-E en la fila 1 o la columna F-J en la fila 3) está conectado. Por lo tanto, si una señal eléctrica fluye desde A1, puede salir de B1, C1, D1, E1, pero no de F1 o A2.

#. En la mayoría de los casos, ambos lados de la protoboard se utilizan como buses de energía, y los agujeros en cada columna (alrededor de 50 agujeros) están conectados entre sí. Como regla general, las fuentes de alimentación positivas se conectan a los agujeros cerca del cable rojo, y las fuentes de alimentación negativas se conectan a los agujeros cerca del cable azul.

**¡Sigamos la dirección de la corriente para construir el circuito!**

.. image:: img/08_circuit_3.png
    :align: center
    :width: 60%

.. raw:: html
    
    <br/>

1. En este circuito, usamos el pin de 5V de la placa para alimentar el LED. Usa un cable de salto macho a macho (M2M) para conectarlo al bus de energía rojo.
#. Para proteger el LED y los pines de la UNO R4, la corriente debe pasar a través de una resistencia de 1k ohm. Conecta un extremo (cualquiera de los dos extremos) de la resistencia al bus de energía rojo, y el otro extremo a la fila libre de la protoboard.

   .. note::
        El anillo de color de la resistencia de 1000 ohm :ref:`cpn_resistor` es rojo, negro, negro, marrón y marrón.

#. Si recoges el LED, verás que una de sus patas es más larga que la otra. Conecta la pata más larga a la misma fila que la resistencia, y la pata más corta a la otra fila.

   .. note::
        La pata más larga es el ánodo, que representa el lado positivo del circuito; la pata más corta es el cátodo, que representa el lado negativo.

        El ánodo necesita estar conectado al pin GPIO a través de una resistencia; el cátodo necesita estar conectado al pin GND.

#. Usando un cable de salto macho a macho (M2M), conecta la pata corta del LED al bus de energía negativo de la protoboard.
#. Conecta el pin GND de la placa al bus de energía negativo usando un cable de salto.

Cuidado con los cortocircuitos
-----------------------------------
Los cortocircuitos pueden ocurrir cuando dos componentes que no deberían estar conectados están "accidentalmente" conectados. 
Este kit incluye resistencias, transistores, condensadores, LED, etc. que tienen patas de metal largas que pueden chocar entre sí y causar un cortocircuito. Algunos circuitos simplemente se previenen de funcionar correctamente cuando ocurre un cortocircuito. Ocasionalmente, un cortocircuito puede dañar los componentes permanentemente, especialmente entre la fuente de alimentación y el bus de tierra, causando que el circuito se caliente mucho, derritiendo el plástico en la protoboard e incluso quemando los componentes.

Por lo tanto, siempre asegúrate de que las patas de todos los componentes electrónicos en la protoboard no se toquen entre sí.

Dirección del circuito
-------------------------------
Los circuitos tienen una orientación, y la orientación juega un papel importante en ciertos componentes electrónicos. Hay algunos dispositivos con polaridad, lo que significa que deben conectarse correctamente según sus polos positivo y negativo. Los circuitos construidos con la orientación incorrecta no funcionarán correctamente.

.. image:: img/08_circuit_4.png
    :align: center
    :width: 60%

.. raw:: html
    
    <br/>

Si inviertes el LED en este simple circuito que construimos anteriormente, descubrirás que ya no funciona.

En cambio, algunos dispositivos no tienen dirección, como las resistencias en este circuito, por lo que puedes intentar invertirlas sin afectar el funcionamiento normal de los LED.

La mayoría de los componentes y módulos con etiquetas como "+", "-", "GND", "VCC" o que tienen patas de diferentes longitudes deben conectarse al circuito de una manera específica.

Protección del circuito
-------------------------------------

La corriente es la tasa a la que los electrones fluyen a través de un punto en un circuito eléctrico completo. En su nivel más básico, corriente = flujo. Un amperio (AM-pir), o amp, es la unidad internacional utilizada para medir la corriente. Expresa la cantidad de electrones (a veces llamada "carga eléctrica") que fluyen a través de un punto en un circuito durante un tiempo determinado.

La fuerza impulsora (voltaje) detrás del flujo de corriente se llama voltaje y se mide en voltios (V).

La resistencia (R) es la propiedad del material que restringe el flujo de corriente, y se mide en ohmios (Ω).

Según la ley de Ohm (siempre que la temperatura permanezca constante), la corriente, el voltaje y la resistencia son proporcionales.
La corriente de un circuito es proporcional a su voltaje e inversamente proporcional a su resistencia.

Por lo tanto, corriente (I) = voltaje (V) / resistencia (R).

* `Ohm's law - Wikipedia <https://en.wikipedia.org/wiki/Ohm%27s_law>`_

Sobre la ley de Ohm podemos hacer un experimento sencillo.

.. image:: img/08_circuit_5.png
    :width: 55%

Al cambiar el cable que conecta 5V a 3.3V, el LED se atenúa.
Si cambias la resistencia de 1000 ohm a 2000 ohm (anillo de color: rojo, negro, negro, marrón y marrón), noterás que el LED se atenúa más que antes. Cuanto mayor sea la resistencia, más tenue será el LED.

La mayoría de los módulos empaquetados solo requieren acceso al voltaje adecuado (generalmente 3.3V o 5V), como el módulo ultrasónico.

Sin embargo, en tus circuitos construidos por ti mismo, necesitas estar al tanto del voltaje de suministro y el uso de resistencias para los dispositivos eléctricos.

Como ejemplo, los LED generalmente consumen 20mA de corriente, y su caída de voltaje es de aproximadamente 1.8V. Según la ley de Ohm, si usamos una fuente de alimentación de 5V, necesitamos conectar una resistencia mínima de 160 ohm ((5-1.8)/20mA) para no quemar el LED.

Control del circuito con Arduino
--------------------------------

Ahora que tenemos una comprensión básica de la programación de Arduino y los circuitos electrónicos, es hora de enfrentar la pregunta más crítica: ¿Cómo controlar circuitos con Arduino?

En pocas palabras, la forma en que Arduino controla un circuito es cambiando el nivel de los pines en la placa. Por ejemplo, al controlar un LED a bordo, se escribe una señal de nivel alto o bajo en el pin 13.

Ahora intentemos programar la placa Arduino para controlar el parpadeo del LED en la protoboard. Construye el circuito de modo que el LED esté conectado al pin 9.

.. image:: img/08_circuit_6.png
    :width: 400
    :align: center

A continuación, sube este sketch a la placa de desarrollo Arduino.

.. code-block:: C

    int ledPin = 9;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Este sketch es muy similar al que usamos para controlar el parpadeo del LED a bordo, la diferencia es que el valor de ``ledPin`` se ha cambiado a 9.
Esto se debe a que esta vez estamos tratando de controlar el nivel del pin 9.

Ahora puedes ver el LED en la protoboard parpadeando.
