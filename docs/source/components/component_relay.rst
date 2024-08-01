.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_realy:

Relé
=======

.. image:: img/relay_pic.png
    :width: 200
    :align: center

Como sabemos, el relé es un dispositivo que se utiliza para proporcionar conexión entre dos o más puntos o dispositivos en respuesta a la señal de entrada aplicada. En otras palabras, los relés proporcionan aislamiento entre el controlador y el dispositivo, ya que los dispositivos pueden funcionar con CA (corriente alterna) así como con CC (corriente continua). Sin embargo, reciben señales de un microcontrolador que funciona con CC, por lo tanto, se requiere un relé para cerrar la brecha. El relé es extremadamente útil cuando necesitas controlar una gran cantidad de corriente o voltaje con una pequeña señal eléctrica.

Hay 5 partes en cada relé:

.. image:: img/relay142.jpeg

**Electroimán** - Consiste en un núcleo de hierro enrollado con una bobina de cables. Cuando se pasa electricidad a través de él, se vuelve magnético. Por lo tanto, se llama electroimán.

**Armadura** - La tira magnética móvil se conoce como armadura. Cuando la corriente fluye a través de ella, la bobina se energiza, produciendo un campo magnético que se usa para hacer o romper los puntos normalmente abiertos (N/O) o normalmente cerrados (N/C). La armadura se puede mover con corriente continua (CC) así como con corriente alterna (CA).

**Resorte** - Cuando no fluye corriente a través de la bobina del electroimán, el resorte tira de la armadura hacia atrás, por lo que el circuito no puede completarse.

Conjunto de **contactos eléctricos** - Hay dos puntos de contacto:

- Normalmente abierto: conectado cuando el relé está activado, y desconectado cuando está inactivo.

- Normalmente cerrado: no conectado cuando el relé está activado, y conectado cuando está inactivo.

**Marco moldeado** - Los relés están cubiertos de plástico para protección.

El principio de funcionamiento del relé es simple. Cuando se suministra energía al relé, la corriente comienza a fluir a través de la bobina de control; como resultado, el electroimán comienza a energizarse. Luego, la armadura es atraída hacia la bobina, bajando el contacto móvil y conectándose con los contactos normalmente abiertos. Así, el circuito con la carga se energiza. Romper el circuito sería un caso similar, ya que el contacto móvil será empujado hacia arriba a los contactos normalmente cerrados bajo la fuerza del resorte. De esta manera, el encendido y apagado del relé puede controlar el estado de un circuito de carga.


**Ejemplo**

* :ref:`basic_relay` (Basic Project)