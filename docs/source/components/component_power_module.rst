.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_power:

Modulo di Alimentazione
===============================

.. note::    Per proteggere la batteria del :ref:`cpn_power`, caricala completamente prima di utilizzarla per la prima volta.

Quando abbiamo bisogno di una grande corrente per pilotare un componente, ciò può interferire gravemente con il normale funzionamento della scheda Arduino UNO. Pertanto, forniamo separatamente l'alimentazione per il componente tramite questo modulo per farlo funzionare in modo sicuro e stabile.

Puoi semplicemente collegarlo alla breadboard per fornire alimentazione. Fornisce una tensione di 3.3V e 5V, e puoi connetterti tramite un cappuccio di ponticello incluso.

.. image:: img/power_supply_new.png
    :width: 95%
    :align: center

.. raw:: html

    <br/>

**Caratteristiche e specifiche**

* Ingresso di Carica: USB Type-C, 5V
* Tensione di Uscita: 5V, 3.3V (regolabile tramite jumper. Configurazione 0V, 3.3V e 5V)
* Corrente di Uscita: 5V/1.5A, 3.3V/1A
* Interruttore ON-OFF Disponibile
* Due Canali Indipendenti
* Uscita USB (Type-A) Disponibile
* Batteria: Batteria agli ioni di litio 14500 da 3.7V, 500mAh
* Dimensioni: 52mm x 32mm x 24mm (L x P x A)


**Esempio**

* :ref:`basic_motor` (Progetto di base)
* :ref:`basic_pump` (Progetto di base)
* :ref:`basic_stepper_motor` (Progetto di base)
* :ref:`fun_smart_fan` (Progetto divertente)
* :ref:`fun_plant_monitor` (Progetto divertente)
* :ref:`fun_access` (Progetto divertente)
* :ref:`fun_pong` (Progetto divertente)
