.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_ws2812:

Striscia LED RGB WS2812 8 LEDs
===================================

.. image:: img/ws2812b.png

La striscia LED RGB WS2812 8 LEDs è composta da 8 LED RGB. 
È necessario un solo pin per controllare tutti i LED. Ogni LED RGB ha un chip WS2812, che può essere controllato indipendentemente. 
Può realizzare una visualizzazione della luminosità a 256 livelli e una visualizzazione a colori reali completa di 16.777.216 colori. 
Allo stesso tempo, il pixel contiene un circuito di latch di dati di interfaccia digitale intelligente, un circuito di amplificazione del segnale e un circuito di formattazione del segnale integrato per garantire efficacemente la consistenza dell'altezza del colore del punto luce del pixel.

È flessibile, può essere collegato, piegato e tagliato a piacimento, e il retro è dotato di nastro adesivo, che può essere fissato su superfici irregolari a piacimento e può essere installato in spazi ristretti.

**Caratteristiche**

* Tensione di lavoro: DC5V
* IC: Un IC controlla un LED RGB
* Consumo: 0,3W per ogni LED
* Temperatura di lavoro: -15-50°C
* Colore: RGB a colori pieni
* Tipo RGB: 5050RGB (IC integrato WS2812B)
* Spessore della striscia LED: 2mm
* Ogni LED può essere controllato individualmente

**Introduzione al WS2812B**

* |link_ws2812b_datasheet|

WS2812B è una sorgente luminosa a LED a controllo intelligente in cui il circuito di controllo e il chip RGB sono integrati in un pacchetto di componenti 5050. Include internamente un latch di dati della porta digitale intelligente e un circuito di amplificazione di formattazione del segnale. Include anche un oscillatore interno di precisione e una parte di controllo a corrente costante programmabile a 12V, garantendo efficacemente la coerenza dell'altezza del colore del punto luce del pixel.

Il protocollo di trasferimento dei dati utilizza la modalità di comunicazione NZR singola. Dopo il reset di accensione del pixel, la porta DIN riceve i dati dal controller, il primo pixel raccoglie i primi 24 bit di dati e li invia al latch interno, mentre gli altri dati, riformattati dal circuito di amplificazione della formattazione del segnale interno, vengono inviati al pixel a cascata successivo attraverso la porta DO. Dopo la trasmissione di ogni pixel, il segnale si riduce di 24 bit. Il pixel adotta la tecnologia di trasmissione di formattazione automatica, rendendo il numero di pixel a cascata non limitato dalla trasmissione del segnale, ma solo dalla velocità di trasmissione del segnale.

Il LED ha una bassa tensione di pilotaggio, è ecologico e a risparmio energetico, ha un'elevata luminosità, un ampio angolo di diffusione, una buona coerenza, un basso consumo di energia, una lunga durata e altri vantaggi. Il chip di controllo integrato nel LED rende il circuito più semplice, di piccolo volume e di facile installazione.
.. Example
.. -------------------

.. :ref:`RGB LED Strip`



**Esempio**

* :ref:`basic_ws2812` (Progetto di base)
* :ref:`iot_cheerlights` (Progetto IoT)
