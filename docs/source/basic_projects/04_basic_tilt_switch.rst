.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_tilt_switch:

Interruttore a Inclinazione
===============================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.17_tilt_switch.html#ar-tilt

Panoramica
---------------

In questa lezione, imparerai a conoscere l'interruttore a inclinazione. Questo dispositivo può essere utilizzato per rilevare l'inclinazione degli oggetti, il che è di grande valore nelle applicazioni pratiche. Può essere impiegato per valutare l'inclinazione di ponti, edifici, torri di linee di trasmissione e così via, avendo quindi un'importante funzione di guida nel condurre lavori di manutenzione.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_tilt_switch`
        - \-

Circuito Fritzing
---------------------

In questo esempio, il pin digitale 2 è utilizzato per leggere il segnale dell'interruttore a inclinazione.

.. image:: img/04-tilt_switch_bb.png
   :align: center
   :width: 85%

Schema Elettrico
-----------------------

.. image:: img/04_tilt_switch_schematic.png
   :align: center
   :width: 70%

Codice
----------

.. note::

    * Puoi aprire il file ``04-tilt_switch.ino`` direttamente dal percorso ``elite-explorer-kit-main\basic_project\04-tilt_switch``.
    * Oppure copia questo codice nell'IDE di Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d85d75d9-e491-424c-93be-95e1f4e99549/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una volta caricato il codice sulla scheda uno r4, puoi aprire il monitor seriale per visualizzare le letture del pin. Le letture mostreranno "1" o "0" a seconda che l'interruttore a inclinazione sia in posizione verticale (con la sfera di metallo interna che fa contatto con i pin) o inclinato.
