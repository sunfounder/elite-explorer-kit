.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_irrecv:

Ricevitore Infrarossi
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/infrared_Receiver_uno.html#receive-uno

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/infrared_Receiver_uno.html#receive-uno


Panoramica
------------------

Un ricevitore a infrarossi è un componente che riceve segnali a infrarossi e può ricevere indipendentemente il raggio infrarosso e fornire segnali compatibili con il livello TTL. È simile a un normale transistor in plastica per dimensioni ed è adatto a tutti i tipi di telecomandi e trasmissioni a infrarossi.

Componenti Necessari
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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|


Cablaggio
----------------------

.. image:: img/22-ir_receiver_bb.png
    :align: center
    :width: 80%


Schema Elettrico
---------------------

.. image:: img/22_irrecv_schematic.png
    :align: center
    :width: 50%

Codice
---------------

.. note::

    * Puoi aprire direttamente il file ``22-ir_receiver.ino`` nel percorso ``elite-explorer-kit-main\basic_project\22-ir_receiver``.
    * Oppure copia questo codice nell'IDE di Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/92e1cb75-cda1-4fc7-9680-28e28df8dccc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

* Qui viene utilizzata la libreria ``IRremote``, puoi installarla dal **Library Manager**.

    .. image:: img/22_irrecv_lib.png
        :align: center

.. note::
    * C'è un pezzo di plastica trasparente sul retro del telecomando per interrompere l'alimentazione; estrailo prima di utilizzare il telecomando.


Analisi del Codice
---------------------

Questo codice è progettato per funzionare con un telecomando a infrarossi (IR) utilizzando la libreria ``IRremote``. Ecco la spiegazione:

#. Inclusione della libreria e definizione delle costanti. Prima, viene inclusa la libreria IRremote e il numero del pin per il ricevitore IR viene definito come 2.

   .. code-block:: cpp
 
     #include <IRremote.h>
     const int IR_RECEIVE_PIN = 2;


#. Inizializza la comunicazione seriale a un baud rate di 9600. Inizializza il ricevitore IR sul pin specificato (``IR_RECEIVE_PIN``) e abilita il feedback LED (se applicabile).

   .. code-block:: arduino

       void setup() {
           Serial.begin(9600);                                     // Avvia la comunicazione seriale a 9600 baud
           IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Avvia il ricevitore IR
       }

#. Il ciclo loop viene eseguito continuamente per elaborare i segnali del telecomando IR in arrivo.

   .. code-block:: arduino

      void loop() {
        // Controlla se c'è un segnale IR in arrivo
        if (IrReceiver.decode()) {
          // IrReceiver.printIRResultShort(&Serial);                 // Stampa i dati ricevuti su una riga
          // Serial.println(IrReceiver.decodedIRData.command, HEX);  // Stampa il comando in formato esadecimale
          Serial.println(decodeKeyValue(IrReceiver.decodedIRData.command));  // Mappa e stampa il segnale IR decodificato al valore corrispondente
      
          IrReceiver.resume();  // Abilita la ricezione del prossimo valore
        }
      }
   
   * Controlla se viene ricevuto un segnale IR e se è stato decodificato correttamente.
   * Decodifica il comando IR e lo memorizza in ``decodedValue`` utilizzando una funzione personalizzata ``decodeKeyValue()``.
   * Stampa il valore IR decodificato sul monitor seriale.
   * Riprende la ricezione del segnale IR per il prossimo segnale.

   .. raw:: html

        <br/>

#. Funzione di supporto per mappare i segnali IR ricevuti ai tasti corrispondenti

   .. image:: img/22_irrecv_key.png
      :align: center
      :width: 80%

   .. code-block:: arduino

      // Funzione per mappare i segnali IR ricevuti ai tasti corrispondenti
      String decodeKeyValue(long result) {
        // Ogni caso corrisponde a un comando IR specifico
        switch (result) {
          case 0x16:
            return "0";
          case 0xC:
            return "1";
          case 0x18:
            return "2";
          case 0x5E:
            return "3";
          case 0x8:
            return "4";
          case 0x1C:
            return "5";
          case 0x5A:
            return "6";
          case 0x42:
            return "7";
          case 0x52:
            return "8";
          case 0x4A:
            return "9";
          case 0x9:
            return "+";
          case 0x15:
            return "-";
          case 0x7:
            return "EQ";
          case 0xD:
            return "U/SD";
          case 0x19:
            return "CYCLE";
          case 0x44:
            return "PLAY/PAUSE";
          case 0x43:
            return "FORWARD";
          case 0x40:
            return "BACKWARD";
          case 0x45:
            return "POWER";
          case 0x47:
            return "MUTE";
          case 0x46:
            return "MODE";
          case 0x0:
            return "ERROR";
          default:
            return "ERROR";
        }
      }