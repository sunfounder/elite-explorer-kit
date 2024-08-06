.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_oled:

Modulo Display OLED
==========================

.. image:: img/oled.png
    :width: 300
    :align: center

Introduzione
------------------------------
Un modulo display OLED (Organic Light-Emitting Diode) è un dispositivo che può visualizzare testo, grafica e immagini su uno schermo sottile e flessibile utilizzando materiali organici che emettono luce quando viene applicata una corrente elettrica.

Il principale vantaggio di un display OLED è che emette la propria luce e non necessita di un'altra fonte di retroilluminazione. Per questo motivo, i display OLED hanno spesso un migliore contrasto, luminosità e angoli di visualizzazione rispetto ai display LCD.

Un'altra caratteristica importante dei display OLED è il livello di nero profondo. Poiché ogni pixel emette la propria luce in un display OLED, per produrre il colore nero, il singolo pixel può essere spento.

Grazie al minor consumo energetico (solo i pixel accesi assorbono corrente), i display OLED sono anche popolari nei dispositivi a batteria come Smart Watch, Health Tracker e altri dispositivi indossabili.

Principio di funzionamento
------------------------------
Un modulo display OLED è composto da un pannello OLED e da un chip driver OLED montato sul retro del modulo. Il pannello OLED è costituito da molti piccoli pixel che possono produrre diversi colori di luce. Ogni pixel è composto da diversi strati di materiali organici inseriti tra due elettrodi (anodo e catodo). Quando la corrente elettrica scorre attraverso gli elettrodi, i materiali organici emettono luce di diverse lunghezze d'onda a seconda della loro composizione.

Il chip driver OLED è un chip che può controllare i pixel del pannello OLED utilizzando un protocollo di comunicazione seriale chiamato I2C (Inter-Integrated Circuit).

Il chip driver OLED converte i segnali dall'Arduino in comandi per il pannello OLED. L'Arduino può inviare dati al chip driver OLED utilizzando una libreria che può controllare il protocollo I2C. Una di queste librerie è la libreria Adafruit SSD1306. Con questa libreria, è possibile inizializzare il modulo display OLED, impostare il livello di luminosità, stampare testo, grafica o immagini, ecc.

**Esempio**

* :ref:`basic_oled` (Progetto di base)
* :ref:`fun_pong` (Progetto divertente)
* :ref:`iot_weathertime_screen` (Progetto IoT)
