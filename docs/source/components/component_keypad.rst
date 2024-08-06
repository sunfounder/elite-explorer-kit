.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_keypad:

Tastierino
========================

Un tastierino è una matrice rettangolare di 12 o 16 pulsanti OFF-(ON). 
I loro contatti sono accessibili tramite un connettore adatto per il collegamento con un cavo a nastro o per l'inserimento in una scheda a circuito stampato. 
In alcuni tastierini, ogni pulsante si connette con un contatto separato nel connettore, mentre tutti i pulsanti condividono un comune di massa.

.. image:: img/keypad314.png

Più spesso, i pulsanti sono codificati a matrice, il che significa che ciascuno di essi collega una coppia unica di conduttori in una matrice. 
Questa configurazione è adatta per il polling da parte di un microcontrollore, che può essere programmato per inviare un impulso di uscita a ciascuno dei quattro fili orizzontali a turno. 
Durante ciascun impulso, controlla i restanti quattro fili verticali in sequenza, per determinare quale di essi, se presente, sta trasmettendo un segnale. 
Resistori di pull-up o pull-down dovrebbero essere aggiunti ai fili di ingresso per prevenire comportamenti imprevedibili negli ingressi del microcontrollore quando non è presente alcun segnale.

**Esempio**

* :ref:`basic_keypad` (Progetto di base)

