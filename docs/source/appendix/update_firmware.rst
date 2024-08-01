.. note::

    ¡Hola, bienvenido a la Comunidad de Entusiastas de SunFounder Raspberry Pi, Arduino y ESP32 en Facebook! Sumérgete más profundamente en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte experto**: Resuelve problemas postventa y desafíos técnicos con la ayuda de nuestra comunidad y equipo.
    - **Aprende y comparte**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Avances exclusivos**: Obtén acceso anticipado a nuevos anuncios de productos y adelantos.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de temporada.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy mismo!
    
.. _update_firmware:

Actualizar el firmware del módulo de radio en tu placa UNO R4 WiFi
=======================================================================

.. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

1. Conecta la placa UNO R4 WiFi a tu computadora con el cable USB.
2. Si tienes el Monitor Serial o el Trazador Serial del Arduino IDE abiertos, ciérralos.

   Puedes cerrar el Monitor Serial haciendo clic en el ícono X que aparece en su pestaña cuando está seleccionado:

   .. image:: img/close_serial_monitor2.png
      :width: 85%

3. Selecciona Herramientas > Actualizador de Firmware en los menús del Arduino IDE.
   Se abrirá el cuadro de diálogo "Actualizador de Firmware".

   .. image:: img/update_firmware_1.png
         :width: 70%

4. Selecciona la placa UNO R4 WiFi en el menú "Seleccionar placa" en el cuadro de diálogo "Actualizador de Firmware".
5. Haz clic en el botón "COMPROBAR ACTUALIZACIONES".
   Se añadirá un botón "INSTALAR" al cuadro de diálogo.

   .. image:: img/update_firmware_2.png
         :width: 85%

6. Haz clic en el botón "INSTALAR".
   Comenzará un proceso de "Instalación de firmware", como se indica en el mensaje cerca de la parte inferior del cuadro de diálogo.

   .. image:: img/update_firmware_3.png
         :width: 85%

7. Espera a que el proceso de actualización del firmware termine exitosamente, como se indica en el mensaje del cuadro de diálogo:
   Firmware instalado con éxito.

   .. image:: img/update_firmware_4.png
         :width: 85%

8. Haz clic en el ícono X en el cuadro de diálogo.
   El cuadro de diálogo se cerrará.
9. Desconecta el cable USB de la placa UNO R4 WiFi de tu computadora.
10. Vuelve a conectar la placa UNO R4 WiFi a tu computadora con el cable USB.


**Referencia**

- |link_update_firmware|