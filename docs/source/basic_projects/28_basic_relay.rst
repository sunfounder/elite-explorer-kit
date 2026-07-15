.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_relay:

Relè
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/relay_uno.html#relay-uno

Panoramica
---------------

Come sappiamo, il relè è un dispositivo utilizzato per fornire connessione tra due o più punti o dispositivi in risposta al segnale di ingresso applicato. In altre parole, i relè forniscono isolamento tra il controller e il dispositivo, poiché i dispositivi possono funzionare sia in AC che in DC. Tuttavia, ricevono segnali da un microcontrollore che funziona in DC, richiedendo quindi un relè per colmare il divario. Il relè è estremamente utile quando è necessario controllare una grande quantità di corrente o tensione con un piccolo segnale elettrico.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_realy`
        - |link_realy_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_diode`
        - |link_diode_buy| 

Cablaggio
----------------------

.. image:: img/28-relay_bb.png
    :align: center
    :width: 90%

Schema Elettrico
-----------------------

Collega una resistenza da 1K (per limitare la corrente quando il transistor è attivato) al pin 8 della scheda SunFounder Uno, quindi a un transistor NPN il cui collettore è collegato alla bobina di un relè e l'emettitore a GND; collega il contatto normalmente aperto del relè a un LED e poi a GND. Pertanto, quando viene fornito un segnale ad alto livello al pin 8, il transistor viene attivato, rendendo la bobina del relè conduttiva. Quindi il suo contatto normalmente aperto si chiude e il LED si accenderà. Quando al pin 8 viene fornito un segnale a basso livello, il LED rimarrà spento.

.. image:: img/28_relay_schematic.png


**Funzione del diodo di freewheeling**: Quando l'ingresso di tensione passa da High (5V) a Low (0V), il transistor passa dalla saturazione (tre condizioni di lavoro: amplificazione, saturazione e interruzione) all'interruzione, la corrente nella bobina improvvisamente non ha modo di fluire. In questo momento, senza il diodo di freewheeling, si genererà una controforza elettromotrice (EMF) alle estremità della bobina, con positivo in basso e negativo in alto, una tensione superiore a 100V. Questa tensione, sommata a quella del transistor, è sufficientemente alta da bruciarlo. Pertanto, il diodo di freewheeling è estremamente importante per scaricare questa contro-EMF nella direzione della freccia nella figura sopra, in modo che la tensione del transistor verso GND non superi +5V (+0,7V).

In questo esperimento, quando il relè si chiude, il LED si accende; quando il relè si apre, il LED si spegne.


Codice
--------

.. note::

    * Puoi aprire il file ``28-relay.ino`` nel percorso ``elite-explorer-kit-main\basic_project\28-relay`` direttamente.
    * Oppure copia questo codice nell'IDE di Arduino.

.. literalinclude:: /_code/28_basic_relay.ino
   :language: cpp
   :linenos:
   :caption: 28-relay.ino
  

Ora, invia un segnale ad alto livello e il relè si chiuderà e il LED si accenderà; invia un segnale a basso livello e si aprirà e il LED si spegnerà. Inoltre, puoi sentire un ticchettio causato dall'interruzione del contatto normalmente chiuso e dalla chiusura di quello normalmente aperto.

Analisi del Codice
----------------------

.. code-block:: arduino

   void loop() {
     digitalWrite(relayPin, HIGH);  // Accende il relè
     delay(1000);                   // Attende un secondo
     digitalWrite(relayPin, LOW);   // Spegne il relè
     delay(1000);                   // Attende un secondo
   }

Il codice in questo esperimento è semplice. Prima, imposta relayPin ad un livello HIGH e il LED collegato al relè si accenderà. Poi imposta relayPin ad un livello LOW e il LED si spegnerà.
