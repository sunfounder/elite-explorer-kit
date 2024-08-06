.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_moisture:

Umidità del Suolo
===========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_moisture.html

Panoramica
---------------

Nell'industria agricola, le colture non possono acquisire direttamente elementi inorganici dal suolo. Invece, l'acqua presente nel suolo funge da solvente per dissolvere questi elementi.

Le colture assorbono l'umidità dal suolo attraverso il loro sistema radicale per ottenere nutrienti e facilitare la crescita.

Durante la crescita e lo sviluppo delle colture, ci sono diverse esigenze per la temperatura del suolo. Pertanto, è necessario utilizzare un sensore di umidità del suolo.

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

Collegamenti
----------------------

.. image:: img/03-soil_moisture_bb.png
    :align: center
    :width: 80%

Schema Elettrico
-----------------------

.. image:: img/03_moisture_schematic.webp
    :align: center
    :width: 70%

Codice
---------------

.. note::

    * Apri il file ``03-moisture.ino`` dal percorso ``elite-explorer-kit-main\basic_project\03-moisture``.
    * Oppure copia questo codice nell'**Arduino IDE**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c585dd77-2e8a-4839-a908-d22e1d6e93aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Una volta caricato correttamente il codice, il monitor seriale stamperà il valore dell'umidità del suolo.

Inserendo il modulo nel terreno e annaffiandolo, il valore del sensore di umidità del suolo diminuirà.
