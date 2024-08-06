.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_pir:

Modulo Sensore di Movimento PIR
==================================

.. https://docs.sunfounder.com/projects/kepler-kit/en/latest/cproject/ar_pir.html#ar-pir


Panoramica
---------------

In questa lezione, imparerai a conoscere il modulo sensore di movimento PIR. Il sensore di movimento a infrarossi passivo (PIR) è un sensore che rileva il movimento. È comunemente usato nei sistemi di sicurezza e nei sistemi di illuminazione automatica. Il sensore ha due slot che rilevano la radiazione infrarossa. Quando un oggetto, come una persona, passa davanti al sensore, questo rileva un cambiamento nella quantità di radiazione infrarossa e attiva un segnale di uscita.

Componenti necessari
-------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

Collegamenti
----------------------

.. image:: img/05-pir_bb.png
   :align: center
   :width: 100%

Schema Elettrico
-----------------------

.. image:: img/05-pir_schematic.png
   :align: center
   :width: 50%

Codice
---------------

.. note::

    * Puoi aprire il file ``05-pir_motion_sensor.ino`` direttamente dal percorso ``elite-explorer-kit-main\basic_project\05-pir_motion_sensor``.
    * Oppure copia questo codice nell'IDE di Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d9fc9198-1538-413d-b501-2cddc8d7cfe6/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato il codice sulla scheda Arduino Uno, puoi aprire il monitor seriale per osservare l'uscita del sensore. Quando il sensore di movimento PIR rileva un movimento, il monitor seriale visualizzerà il messaggio "Somebody here!" per indicare che è stato rilevato un movimento. Se non viene rilevato alcun movimento, verrà mostrato il messaggio "Monitoring...".

Il sensore PIR fornisce un segnale digitale HIGH o LOW, corrispondente rispettivamente a movimento rilevato o non rilevato. A differenza di un sensore analogico che fornisce una gamma di valori, l'uscita digitale di questo sensore PIR sarà HIGH (tipicamente rappresentato come '1') o LOW (tipicamente rappresentato come '0').

Si noti che la sensibilità effettiva e la gamma di rilevamento possono variare in base alle caratteristiche del sensore PIR e alle condizioni ambientali. Pertanto, è consigliabile calibrare il sensore in base alle proprie esigenze specifiche.
