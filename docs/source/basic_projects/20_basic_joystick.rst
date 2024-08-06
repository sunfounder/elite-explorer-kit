.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_joystick:

Modulo Joystick
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/joystick_ps2_uno.html#joystick-uno


Panoramica
---------------

Un joystick è un dispositivo di input costituito da un'asta che ruota su una base e segnala il suo angolo o direzione al dispositivo che sta controllando. I joystick sono spesso utilizzati per controllare i videogiochi e i robot. Qui viene utilizzato un Joystick PS2.

Componenti Necessari
----------------------------

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

Cablaggio
----------------------

.. image:: img/20-joystick_bb.png
    :align: center
    :width: 70%

Schema Elettrico
---------------------

Questo modulo ha due uscite analogiche (corrispondenti agli offset biaxiali X,Y).

In questo esperimento, utilizziamo la scheda Uno per rilevare la direzione di movimento della manopola del joystick.

.. image:: img/20_joystick_schematic.png
    :align: center 
    :width: 70%

Codice
----------

.. note::

    * Puoi aprire direttamente il file ``20-joystick.ino`` nel percorso ``elite-explorer-kit-main\basic_project\20-joystick``.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ac0f9910-e53e-43a3-a5ae-ec4d3a3f4aa1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ora, quando spingi la leva, le coordinate degli assi X e Y visualizzate sul Monitor Seriale cambieranno di conseguenza. Premendo il pulsante verrà visualizzata anche la coordinata Z=0.


Analisi del Codice
----------------------

Il codice utilizza il monitor seriale per stampare il valore dei pin VRX e VRY del joystick ps2.

.. code-block:: arduino

    void loop()
    {
        Serial.print("X: "); 
        Serial.print(analogRead(xPin), DEC);  // stampa il valore di VRX in DEC
        Serial.print("|Y: ");
        Serial.print(analogRead(yPin), DEC);  // stampa il valore di VRY in DEC
        Serial.print("|Z: ");
        Serial.println(digitalRead(swPin));  // stampa il valore di SW
        delay(50);
    }