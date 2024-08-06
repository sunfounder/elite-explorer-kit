.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_audio_speaker:

Modulo Audio e Altoparlante
===================================

Panoramica
---------------

In questa lezione imparerai a conoscere il Modulo Audio e l'Altoparlante quando utilizzati con una scheda Arduino Uno. Questi componenti sono ampiamente utilizzati in varie applicazioni elettroniche, tra cui giocattoli musicali, sistemi audio fai-da-te, allarmi e persino strumenti musicali sofisticati. Combinando un Arduino con un Modulo Audio e un Altoparlante, puoi creare un semplice ma efficace lettore di melodie.

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
    *   - :ref:`cpn_audio_speaker`
        - \-

Cablaggio
----------------------

Dato che si tratta di un amplificatore mono, puoi collegare il pin 8 al pin L o R del modulo amplificatore audio.

La resistenza da 10K viene utilizzata per ridurre il rumore ad alta frequenza e abbassare il volume audio. Forma un filtro passa-basso RC con la capacità parassita del DAC e dell'amplificatore audio. Questo filtro riduce l'ampiezza dei segnali ad alta frequenza, riducendo efficacemente il rumore ad alta frequenza. Pertanto, aggiungere la resistenza da 10K rende la musica più morbida ed elimina il rumore indesiderato ad alta frequenza.

.. image:: img/17-audio_bb.png
    :align: center
    :width: 100%

Schema Elettrico
-----------------------

.. image:: img/17-audio_schematic.png
    :align: center
    :width: 80%

Codice
---------------

.. note::

    * Puoi aprire direttamente il file ``17-speaker.ino`` nel percorso ``elite-explorer-kit-main\basic_project\17-speaker``.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/33b690b5-0be6-434d-83d7-5bfcfce3775e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Al termine del caricamento del codice sulla scheda R4, sentirai una melodia composta da sette note.

Analisi del Codice
------------------------

1. Inclusione della libreria pitches:
   Questa libreria fornisce i valori di frequenza per varie note musicali, permettendoti di usare la notazione musicale nel tuo codice.

   .. note::
      Per favore, posiziona il file ``pitches.h`` nella stessa directory del codice per garantirne il corretto funzionamento. |link_pitches|

      .. image:: img/16_passive_buzzer_piches.png

   .. code-block:: arduino
       
      #include "pitches.h"

2. Definizione di costanti e array:

   * ``speakerPin`` è il pin digitale sull'Arduino a cui è collegato l'altoparlante.

   * ``melody[]`` è un array che memorizza la sequenza delle note da suonare.

   * ``noteDurations[]`` è un array che memorizza la durata di ciascuna nota nella melodia.

   .. code-block:: arduino
   
      const int speakerPin = 8;
      int melody[] = {
        NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
      };
      int noteDurations[] = {
        4, 8, 8, 4, 4, 4, 4, 4
      };

3. Esecuzione della melodia:

   * Il ciclo ``for`` itera su ciascuna nota della melodia.

   * La funzione ``tone()`` suona una nota sull'altoparlante per una durata specifica.

   * Viene aggiunto un ritardo tra le note per distinguerle.

   * La funzione ``noTone()`` interrompe il suono.

   .. code-block:: arduino
   
      void setup() {
        for (int thisNote = 0; thisNote < 8; thisNote++) {
          int noteDuration = 1000 / noteDurations[thisNote];
          tone(speakerPin, melody[thisNote], noteDuration);
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          noTone(speakerPin);
        }
      }

4. Funzione loop vuota:
   Poiché la melodia viene suonata solo una volta nel setup, non c'è codice nella funzione loop.

5. Sentiti libero di sperimentare modificando le note e le durate negli array ``melody[]`` e ``noteDurations[]`` per creare le tue melodie. Se sei interessato, c'è un repository GitHub (|link_arduino-songs|) che offre codice Arduino per suonare varie canzoni. Sebbene il loro approccio possa differire da questo progetto, puoi consultare le loro note e durate come riferimento.
