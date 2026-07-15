.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_thermistor:

Termistore
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.27_thermistor.html#ar-thermistor

Panoramica
-------------

In questa lezione, imparerai a usare il termistore. Il termistore può essere utilizzato come componente del circuito elettronico per la compensazione della temperatura dei circuiti degli strumenti. Nei dispositivi come amperometri, flussometri, analizzatori di gas e altri dispositivi. Può anche essere utilizzato per la protezione dal surriscaldamento, relè senza contatto, temperatura costante, controllo automatico del guadagno, avviamento del motore, ritardo temporale, smagnetizzazione automatica dei televisori a colori, allarmi antincendio e compensazione della temperatura.

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

Collegamenti
----------------------

In questo esempio, utilizziamo il pin analogico A0 per ottenere il valore del termistore. Un pin del termistore è collegato a 5V, e l'altro è collegato ad A0. Allo stesso tempo, un resistore da 10kΩ è collegato all'altro pin prima di collegarlo a GND.

.. image:: img/02-thermistor_bb.png
    :align: center
    :width: 70%

Schema Elettrico
-----------------------

.. image:: img/02_thermistor_schematic.png
   :align: center
   :width: 70%

Codice
-----------

.. note::

    * Puoi aprire il file ``02-thermistor.ino`` direttamente dal percorso ``elite-explorer-kit-main\basic_project\02-thermistor``.
    * Oppure copia questo codice nell'IDE di Arduino.

.. literalinclude:: /_code/02_basic_thermistor.ino
   :language: cpp
   :linenos:
   :caption: 02-thermistor.ino

Dopo aver caricato il codice sulla scheda uno r4, puoi aprire il monitor seriale per controllare la temperatura corrente.

La temperatura in Kelvin è calcolata utilizzando la formula **T\ K\ =1/(ln(R\ T/R\ N)/B+1/T\ N)**. Questa equazione è derivata dalla |link_steinhart_hart| e semplifica i calcoli. Puoi trovare ulteriori informazioni su questa formula nella pagina di introduzione dettagliata del :ref:`cpn_thermistor`.
