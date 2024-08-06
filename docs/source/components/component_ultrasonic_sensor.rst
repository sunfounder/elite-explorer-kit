.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_ultrasonic:

Modulo Ultrasonico
==========================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

Un modulo sensore ultrasonico è uno strumento che misura la distanza da un oggetto utilizzando onde sonore ultrasoniche. Ha due sonde. Una serve per inviare onde ultrasoniche e l'altra per riceverle e trasformare il tempo di invio e ricezione in una distanza, rilevando così la distanza tra il dispositivo e un ostacolo. In pratica è davvero conveniente e funzionale.

Fornisce una funzione di misurazione senza contatto da 2 cm a 400 cm, e la precisione di misurazione può raggiungere i 3 mm.
Può garantire che il segnale sia stabile entro 5 m, e il segnale si indebolisce gradualmente dopo i 5 m, fino a scomparire alla posizione di 7 m.

Il modulo include trasmettitori ultrasonici, ricevitore e circuito di controllo. I principi di base sono i seguenti:

#. Utilizzare un flip-flop IO per processare un segnale di livello alto di almeno 10us.

#. Il modulo invia automaticamente otto impulsi a 40khz e rileva se c'è un ritorno di segnale.

#. Se il segnale ritorna, passando al livello alto, la durata dell'uscita alta dell'IO è il tempo dal momento della trasmissione dell'onda ultrasonica al suo ritorno. Qui, la distanza di test = (tempo alto x velocità del suono (340 m / s) / 2.

Il diagramma temporale è mostrato di seguito.

.. image:: img/ultrasonic228.png

È sufficiente fornire un breve impulso di 10us per l'ingresso del trigger per avviare la misurazione, e poi il modulo
invierà una raffica di 8 cicli di ultrasuoni a 40 kHz e solleverà il suo
eco. È possibile calcolare la distanza tramite l'intervallo di tempo tra
l'invio del segnale di trigger e la ricezione del segnale di eco.

Formula: us / 58 = centimetri o us / 148 = pollici; oppure: la distanza = tempo di livello alto \* velocità (340M/S) / 2; si consiglia di utilizzare
un ciclo di misurazione superiore a 60ms per evitare collisioni tra
segnale di trigger e segnale di eco.

**Esempio**

* :ref:`basic_ultrasonic_sensor` (Progetto di Base)
* :ref:`fun_smart_can` (Progetto Divertente)
