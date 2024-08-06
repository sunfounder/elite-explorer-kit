.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_fruit_piano:

Piano di Frutta
========================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/02_fun_fruit_piano.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

Questo progetto è un semplice piano di frutta che legge gli input da un sensore touch MPR121 e riproduce musica tramite un DAC. In altre parole, abbiamo trasformato la frutta in una tastiera, permettendoti di suonare musica semplicemente toccandola.

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
    *   - :ref:`cpn_mpr121`
        - \-
    *   - :ref:`cpn_audio_speaker`
        - \-


**Collegamenti**

.. image:: img/02_fruit_piano_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>


**Schema Elettrico**

.. image:: img/02_fruit_piano_schematic.png
   :width: 100%

**Codice**

.. note::

    * Puoi aprire il file ``02_fruit_piano.ino`` nel percorso ``elite-explorer-kit-main\fun_project\02_fruit_piano`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. note::
   Per installare la libreria, usa l'Arduino Library Manager, cerca **"Adafruit MPR121"** e installala.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/e677c06a-7af1-4846-a507-dd69c0c50aae/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Come funziona?**

Ecco una spiegazione passo-passo del codice:

1. Inizializzazione delle Librerie e degli Oggetti:

   Importa le librerie necessarie: la libreria ``Wire`` (per la comunicazione I2C), la libreria ``Adafruit_MPR121`` (per controllare l'MPR121), la libreria ``analogWave`` (per generare forme d'onda analogiche) e ``pitches.h`` (che definisce le frequenze delle note).
   Crea istanze degli oggetti ``Adafruit_MPR121`` e ``analogWave``.
   Definisci un array di note per memorizzare la nota corrispondente a ciascun canale touch.

2. ``setup()``:

   Inizializza la comunicazione Serial e attendi che inizi.
   Controlla e inizializza l'MPR121; se non trovato, stampa un messaggio di errore sul monitor seriale e interrompi l'esecuzione.
   Inizializza l'oggetto ``analogWave`` e imposta la frequenza iniziale dell'onda sinusoidale a 10Hz.

3. ``loop()``:

   Leggi i canali attualmente toccati dell'MPR121.
   Itera attraverso tutti i canali, controlla quale è toccato e riproduci la nota corrispondente.
   Aggiungi un piccolo ritardo tra ogni iterazione.

4. Riproduci Nota ``playNote()``:

   La funzione ``playNote`` prende un parametro ``note`` e imposta la frequenza del DAC per riprodurre la nota corrispondente.
   Ritarda per un periodo per riprodurre la nota.
   Interrompi la riproduzione della nota.

