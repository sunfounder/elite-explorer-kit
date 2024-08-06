.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder per Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri entusiasti.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a promozioni e omaggi festivi.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _i2c_sacnner:

Come scansionare e rilevare gli indirizzi I2C?
==============================================

Questo tutorial utilizza come esempio la scansione dell'indirizzo I2C del modulo gy-87 e ti guida su come rilevare gli indirizzi I2C.

Collegamenti
---------------

Collega il SCL del modulo GY-87 al SCL dell'UNO R4 e collega il SDA del modulo GY-87 al SDA dell'UNO R4.

Un'altra opzione è collegare il SCL del modulo GY-87 al pin A5 dell'UNO R4 e il SDA del modulo GY-87 al pin A4 dell'UNO R4.

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

Carica il codice
---------------------

Copia il codice sottostante nel tuo Arduino IDE e poi caricalo.

.. code-block:: arduino

   #include <Wire.h>
   
   // Imposta il bus I2C da utilizzare: Wire, Wire1, ecc.
   #define WIRE Wire
   
   void setup() {
     WIRE.begin();
   
     Serial.begin(9600);
     while (!Serial)
       delay(10);
     Serial.println("\nI2C Scanner");
   
     // Abilita la modalità bypass per mpu6050
     Wire.beginTransmission(0x68);
     Wire.write(0x37);
     Wire.write(0x02);
     Wire.endTransmission();
   
     Wire.beginTransmission(0x68);
     Wire.write(0x6A);
     Wire.write(0x00);
     Wire.endTransmission();
   
     // Disabilita la modalità Sleep
     Wire.beginTransmission(0x68);
     Wire.write(0x6B);
     Wire.write(0x00);
     Wire.endTransmission();
   }
   
   
   void loop() {
     byte error, address;
     int nDevices;
   
     Serial.println("Scanning...");
   
     nDevices = 0;
     for (address = 1; address < 127; address++) {
       // L'i2c_scanner utilizza il valore di ritorno di
       // Wire.endTransmission per verificare se
       // un dispositivo ha riconosciuto l'indirizzo.
       WIRE.beginTransmission(address);
       error = WIRE.endTransmission();
   
       if (error == 0) {
         Serial.print("I2C device found at address 0x");
         if (address < 16)
           Serial.print("0");
         Serial.print(address, HEX);
         Serial.println("  !");
   
         nDevices++;
       } else if (error == 4) {
         Serial.print("Unknown error at address 0x");
         if (address < 16)
           Serial.print("0");
         Serial.println(address, HEX);
       }
     }
     if (nDevices == 0)
       Serial.println("No I2C devices found\n");
     else
       Serial.println("done\n");
   
     delay(5000);  // aspetta 5 secondi per la prossima scansione
   }


Dopo aver caricato il codice, apri il monitor seriale e imposta il baud rate a 9600. Controlla l'output nel monitor seriale.

Questi sono gli indirizzi I2C rilevati. Puoi fare riferimento alle informazioni pertinenti per determinare a quali chip corrispondono questi indirizzi. In questo caso, ``0x68`` è per MPU6050 e ``0x77`` è per BMP180. L'indirizzo ``0x1E`` è per QMC5883L e occasionalmente (a causa di diversi lotti di produzione) l'indirizzo di QMC5883L può anche essere ``0x0D``.

.. image:: img/gy87-i2c.png
    :width: 100%