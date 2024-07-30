.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _i2c_sacnner:

Comment scanner et détecter les adresses I2C ?
================================================

Ce tutoriel utilise comme exemple le scan de l'adresse I2C du module gy-87 et vous guide sur la détection des adresses I2C.

Câblage
---------------

Connectez le SCL du module GY-87 au SCL de l'UNO R4, et connectez le SDA du module GY-87 au SDA de l'UNO R4.

Une autre méthode consiste à connecter le SCL du module GY-87 à A5 de l'UNO R4, et à connecter le SDA du module GY-87 à A4 de l'UNO R4.

.. image:: img/09-gy87_bb.png
    :align: center
    :width: 80%

.. raw:: html

   <br/>

Télécharger le code
-------------------------

Copiez le code ci-dessous dans votre Arduino IDE puis téléchargez-le.

.. code-block:: arduino

   #include <Wire.h>
   
   // Définir le bus I2C à utiliser : Wire, Wire1, etc.
   #define WIRE Wire
   
   void setup() {
     WIRE.begin();
   
     Serial.begin(9600);
     while (!Serial)
       delay(10);
     Serial.println("\nI2C Scanner");
   
     // Activer le mode bypass pour le mpu6050
     Wire.beginTransmission(0x68);
     Wire.write(0x37);
     Wire.write(0x02);
     Wire.endTransmission();
   
     Wire.beginTransmission(0x68);
     Wire.write(0x6A);
     Wire.write(0x00);
     Wire.endTransmission();
   
     // Désactiver le mode veille
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
       // Le i2c_scanner utilise la valeur de retour de
       // Write.endTransmission pour voir si
       // un périphérique a reconnu l'adresse.
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
   
     delay(5000);  // attendre 5 secondes avant le prochain scan
   }


Après avoir téléchargé le code, ouvrez le moniteur série et réglez la vitesse de transmission à 9600 bauds. Vérifiez la sortie dans le moniteur série.

Voici les adresses I2C détectées. Vous pouvez vous référer aux informations pertinentes pour déterminer à quels composants correspondent ces adresses. Dans ce cas, ``0x68`` est pour le MPU6050 et ``0x77`` pour le BMP180. L'adresse ``0x1E`` est pour le QMC5883L, et occasionnellement (en raison de différents lots de production), l'adresse du QMC5883L peut également être ``0x0D``.

.. image:: img/gy87-i2c.png
    :width: 100%