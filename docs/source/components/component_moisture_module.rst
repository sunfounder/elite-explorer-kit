.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_soil_moisture:

Modulo di Umidità del Suolo
=================================

.. image:: img/soil_mositure.png

* GND: Massa
* VCC: Alimentazione, 3.3v~5V
* AOUT: Uscita del valore di umidità del suolo, più è umido il suolo, minore è il suo valore.

Questo sensore capacitivo di umidità del suolo è diverso dalla maggior parte dei sensori resistivi sul mercato, utilizzando il principio dell'induzione capacitiva per rilevare l'umidità del suolo. Evita il problema che i sensori resistivi sono altamente suscettibili alla corrosione e ne prolunga notevolmente la durata.

È realizzato con materiali resistenti alla corrosione e ha una durata eccellente. Inseriscilo nel terreno intorno alle piante e monitora i dati di umidità del suolo in tempo reale. Il modulo include un regolatore di tensione integrato che gli consente di funzionare su un intervallo di tensione di 3.3 ~ 5.5 V. È ideale per microcontrollori a bassa tensione con alimentazioni a 3.3 V e 5 V.

Lo schema hardware del sensore capacitivo di umidità del suolo è mostrato di seguito.

.. image:: img/solid_schematic.png

C'è un oscillatore a frequenza fissa, costruito con un timer IC 555. L'onda quadra generata viene quindi inviata al sensore come un condensatore. Tuttavia, per il segnale dell'onda quadra, il condensatore ha una certa reattanza o, per così dire, un resistore con un resistore puramente ohmico (resistore da 10k su pin 3) per formare un partitore di tensione.

Più alta è l'umidità del suolo, maggiore è la capacità del sensore. Di conseguenza, l'onda quadra ha meno reattanza, il che riduce la tensione sulla linea del segnale, e minore è il valore dell'ingresso analogico attraverso il microcontrollore.

**Specifiche**

* Tensione di funzionamento: 3.3 ~ 5.5 VDC
* Tensione di uscita: 0 ~ 3.0VDC
* Corrente operativa: 5mA
* Interfaccia: PH2.0-3P
* Dimensioni: 3.86 x 0.905 pollici (L x P)
* Peso: 15g

**Esempio**

* :ref:`basic_moisture` (Progetto di base)
* :ref:`fun_plant_monitor` (Progetto divertente)
