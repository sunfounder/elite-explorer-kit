.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_led:

LED
==========

.. image:: img/LED.png
    :width: 400

Il diodo a emissione di luce semiconduttore è un tipo di componente che può trasformare l'energia elettrica in energia luminosa tramite giunzioni PN. In base alla lunghezza d'onda, può essere classificato in diodo laser, diodo a emissione di luce infrarossa e diodo a emissione di luce visibile, generalmente noto come diodo a emissione di luce (LED).

Il diodo ha una conduttività unidirezionale, quindi il flusso di corrente seguirà la direzione indicata dalla freccia nel simbolo del circuito. È possibile fornire al solo anodo una potenza positiva e al catodo una potenza negativa. In questo modo, l'LED si accenderà.

.. image:: img/led_symbol.png

Un LED ha due pin. Quello più lungo è l'anodo, mentre quello più corto è il catodo. È importante non collegarli in modo inverso. C'è una caduta di tensione fissa nel LED, quindi non può essere collegato direttamente al circuito perché la tensione di alimentazione potrebbe superare questa caduta e causare la bruciatura dell'LED. La tensione diretta dell'LED rosso, giallo e verde è di 1,8 V, mentre quella dell'LED bianco è di 2,6 V. La maggior parte degli LED può sopportare una corrente massima di 20 mA, quindi è necessario collegare in serie una resistenza di limitazione della corrente.

La formula per il valore della resistenza è la seguente:

    R = (Vsupply – VD)/I

**R** rappresenta il valore della resistenza di limitazione della corrente, **Vsupply** la tensione di alimentazione, **VD** la caduta di tensione e **I** la corrente di lavoro dell'LED.

Ecco l'introduzione dettagliata per l'LED: |link_led_wiki|.



**Esempio**

* :ref:`basic_led` (Progetto di base)
* :ref:`basic_relay` (Progetto di base)
* :ref:`fun_light_array` (Progetto divertente)
* :ref:`fun_smart_fan` (Progetto divertente)

