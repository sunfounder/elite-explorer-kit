.. note::

    Hola, ¡bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi & Arduino & ESP32 en Facebook! Sumérgete en el mundo de Raspberry Pi, Arduino y ESP32 junto a otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Accede anticipadamente a anuncios de nuevos productos y adelantos exclusivos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más recientes.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _fun_access:

Sistema de Control de Acceso
======================================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/09_fun_access.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

La función principal de este código es realizar la autenticación de usuarios utilizando un módulo RFID. 
Si la autenticación es exitosa, controla un motor paso a paso para abrir la puerta y emite un sonido a través de un buzzer para indicar el resultado de la autenticación. 
Si la autenticación falla, la puerta no se abrirá.

Puedes abrir el monitor serie para ver el ID de tu tarjeta RFID y reconfigurar la contraseña en este código.

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
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_power`
        - \-


**Cableado**

.. note::
    Para proteger la batería del :ref:`cpn_power`, cárgala completamente antes de usarla por primera vez.

.. image:: img/09_access_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Esquema**

.. image:: img/09_access_schematic.png
   :width: 100%
   :align: center

.. raw:: html

   <br/>

**Código**

.. note::

    * Puedes abrir el archivo ``09_access_control_system.ino`` bajo la ruta de ``elite-explorer-kit-main\fun_project09_access_control_system`` directamente.
    * O copiar este código en Arduino IDE.

.. note::

    * Se utiliza la biblioteca ``RFID1``. La biblioteca se encuentra en el directorio ``elite-explorer-kit-main/library/``, o puedes hacer clic aquí :download:`RFID1.zip </_static/RFID1.zip>` para descargarla. Consulta :ref:`manual_install_lib` para un tutorial sobre cómo instalarla.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/3486dd4e-a76e-478f-b5a4-a86281f7f374/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**¿Cómo funciona?**

A continuación se explica paso a paso el código:



1. **Incluir Archivos de Biblioteca**: Se han incluido tres archivos de biblioteca: ``rfid1.h``, ``Stepper.h`` y ``Wire.h``. Estas bibliotecas se utilizan para comunicarse con el módulo RFID, el motor paso a paso y para la comunicación I2C.

2. **Definiciones de Constantes**: Se han definido algunas constantes, incluyendo ``ID_LEN`` (longitud del ID), ``stepsPerRevolution`` (pasos por revolución para el motor paso a paso), ``rolePerMinute`` (velocidad del motor paso a paso), así como los cuatro pines del motor paso a paso (IN1, IN2, IN3, IN4), el pin del buzzer (``buzPin``) y variables relacionadas con la autenticación.

3. **Definición de Variables**: Se han definido variables como un array para almacenar el ID de usuario leído (``userIdRead``), el ID de usuario autenticado (``userId``) y una variable booleana (``approved``) para indicar la autenticación exitosa.

4. **Instanciación de Objetos**: Se han creado instancias de dos objetos: ``RFID1 rfid`` y ``Stepper stepper`` para interactuar con el módulo RFID y el motor paso a paso, respectivamente.

5. ``setup()``: En la función ``setup()``, se inicializa la velocidad del motor paso a paso, se establece el pin del buzzer como salida y se inicializa el módulo RFID.

6. ``loop()``: En la función ``loop()``, se ejecuta la lógica principal. Si ``approved`` es 0 (indicando que aún no está autenticado), se llama a la función ``rfidRead()`` para leer datos del módulo RFID y luego se borra el array ``userIdRead``. Si ``approved`` es 1 (indicando autenticación exitosa), se llama a la función ``openDoor()`` para abrir la puerta y se restablece ``approved`` a 0.

7. ``beep()``: Esta función controla el sonido del buzzer en función de los parámetros ``duration`` y ``frequency`` proporcionados.

8. ``verifyPrint()``: Esta función produce diferentes sonidos de buzzer en función del parámetro ``result`` para indicar si la autenticación fue exitosa.

9. ``openDoor()``: Esta función controla el motor paso a paso para abrir la puerta a un cierto ángulo (``doorStep``) y luego espera un período antes de cerrar la puerta.

10. ``rfidRead()``: Esta función lee datos del módulo RFID, primero llamando a ``getId()`` para obtener el ID del usuario y luego a ``idVerify()`` para verificar si el ID del usuario coincide con el ID autenticado.

11. ``getId()``: Esta función recupera el ID del usuario desde el módulo RFID y lo almacena en el array ``userIdRead``. Emite un beep si la lectura falla.

12. ``idVerify()``: Esta función verifica si el ID del usuario coincide con el ID autenticado y produce un sonido indicando autenticación exitosa o fallida.

