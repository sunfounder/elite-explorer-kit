.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!

¿Cómo subir un sketch a la placa?
=============================================

En esta sección, aprenderás cómo subir el sketch creado anteriormente a la placa Arduino, así como algunas consideraciones.

**1. Elegir placa y puerto**

Las placas de desarrollo de Arduino generalmente vienen con un cable USB. Puedes usarlo para conectar la placa a tu computadora.

Selecciona la **Placa** y el **Puerto** correctos en el Arduino IDE. Normalmente, las placas Arduino son reconocidas automáticamente por la computadora y se les asigna un puerto, por lo que puedes seleccionarlo aquí.

    .. image:: img/04_upload_1.png
        :width: 90%

Si tu placa ya está conectada pero no es reconocida, verifica si el logo de **INSTALLED** aparece en la sección de **Arduino UNO R4 Boards** del **Administrador de Placas**, si no, desplázate un poco hacia abajo y haz clic en **INSTALL**.

Busca **"UNO R4"** en el **Administrador de Placas** y verifica si la biblioteca correspondiente está instalada.

    .. image:: img/04_upload_2.png
        :width: 90%

Reabrir el Arduino IDE y volver a conectar la placa Arduino solucionará la mayoría de los problemas. También puedes hacer clic en **Herramientas** -> **Placa** o **Puerto** para seleccionarlos.


**2. Verificar el sketch**

Después de hacer clic en el botón Verificar, el sketch se compilará para ver si hay errores.

    .. image:: img/04_upload_3.png
        :width: 90%

Puedes usarlo para encontrar errores si eliminas algunos caracteres o escribes algunas letras por error. En la barra de mensajes, puedes ver dónde y qué tipo de errores ocurrieron.

    .. image:: img/04_upload_4.png
        :width: 90%

Si no hay errores, verás un mensaje como el siguiente.

    .. image:: img/04_upload_5.png
        :width: 90%


**3. Subir sketch**

Después de completar los pasos anteriores, haz clic en el botón **Upload** para subir este sketch a la placa.

    .. image:: img/04_upload_6.png
        :width: 90%

Si tiene éxito, podrás ver el siguiente mensaje.

    .. image:: img/04_upload_7.png
        :width: 90%

Al mismo tiempo, el LED a bordo parpadeará.

.. image:: img/04_upload_8.png
    :width: 400
    :align: center

.. raw:: html
    
    <br/>

La placa Arduino ejecutará automáticamente el sketch una vez aplicada la energía después de haber subido el sketch. El programa en ejecución puede ser sobrescrito subiendo un nuevo sketch.
