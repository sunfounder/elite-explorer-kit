.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_motor:

Motore
==========================

Panoramica
--------------

In questa lezione, imparerai come utilizzare un motore, il cui principio di funzionamento si basa sul fatto che la bobina alimentata è costretta a ruotare nel campo magnetico, facendo ruotare il rotore del motore, il quale aziona il volano del motore tramite un ingranaggio.

Componenti Necessari
--------------------------

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

Puoi anche acquistarli separatamente dai link seguenti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE DEI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_power`
        - \-

Cablaggio
----------------------

In questo esempio, utilizziamo un modulo di alimentazione per alimentare l'anodo e il catodo della breadboard.

.. note::
    Per proteggere la batteria del :ref:`cpn_power`, caricala completamente prima di utilizzarla per la prima volta.

.. image:: img/24-motor_bb.png
    :align: center
    :width: 80%

.. raw:: html
  
  <br/> 

Schema Elettrico
---------------------

.. image:: img/24_motor_schematic.png
    :align: center
    :width: 100%

.. raw:: html
  
  <br/> 

Codice
---------

.. note::

    * Puoi aprire direttamente il file ``24-motor.ino`` nel percorso ``elite-explorer-kit-main\basic_project\24-motor``.
    * Oppure copia questo codice nell'IDE di Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/7376df09-204d-4698-b2a6-106e2d2f00e6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato il codice sulla scheda UNO, puoi scegliere la direzione di rotazione del motore digitando "A" o "B" nel monitor seriale.


Analisi del Codice
--------------------------

Il motore può essere azionato fornendo una differenza di tensione tra le lamelle di rame su entrambi i lati del motore. 
Pertanto, è sufficiente scrivere 0 per la tensione di un lato della lamella di rame e 5V per l'altro lato. Modifica il valore del segnale analogico scritto per regolare la direzione e la velocità.

.. code-block:: arduino

   // Funzione per ruotare il motore in senso orario
   void clockwise(int Speed) {
     analogWrite(motorBI, 0);
     analogWrite(motorFI, Speed);
   }
   
   // Funzione per ruotare il motore in senso antiorario
   void anticlockwise(int Speed) {
     analogWrite(motorBI, Speed);
     analogWrite(motorFI, 0);
   }

In questo esempio, Serial.Read() viene utilizzato per controllare la direzione del motore. 

Quando digiti 'A' nel monitor seriale, viene chiamata la funzione clockwise (255) per far ruotare il motore con la velocità di 255.
Digitando 'B', il motore ruoterà in senso inverso.

.. code-block:: arduino

   void loop() {
     // Controlla se ci sono dati disponibili sulla porta seriale
     if (Serial.available() > 0) {
       int incomingByte = Serial.read(); // Leggi i dati in arrivo
       
       // Determina la direzione del motore in base all'input dell'utente
       switch (incomingByte) {
         case 'A':
           clockwise(255); // Ruota il motore in senso orario
           Serial.println("The motor rotates clockwise.");
           break;
         case 'B':
           anticlockwise(255); // Ruota il motore in senso antiorario
           Serial.println("The motor rotates anticlockwise.");
           break;
       }
     }
     
     delay(3000); // Attendi per 3 secondi
     stopMotor(); // Ferma il motore
   }
