.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

.. _add_libraries:

¿Cómo añadir bibliotecas? (Importante)
=============================================

Una biblioteca es una colección de código o funciones preescritas que amplían las capacidades del IDE de Arduino. Las bibliotecas proporcionan código listo para usar para varias funcionalidades, lo que te permite ahorrar tiempo y esfuerzo al programar características complejas.


Usando el Administrador de Bibliotecas
-----------------------------------------------

Muchas bibliotecas están disponibles directamente a través del Administrador de Bibliotecas de Arduino. Puedes acceder al Administrador de Bibliotecas siguiendo estos pasos:

#. En el **Administrador de Bibliotecas**, puedes buscar la biblioteca deseada por nombre o navegar por diferentes categorías.

   .. note::

      En los proyectos donde se requiera la instalación de bibliotecas, habrá indicaciones que señalarán qué bibliotecas instalar. Sigue las instrucciones proporcionadas, como "La biblioteca del sensor DHT se usa aquí, puedes instalarla desde el Administrador de Bibliotecas". Simplemente instala las bibliotecas recomendadas según se indique.

   .. image:: img/install_lib3.png

#. Una vez que encuentres la biblioteca que deseas instalar, haz clic en ella y luego en el botón **Instalar**.

   .. image:: img/install_lib2.png

#. El IDE de Arduino descargará e instalará automáticamente la biblioteca por ti.

.. _manual_install_lib:

Instalación Manual
-----------------------

Algunas bibliotecas no están disponibles a través del **Administrador de Bibliotecas** y deben instalarse manualmente. Para instalar estas bibliotecas, sigue estos pasos:

#. Abre el IDE de Arduino y ve a **Sketch** -> **Include Library** -> **Add .ZIP Library**.

   .. image:: img/add_lib_zip.png

#. Navega hasta el directorio donde se encuentran los archivos de la biblioteca, como la carpeta ``elite-explorer-kit-main/library/``, selecciona el archivo de la biblioteca y haz clic en **Abrir**.

   .. image:: img/rfid_choose.png

#. Una vez que la instalación esté completa, recibirás una notificación confirmando que la biblioteca se ha añadido exitosamente a tu IDE de Arduino. La próxima vez que necesites usar esta biblioteca, no necesitarás repetir el proceso de instalación.

   .. image:: img/rfid_success.png

#. Repite el mismo proceso para añadir otras bibliotecas.


Ubicación de la Biblioteca
-----------------------------------

Las bibliotecas instaladas usando cualquiera de los métodos anteriores se pueden encontrar en el directorio de bibliotecas predeterminado del IDE de Arduino, que generalmente se encuentra en ``C:\Users\xxx\Documents\Arduino\libraries``.

Si tu directorio de bibliotecas es diferente, puedes verificarlo yendo a **Archivo** -> **Preferencias**.

.. image:: img/install_lib1.png



**Referencia**

* |link_install_arduino_lib|