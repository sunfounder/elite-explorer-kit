.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_ultrasonic_sensor:

Ultrasonico
==========================

Panoramica
--------------------

Quando stai facendo retromarcia, vedrai la distanza tra l'auto e gli ostacoli circostanti per evitare collisioni. Il dispositivo per rilevare la distanza è un sensore ultrasonico. In questo esperimento, imparerai come l'onda ultrasonica rileva la distanza.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|

Collegamenti
----------------------

.. image:: img/06-ultrasonic_module_bb.png
    :align: center
    :width: 100%

.. raw:: html

    <br/>

Schema Elettrico
-----------------------

.. image:: img/06_ultrasonic_schematic.png
    :align: center
    :width: 100%

Codice
--------

.. note::

    * Puoi aprire il file ``06-ultrasonic.ino`` dal percorso ``elite-explorer-kit-main\basic_project\06-ultrasonic`` direttamente.
    * Oppure copia questo codice nell'IDE di Arduino.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/1897efb6-fa3c-4ebc-8993-6561b24848a9/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/06_basic_ultrasonic_sensor.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Analisi del Codice
------------------------

**1. Inizializzare il sensore ultrasonico e LCD1602**

    .. code-block:: arduino
    
       #include <LiquidCrystal_I2C.h>
       
       LiquidCrystal_I2C lcd(0x27, 16, 2);  // inizializza l'oggetto del display LCD con l'indirizzo I2C 0x27, 16 colonne e 2 righe
       
       // Definisci i numeri dei pin per il sensore ultrasonico
       const int echoPin = 3;
       const int trigPin = 4;
       
       void setup() {
         pinMode(echoPin, INPUT);               // Imposta il pin echo come ingresso
         pinMode(trigPin, OUTPUT);              // Imposta il pin trig come uscita
       
         lcd.init();       // inizializza l'LCD
         lcd.clear();      // pulisce il display LCD
         lcd.backlight();  // Assicurati che la retroilluminazione sia accesa
       
       }

**2. Visualizzare la distanza sull'LCD1602**

    .. code-block:: arduino
    
       void loop() {
         float distance = readDistance();  // Chiama la funzione per leggere i dati del sensore e ottenere la distanza
       
         lcd.setCursor(0, 0);         //Posiziona il cursore alla riga 1, colonna 1. Da qui verranno visualizzati i caratteri
         lcd.print("Distance:");      //Stampa "Distance:" sull'LCD
         lcd.setCursor(0, 1);         //Posiziona il cursore alla riga 1, colonna 0
         lcd.print("               ");  //Lascia alcuni spazi dopo i caratteri per cancellare i caratteri precedenti che potrebbero rimanere.
         lcd.setCursor(7, 1);         //Posiziona il cursore alla riga 1, colonna 7.
         lcd.print(distance);         // stampa sull'LCD il valore della distanza convertito dal tempo tra l'invio e la ricezione del ping.
         lcd.setCursor(14, 1);        //Posiziona il cursore alla riga 1, colonna 14.
         lcd.print("cm");             //stampa l'unità "cm"
       
         delay(800);                       // Ritarda di 800 millisecondi prima di ripetere il loop
       }

**3. Convertire il tempo in distanza**

    .. code-block:: arduino

        float readDistance(){// ...}

    Qui, "PING" si riferisce al processo in cui il sensore ultrasonico invia un impulso ultrasonico (o "ping") e poi attende il suo eco.
    
    Il PING viene attivato da un impulso HIGH di 2 o più microsecondi. (Dai un breve impulso LOW prima per assicurarti di avere un impulso HIGH pulito.)

    .. code-block:: arduino

        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW); 

    Il pin echo viene utilizzato per leggere il segnale del PING, un impulso HIGH la cui durata è il tempo (in microsecondi) dall'invio del ping alla ricezione dell'eco dell'oggetto. Utilizziamo la seguente funzione per ottenere la durata.

    .. code-block:: arduino

        pulseIn(echoPin, HIGH);

    La velocità del suono è di 340 m/s o 29 microsecondi per centimetro.

    Questo dà la distanza percorsa dal ping, in uscita e ritorno, quindi dividiamo per 2 per ottenere la distanza dell'ostacolo.

    .. code-block:: arduino

        float distance = pulseIn(echoPin, HIGH) / 29.00 / 2;     // Formula: (340m/s * 1us) / 2
