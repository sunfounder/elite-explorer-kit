.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_digital_dice:

Dado Digitale
=======================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/05_fun_dice.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo codice è progettato per simulare un lancio di dadi utilizzando un registro a scorrimento 74HC595 e un display digitale a 7 segmenti. La simulazione del lancio del dado viene attivata agitando direttamente l'interruttore inclinabile. Al compimento di questa azione, il display digitale scorre tra numeri casuali tra 1 e 6, simulando il lancio di un dado. Dopo un breve intervallo, il display si ferma, mostrando un numero casuale che rappresenta il risultato del lancio del dado.

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
    *   - :ref:`cpn_tilt_switch`
        - \-
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7segment`
        - |link_7segment_buy|

**Collegamenti**

.. image:: img/05_dice_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>

**Schema Elettrico**

.. image:: img/05_digital_dice_schematic.png
   :width: 100%

**Codice**

.. note::

    * Puoi aprire il file ``05_digital_dice.ino`` nel percorso ``elite-explorer-kit-main\fun_project\05_digital_dice`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ff0528b0-a10d-49e8-8916-6cb1fdfdf9a2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Come funziona?**

Ecco una spiegazione dettagliata del codice:

1. Inizializzazione delle variabili:

   ``dataPin``, ``clockPin``, ``latchPin``: Pin per il 74HC595.
   ``buttonPin``: Il pin digitale a cui è collegato il pulsante.
   ``numbers[]``: Un array per memorizzare la codifica che rappresenta i numeri da 1 a 6 su un tubo digitale ad anodo comune.

2. Variabili volatili:

   rolling: Questa è una variabile volatile che indica se il dado sta attualmente rotolando. 
   È dichiarata volatile poiché viene acceduta sia nella routine di servizio degli interrupt sia nel programma principale.

3. ``setup()``:

   Imposta le modalità per i pin rilevanti.
   Imposta la modalità input per il pulsante utilizzando il resistore pull-up interno.
   Assegna un interrupt al pulsante, che chiama la funzione rollDice quando lo stato del pulsante cambia.

4. ``loop()``:

   Controlla se rolling è true. Se lo è, continua a visualizzare un numero casuale tra 1 e 6. Se il pulsante è stato premuto per più di 500 millisecondi, il rolling si ferma.

5. ``rollDice()``:

   Questa è la routine di servizio degli interrupt per il pulsante. Controlla se il pulsante è premuto (livello basso). Se lo è, il tempo corrente viene registrato e il rolling inizia.

6. ``displayNumber()``:

   Questa funzione visualizza un numero sul tubo digitale. Invia il numero al tubo digitale attraverso il registro a scorrimento 74HC595.

