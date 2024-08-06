.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni l'accesso anticipato agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Concorsi Festivi**: Partecipa a concorsi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _fun_welcome:

Benvenuto
========================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/01_fun_welcome.mp4"  type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

In questo progetto, useremo un sensore PIR per rilevare la presenza umana e un altoparlante per simulare un campanello, simile ai campanelli delle porte nei negozi di convenienza. Quando un pedone appare nel raggio del sensore PIR, l'altoparlante suonerà, imitando un campanello.

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|
    *   - :ref:`cpn_audio_speaker`
        - \-


**Collegamenti**

.. image:: img/01_welcome_bb.png
    :width: 90%
    :align: center

.. raw:: html

   <br/>

**Schema Elettrico**

.. image:: img/01_welcome_schematic.png
   :width: 100%

**Codice**

.. note::

    * Puoi aprire il file ``01_welcome.ino`` nel percorso ``elite-explorer-kit-main\fun_project\01_welcome`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/b9791d5d-169d-4603-9fc3-8081138811fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Come funziona?**

Ecco una spiegazione passo-passo del codice:

1. Includere i File Header:

   Includi due file header, ``analogWave.h`` e ``pitches.h``. Il file ``analogWave.h`` contiene la definizione della classe ``analogWave``, mentre ``pitches.h`` contiene le definizioni delle note musicali.

2. Istanziamento degli Oggetti e Definizione delle Costanti:

   Crea un oggetto ``wave`` utilizzando la classe ``analogWave`` e definisci ``PIR_PIN`` come 2, che è il pin collegato al sensore PIR.

3. Array della Melodia:

   L'array ``melody`` definisce una melodia musicale, con ogni nota seguita da un numero che rappresenta la sua durata. 
   I numeri negativi rappresentano note puntate (aumentando la durata del 50%).

4. Variabili Globali:

   Definisci alcune variabili globali per la condivisione dei dati tra le funzioni.

5. ``setup()``:

   Inizializza ``PIR_PIN`` come input e imposta la frequenza dell'onda sinusoidale a 10 Hz utilizzando ``wave.sine(10)``.

6. ``loop()``:

   Monitora continuamente il valore del sensore PIR.
   Se viene rilevata la presenza umana (pirValue è HIGH), chiama la funzione ``playMelody()`` per riprodurre la melodia e attendi 10 secondi per evitare la riproduzione ripetitiva della melodia.

7. ``playMelody()``:

   Questa funzione calcola la durata di ogni nota in base ai dati nell'array ``melody`` e riproduce la nota corrispondente. C'è una breve pausa tra le note.
   La funzione imposta la frequenza della forma d'onda utilizzando ``wave.freq()`` e controlla la durata delle note e delle pause tra le note utilizzando la funzione ``delay()``.

   Nota: Assicurati che il file header ``pitches.h`` esista effettivamente prima di eseguire questo codice.
