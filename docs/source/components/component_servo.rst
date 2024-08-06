.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_servo:

Servo
===========

.. image:: img/servo.png
    :align: center

Un servo è generalmente composto dai seguenti componenti: cassa, albero, sistema di ingranaggi, potenziometro, motore DC e scheda incorporata.

Funziona così: Il microcontrollore invia segnali PWM al servo, e poi la scheda incorporata nel servo riceve i segnali attraverso il pin del segnale e controlla il motore interno per farlo girare. Di conseguenza, il motore aziona il sistema di ingranaggi che poi muove l'albero dopo la decelerazione. L'albero e il potenziometro del servo sono collegati insieme. Quando l'albero ruota, aziona il potenziometro, quindi il potenziometro invia un segnale di tensione alla scheda incorporata. Poi la scheda determina la direzione e la velocità di rotazione in base alla posizione corrente, così può fermarsi esattamente nella posizione definita e mantenerla.

.. image:: img/servo_internal.png
    :align: center

L'angolo è determinato dalla durata di un impulso applicato al filo di controllo. Questo si chiama modulazione di larghezza di impulso (PWM). Il servo si aspetta di ricevere un impulso ogni 20 ms. La lunghezza dell'impulso determinerà quanto girerà il motore. Ad esempio, un impulso di 1,5 ms farà girare il motore alla posizione di 90 gradi (posizione neutrale). 
Quando viene inviato un impulso a un servo inferiore a 1,5 ms, il servo ruota in una posizione e tiene il suo albero di uscita a un certo numero di gradi in senso antiorario rispetto al punto neutro. Quando l'impulso è più largo di 1,5 ms accade il contrario. La larghezza minima e massima dell'impulso che comanderà il servo a girare in una posizione valida è una funzione di ogni servo. Generalmente l'impulso minimo sarà di circa 0,5 ms e l'impulso massimo sarà di 2,5 ms.

.. image:: img/servo_duty.png
    :width: 600
    :align: center


**Esempio**

* :ref:`basic_servo` (Progetto di Base)
* :ref:`fun_smart_can` (Progetto Divertente)

