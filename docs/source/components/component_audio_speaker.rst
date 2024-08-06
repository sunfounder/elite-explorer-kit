.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_audio_speaker:

Modulo Audio e Altoparlante
==============================

**Modulo Amplificatore Audio**

.. image:: img/audio_module.jpg
    :width: 500
    :align: center

Il Modulo Amplificatore Audio contiene un chip amplificatore audio HXJ8002. Questo chip è un amplificatore di potenza a bassa tensione di alimentazione, che può fornire una potenza audio media di 3W per un carico BTL da 3Ω con bassa distorsione armonica (sotto la soglia del 10% a 1KHz) da un'alimentazione di 5V DC. Questo chip può amplificare segnali audio senza alcun condensatore di accoppiamento o condensatore bootstrap.

Il modulo può essere alimentato da una tensione DC compresa tra 2.0V e 5.5V con una corrente operativa di 10mA (0.6uA per corrente tipica in modalità standby) e produrre un suono amplificato potente in un altoparlante di impedenza 3Ω, 4Ω o 8Ω. Questo modulo ha un circuito migliorato per ridurre significativamente il rumore di transizione al momento dell'accensione e dello spegnimento. Le dimensioni ridotte oltre all'alta efficienza e alla bassa potenza di alimentazione lo rendono applicabile in numerosi progetti portatili e alimentati a batteria e microcontrollori.  

* **IC**: HXJ8002
* **Tensione di Ingresso**: 2V ~ 5.5V
* **Corrente in Modalità Standby**: 0.6uA (valore tipico)
* **Potenza di Uscita**: 3W (carico 3Ω) , 2.5W (carico 4Ω) , 1.5W (carico 8Ω)
* **Impedenza dell'Altoparlante di Uscita**: 3Ω, 4Ω, 8Ω
* **Dimensioni**: 19.8mm x 14.2mm

**Altoparlante**

.. image:: img/speaker_pic.png
    :width: 300
    :align: center

* **Dimensioni**: 20x30x7mm
* **Impedenza**: 8ohm
* **Potenza di Ingresso Nominale**: 1.5W 
* **Potenza di Ingresso Massima**: 2.0W
* **Lunghezza del Cavo**: 10cm

.. image:: img/2030_speaker.png

Il grafico delle dimensioni è il seguente:

* :download:`2030 Speaker Datasheet <https://github.com/sunfounder/sf-pdf/raw/master/datasheet/2030-speaker-datasheet.pdf>`


**Esempio**

* :ref:`basic_audio_speaker` (Basic Project)
* :ref:`fun_welcome` (Fun Project)
* :ref:`fun_fruit_piano` (Fun Project)
* :ref:`new_dac`

