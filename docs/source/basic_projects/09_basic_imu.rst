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


Calibrazione
----------------------

Prima di leggere i dati del sensore, calibra il modulo IMU per rendere accurate le misurazioni.

#. Installa la libreria **SunFounder_IMU**: apri il Library Manager di Arduino, cerca **"SunFounder_IMU"** e fai clic su **INSTALL**. L'immagine qui sotto mostra la voce dopo l'installazione.

   .. image:: img/09-add_lib_tip_imu.png
      :align: center

#. Apri il file ``09-imu_calibration.ino`` nel percorso ``elite-explorer-kit-main\basic_project\09-imu_calibration`` e caricalo sulla scheda.

#. Apri il monitor seriale e imposta la velocità in baud a **115200** e la fine riga su **Both NL & CR**.

#. Esegui la calibrazione a sei facce seguendo le indicazioni del monitor seriale:

   * Invia un carattere qualsiasi per iniziare. Il monitor seriale mostra quindi il primo orientamento.
   * Metti il modulo nei sei orientamenti nell'ordine indicato: Z verso l'alto, Z verso il basso, X verso l'alto, X verso il basso, Y verso l'alto e Y verso il basso.
   * Mantieni il modulo completamente fermo durante ogni misurazione, poi invia di nuovo un carattere per misurare l'orientamento corrente e passare al successivo.

   .. image:: img/09_imu_cali.png
      :align: center
      :width: 90%

#. Dopo il sesto orientamento il monitor seriale stampa le costanti di calibrazione. Copia le sei righe:

   .. code-block:: text

      Calibration complete!
      Copy the following calibration data to your calibration_data.h:
      const float ACCEL_BIAS[3] = {-0.0345, 0.0192, -0.1268};
      const float ACCEL_SCALE[3] = {1.0012, 0.9987, 1.0005};
      const float GYRO_BIAS[3] = {0.4120, -0.2085, 0.0331};
      const float GYRO_SCALE[3] = {1.0000, 1.0000, 1.0000};
      const float MAG_BIAS[3] = {-212.5000, 87.2500, -341.0000};
      const float MAG_SCALE[3] = {0.9620, 1.0110, 1.0270};

   I valori qui sopra sono solo un esempio; i tuoi appartengono al tuo modulo.

#. Apri il progetto ``09-imu`` e la sua scheda ``calibration_data.h``, e sostituisci i sei array con i valori copiati.

   .. image:: img/imu_cali_data.png
      :align: center
      :width: 80%

#. Carica ``09-imu.ino`` sulla tua scheda Arduino Uno R4. Il monitor seriale stamperà di continuo i dati di accelerometro, giroscopio, magnetometro e barometro.

   .. image:: img/imu_reading.png