.. note::
    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_gy87:

Modulo IMU (GY-87)
==========================

.. note:: Diverse versioni di questo kit possono utilizzare diversi moduli IMU. Seleziona il tutorial appropriato in base alla versione del kit che possiedi. Se hai un modulo IMU a 10 assi, fai riferimento a :ref:`basic_imu`. Se hai un modulo GY-87, fai riferimento a questa lezione.

Il modulo GY-87 è dotato di tre chip sensori: MPU6050, QMC5883L e BMP180, ciascuno con capacità uniche. L'MPU6050 combina un giroscopio e un accelerometro per il tracciamento dei movimenti, il QMC5883L funge da magnetometro per il rilevamento della direzione e il BMP180 viene utilizzato per misurare la pressione barometrica e la temperatura. Questi possono essere interfacciati utilizzando il protocollo I2C per una comunicazione efficace con un Arduino.

Questi sensori sono progettati per un'integrazione senza soluzione di continuità tramite il protocollo I2C, garantendo una comunicazione efficiente con piattaforme come Arduino. Ogni sensore nel modulo GY-87 è accessibile attraverso indirizzi I2C unici: l'MPU6050 è accessibile a 0x68, il QMC5883L a 0x0D e il BMP180 a 0x77.

Tutorial individuali per ciascun chip sensore:

.. toctree::
    :maxdepth: 1

    09_basic_gy87_bmp180
    09_basic_gy87_mpu6050
    09_basic_gy87_qmc5883l

.. raw:: html

   <br/>

.. **Codice per il modulo GY-87**

Se vuoi utilizzare questi tre chip contemporaneamente, ecco un semplice esempio:

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

.. .. image:: img/09_basic_gy87_schematic.png
..     :align: center
..     :width: 90%

.. note::
    * Puoi aprire il file ``09-gy87.ino`` sotto il percorso ``elite-explorer-kit-main\basic_project\09-gy87`` direttamente.
    * Oppure copia questo codice nell'Arduino IDE.

.. note::    Per installare la libreria, usa l'Arduino Library Manager.

        - Cerca **"Adafruit MPU6050"** e installa

          Durante l'installazione di ciascuna libreria, 
          assicurati di selezionare l'installazione di tutte le dipendenze.

          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Cerca **"Adafruit Unified Sensor"** e installa
        - Cerca **"QMC5883LCompass"** e installa
        - Cerca **"Adafruit BMP085 Library"** e installa

.. literalinclude:: /_code/09_basic_gy87.ino
   :language: cpp
   :linenos:
   :caption: 09-gy87.ino

.. note::    I magnetometri devono essere calibrati (:ref:`basic_gy87_calibrate`) prima di poter essere utilizzati come bussole, devono essere mantenuti in piano durante l'uso e **tenuti lontani da oggetti in ferro, materiali magnetizzati e fili che trasportano corrente**.

Dopo che il codice è stato caricato con successo sul tuo Arduino Uno R4, il Monitor Seriale prenderà vita, stampando continuamente i dati dei sensori dal modulo GY-87 IMU. Questo modulo incorpora tre sensori individuali: l'MPU6050 per le letture di accelerometro e giroscopio, il QMC5883L per le letture del magnetometro e il BMP180 per le letture di pressione barometrica e temperatura.
