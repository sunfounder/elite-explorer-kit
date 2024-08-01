.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

Cómo crear, abrir o guardar un sketch
=======================================

#. Cuando abres el Arduino IDE por primera vez o creas un nuevo sketch, verás una página como esta, donde el Arduino IDE crea un nuevo archivo para ti, llamado "sketch".

   .. image:: img/sp221014_173458.png

   Estos archivos de sketch tienen un nombre temporal regular, del cual puedes deducir la fecha en que se creó el archivo. ``sketch_oct14a.ino`` significa primer sketch del 14 de octubre, ``.ino`` es el formato de archivo de este sketch.

#. Ahora intentemos crear un nuevo sketch. Copia el siguiente código en el Arduino IDE para reemplazar el código original.

   .. image:: img/create1.png

   .. code-block:: Arduino

       void setup() {
           // put your setup code here, to run once:
           pinMode(13,OUTPUT); 
       }

       void loop() {
           // put your main code here, to run repeatedly:
           digitalWrite(13,HIGH);
           delay(500);
           digitalWrite(13,LOW);
           delay(500);
       }

#. Presiona ``Ctrl+S`` o haz clic en **Archivo** -> **Guardar**. El sketch se guarda en: ``C:\Users\{tu_usuario}\Documents\Arduino`` por defecto, puedes renombrarlo o elegir una nueva ruta para guardarlo.

   .. image:: img/create2.png

#. Después de guardar exitosamente, verás que el nombre en el Arduino IDE se ha actualizado.

   .. image:: img/create3.png

Por favor, continúa con la siguiente sección para aprender cómo subir este sketch creado a tu placa Arduino.
