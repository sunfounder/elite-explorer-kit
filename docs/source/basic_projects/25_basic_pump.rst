.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_pump:

Pompa dell'Acqua
==========================

Panoramica
---------------

La pompa dell'acqua è anch'essa un motore, che converte l'energia meccanica del motore o altra energia esterna attraverso una struttura speciale per trasportare il liquido.

Componenti Necessari
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

Puoi anche acquistarli separatamente dai link seguenti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE DEI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pump`
        - 
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_power`
        - \-


Cablaggio
----------------------

.. note::
    Per proteggere la batteria del :ref:`cpn_power`, caricala completamente prima di utilizzarla per la prima volta.

.. image:: img/25-pump_bb.png
    :align: center
    :width: 80%

.. raw:: html
  
  <br/> 

Schema Elettrico
-----------------------

.. image:: img/25_pump_schematic.png


Codice
---------------

.. note::

   * Puoi aprire direttamente il file ``25-pump.ino`` nel percorso ``elite-explorer-kit-main\basic_project\25-pump``.
   * Oppure copia questo codice nell'**IDE di Arduino**.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a530528-aa58-4306-acc9-01632ae5e99a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Collega il tubo alla pompa e posizionalo nella bacinella. Una volta caricato correttamente il codice, la pompa dell'acqua si accenderà e rimarrà attiva per cinque secondi.
Durante questo esperimento, assicurati che il circuito sia tenuto lontano dall'acqua per evitare possibili cortocircuiti.


Analisi del Codice
--------------------------

Il motore può essere azionato fornendo una differenza di tensione tra le lamelle di rame su entrambi i lati del motore.

.. code-block:: arduino
    
   digitalWrite(motorBI, HIGH);
   digitalWrite(motorFI, LOW);
