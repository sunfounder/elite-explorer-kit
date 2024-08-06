.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri entusiasti.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi festivi.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

Come creare, aprire o salvare uno sketch?
================================================

#. Quando apri l'Arduino IDE per la prima volta o crei un nuovo sketch, vedrai una pagina come questa, dove l'Arduino IDE crea un nuovo file per te, chiamato "sketch".

   .. image:: img/sp221014_173458.png

   Questi file sketch hanno un nome temporaneo regolare, dal quale puoi capire la data in cui il file è stato creato. ``sketch_oct14a.ino`` significa primo sketch del 14 ottobre, ``.ino`` è il formato del file di questo sketch.

#. Ora proviamo a creare un nuovo sketch. Copia il seguente codice nell'Arduino IDE per sostituire il codice originale.

   .. image:: img/create1.png

   .. code-block:: Arduino

       void setup() {
           // metti qui il tuo codice di setup, da eseguire una sola volta:
           pinMode(13, OUTPUT); 
       }

       void loop() {
           // metti qui il tuo codice principale, da eseguire ripetutamente:
           digitalWrite(13, HIGH);
           delay(500);
           digitalWrite(13, LOW);
           delay(500);
       }

#. Premi ``Ctrl+S`` o clicca **File** -> **Salva**. Lo sketch viene salvato in: ``C:\Users\{your_user}\Documents\Arduino`` per impostazione predefinita, puoi rinominarlo o trovare un nuovo percorso per salvarlo.

   .. image:: img/create2.png

#. Dopo il salvataggio, vedrai che il nome nell'Arduino IDE è stato aggiornato.

   .. image:: img/create3.png

Continua con la sezione successiva per imparare come caricare questo sketch creato sulla tua scheda Arduino.
