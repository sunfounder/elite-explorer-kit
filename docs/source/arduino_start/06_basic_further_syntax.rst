.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!


Reglas para escribir sketches
================================

Si le pides a un amigo que encienda las luces, puedes decir "Enciende las luces." o "Luces encendidas, amigo.", puedes usar cualquier tono de voz que quieras.

Sin embargo, si quieres que la placa Arduino haga algo por ti, necesitas seguir las reglas de escritura de programas de Arduino para escribir los comandos.

Este capítulo contiene las reglas básicas del lenguaje Arduino y te ayudará a entender cómo traducir el lenguaje natural en código.

Por supuesto, este es un proceso que toma tiempo para familiarizarse y también es la parte más propensa a errores para los principiantes, así que si cometes errores con frecuencia, está bien, solo inténtalo unas cuantas veces más.


Punto y coma ``;``
-----------------------

Al igual que al escribir una carta, donde pones un punto al final de cada oración como el final, el lenguaje Arduino requiere que uses ``;`` para indicar a la placa el final del comando.

Tomemos el ejemplo familiar del "parpadeo del LED a bordo". Un sketch saludable debería verse así.

Ejemplo:

.. code-block:: C

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

A continuación, echemos un vistazo a los dos siguientes sketches y adivinemos si pueden ser reconocidos correctamente por Arduino antes de ejecutarlos.

Sketch A:

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // pon tu código de configuración aquí, para ejecutarse una vez:
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // pon tu código principal aquí, para ejecutarse repetidamente:
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Sketch B:

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // pon tu código de configuración aquí, para ejecutarse una vez:
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // pon tu código principal aquí, para ejecutarse repetidamente:
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

El resultado es que **Sketch A** reporta un error y **Sketch B** se ejecuta.

* Los errores en **Sketch A** son la falta de ``;`` y aunque parece normal, Arduino no puede leerlo.
* **Sketch B** parece anti-humano, pero de hecho, la sangría, los saltos de línea y los espacios en las declaraciones son cosas que no existen en los programas Arduino, por lo que para el compilador de Arduino, se ve igual que en el ejemplo.

Sin embargo, por favor no escribas tu código como **Sketch B**, porque generalmente son personas naturales las que escriben y ven el código, así que no te pongas en problemas.

Llaves ``{}``
------------------

``{}`` es el componente principal del lenguaje de programación de Arduino, y deben aparecer en pares. 
Una mejor convención de programación es insertar una estructura que requiera llaves escribiendo directamente la llave derecha después de escribir la llave izquierda, y luego mover el cursor entre las llaves para insertar la declaración.


Comentario ``//``
---------------------

El comentario es la parte del sketch que el compilador ignora. Usualmente se utilizan para decir a otros cómo funciona el programa.

Si escribimos dos barras diagonales adyacentes en una línea de código, el compilador ignorará cualquier cosa hasta el final de la línea.

Si creamos un nuevo sketch, viene con dos comentarios, y si eliminamos estos dos comentarios, el sketch no se verá afectado de ninguna manera.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // pon tu código de configuración aquí, para ejecutarse una vez:

    }

    void loop() {
        // pon tu código principal aquí, para ejecutarse repetidamente:

    }

El comentario es muy útil en la programación, y se enumeran varios usos comunes a continuación.

* Uso A: Decirte a ti mismo o a otros lo que hace esta sección de código.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); //Establecer el pin 13 en modo de salida, controla el LED a bordo
    }

    void loop() {
        digitalWrite(13,HIGH); // Activar el LED a bordo estableciendo el pin 13 en alto
        delay(500); // Mantener el estado durante 500 ms
        digitalWrite(13,LOW); // Apagar el LED a bordo
        delay(500);// Mantener el estado durante 500 ms
    }

* Uso B: Invalidar temporalmente algunas declaraciones (sin eliminarlas) y descomentarlas cuando necesites usarlas, así no tendrás que reescribirlas. Esto es muy útil al depurar el código y tratar de localizar errores en el programa.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13,HIGH);
        // delay(1000);
        // digitalWrite(13,LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    Usa el atajo ``Ctrl+/`` para ayudarte a comentar o descomentar tu código rápidamente.

Comentario ``/**/``
--------------------------

Al igual que ``//`` para comentarios. Este tipo de comentario puede tener más de una línea, y una vez que el compilador lee ``/*``, ignora todo lo que sigue hasta que encuentra ``*/``.

Ejemplo 1:

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Parpadeo */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        El siguiente código hará que el LED a bordo parpadee
        Puedes modificar el número en delay() para cambiar la frecuencia de parpadeo
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }



``#define``
--------------

Esta es una herramienta útil de C++.

.. code-block:: C

    #define identificador cadena-de-texto

El compilador reemplaza automáticamente ``identificador`` con ``cadena-de-texto`` cuando lo lee, que generalmente se usa para definiciones de constantes.

Como ejemplo, aquí hay un sketch que usa define, lo que mejora la legibilidad del código.

.. code-block:: C
    :emphasize-lines: 1,2

    #define LED_BORDO 13
    #define TIEMPO_RETRASO 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

Para el compilador, en realidad se ve así.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

Podemos ver que el ``identificador`` es reemplazado y no existe dentro del programa.
Por lo tanto, hay varias advertencias al usarlo.

1. Una ``cadena-de-texto`` solo puede ser modificada manualmente y no puede ser convertida en otros valores por aritmética en el programa.

2. Evita usar símbolos como ``;``. Por ejemplo.

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

El compilador lo reconocerá como lo siguiente, lo que será reportado como un error.

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;,OUTPUT); 
    }

    void loop() {
        digitalWrite(13;,HIGH); 
    }

.. note:: 
    Una convención de nomenclatura para ``#define`` es capitalizar ``identificador`` para evitar confusiones con variables.
