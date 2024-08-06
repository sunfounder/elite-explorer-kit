.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_gy87_qmc5883l:

QMC5883L
==========================

Panoramica
---------------

In questo tutorial esploreremo il modulo IMU GY-87, concentrandoci sul magnetometro QMC5883L. La prima parte del tutorial ti guiderà nella calibrazione del magnetometro QMC5883L, essenziale per misurazioni accurate del campo magnetico. Imparerai come caricare uno sketch di calibrazione su Arduino, eseguire la calibrazione in tempo reale e applicare queste impostazioni nei tuoi progetti. La seconda parte del tutorial copre l'inizializzazione dell'MPU6050 (accelerometro e giroscopio) e del QMC5883L su un Arduino Uno utilizzando le librerie Adafruit MPU6050 e QMC5883LCompass. Imparerai come leggere e visualizzare i dati dei sensori sul Serial Monitor, una competenza fondamentale per applicazioni in navigazione, tracciamento dei movimenti e rilevamento dell'orientamento.

Componenti necessari
-------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - OGGETTI IN QUESTO KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

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

Cablaggio
----------------------

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 90%

.. raw:: html

   <br/>

Schema elettrico
-----------------------

.. image:: img/09_basic_gy87_schematic.png
    :align: center
    :width: 60%

Installazione della libreria
-------------------------------------

.. note:: 
    Per installare la libreria, usa il Gestore Librerie di Arduino.
    
        - Cerca **"Adafruit MPU6050"** e installa.

          Durante l'installazione di ogni libreria, assicurati di selezionare l'installazione di tutte le dipendenze.
      
          .. image:: img/09-add_lib_tip.png
             :width: 80%

        - Cerca **"QMC5883LCompass"** e installa.

.. _basic_gy87_calibrate:

Calibrare QMC5883L
-----------------------

.. note::

    * Puoi aprire direttamente il file ``09-gy87_compass_calibration.ino`` nel percorso ``elite-explorer-kit-main\basic_project\09-gy87_compass_calibration``.
    * Oppure copia questo codice nell'IDE di Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/252c7a58-3a9f-4c66-959e-f45fc19e68aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato il codice, apri il monitor seriale. Segui le istruzioni nel monitor seriale per calibrare il QMC5883L. Quando ti viene chiesto di muovere il sensore, si consiglia di utilizzare il metodo di calibrazione a 8. In alternativa, mantieni semplicemente il sensore parallelo al suolo e ruotalo in senso orario o antiorario fino a quando il monitor seriale indica che la calibrazione è completa.

.. image:: img/09_calibrate_qmc5883l.png
    :width: 100%
    :align: center

Una volta raccolti tutti i dati di calibrazione, lo sketch ti fornirà un codice simile a ``compass.setCalibrationOffsets(-375.00, -179.00, 85.00);`` e ``compass.setCalibrationScales(1.04, 0.96, 1.01);``. Copia questo codice. Potresti volerlo salvare per riferimento futuro.

Quando utilizzi il QMC5883L: apri lo sketch del tuo progetto e incolla la linea di codice copiata direttamente sotto la chiamata ``compass.init()``. Proprio così:

.. code:: arduino 

   void initializeQMC5883L() {
   
     compass.init();
   
     // Sostituisci il codice sottostante con i risultati della tua calibrazione
     compass.setCalibrationOffsets(-375.00, -179.00, 85.00);
     compass.setCalibrationScales(1.04, 0.96, 1.01);
   
   }

Codice
---------------------------------------------

.. note::

   I magnetometri devono essere calibrati (:ref:`basic_gy87_calibrate`) prima di poter essere utilizzati come bussole e devono essere mantenuti livellati durante l'uso e **tenuti lontani da oggetti di ferro, materiali magnetizzati e fili portatori di corrente**.

.. note::

    * Puoi aprire direttamente il file ``09-gy87_qmc5883l.ino`` nel percorso ``elite-explorer-kit-main\basic_project\09-gy87_qmc5883l``.
    * Oppure copia questo codice nell'IDE di Arduino.
    * Inserisci il codice ottenuto dai passaggi di calibrazione sotto la linea di codice ``compass.init()`` nella funzione ``initializeQMC5883L()``.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b266a18-ce7b-4330-8c10-c9f4148bb8ec/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Analisi del Codice
------------------------

#. Includere le Librerie e Inizializzare i Sensori
   Questa sezione include le librerie necessarie per i sensori MPU6050 e QMC5883L e inizializza i loro oggetti.

   .. code-block:: arduino
      
      #include <Adafruit_MPU6050.h>
      #include <Adafruit_Sensor.h>
      #include <Wire.h>
      #include <QMC5883LCompass.h>

      Adafruit_MPU6050 mpu;
      QMC5883LCompass compass;

#. Funzione di Setup

   Inizializza la comunicazione seriale, il sensore MPU6050 e imposta l'MPU6050 in modalità bypass I2C per consentire l'accesso diretto al magnetometro QMC5883L. Successivamente, inizializza il magnetometro QMC5883L.

   .. code-block:: arduino
      
      void setup() {
        // Inizializza la comunicazione seriale con una velocità di trasmissione di 9600 baud
        Serial.begin(9600);
      
        // Inizializza il sensore MPU6050 (accelerometro e giroscopio)
        initializeMPU6050();
      
        // Abilita il bypass I2C su MPU6050 per accedere direttamente al magnetometro QMC5883L
        mpu.setI2CBypass(true);
      
        // Inizializza il sensore magnetometro QMC5883L
        initializeQMC5883L();
      }

#. Funzione Loop

   Legge continuamente i dati dal magnetometro QMC5883L e li stampa sul Monitor Seriale.

   .. code-block:: arduino
      
      void loop() {
        printQMC5883L();
        delay(500);
      }

#. Funzione di Inizializzazione del QMC5883L

   Inizializza e calibra il magnetometro QMC5883L. I valori di calibrazione devono essere regolati in base ai dati di calibrazione specifici.(:ref:`basic_gy87_calibrate`)

   .. code-block:: arduino
      
      void initializeQMC5883L() {
        compass.init();
      
        // Sostituisci il codice sottostante con i risultati della tua calibrazione
        compass.setCalibrationOffsets(-549.00, -66.00, 160.00);
        compass.setCalibrationScales(0.97, 1.02, 1.02);
      }

#. Funzione di Stampa dei Dati del QMC5883L

   Questa funzione legge i valori X, Y, Z e l'azimuth del magnetometro, quindi li stampa sul Monitor Seriale.

   .. code-block:: arduino

    void printQMC5883L() {
    
      Serial.println();
      Serial.println("QMC5883L ------------");
    
    	int x, y, z, a;
    	char myArray[3];
    	
    	compass.read();
      
    	x = compass.getX();
    	y = compass.getY();
    	z = compass.getZ();
    	
    	a = compass.getAzimuth();
    
    	compass.getDirection(myArray, a);
      
    	Serial.print("X: ");
    	Serial.print(x);
    
    	Serial.print(" Y: ");
    	Serial.print(y);
    
    	Serial.print(" Z: ");
    	Serial.print(z);
    
    	Serial.print(" Azimuth: ");
    	Serial.print(a);
    
    	Serial.print(" Direction: ");
    	Serial.print(myArray[0]);
    	Serial.print(myArray[1]);
    	Serial.println(myArray[2]);
    
      Serial.println("QMC5883L ------------");
      Serial.println();
    }
