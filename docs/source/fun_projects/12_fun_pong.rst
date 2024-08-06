.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_pong:

GIOCO - Pong
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/12_fun_pong.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo è un semplice gioco Pong progettato utilizzando un display OLED e una scheda Arduino.
Nel gioco Pong, i giocatori competono contro il computer, controllando una paletta verticale per respingere una palla rimbalzante. 
L'obiettivo è impedire che la palla superi il bordo della propria paletta, altrimenti l'avversario segna un punto.

Le meccaniche del gioco possono essere suddivise nelle seguenti parti:

1. Movimento della palla - La palla si muove nella direzione corrente a una velocità impostata. Ogni volta che la palla colpisce una paletta, la sua velocità aumenta, rendendo il gioco più difficile.

2. Movimento della paletta - Utilizzata per bloccare il movimento della palla, la paletta può muoversi su o giù. I giocatori controllano la propria paletta usando i pulsanti, mentre la paletta del computer segue automaticamente la posizione della palla.

3. Punteggio - Ogni volta che la palla supera il bordo sinistro o destro dello schermo, il giocatore o il CPU corrispondente segna un punto.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_oled`
        - |link_oled_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_power`
        - \-


**Collegamenti**

.. note::
    Per proteggere la batteria del :ref:`cpn_power`, caricala completamente prima di utilizzarla per la prima volta.

.. image:: img/12_pong_bb.png
    :width: 100%
    :align: center


**Schema Elettrico**

.. image:: img/12_pong_schematic.png
    :width: 100%
    :align: center

**Codice**

.. note::

    * Puoi aprire il file ``12_pong_oled.ino`` nel percorso ``elite-explorer-kit-main\fun_project\12_pong_oled`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. note::
   Per installare la libreria, usa l'Arduino Library Manager e cerca **"Adafruit SSD1306"** e **"Adafruit GFX"** e installale.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/86dbb549-d425-4f42-8b5b-28d486e3f7f8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Come funziona?**

La struttura del programma può essere suddivisa nelle seguenti cinque parti:

1. Importare le Librerie Necessarie - Utilizzate per controllare lo schermo OLED e leggere gli input dei pulsanti.

2. Definire Costanti e Variabili Globali:

   Definizioni per la larghezza e l'altezza dello schermo OLED.
   Definizioni per i pulsanti e i pin di reset dell'OLED.
   Posizione, velocità, dimensione e direzione della palla e delle palette.
   Punteggi per il giocatore e il CPU.

3. Inizializzazione:

   Inizializzare la comunicazione seriale, lo schermo OLED e visualizzare l'interfaccia iniziale.
   Impostare i pulsanti come input e collegare le resistenze pull-up.
   Disegnare il campo da gioco.

4. Ciclo Principale:

   Leggere lo stato dei pulsanti.
   Muovere la palla in base alla frequenza di aggiornamento impostata.
   Rilevare le collisioni tra la palla e le palette o i muri, regolando la direzione e la velocità della palla di conseguenza.
   Aggiornare lo schermo con i punteggi in base agli eventi di punteggio.
   Aggiornare le posizioni delle palette.

5. Funzioni Aggiuntive:

   ``crossesPlayerPaddle`` e ``crossesCpuPaddle`` - Utilizzate per rilevare se la palla collide con la paletta del giocatore o del CPU.
   
   ``drawCourt`` - Disegna il campo da gioco sullo schermo OLED.

   ``displayScore`` - Visualizza i punteggi del giocatore e del CPU sullo schermo.

