.. note::
    Ciao, benvenuto nella comunità degli appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_joystick:

Modulo Joystick
=======================

.. image:: img/joystick_pic.png
    :align: center
    :width: 600

L'idea di base di un joystick è quella di tradurre il movimento di un bastone in informazioni elettroniche che un computer può elaborare.

Per comunicare un'intera gamma di movimenti al computer, un joystick deve misurare la posizione del bastone su due assi: l'asse X (da sinistra a destra) e l'asse Y (su e giù). Proprio come nella geometria di base, le coordinate X-Y individuano esattamente la posizione del bastone.

Per determinare la posizione del bastone, il sistema di controllo del joystick monitora semplicemente la posizione di ciascun asse. Il design convenzionale del joystick analogico fa questo con due potenziometri o resistori variabili.

Il joystick ha anche un input digitale che viene attivato quando il joystick viene premuto verso il basso.

.. image:: img/joystick318.png
    :align: center
    :width: 600
	
    
**Esempio**

* :ref:`basic_joystick` (Progetto di base)
* :ref:`fun_snake` (Progetto divertente)
