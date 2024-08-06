.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_motor:

Motore DC
===================

.. image:: img/motor.jpeg
    :align: center

Questo è un motore DC a 3V. Quando si applica un livello alto e un livello basso a ciascuno dei 2 terminali, il motore ruoterà.

* **Lunghezza**: 25mm
* **Diametro**: 21mm
* **Diametro dell'albero**: 2mm
* **Lunghezza dell'albero**: 8mm
* **Tensione**: 3-6V
* **Corrente**: 0.35-0.4A
* **Velocità a 3V**: 19000 RPM (Rotazioni Per Minuto)
* **Peso**: Circa 14g (per unità)

Il motore a corrente continua (DC) è un attuatore continuo che converte l'energia elettrica in energia meccanica. I motori DC fanno funzionare pompe rotative, ventilatori, compressori, giranti e altri dispositivi producendo una rotazione angolare continua.

Un motore DC è composto da due parti, la parte fissa del motore chiamata **statore** e la parte interna del motore chiamata **rotore** (o **indotto** di un motore DC) che ruota per produrre movimento.
La chiave per generare movimento è posizionare l'indotto all'interno del campo magnetico del magnete permanente (il cui campo si estende dal polo nord al polo sud). L'interazione tra il campo magnetico e le particelle cariche in movimento (il filo che trasporta corrente genera il campo magnetico) produce la coppia che fa ruotare l'indotto.

.. image:: img/motor_sche.png
    :align: center

La corrente fluisce dal terminale positivo della batteria attraverso il circuito, attraverso le spazzole di rame verso il commutatore e quindi verso l'indotto.
Ma a causa dei due spazi nel commutatore, questo flusso si inverte a metà di ogni rotazione completa.
Questa inversione continua essenzialmente converte la corrente continua (DC) dalla batteria in corrente alternata (AC), permettendo all'indotto di sperimentare la coppia nella giusta direzione al momento giusto per mantenere la rotazione.

**Esempio**

* :ref:`basic_motor` (Progetto di base)
* :ref:`fun_smart_fan` (Progetto divertente)
