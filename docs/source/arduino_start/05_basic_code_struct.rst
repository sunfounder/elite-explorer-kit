.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

Estructura del programa Arduino
=======================================

Vamos a echar un vistazo al nuevo archivo de sketch. Aunque tiene unas pocas líneas de código, en realidad es un sketch "vacío". 
Subir este sketch a la placa de desarrollo no causará ningún efecto.

.. code-block:: C

    void setup() {
    // pon tu código de configuración aquí, para ejecutarse una vez:

    }

    void loop() {
    // pon tu código principal aquí, para ejecutarse repetidamente:

    }

Si eliminamos ``setup()`` y ``loop()`` y hacemos que el sketch sea un archivo realmente ``en blanco``, verás que no pasa la verificación. 
Son el equivalente al esqueleto humano y son indispensables.

Durante la ejecución del sketch, primero se ejecuta ``setup()``, y el código dentro de ella (dentro de ``{}``) se ejecuta después de que la placa esté encendida o reiniciada, y solo una vez. 
``loop()`` se usa para escribir la función principal, y el código dentro de ella se ejecutará en un bucle después de que ``setup()`` se haya ejecutado.

Para entender mejor ``setup()`` y ``loop()``, vamos a utilizar cuatro sketches. Su propósito es hacer que el LED a bordo del Arduino parpadee. Por favor, ejecuta cada experimento por turno y registra sus efectos específicos.

* Sketch 1: Hacer que el LED a bordo parpadee continuamente.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // pon tu código de configuración aquí, para ejecutarse una vez:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // pon tu código principal aquí, para ejecutarse repetidamente:
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Sketch 2: Hacer que el LED a bordo parpadee solo una vez. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // pon tu código de configuración aquí, para ejecutarse una vez:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // pon tu código principal aquí, para ejecutarse repetidamente:
    }

* Sketch 3: Hacer que el LED a bordo parpadee lentamente una vez y luego parpadee rápidamente. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // pon tu código de configuración aquí, para ejecutarse una vez:
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // pon tu código principal aquí, para ejecutarse repetidamente:
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Sketch 4: Reportar un error.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // pon tu código de configuración aquí, para ejecutarse una vez:
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // pon tu código principal aquí, para ejecutarse repetidamente:
    }    

Con la ayuda de estos sketches, podemos resumir varias características de ``setup-loop``.

* ``loop()`` se ejecutará repetidamente después de que la placa esté encendida. 
* ``setup()`` se ejecutará solo una vez después de que la placa esté encendida. 
* Después de que la placa esté encendida, ``setup()`` se ejecutará primero, seguido de ``loop()``. 
* El código debe escribirse dentro del alcance de ``{}`` de ``setup()`` o ``loop()``, fuera del marco será un error.

.. note::  
    Declaraciones como ``digitalWrite(13,HIGH)`` se utilizan para controlar el LED a bordo, y hablaremos sobre su uso en detalle en capítulos posteriores.
