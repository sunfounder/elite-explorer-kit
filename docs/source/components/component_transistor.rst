.. note::
    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _cpn_transistor:

Transistor
============

.. image:: img/npn_pnp.png
    :width: 300

Il transistor è un dispositivo semiconduttore che controlla la corrente tramite la corrente. Funziona amplificando un segnale debole in un segnale di ampiezza maggiore ed è anche utilizzato come interruttore senza contatto.

Un transistor è una struttura a tre strati composta da semiconduttori di tipo P e N. Formano le tre regioni internamente. La più sottile al centro è la regione di base; le altre due sono entrambe di tipo N o P - la regione più piccola con una intensa presenza di portatori di maggioranza è la regione dell'emettitore, mentre l'altra è la regione del collettore. Questa composizione permette al transistor di essere un amplificatore.
Da queste tre regioni si generano rispettivamente tre poli: base (b), emettitore (e) e collettore (c). Formano due giunzioni P-N, cioè la giunzione dell'emettitore e la giunzione del collettore. La direzione della freccia nel simbolo del circuito del transistor indica quella della giunzione dell'emettitore.

* `P–N junction - Wikipedia <https://en.wikipedia.org/wiki/P-n_junction>`_

In base al tipo di semiconduttore, i transistor possono essere divisi in due gruppi: NPN e PNP. Dall'abbreviazione, possiamo capire che il primo è composto da due semiconduttori di tipo N e uno di tipo P, mentre il secondo è l'opposto. Vedi la figura qui sotto.

.. note::    l'S8550 è un transistor PNP e l'S8050 è un transistor NPN. Sono molto simili e bisogna controllare attentamente per vedere le loro etichette.

.. image:: img/transistor_symbol.png
    :width: 600

Quando un segnale di livello alto passa attraverso un transistor NPN, esso si attiva. Ma un transistor PNP ha bisogno di un segnale di livello basso per attivarsi. Entrambi i tipi di transistor sono frequentemente utilizzati per interruttori senza contatto, proprio come in questo esperimento.

Posiziona il lato dell'etichetta rivolto verso di te e i pin rivolti verso il basso. I pin da sinistra a destra sono emettitore(e), base(b) e collettore(c).

.. image:: img/ebc.png
    :width: 150

* |link_s8050_datasheet|
* |link_s8550_datasheet|

**Esempio**

* :ref:`basic_relay` (Progetto di Base)
* :ref:`basic_active_buzzer` (Progetto di Base)
* :ref:`basic_passive_buzzer` (Progetto di Base)

