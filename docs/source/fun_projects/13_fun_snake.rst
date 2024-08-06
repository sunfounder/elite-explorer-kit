.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_snake:

GIOCO - Snake
=========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/13_fun_snake.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo esempio implementa il classico gioco Snake su una matrice LED 8x12 utilizzando la scheda R4 Wifi.
I giocatori controllano la direzione del serpente utilizzando un joystick a doppio asse.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

**Collegamenti**

.. image:: img/13_snake_bb.png
    :width: 80%
    :align: center


**Schema Elettrico**

.. image:: img/13_snake_schematic.png
   :width: 80%
   :align: center


**Codice**

.. note::

    * Puoi aprire il file ``13_snake.ino`` nel percorso ``elite-explorer-kit-main\fun_project\13_snake`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/df370ec5-d1b5-4ae7-b3b9-e97e0eb9a872/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Come funziona?**

Ecco una spiegazione dettagliata del codice:

1. Definizione e Inizializzazione delle Variabili

   Importa la libreria ``Arduino_LED_Matrix`` per le operazioni sulla matrice LED.
   matrix è un'istanza della matrice LED.
   ``frame`` e ``flatFrame`` sono array utilizzati per memorizzare e processare le informazioni dei pixel sullo schermo.
   Il serpente è rappresentato come un array di strutture ``Point``, dove ogni punto ha una coordinata x e y.
   food rappresenta la posizione del cibo.
   ``direction`` è la direzione di movimento corrente del serpente.

2. ``setup()`` 

   Inizializza gli assi X e Y del joystick come input.
   Avvia la matrice LED.
   Inizializza la posizione iniziale del serpente al centro dello schermo.
   Genera casualmente la posizione iniziale del cibo.

3. ``loop()`` 

   Determina la direzione del serpente in base alle letture del joystick.
   Muove il serpente.
   Controlla se la testa del serpente collide con il cibo. 
   Se lo fa, il serpente cresce e viene generato nuovo cibo in una nuova posizione.
   Controlla se il serpente collide con sé stesso. Se lo fa, resetta il gioco.
   Disegna lo stato attuale del gioco (posizioni del serpente e del cibo) sulla matrice LED.
   Aggiunge un ritardo per controllare la velocità del gioco.

4. ``moveSnake()`` 

   Muove ogni parte del serpente nella posizione della parte precedente, iniziando dalla coda e andando verso la testa.
   Muove la testa del serpente in base alla sua direzione.

5. ``generateFood()`` 

   Genera tutte le possibili posizioni del cibo.
   Controlla se ogni posizione si sovrappone a una parte del serpente. Se non si sovrappone, la posizione è considerata una possibile posizione del cibo.
   Seleziona casualmente una posizione possibile del cibo.

6. ``drawFrame()`` 

   Cancella il frame corrente.
   Disegna il serpente e il cibo sul frame.
   Appiattisce l'array frame bidimensionale in un array unidimensionale (flatFrame) e lo carica sulla matrice LED.

