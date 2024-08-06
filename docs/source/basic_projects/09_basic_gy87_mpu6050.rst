.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_gy87_mpu6050:

MPU6050
==========================


Panoramica
---------------

In questo tutorial, imparerai a interfacciare il modulo IMU GY-87 con un Arduino Uno, concentrandoti sul sensore MPU6050. Tratteremo l'inizializzazione del MPU6050 e la visualizzazione dei dati dell'accelerometro, giroscopio e temperatura sul Monitor Seriale. Questa lezione è essenziale per progetti che richiedono il rilevamento del movimento e della temperatura, come robotica, dispositivi controllati da gesti e installazioni artistiche interattive.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_gy87`
        - \-

Collegamenti
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 75%

.. raw:: html

   <br/>

Schema Elettrico
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%

Codice
-----------

.. note::

    * Puoi aprire il file ``09-gy87_mpu6050.ino`` dal percorso ``elite-explorer-kit-main\basic_project\09-gy87_mpu6050`` direttamente.
    * Oppure copia questo codice nell'IDE di Arduino.

.. note:: 
    Per installare la libreria, usa il Library Manager di Arduino e cerca **"Adafruit MPU6050"** e installala.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/f89edd5d-e6f9-4f83-979c-6c1d5da3e9d7/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Analisi del Codice
------------------------

#. Includi Librerie

   Le librerie ``Adafruit_MPU6050``, ``Adafruit_Sensor`` e ``Wire`` sono incluse per l'interfacciamento e la comunicazione del sensore.

   .. code-block:: arduino

      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>

#. Inizializza Oggetto Sensore

   Viene creato un oggetto della classe Adafruit_MPU6050 per rappresentare il sensore MPU6050.

   .. code-block:: arduino

      Adafruit_MPU6050 mpu;

#. Funzione di Setup

   Inizializza la comunicazione seriale e chiama la funzione per inizializzare il sensore MPU6050.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        initializeMPU6050();
      }

#. Funzione di Loop

   Chiama ripetutamente la funzione per stampare i dati del MPU6050 con un ritardo di 500 millisecondi tra ogni chiamata.

   .. code-block:: arduino

      void loop() {
        printMPU6050();
        delay(500);
      }

#. Funzione di Inizializzazione del MPU6050

   Controlla se il MPU6050 è collegato, imposta i range di accelerometro e giroscopio, e configura la larghezza di banda del filtro.

   .. code-block:: arduino

      void initializeMPU6050() {
        // Controlla se il sensore MPU6050 è rilevato
        if (!mpu.begin()) {
          Serial.println("Failed to find MPU6050 chip");
          while (1)
            ;  // Blocca se il sensore non è trovato
        }
        Serial.println("MPU6050 Found!");
      
        // imposta il range dell'accelerometro a +-8G
        mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
      
        // imposta il range del giroscopio a +- 500 deg/s
        mpu.setGyroRange(MPU6050_RANGE_500_DEG);
      
        // imposta la larghezza di banda del filtro a 21 Hz
        mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
      
        Serial.println("");
        delay(100);
      }

#. Funzione per Stampare i Dati del MPU6050

   Legge e stampa i dati di accelerazione, giroscopio e temperatura dal MPU6050 sul Monitor Seriale.

   .. code-block:: arduino

      void printMPU6050() {
      
        Serial.println();
        Serial.println("MPU6050 ------------");
      
        /* Ottieni nuovi eventi del sensore con le letture */
        sensors_event_t a, g, temp;
        mpu.getEvent(&a, &g, &temp);
      
        /* Stampa i valori */
        Serial.print("Accelerazione X: ");
        Serial.print(a.acceleration.x);
        Serial.print(", Y: ");
        Serial.print(a.acceleration.y);
        Serial.print(", Z: ");
        Serial.print(a.acceleration.z);
        Serial.println(" m/s^2");
      
        Serial.print("Rotation X: ");
        Serial.print(g.gyro.x);
        Serial.print(", Y: ");
        Serial.print(g.gyro.y);
        Serial.print(", Z: ");
        Serial.print(g.gyro.z);
        Serial.println(" rad/s");
      
        Serial.print("Temperature: ");
        Serial.print(temp.temperature);
        Serial.println(" degC");
      
        Serial.println("MPU6050 ------------");
        Serial.println();
      }
