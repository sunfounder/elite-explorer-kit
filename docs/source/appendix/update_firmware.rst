.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri entusiasti.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi festivi.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _update_firmware:

Aggiorna il firmware del modulo radio sulla tua scheda UNO R4 WiFi
========================================================================

.. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

1. Collega la scheda UNO R4 WiFi al computer con il cavo USB.
2. Se hai aperto il Serial Monitor o il Serial Plotter dell'Arduino IDE, chiudili.

   Puoi chiudere il Serial Monitor cliccando sull'icona X che appare sulla sua scheda quando è selezionato:

   .. image:: img/close_serial_monitor2.png
      :width: 85%

3. Seleziona Strumenti > Aggiornamento Firmware dai menu dell'Arduino IDE.
   Si aprirà la finestra di dialogo "Aggiornamento Firmware".

   .. image:: img/update_firmware_1.png
         :width: 70%

4. Seleziona la scheda UNO R4 WiFi dal menu "Select Board" nella finestra di dialogo "Aggiornamento Firmware".
5. Clicca sul pulsante "CHECK UPDATES".
   Verrà aggiunto un pulsante "INSTALL" alla finestra di dialogo.

   .. image:: img/update_firmware_2.png
         :width: 85%

6. Clicca sul pulsante "INSTALL".
   Inizierà il processo di installazione del firmware, come indicato dal messaggio vicino alla parte inferiore della finestra di dialogo.

   .. image:: img/update_firmware_3.png
         :width: 85%

7. Attendi che il processo di aggiornamento del firmware termini con successo, come indicato dal messaggio nella finestra di dialogo:
   Firmware installato con successo.

   .. image:: img/update_firmware_4.png
         :width: 85%

8. Clicca sull'icona X nella finestra di dialogo.
   La finestra di dialogo si chiuderà.
9. Scollega il cavo USB della scheda UNO R4 WiFi dal computer.
10. Collega nuovamente la scheda UNO R4 WiFi al computer con il cavo USB.

**Riferimento**

- |link_update_firmware|
