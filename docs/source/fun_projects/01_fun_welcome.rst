.. note::

    ¡Hola! ¡Bienvenido a la comunidad de entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros apasionados.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _fun_welcome:

Bienvenida
============

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/01_fun_welcome.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

En este proyecto, utilizaremos un sensor PIR para detectar la presencia humana y un 
altavoz para simular un timbre, similar a los timbres de entrada en las tiendas de 
conveniencia. Cuando un peatón aparezca dentro del rango del sensor PIR, el altavoz sonará, imitando un timbre.

**Componentes necesarios**

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

También puedes comprarlos por separado desde los enlaces a continuación.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCCIÓN DEL COMPONENTE
        - ENLACE DE COMPRA

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|
    *   - :ref:`cpn_audio_speaker`
        - \-


**Cableado**

.. image:: img/01_welcome_bb.png
    :width: 90%
    :align: center

.. raw:: html

   <br/>

**Esquema**

.. image:: img/01_welcome_schematic.png
   :width: 100%

**Código**

.. note::

    * Puedes abrir el archivo ``01_welcome.ino`` bajo la ruta ``elite-explorer-kit-main\fun_project\01_welcome`` directamente.
    * O copia este código en Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/b9791d5d-169d-4603-9fc3-8081138811fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**¿Cómo funciona?**

Aquí hay una explicación paso a paso del código:

1. Incluir archivos de cabecera:

   Incluye dos archivos de cabecera, ``analogWave.h`` y ``pitches.h``. El archivo ``analogWave.h`` contiene la definición de la clase ``analogWave``, mientras que ``pitches.h`` contiene las definiciones de notes musicales.

2. Instanciar objetos y definir constantes:

   Crea un objeto ``wave`` usando la clase ``analogWave`` y define ``PIR_PIN`` como 2, que es el pin conectado al sensor PIR.

3. Array de melodía:

   El array ``melody`` define una melodía musical, con cada note seguida de un número que representa su duración.
   Los números negativos representan notes punteadas (aumentando la duración en un 50%).

4. Variables globales:

   Define algunas variables globales para compartir datos entre funciones.

5. ``setup()``:

   Inicializa ``PIR_PIN`` como entrada y establece la frecuencia de la onda sinusoidal a 10 Hz usando ``wave.sine(10)``.

6. ``loop()``:

   Monitorea continuamente el valor del sensor PIR.
   Si se detecta presencia humana (pirValue es ALTO), llama a la función ``playMelody()`` para reproducir la melodía y espera 10 segundos para prevenir la reproducción repetitiva de la melodía.

7. ``playMelody()``:

   Esta función calcula la duración de cada note basada en los datos en el array ``melody`` y reproduce la note correspondiente. Hay una breve pausa entre notes.
   La función establece la frecuencia de la forma de onda usando ``wave.freq()`` y controla la duración de las notes y las pausas entre notes usando la función ``delay()``.

   note: Asegúrate de que el archivo de cabecera ``pitches.h`` exista antes de ejecutar este código.

