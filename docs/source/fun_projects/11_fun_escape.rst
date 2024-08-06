.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_escape:

GIOCO - Escape
==================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/11_fun_escape_square.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo gioco si chiama "Escape".
L'obiettivo del giocatore è inclinare il sensore MPU6050 per muovere un pixel sulla matrice LED e cercare di farlo passare attraverso un'apertura nel bordo della matrice (l'uscita).

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
    *   - :ref:`cpn_gy87`
        - \-


**Collegamenti**

.. image:: img/11_escape_bb.png
    :width: 80%
    :align: center


**Schema Elettrico**

.. image:: img/11_escape_schematic.png
   :width: 70%
   :align: center


**Codice**

.. note::

    * Puoi aprire il file ``11_escape_square.ino`` nel percorso ``elite-explorer-kit-main\fun_project\11_escape_square`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. note::
   Per installare la libreria, usa l'Arduino Library Manager e cerca **"Adafruit MPU6050"** e installala.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/6b239445-f921-48fb-a93e-70cc7ef8afc7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Come funziona?**

Ecco una spiegazione dettagliata del codice:

1. Importazione Librerie e Variabili Globali:

   Le librerie importate includono la matrice LED, Wire (per la comunicazione I2C), MPU6050 (sensore di movimento) e la libreria ``Adafruit_Sensor``.
   Inizializzazione degli oggetti MPU6050 e matrice LED.
   Definizione di variabili globali come pixelX e pixelY (posizione del pixel), gapStart e side (posizione iniziale del gap e lato), level (livello di difficoltà del gioco) e altre.

2. ``setup()``:

   Inizializza la matrice LED e disegna la matrice con il gap.
   Inizializza la comunicazione seriale e controlla se il sensore MPU6050 si avvia correttamente, impostando il suo intervallo di accelerazione a 2g.

3. ``loop()``:

   Aggiorna periodicamente la posizione del pixel in base alle letture del sensore MPU6050.
   Sposta periodicamente la posizione del gap.
   Carica il nuovo layout del pixel e lo visualizza sulla matrice LED.
   Controlla se il pixel è passato attraverso il gap. 
   Se lo è, ritarda di 1,5 secondi per visualizzare il successo, aumenta la difficoltà del gioco e ripristina la posizione del pixel.

4. Altre Funzioni:

   * ``drawSquareWithGap()``: Disegna un bordo 8x8 e crea un gap al suo interno.
   * ``createGap()``: Crea un gap di lunghezza 2 sul lato specificato.
   * ``moveGap()``: Sposta la posizione del gap in base al lato corrente e a gapStart, cambiando lato quando necessario.
   * ``movePixelBasedOnMPU()``: Legge i dati di accelerazione dal sensore MPU6050. Sposta la posizione del pixel in base ai dati di accelerazione (reimpostando se il pixel esce dai limiti o entra nelle pareti).
   * ``resetPixel()``: Reimposta la posizione del pixel al centro della matrice.
   * ``checkPixelPosition()``: Controlla se il pixel si trova sul gap. Se lo è, aumenta il livello di difficoltà del gioco e imposta il flag di passaggio su true.

