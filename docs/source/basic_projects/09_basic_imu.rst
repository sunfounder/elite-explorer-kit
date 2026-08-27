.. note::
    Ciao, benvenuto nella Community degli Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e agli sneak peek.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_imu:

Modulo IMU (10 assi)
==========================

.. note:: Diverse versioni di questo kit possono utilizzare diversi moduli IMU. Seleziona il tutorial appropriato in base alla versione del kit che possiedi. Se hai un modulo IMU a 10 assi, fai riferimento a questo tutorial. Se hai un modulo GY-87, fai riferimento a :ref:`basic_gy87`.

Il modulo IMU a 10 assi (Inertial Measurement Unit) combina più sensori per fornire dati completi su movimento e ambiente. Integra un sensore di pressione barometrica (SPL06_001) per la misurazione dell'altitudine, un sensore di movimento a 6 assi (SH3001) per accelerazione e rotazione, e un magnetometro a 3 assi (QMC6310) per la direzione della bussola. Questo sofisticato modulo è ideale per robotica, sistemi di navigazione e applicazioni di tracciamento del movimento.





Circuito Fritzing
----------------------------------

.. image:: img/imu_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%


Installare la libreria
---------------------------------

Per installare la libreria, usa il Library Manager di Arduino.

   - Cerca **"SunFounder_IMU"** e installa


      .. image:: img/09-add_lib_tip_imu.png



Calibrazione
----------------------

Prima di utilizzare il modulo IMU, si consiglia di eseguire la calibrazione per garantire l'accuratezza dei dati del sensore. Ecco i passaggi di calibrazione:

* Apri direttamente il file ``09-imu_calibration.ino`` nel percorso ``elite-explorer-kit-main\basic_project\09-imu_calibration``.

Dopo aver eseguito questo codice, apri il monitor seriale e vedrai l'output dei dati del sensore. Di solito ha il seguente formato:

.. code-block:: text

   const float ACCEL_BIAS[3] = {0.0, 0.0, 0.0};
   const float ACCEL_SCALE[3] = {1.0, 1.0, 1.0};
   const float GYRO_BIAS[3] = {0.0, 0.0, 0.0};
   const float GYRO_SCALE[3] = {1.0, 1.0, 1.0};
   const float MAG_BIAS[3] = {0.0, 0.0, 0.0};
   const float MAG_SCALE[3] = {1.0, 1.0, 1.0};

Copia questi dati.

Eseguire il codice
----------------------


Apri direttamente il file ``09-imu.ino`` nel percorso ``elite-explorer-kit-main\basic_project\09-imu``.

Vai alla pagina ``calibration_data.h`` nel progetto, incolla i dati che hai appena copiato nel file ``calibration_data.h``, sostituendo i dati originali.

.. image:: img/imu_cali_data.png
   :width: 80%

Torna alla pagina ``09-imu.ino`` e carica il codice sulla tua scheda Arduino Uno R4.

.. literalinclude:: /_code/09_basic_imu.ino
   :language: cpp
   :linenos:
   :caption: 09-imu.ino

Dopo aver caricato con successo il codice sul tuo Arduino Uno R4, il monitor seriale prenderà vita, stampando continuamente i dati dei sensori del modulo IMU a 10 assi.

.. image:: img/imu_reading.png