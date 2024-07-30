.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Plongez-vous dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Remises spéciales** : Profitez de remises exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des cadeaux et promotions de vacances.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_mpr121:

MPR121
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.24_mpr121_module.html#ar-mpr121


Aperçu
---------------

Dans cette leçon, vous apprendrez à utiliser le MPR121. C'est une bonne option lorsque vous souhaitez ajouter de nombreux interrupteurs tactiles à votre projet. L'électrode du MPR121 peut être étendue avec un conducteur. Si vous connectez un fil à une banane, vous pouvez transformer la banane en un interrupteur tactile, réalisant ainsi des projets comme un piano de fruits.

Composants nécessaires
-------------------------

Pour ce projet, nous avons besoin des composants suivants. 

Il est définitivement pratique d'acheter un kit complet, voici le lien : 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Kit Elite Explorer
        - 300+
        - |link_Elite_Explorer_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_mpr121`
        - \-

Câblage
----------------------

Dans cet exemple, nous insérons le MPR121 dans la breadboard. Connectez le GND du MPR121 à GND, 3.3V à 3V3, IRQ à la broche numérique 2, SCL à la broche SCL (A5), et SDA à la broche SDA (A4). Il y a 12 électrodes pour la détection tactile. 

.. note::
    Le MPR121 est alimenté par 3,3V, pas par 5V.

.. image:: img/23-mpr121_bb.png
    :align: center
    :width: 70%

Schéma de câblage
----------------------

.. image:: img/23_mpr121_schematic.png
   :align: center
   :width: 70%

Code
--------

.. note::

    * Vous pouvez ouvrir le fichier ``23-mpr121.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\23-mpr121`` directement.
    * La bibliothèque ``Adafruit MPR121`` est utilisée ici, vous pouvez l'installer à partir du **Gestionnaire de bibliothèques**.

        .. image:: img/22_mpr121_lib.png
            :align: center

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/de0aa390-de85-43ab-87f7-f380c67c65e8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir téléchargé le code sur la carte UNO, l'état tactile des broches MPR121 "1" et "0" sera enregistré dans un tableau booléen de 12 bits. Ce tableau sera ensuite imprimé sur le moniteur série.

Analyse du code
--------------------
Ce code facilite la communication et l'utilisation du capteur tactile MPR121. Il peut détecter l'état des électrodes tactiles et imprimer des informations sur les électrodes touchées ou relâchées sur l'interface série. Si des données de capteur détaillées sont nécessaires, le code pertinent peut être décommenté.

Voici une analyse du code :

#. Importation des bibliothèques :

   .. code-block:: arduino

       #include <Wire.h>
       #include "Adafruit_MPR121.h"

   * ``Wire.h`` : Utilisé pour la communication I2C.
   * ``Adafruit_MPR121.h`` : Bibliothèque Adafruit pour le capteur tactile MPR121.

#. Définition de la macro ``_BV`` :

   .. code-block:: arduino

       #ifndef _BV
       #define _BV(bit) (1 << (bit)) 
       #endif
   
   ``_BV(bit)`` définit une macro qui convertit un bit donné en valeur binaire correspondante, similaire à 1 << bit.

#. Initialisation de l'instance de la classe ``Adafruit_MPR121`` :

   .. code-block:: arduino

       Adafruit_MPR121 cap = Adafruit_MPR121();

   Création d'une instance de la classe ``Adafruit_MPR121`` nommée ``cap``. L'objet ``cap`` sera utilisé pour communiquer avec et utiliser le capteur tactile MPR121.

#. Fonction ``setup()`` :

   Initialisation de la communication série à un débit de 9600 bauds. Puis, initialisation du capteur tactile MPR121 avec l'adresse I2C par défaut de 0x5A. Si l'initialisation échoue, imprimer un message d'erreur et entrer dans une boucle infinie.

   .. code-block:: arduino

       void setup() {
           Serial.begin(9600);
           
           while (!Serial) { // nécessaire pour éviter que leonardo/micro ne démarre trop vite !
               delay(10);
           }
           
           Serial.println("Test du capteur tactile capacitif Adafruit MPR121"); 
           
           // L'adresse par défaut est 0x5A, si reliée à 3.3V c'est 0x5B
           // Si reliée à SDA c'est 0x5C et si à SCL alors 0x5D
           if (!cap.begin(0x5A)) {
               Serial.println("MPR121 non trouvé, vérifier le câblage ?");
               while (1);
           }
           Serial.println("MPR121 trouvé !");
       }

#. Fonction ``loop()`` :

   * Obtenir l'état actuel du toucher, renvoyé sous forme d'entier 16 bits.

     .. code-block:: arduino

         currtouched = cap.touched();

   * Parcourir l'état des 12 électrodes (numérotées de 0 à 11).

     .. code-block:: arduino

         for (uint8_t i=0; i<12; i++) {
             // si *est* touchée et *n'était pas* touchée avant, alerte !
             if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
                 Serial.print(i); Serial.println(" touched");
             }
             // si *était* touchée et maintenant *ne l'est pas*, alerte !
             if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
                 Serial.print(i); Serial.println(" released");
             }
         }

     * Si une électrode est touchée et ne l'était pas avant, imprimer "x touchée", où x est le numéro de l'électrode.
     * Si une électrode était touchée avant mais ne l'est plus maintenant, imprimer "x relâchée."

   * Mettre à jour ``lasttouched`` pour stocker l'état actuel du toucher pour comparaison lors de la prochaine itération.

     .. code-block:: arduino

         lasttouched = currtouched;

   * Informations de débogage (section optionnelle) :

     .. code-block:: arduino

         // informations de débogage, ce qui
         Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
         Serial.print("Filt: ");
         for (uint8_t i=0; i<12; i++) {
             Serial.print(cap.filteredData(i)); Serial.print("\t");
         }
         Serial.println();
         Serial.print("Base: ");
         for (uint8_t i=0; i<12; i++) {
             Serial.print(cap.baselineData(i)); Serial.print("\t");
         }
         Serial.println();
         
         // ajouter un délai pour ne pas submerger
         delay(100);
