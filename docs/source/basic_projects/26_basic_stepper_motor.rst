.. note::

    ¡Hola! Bienvenido a la Comunidad de Entusiastas de SunFounder para Raspberry Pi, Arduino y ESP32 en Facebook. Profundiza en el mundo de Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones y sorteos festivos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _basic_stepper_motor:

Motor paso a paso
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/stepper_motor_uno.html#stepper-uno

Descripción general
----------------------

En esta lección, aprenderás a controlar motores paso a paso, específicamente el modelo 28BYJ-48, utilizando un controlador ULN2003 y un Arduino Uno R4. Los motores paso a paso se utilizan en una variedad de aplicaciones como impresoras 3D, máquinas CNC, robótica e incluso en electrodomésticos comunes. Su control preciso permite movimientos intrincados, lo que los hace ideales para proyectos que requieren alta precisión posicional.

En este proyecto, configuraremos el motor paso a paso 28BYJ-48 para que gire en direcciones tanto en el sentido de las agujas del reloj como en el sentido contrario a diferentes velocidades. Los motores paso a paso como estos se utilizan a menudo en sistemas automatizados para girar objetos o accionar mecanismos que requieren un control preciso. Por ejemplo, pueden usarse en cortinas automáticas, donde las cortinas se abren o cierran en momentos específicos o bajo condiciones específicas. Al comprender cómo controlar la rotación y la velocidad de un motor paso a paso, estarás en camino de incorporarlos en tus propios proyectos electrónicos.

Componentes necesarios
---------------------------

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
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_power`
        - \-


Conexión
----------

.. warning::
    Debido al alto consumo de energía del motor paso a paso, es aconsejable utilizar una fuente de alimentación externa de 5V en lugar de depender del Arduino.

    Aunque es posible alimentar el motor paso a paso directamente desde el Arduino, esto no se recomienda ya que puede causar ruido eléctrico en sus líneas de suministro de energía, lo que podría dañar el Arduino.

.. note::
    Para proteger el Power Pack del :ref:`cpn_power`, cárgalo completamente antes de usarlo por primera vez.

.. image:: img/26-stepper_motor_bb.png
    :align: center

Diagrama esquemático
--------------------------

.. image:: img/26_stepper_motor_schematic.png
   :align: center
   :width: 80%


Código
----------

.. note::

    * Puedes abrir el archivo ``26-stepper_motor.ino`` en la ruta ``elite-explorer-kit-main\basic_project\26-stepper_motor.rst`` directamente.
    * O copiar este código en Arduino IDE.

.. literalinclude:: /_code/26_basic_stepper_motor.ino
   :language: cpp
   :linenos:
   :caption: 26-stepper_motor.ino

Después de cargar el código en la placa Arduino Uno, el motor paso a paso 28BYJ-48 comenzará a girar, impulsado por el controlador ULN2003. Inicialmente, el motor girará en el sentido de las agujas del reloj a una velocidad de 5 RPM (revoluciones por minuto) durante una revolución completa. Después de completar la rotación en el sentido de las agujas del reloj, el motor hará una pausa de 1 segundo.

Posteriormente, el motor girará en sentido contrario a las agujas del reloj a una velocidad aumentada de 15 RPM durante otra revolución completa. Nuevamente, el motor hará una pausa de 1 segundo después de la rotación en sentido contrario a las agujas del reloj. El ciclo de rotación y pausa continuará indefinidamente mientras el Arduino permanezca encendido.

Análisis del código
----------------------

1. **Inicializar el motor paso a paso**

   .. code-block:: arduino
   
       #include <Stepper.h>  // Incluir la librería Stepper

       #define STEPS 2038                   // Definir el número de pasos por revolución para el motor
       Stepper stepper(STEPS, 2, 3, 4, 5);  // Inicializar el objeto stepper y configurar las conexiones de pines (IN1, IN3, IN2, IN4)

   Incluir el archivo de cabecera ``Stepper.h``, establecer los pasos a 2038 y luego inicializar el motor paso a paso con la función stepper().

   ``STEPS``: El número de pasos en una revolución de tu motor. Para este motor paso a paso, este valor es 2038.

   ``Stepper(steps, pin1, pin2, pin3, pin4)``: Esta función crea una nueva instancia de la clase Stepper que representa un motor paso a paso particular conectado a tu placa Arduino. Los pines pin1, pin2, pin3 y pin4 corresponden a los pines IN1, IN3, IN2 e IN4 en el controlador ULN2003.
   
2. **Función loop()**

   .. code-block:: arduino
   
      void loop() {
        // Girar en el sentido de las agujas del reloj a 5 RPM
        stepper.setSpeed(5);
        stepper.step(STEPS);  // Girar una revolución completa en el sentido de las agujas del reloj
        delay(1000);          // Esperar 1 segundo
      
        // Girar en sentido contrario a las agujas del reloj a 15 RPM
        stepper.setSpeed(15);
        stepper.step(-STEPS);  // Girar una revolución completa en sentido contrario a las agujas del reloj
        delay(1000);           // Esperar 1 segundo
      }
   
   El programa principal gira el motor paso a paso continuamente, completando un círculo completo en el sentido de las agujas del reloj a 5 RPM y luego un círculo completo en sentido contrario a las agujas del reloj a 15 RPM.

   - ``setSpeed(rpms)``: Establece la velocidad del motor en revoluciones por minuto (RPM). Esta función no hace que el motor gire, solo establece la velocidad a la que lo hará cuando llames a step().

     - ``rpms``: la velocidad a la que el motor debe girar en revoluciones por minuto - un número positivo (long).
   
   .. raw:: html

        <br/>

   - ``step(steps)``: Esta función gira el motor por un número especificado de pasos, utilizando la velocidad establecida en la llamada más reciente a setSpeed(). Es importante noter que esta función opera de manera bloqueante, lo que significa que esperará hasta que el motor haya completado su movimiento antes de permitir que el control pase a la siguiente línea en tu boceto.
   
     Por ejemplo, si establecieras la velocidad en 1 RPM y llamaras a step(2038) en un motor con 2038 pasos, tomaría un minuto completo para que esta función se ejecute. Para lograr un control más preciso, se recomienda mantener una velocidad más alta y solo mover unos pocos pasos con cada llamada a step().
   
     - ``steps``: el número de pasos para girar el motor - positivo para girar en una dirección, negativo para girar en la otra (int).

