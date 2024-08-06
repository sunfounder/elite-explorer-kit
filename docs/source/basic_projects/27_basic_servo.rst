.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_servo:

Servo
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/servo_uno.html#servo-uno

Panoramica
---------------

In questa lezione, esplorerai l'uso di Arduino e dei motori Servo. Concentrandoti sull'Arduino Uno e sul servo motore SG90, imparerai a programmare l'Arduino per controllare il movimento oscillante del servo. Questa tecnica è essenziale in varie applicazioni come la robotica e i sistemi automatizzati.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

Cablaggio
----------------------

.. image:: img/27-servo_bb.png
    :align: center
    :width: 70%

.. raw:: html

   <br/>

Schema Elettrico
-----------------------

.. image:: img/27_servo_schematic.png
    :align: center
    :width: 60%

Codice
---------------

.. note::

    * Puoi aprire il file ``27-servo.ino`` nel percorso ``elite-explorer-kit-main\basic_project\27-servo`` direttamente.
    * Oppure copia questo codice nell'IDE di Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c57ddb7a-0acb-4a64-938a-0a0abfc0ec4b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Analisi del Codice
------------------------


1. Qui, viene inclusa la libreria ``Servo`` che permette un facile controllo del motore servo. Viene definito il pin collegato al servo e l'angolo iniziale del servo.

   .. code-block:: arduino

      #include <Servo.h>
      const int servoPin = 9;  // Definisce il pin del servo
      int angle = 0;           // Inizializza la variabile angolo a 0 gradi
      Servo servo;             // Crea un oggetto servo

2. La funzione ``setup()`` viene eseguita una sola volta quando l'Arduino si avvia. Il servo viene collegato al pin definito utilizzando la funzione ``attach()``.

   .. code-block:: arduino

      void setup() {
        servo.attach(servoPin);
      }

3. Il ciclo principale contiene due cicli ``for``. Il primo ciclo aumenta l'angolo da 0 a 180 gradi, e il secondo ciclo diminuisce l'angolo da 180 a 0 gradi. Il comando ``servo.write(angle)`` imposta il servo all'angolo specificato. Il ``delay(15)`` fa sì che il servo aspetti per 15 millisecondi prima di passare all'angolo successivo, controllando la velocità del movimento di scansione.

   .. code-block:: arduino

      void loop() {
        // scansiona da 0 a 180 gradi
        for (angle = 0; angle < 180; angle++) {
          servo.write(angle);
          delay(15);
        }
        // ora scansiona indietro da 180 a 0 gradi
        for (angle = 180; angle > 0; angle--) {
          servo.write(angle);
          delay(15);
        }
      }