.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_pir:

Modulo Sensore di Movimento PIR
==================================

.. image:: img/pir_pic.png
    :width: 300
    :align: center

Il sensore PIR rileva la radiazione di calore infrarosso che può essere utilizzata per rilevare la presenza di organismi che emettono radiazioni di calore infrarosso.

Il sensore PIR è diviso in due slot collegati a un amplificatore differenziale. Quando un oggetto stazionario si trova di fronte al sensore, i due slot ricevono la stessa quantità di radiazioni e l'uscita è zero. Quando un oggetto in movimento si trova di fronte al sensore, uno degli slot riceve più radiazioni rispetto all'altro, facendo fluttuare l'uscita verso l'alto o verso il basso. Questo cambiamento nella tensione di uscita è il risultato del rilevamento del movimento.

.. image:: img/PIR_working_principle.jpg
    :width: 800

Dopo che il modulo di rilevamento è stato collegato, c'è un'inizializzazione di un minuto. Durante l'inizializzazione, il modulo uscirà per 0~3 volte a intervalli. Quindi il modulo sarà in modalità standby. Si prega di mantenere l'interferenza della fonte di luce e altre fonti lontano dalla superficie del modulo per evitare il malfunzionamento causato dal segnale di interferenza. Sarebbe meglio usare il modulo senza troppa aria, perché anche il vento può interferire con il sensore.

.. image:: img/pir_back.png
    :width: 600
    :align: center

**Regolazione della Distanza**

Ruotando la manopola del potenziometro di regolazione della distanza in senso orario, l'intervallo della distanza di rilevamento aumenta, e l'intervallo massimo della distanza di rilevamento è di circa 0-7 metri. Se lo ruoti in senso antiorario, l'intervallo della distanza di rilevamento si riduce, e l'intervallo minimo della distanza di rilevamento è di circa 0-3 metri.

**Regolazione del Ritardo**

Ruotando la manopola del potenziometro di regolazione del ritardo in senso orario, è possibile vedere anche l'aumento del ritardo di rilevamento. Il massimo ritardo di rilevamento può raggiungere fino a 300s. Al contrario, se lo ruoti in senso antiorario, puoi ridurre il ritardo con un minimo di 5s.

**Due Modalità di Attivazione**

Scegliere modalità diverse utilizzando il cappuccio del ponticello.

* **H**: Modalità di attivazione ripetibile, dopo aver rilevato il corpo umano, il modulo emette un livello alto. Durante il successivo periodo di ritardo, se qualcuno entra nell'intervallo di rilevamento, l'uscita continuerà a essere di livello alto.

* **L**: Modalità di attivazione non ripetibile, emette un livello alto quando rileva il corpo umano. Dopo il ritardo, l'uscita passerà automaticamente da livello alto a livello basso.

**Esempio**

* :ref:`basic_pir` (Progetto di base)
* :ref:`fun_welcome` (Progetto divertente)
* :ref:`iot_security_system_ifttt` (Progetto IoT)
