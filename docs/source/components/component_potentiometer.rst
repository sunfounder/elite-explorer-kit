.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_potentiometer:

Potentiometro
==================

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Il potenziometro è anche un componente resistivo con 3 terminali e il suo valore di resistenza può essere regolato secondo alcune variazioni regolari.

I potenziometri sono disponibili in varie forme, dimensioni e valori, ma hanno tutti in comune le seguenti caratteristiche:

* Hanno tre terminali (o punti di connessione).
* Hanno una manopola, una vite o un cursore che può essere mosso per variare la resistenza tra il terminale centrale e uno dei terminali esterni.
* La resistenza tra il terminale centrale e uno dei terminali esterni varia da 0 Ω alla resistenza massima del potenziometro quando la manopola, la vite o il cursore viene spostato.

Ecco il simbolo del circuito del potenziometro.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Le funzioni del potenziometro nel circuito sono le seguenti:

#. Funzionamento come divisore di tensione

    Il potenziometro è una resistenza regolabile in modo continuo. Quando si regola l'albero o il cursore del potenziometro, il contatto mobile scivola sulla resistenza. A questo punto, può essere emessa una tensione a seconda della tensione applicata al potenziometro e dell'angolo a cui si è ruotato il braccio mobile o del percorso che ha compiuto.

#. Funzionamento come reostato

    Quando il potenziometro viene utilizzato come reostato, collegare il pin centrale e uno degli altri 2 pin nel circuito. In questo modo è possibile ottenere un valore di resistenza che cambia in modo regolare e continuo all'interno del percorso del contatto mobile.

#. Funzionamento come regolatore di corrente

    Quando il potenziometro funge da regolatore di corrente, il terminale del contatto scorrevole deve essere collegato come uno dei terminali di uscita.

Se vuoi saperne di più sul potenziometro, consulta: |link_potentiometer_wiki|.

**Esempio**

* :ref:`basic_potentiometer` (Progetto di base)
* :ref:`fun_hue` (Progetto divertente)
