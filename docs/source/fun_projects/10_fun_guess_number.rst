.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_guess_number:

GIOCO - Indovina il Numero
============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/10_fun_guess_game.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Indovina il Numero è un divertente gioco da festa in cui tu e i tuoi amici vi alternate nell'inserire un numero (0~99). 
L'intervallo diventa più stretto ad ogni input fino a quando un giocatore indovina correttamente il numero. 
Il giocatore che indovina correttamente viene dichiarato perdente e soggetto a una penalità. 
Ad esempio, se il numero segreto è 51, che i giocatori non possono vedere, e il giocatore 1 inserisce 50, 
l'intervallo di numeri cambia a 50~99. Se il giocatore 2 inserisce 70, l'intervallo diventa 50~70. 
Se il giocatore 3 inserisce 51, è il perdente. 
In questo gioco, utilizziamo un telecomando a infrarossi per inserire i numeri e un LCD per visualizzare i risultati.

**Componenti Necessari**

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

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTI
        - LINK ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|



**Collegamenti**

.. image:: img/10_guess_number_bb.png
    :width: 90%
    :align: center


**Schema Elettrico**

.. image:: img/10_guess_number_schematic.png
   :width: 100%
   :align: center

**Codice**

.. note::

    * Puoi aprire il file ``10_guess_number.ino`` nel percorso ``elite-explorer-kit-main\fun_project\10_guess_number`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. note::
   Per installare la libreria, usa l'Arduino Library Manager e cerca **"IRremote"** e **"LiquidCrystal I2C"** e installale.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/935cd2e8-23e1-4af8-bdf5-94ac00f10e8b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**Come funziona?**

1. Importazioni Librerie e Definizioni delle Variabili Globali:

   Vengono importate tre librerie: ``Wire`` per la comunicazione I2C, ``LiquidCrystal_I2C`` per il controllo del display LCD e ``IRremote`` per ricevere i segnali dal telecomando a infrarossi.
   Sono definite diverse variabili globali per memorizzare lo stato e le impostazioni del gioco.

2. ``setup()``

   Inizializza il display LCD e accendi la retroilluminazione.
   Inizializza la comunicazione seriale con un baud rate di 9600.
   Avvia il ricevitore a infrarossi.
   Chiama la funzione ``initNewValue()`` per impostare lo stato iniziale del gioco.

3. ``loop()``

   Controlla se è stato ricevuto un segnale dal telecomando a infrarossi.
   Decodifica il segnale infrarosso ricevuto.
   Aggiorna lo stato del gioco o esegui le azioni corrispondenti in base al valore decodificato (numero o comando).

4. ``initNewValue()``

   Utilizza ``analogRead`` per inizializzare il seme del numero casuale, garantendo che vengano generati numeri casuali diversi ogni volta.
   Genera un numero casuale tra 0 e 98 come numero fortunato (il numero che i giocatori devono indovinare).
   Reimposta i prompt dei limiti superiore e inferiore.
   Visualizza un messaggio di benvenuto sul display LCD.
   Reimposta il numero di input.

5. ``detectPoint()``

   Controlla la relazione tra il numero di input del giocatore e il numero fortunato.
   Se il numero di input è maggiore del numero fortunato, aggiorna il prompt del limite superiore.
   Se il numero di input è minore del numero fortunato, aggiorna il prompt del limite inferiore.
   Se il giocatore inserisce il numero corretto, reimposta l'input e restituisce true.

6. ``lcdShowInput()``

   Visualizza l'input del giocatore e i prompt dei limiti superiore e inferiore correnti sul display LCD.
   Se il giocatore indovina correttamente, visualizza un messaggio di successo e pausa per 5 secondi prima di riavviare il gioco.

