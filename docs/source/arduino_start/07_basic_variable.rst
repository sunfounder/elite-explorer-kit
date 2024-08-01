.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

Variable
============

La variable es una de las herramientas más poderosas y críticas en un programa. Nos ayuda a almacenar y llamar datos en nuestros programas.

El siguiente archivo de sketch utiliza variables. Almacena los números de pin del LED a bordo en la variable ``ledPin`` y un número "500" en la variable ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
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

Espera, ¿esto es un duplicado de lo que hace ``#define``? La respuesta es NO.

* El rol de ``#define`` es simplemente y directamente reemplazar texto, no se considera por el compilador como parte del programa. 
* Una ``variable``, por otro lado, existe dentro del programa y se utiliza para almacenar y llamar valores. Una variable también puede modificar su valor dentro del programa, algo que un define no puede hacer.

El archivo de sketch a continuación se auto-incrementa en la variable y hará que el LED a bordo parpadee más tiempo después de cada parpadeo.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime+200; //Cada ejecución incrementa el valor en 200
    }

Declarar una variable
--------------------------

Declarar una variable significa crear una variable. 

Para declarar una variable, necesitas dos cosas: el tipo de dato y el nombre de la variable. El tipo de dato necesita estar separado de la variable por un espacio, y la declaración de la variable necesita terminar con un ``;``.

Usemos esta variable como ejemplo.

.. code-block:: C

    int delayTime;

**Tipo de Dato**

Aquí ``int`` es un tipo de dato llamado entero, que puede usarse para almacenar enteros de -32768 a 32766. No se puede usar para almacenar decimales.

Las variables pueden contener diferentes tipos de datos además de enteros. El lenguaje Arduino (que, recuerda, es C++) tiene soporte incorporado para algunos de ellos (solo se enumeran los más frecuentemente usados y útiles):

* ``float``: Almacena un número decimal, por ejemplo 3.1415926.
* ``byte``: Puede contener números del 0 al 255.
* ``boolean``: Contiene solo dos valores posibles, ``True`` o ``False``, aunque ocupa un byte en la memoria.
* ``char``: Contiene un número de -127 a 127. Porque está marcado como un ``char``, el compilador intentará coincidirlo con un carácter del |link_ascii|.
* ``string``: Puede almacenar una cadena de caracteres, por ejemplo ``Halloween``.

**Nombre de la Variable**

Puedes establecer la variable con cualquier nombre que desees, como ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, pero hay algunas reglas básicas a seguir.

1. Describe para qué se usa. Aquí, nombré la variable delayTime, para que puedas entender fácilmente lo que hace. Funciona bien si nombro la variable ``barryAllen``, pero confunde a la persona que mira el código.

2. Usa una nomenclatura regular. Puedes usar CamelCase como lo hice yo, con la T inicial en ``delayTime`` para que sea fácil ver que la variable consiste en dos palabras. También puedes usar UnderScoreCase para escribir la variable como ``delay_time``. No afecta la ejecución del programa, pero ayudaría al programador a leer el código si usas la nomenclatura que prefieras.

3. No uses palabras clave. Similar a lo que sucede cuando escribimos "int", el Arduino IDE lo coloreará para recordarte que es una palabra con un propósito especial y no puede usarse como nombre de variable. Cambia el nombre de la variable si está coloreado.

4. No se permiten símbolos especiales. Por ejemplo, espacio, #, $, /, +, %, etc. La combinación de letras inglesas (distingue entre mayúsculas y minúsculas), guiones bajos y números (pero los números no pueden usarse como el primer carácter de un nombre de variable) es lo suficientemente rica.

**Asignar un valor a una variable**

Una vez que hemos declarado la variable, es hora de almacenar los datos. Usamos el operador de asignación (es decir, ``=``) para poner un valor en la variable.

Podemos asignar valores a la variable tan pronto como la declaremos.

.. code-block:: C

    int delayTime = 500;

It is also possible to assign a new value to it at some time.

.. code-block:: C

    int delayTime; // sin valor
    delayTime = 500; // el valor es 500
    delayTime = delayTime +200; // el valor es 700
