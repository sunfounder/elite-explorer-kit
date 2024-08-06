.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_gy87_bmp180:

BMP180
==========================


Panoramica
---------------

In questo tutorial, approfondiremo il modulo IMU GY-87, concentrandoci sul sensore BMP180 per la misurazione di temperatura, pressione e altitudine. Ideale per applicazioni come il monitoraggio del clima e il tracciamento dell'altitudine, questa lezione copre l'interfacciamento del GY-87 con un Arduino Uno e l'uso della libreria Adafruit BMP085. Imparerai come inizializzare il sensore BMP180 e leggere i suoi dati sul Monitor Seriale di Arduino, una competenza cruciale per progetti che richiedono dati ambientali.

Componenti necessari
-------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_gy87`
        - \-


Collegamenti
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 75%

.. raw:: html

   <br/>

Schema Elettrico
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%

Codice
-----------

.. note::

    * Puoi aprire il file ``09-gy87_bmp180.ino`` dal percorso ``elite-explorer-kit-main\basic_project\09-gy87_bmp180`` direttamente.
    * Oppure copia questo codice nell'IDE di Arduino.

.. note:: 
    Per installare la libreria, usa il Library Manager di Arduino e cerca **"Adafruit BMP085 Library"** e installala.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7f7347f7-e1e6-400f-b10c-02ccf300b3b9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Analisi del Codice
------------------------

- ``initializeBMP180()``

  Inizializza il sensore BMP180.

  .. code-block:: arduino

     void initializeBMP180() {
       // Start BMP180 initialization
       if (!bmp.begin()) {
         Serial.println("Could not find a valid BMP180 sensor, check wiring!");
         while (1)
           ;  // Halt if sensor not found
       }
       Serial.println("BMP180 Found!");
     }

- ``printBMP180()``

  Stampa i valori letti dal sensore BMP180.

  .. code-block:: arduino

     void printBMP180() {
       Serial.println();
       Serial.println("BMP180 ------------");
       Serial.print("Temperature = ");
       Serial.print(bmp.readTemperature());
       Serial.println(" *C");
     
       Serial.print("Pressure = ");
       Serial.print(bmp.readPressure());
       Serial.println(" Pa");
     
       // Calculate altitude assuming 'standard' barometric
       // pressure of 1013.25 millibar = 101325 Pascal
       Serial.print("Altitude = ");
       Serial.print(bmp.readAltitude());
       Serial.println(" meters");
     
       Serial.print("Pressure at sealevel (calculated) = ");
       Serial.print(bmp.readSealevelPressure());
       Serial.println(" Pa");
       Serial.println("BMP180 ------------");
       Serial.println();
     }


