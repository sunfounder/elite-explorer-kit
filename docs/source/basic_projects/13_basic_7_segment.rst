.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_7segment:

Display a 7 segmenti
==========================

.. https://docs.sunfounder.com/projects/uno-mega-kit/en/latest/uno/7_segment_display_uno.html#segmeng-uno


Panoramica
-------------------

Un display a 7 segmenti è un dispositivo che può visualizzare numeri e lettere. È composto da sette LED collegati in parallelo. Diverse lettere/numeri possono essere mostrati collegando i pin del display alla fonte di alimentazione e abilitando i pin corrispondenti, accendendo così i segmenti LED corrispondenti. In questa lezione impareremo a visualizzare caratteri specifici su di esso.

Componenti Necessari
------------------------

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
    *   - :ref:`cpn_7segment`
        - |link_7segment_buy|

Cablaggio
----------------------

.. image:: img/13-7_segment_display_bb.png
    :align: center
    :width: 70%

Schema Elettrico
------------------------

In questo esperimento, collega ciascun pin a-g del display a 7 segmenti a un resistore di limitazione di corrente da 1000 ohm rispettivamente e poi ai pin 4-11. GND si collega a GND. Tramite la programmazione, possiamo impostare uno o più dei pin 4-11 su livello alto per accendere i LED corrispondenti.

.. image:: img/13-7_segment_display_schematic.png
    :align: center
    :width: 80%

Codice
---------------

.. note::

    * Puoi aprire direttamente il file ``13-7_segment.ino`` nel percorso ``elite-explorer-kit-main\basic_project\13-7_segment``.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ce9857dc-6285-45cd-9918-e35b0b135836/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/13_basic_7_segment.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>

Analisi del Codice
----------------------

Il codice può sembrare un po' lungo per questo esperimento, ma la sintassi è semplice. Diamo un'occhiata.

**Chiamare la funzione nel loop()**

.. code-block:: arduino

   digital_1(); //visualizza 1 sul display a 7 segmenti

   delay(1000); //aspetta un secondo

   digital_2(); //visualizza 2 sul display a 7 segmenti

   delay(1000); //aspetta un secondo

   digital_3(); //visualizza 3 sul display a 7 segmenti

   delay(1000); //aspetta un secondo

   digital_4(); //visualizza 4 sul display a 7 segmenti


Chiamare queste funzioni nel loop() serve a far visualizzare allo schermo a 7 segmenti i numeri da 0 a F. Le funzioni sono mostrate di seguito. Prendiamo ``digital_2()`` come esempio:

**Analisi dettagliata di digital_2()**

.. code-block:: arduino

   void digital_2()  //visualizza 2 sul display a 7 segmenti
   {
     turnOffAllSegments();
     digitalWrite(a, HIGH);
     digitalWrite(b, HIGH);
     digitalWrite(g, HIGH);
     digitalWrite(e, HIGH);
     digitalWrite(d, HIGH);
   }

.. image:: img/13_7segment.jpeg
   :align: center

Prima di tutto, dobbiamo capire come il numero **2** appare sul display a 7 segmenti. Si ottiene alimentando i segmenti a, b, d, e, e g. Nella programmazione, i pin collegati a questi segmenti sono impostati su livello alto mentre c e f sono impostati su livello basso. Iniziamo utilizzando la funzione ``turnOffAllSegments()`` per spegnere tutti i segmenti e poi accendere quelli richiesti.

Dopo aver eseguito questa parte, il display a 7 segmenti mostrerà **2**. Analogamente, la visualizzazione di altri caratteri è la stessa. Poiché le lettere b e d in maiuscolo, ovvero **B** e **D**, sarebbero simili a **8** e **0** sul display, sono visualizzate in minuscolo invece.
