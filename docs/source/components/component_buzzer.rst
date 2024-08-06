.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_buzzer:

Cicalino
============

.. image:: img/buzzer1.png
    :width: 50%
    :align: center

Come tipo di cicalino elettronico con una struttura integrata, i cicalini, alimentati da corrente continua, sono ampiamente utilizzati in computer, stampanti, fotocopiatrici, allarmi, giocattoli elettronici, dispositivi elettronici per auto, telefoni, timer e altri prodotti elettronici o dispositivi vocali.

I cicalini possono essere suddivisi in attivi e passivi (vedi l'immagine seguente). Girando il cicalino in modo che i suoi pin siano rivolti verso l'alto, il cicalino con una scheda di circuito verde è un cicalino passivo, mentre quello chiuso con un nastro nero è un cicalino attivo.

.. image:: img/buzzer2.png
    :width: 60%
    :align: center

La differenza tra un cicalino attivo e uno passivo:

Un cicalino attivo ha una sorgente oscillante integrata, quindi emette suoni quando è alimentato. Ma un cicalino passivo non ha tale sorgente, quindi non emetterà suoni se vengono utilizzati segnali DC; al contrario, è necessario utilizzare onde quadre con una frequenza compresa tra 2K e 5K per pilotarlo. Il cicalino attivo è spesso più costoso di quello passivo a causa dei molteplici circuiti oscillanti integrati.

Di seguito è riportato il simbolo elettrico di un cicalino. Ha due pin con poli positivo e negativo. Con un + sulla superficie rappresenta l'anodo e l'altro è il catodo.

.. image:: img/buzzer_symbol.png
    :width: 150

Puoi controllare i pin del cicalino, il più lungo è l'anodo e il più corto è il catodo. Si prega di non confonderli durante il collegamento, altrimenti il cicalino non emetterà suoni.

|link_buzzer_wiki|

**Esempio**

* :ref:`basic_active_buzzer` (Basic Project)
* :ref:`basic_passive_buzzer` (Basic Project)
* :ref:`fun_access` (Fun Project)
