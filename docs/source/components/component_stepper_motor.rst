.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_stepper_motor:

Motor Paso a Paso
=====================

.. image:: img/stepper_motor2.jpeg
   :align: center

Los motores paso a paso, debido a su diseño único, pueden controlarse con un alto grado de precisión sin ningún mecanismo de retroalimentación. El eje de un motor paso a paso, montado con una serie de imanes, es controlado por una serie de bobinas electromagnéticas que se cargan positiva y negativamente en una secuencia específica, moviéndolo con precisión hacia adelante o hacia atrás en pequeños "pasos".

**Principio**

Hay dos tipos de motores paso a paso, unipolares y bipolares, y es muy importante saber con qué tipo estás trabajando. En este experimento, utilizaremos un motor paso a paso unipolar.

El motor paso a paso es de cuatro fases, que utiliza una fuente de alimentación de CC unipolar. Siempre que electrifiques todas las bobinas del motor en una secuencia de tiempo adecuada, puedes hacerlo girar paso a paso. El diagrama esquemático de un motor paso a paso de cuatro fases:

.. image:: img/stepper_motor3.png
   :align: center

En la figura, en el medio del motor hay un rotor, un imán permanente en forma de engranaje. Alrededor del rotor, de 0 a 5 hay dientes. Más afuera, hay 8 polos magnéticos, con cada dos opuestos conectados por una bobina. Así forman cuatro pares de la A a la D, que se llama una fase. Tiene cuatro cables de conexión con los interruptores SA, SB, SC y SD. Por lo tanto, las cuatro fases están en paralelo en el circuito, y los dos polos magnéticos en una fase están en serie.

**Cómo funciona un motor paso a paso de 4 fases:**

Al principio, el interruptor SB está encendido, los interruptores SA, SC y SD están apagados, y los polos magnéticos de la fase B se alinean con los dientes 0 y 3 del rotor. Al mismo tiempo, los dientes 1 y 4 generan dientes escalonados con los polos de las fases C y D. Los dientes 2 y 5 generan dientes escalonados con los polos magnéticos de las fases D y A. Cuando el interruptor SC está encendido, los interruptores SB, SA y SD están apagados, el rotor gira bajo el campo magnético de la bobina de la fase C y entre los dientes 1 y 4. Luego, los dientes 1 y 4 se alinean con los polos magnéticos de la fase C. Mientras que los dientes 0 y 3 generan dientes escalonados con los polos de las fases A y B, y los dientes 2 y 5 generan dientes escalonados con los polos magnéticos de las fases A y D. La situación similar continúa. Energiza las fases A, B, C y D en orden, y el rotor girará en el orden de A, B, C y D.

El motor paso a paso de cuatro fases tiene tres modos de operación: cuatro pasos simples, cuatro pasos dobles y ocho pasos. El ángulo de paso para los cuatro pasos simples y los cuatro pasos dobles es el mismo, pero el torque de accionamiento para los cuatro pasos simples es menor. El ángulo de paso de los ocho pasos es la mitad que el de los cuatro pasos simples y los cuatro pasos dobles. Por lo tanto, el modo de operación de ocho pasos puede mantener un alto torque de accionamiento y mejorar la precisión de control. En este experimento, dejamos que el motor paso a paso trabaje en el modo de ocho pasos.

**Módulo ULN2003**

.. image:: img/uln2003.png
    :align: center

Para aplicar el motor en el circuito, se necesita usar una placa controladora. El Driver de Motor Paso a Paso ULN2003 es un circuito inversor de 7 canales. Es decir, cuando el extremo de entrada está en alto nivel, el extremo de salida del ULN2003 está en bajo nivel, y viceversa. Si suministramos alto nivel a IN1 y bajo nivel a IN2, IN3 e IN4, entonces el extremo de salida OUT1 está en bajo nivel y todos los demás extremos de salida están en alto nivel. Así, D1 se enciende, el interruptor SA está encendido y el motor paso a paso gira un paso. El caso similar se repite una y otra vez. Por lo tanto, solo da al motor paso a paso una secuencia de tiempo específica y girará paso a paso. El ULN2003 aquí se usa para proporcionar secuencias de tiempo particulares para el motor paso a paso.



**Ejemplo**


* :ref:`basic_stepper_motor` (Basic Project)
* :ref:`fun_access` (Fun Project)