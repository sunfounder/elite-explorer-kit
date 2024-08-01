.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo.

.. _cpn_transistor:

Transistor
=============

.. image:: img/npn_pnp.png
    :width: 300

El transistor es un dispositivo semiconductor que controla la corriente por medio de corriente. Funciona amplificando una señal débil a una señal de mayor amplitud y también se utiliza como interruptor sin contacto.

Un transistor es una estructura de tres capas compuesta por semiconductores de tipo P y tipo N. Forman tres regiones internamente. La región más delgada en el medio es la base; las otras dos son ambas de tipo N o P: la región más pequeña con portadores mayoritarios intensos es la región del emisor, mientras que la otra es la región del colector. Esta composición permite que el transistor sea un amplificador. 
De estas tres regiones se generan tres polos respectivamente, que son base (b), emisor (e) y colector (c). Forman dos uniones P-N, a saber, la unión del emisor y la unión del colector. La dirección de la flecha en el símbolo del circuito del transistor indica la dirección de la unión del emisor.

* `P–N junction - Wikipedia <https://en.wikipedia.org/wiki/P-n_junction>`_

Según el tipo de semiconductor, los transistores se pueden dividir en dos grupos, los NPN y los PNP. A partir de la abreviatura, podemos decir que el primero está hecho de dos semiconductores de tipo N y uno de tipo P y que el segundo es lo contrario. Ver la figura a continuación.

.. note::
    s8550 es un transistor PNP y el s8050 es el NPN. Se ven muy similares, y necesitamos revisarlos cuidadosamente para ver sus etiquetas.

.. image:: img/transistor_symbol.png
    :width: 600

Cuando una señal de nivel alto pasa a través de un transistor NPN, se energiza. Pero un PNP necesita una señal de nivel bajo para activarse. Ambos tipos de transistores se utilizan frecuentemente para interruptores sin contacto, como en este experimento.

Coloca la etiqueta hacia nosotros y los pines hacia abajo. Los pines de izquierda a derecha son emisor (e), base (b) y colector (c).

.. image:: img/ebc.png
    :width: 150

* |link_s8050_datasheet|
* |link_s8550_datasheet|

**Ejemplo**

* :ref:`basic_relay` (Basic Project)
* :ref:`basic_active_buzzer` (Basic Project)
* :ref:`basic_passive_buzzer` (Basic Project)
