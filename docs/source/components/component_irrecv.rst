.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _cpn_ir_receiver:

Ricevitore a Infrarossi
=================================

Ricevitore IR
----------------------------

.. image:: img/infrared-receiver_01.png
    :width: 60%

* S: Uscita del segnale
* +: VCC
* -: GND

.. Un ricevitore a infrarossi è un componente che riceve segnali a infrarossi e può ricevere indipendentemente raggi infrarossi e segnali di uscita compatibili con il livello TTL. È simile a un transistor confezionato in plastica normale e è adatto a tutti i tipi di telecomando a infrarossi e trasmissione a infrarossi.

SL838 è un piccolo ricevitore per sistemi di telecomando a infrarossi. Contiene un fotodiodo ad alta velocità e alta sensibilità e un preamplificatore, ed è confezionato con resina epossidica per formare un filtro a infrarossi. Il suo principale vantaggio è la funzione affidabile anche in ambienti disturbati.

La comunicazione a infrarossi, o IR, è una tecnologia di comunicazione wireless popolare, a basso costo e facile da usare. La luce infrarossa ha una lunghezza d'onda leggermente maggiore della luce visibile, quindi è impercettibile all'occhio umano, ideale per la comunicazione wireless. Uno schema di modulazione comune per la comunicazione a infrarossi è la modulazione a 38KHz.

* Può essere utilizzato per il telecomando
* Ampio intervallo di tensione operativa: 2,7~5V
* Filtro interno per la frequenza PCM
* Compatibilità con TTL e CMOS
* Forte capacità anti-interferenza
* Conforme RoHS

Telecomando
-------------------------

.. image:: img/infrared-receiver_02.jpeg
    :width: 70%

Questo è un mini telecomando wireless a infrarossi sottile con 21 pulsanti funzionali e una distanza di trasmissione fino a 8 metri, adatto per operare un'ampia gamma di dispositivi nella stanza dei bambini.

* Dimensioni: 85x39x6mm
* Gamma di controllo remoto: 8-10m
* Batteria: batteria al litio manganese di tipo a bottone da 3V
* Frequenza portante a infrarossi: 38KHz
* Materiale di superficie: PET da 0,125mm
* Durata effettiva: più di 20.000 utilizzi

**Esempio**

* :ref:`basic_irrecv` (Progetto Base)
* :ref:`fun_guess_number` (Progetto Divertente)
