.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_ble_home:

Bluetooth Environmental Monitor
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/08_iot_ble_home.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Ce projet utilise une application Android créée avec MIT App Inventor pour recevoir et afficher des données environnementales provenant d'une carte Arduino. La carte Arduino récupère les données d'un capteur DHT11 pour mesurer la température et l'humidité. Une fois les données collectées, elles sont transmises via Bluetooth. L'application affiche les données à l'écran dès qu'elle les reçoit.

L'application Android sera construite en utilisant une plateforme web gratuite appelée |link_appinventor|. Ce projet est une excellente occasion de se familiariser avec l'interfaçage d'un Arduino avec un smartphone.

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants. 

Il est certainement pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom	
        - ARTICLES DANS CE KIT
        - LIEN
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Vous pouvez également les acheter séparément à partir des liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DU COMPOSANT
        - LIEN D'ACHAT

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|

**1. Construire le circuit**

.. image:: img/08-bluetooth_environmental_monitor_bb.png
    :width: 80%
    :align: center

.. image:: img/08_ble_home_schematic.png
    :width: 30%
    :align: center

.. raw:: html

   <br/>

**2. Créer l'application Android**

L'application Android sera développée en utilisant une application web gratuite 
appelée |link_appinventor|. MIT App Inventor est un excellent point de départ 
pour le développement Android, grâce à ses fonctionnalités intuitives de glisser-déposer 
qui permettent de créer des applications simples.

Commençons maintenant.

#. Allez sur |link_appinventor_login|, et cliquez sur "online tool" pour vous connecter. Vous aurez besoin d'un compte Google pour vous inscrire sur MIT App Inventor.

   .. image:: img/08_ai_signup.png
       :width: 90%
       :align: center

#. Après vous être connecté, naviguez vers **Projects** -> **Import project (.aia) from my computer**. Ensuite, téléchargez le fichier ``ble_environmental_monitor.aia`` situé dans le chemin ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor``.

   Vous pouvez également le télécharger directement ici : :download:`ble_environmental_monitor.aia</_static/other/ble_environmental_monitor.aia>`

   .. image:: img/08_ai_import.png
        :align: center

#. Après avoir téléchargé le fichier ``.aia``, vous verrez l'application dans le logiciel MIT App Inventor. Il s'agit d'un modèle pré-configuré. Vous pouvez modifier ce modèle après vous être familiarisé avec MIT App Inventor en suivant les étapes ci-dessous.

#. Dans MIT App Inventor, vous avez 2 sections principales : le **Designer** et les **Blocks**. Vous pouvez passer d'une section à l'autre en haut à droite de la page.

   .. image:: img/08_ai_intro_1.png

#. Le **Designer** vous permet d'ajouter des boutons, du texte, des écrans et de modifier l'esthétique générale de votre application.

   .. image:: img/08_ai_intro_2.png
      :width: 100%
   
#. Ensuite, il y a la section **Blocks**. Cette section vous permet de créer des fonctionnalités personnalisées pour votre application, vous permettant de programmer chaque composant de l'interface utilisateur de l'application pour obtenir les fonctionnalités souhaitées.

   .. image:: img/08_ai_intro_3.png
      :width: 100%

#. Pour installer l'application sur un smartphone, naviguez vers l'onglet **Build**.

   .. image:: img/08_ai_intro_4.png

   * Vous pouvez générer un fichier ``.apk``. Après avoir sélectionné cette option, une page apparaîtra vous permettant de choisir entre télécharger un fichier ``.apk`` ou scanner un code QR pour l'installation. Suivez le guide d'installation pour compléter l'installation de l'application. 

     Vous pouvez également télécharger notre APK pré-compilé ici : :download:`ble_environmental_monitor.apk</_static/other/ble_environmental_monitor.apk>`

   * Si vous souhaitez télécharger cette application sur Google Play ou une autre marketplace d'applications, vous pouvez générer un fichier ``.aab``.


**3. Téléchargez le code**

#. Ouvrez le fichier ``08-bluetooth_environmental_monitor.ino`` sous le chemin ``elite-explorer-kit-main\iot_project\08-bluetooth_environmental_monitor``, ou copiez ce code dans **Arduino IDE**.
   
   .. note:: 
      Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino pour rechercher et installer **"DHT sensor library"** et **"ArduinoBLE"**.

.. literalinclude:: /_code/08_iot_ble_home.ino
   :language: cpp
   :linenos:
   :caption: 08-bluetooth_environmental_monitor.ino

#. Après avoir sélectionné la carte et le port corrects, cliquez sur le bouton **Upload**.

#. Ouvrez le moniteur série (réglez le débit en bauds sur **9600**) pour voir les messages de débogage. 

**4. Connexion de l'application et du module Bluetooth**

Assurez-vous que l'application créée précédemment est installée sur votre smartphone.

#. Tout d'abord, activez le **Bluetooth** sur votre smartphone.

   .. image:: img/08_app_1.png
      :width: 60%
      :align: center

#. Ouvrez maintenant la nouvelle application **Environmental Monitor**.

   .. image:: img/08_app_2.png
      :width: 25%
      :align: center

#. Lorsque vous ouvrez cette application pour la première fois, deux invites d'autorisation apparaîtront successivement. Ce sont les autorisations requises pour utiliser le Bluetooth.

   .. image:: img/08_app_3.png
      :width: 100%
      :align: center

   .. raw:: html

      <br/>

#. Dans l'application, cliquez sur le bouton **Connect** pour établir une connexion entre l'application et le module Bluetooth.

   .. image:: img/08_app_4.png
      :width: 55%
      :align: center

#. Cette page affiche une liste de tous les appareils Bluetooth appariés. Choisissez l'option ``xx.xx.xx.xx.xx.xx UNO R4 Home`` dans la liste. Le nom de chaque appareil est indiqué à côté de son adresse MAC.

   .. image:: img/08_app_5.png
      :width: 60%
      :align: center
   
   .. raw:: html

      <br/>

#. Si vous ne voyez aucun appareil sur la page affichée ci-dessus, vous pouvez essayer d'activer le commutateur de localisation de l'appareil (certaines versions du système Android associent le commutateur de localisation à la fonction Bluetooth).

   .. image:: img/08_app_6.png
      :width: 60%
      :align: center

   .. raw:: html

      <br/>

#. Après une connexion réussie, vous serez redirigé vers la page principale où la température et l'humidité seront affichées.

   .. image:: img/08_app_7.png
      :width: 60%
      :align: center

**5. Explication du code**

1. Importation des bibliothèques et définition des constantes

   - Importez les bibliothèques nécessaires et définissez les constantes pour le broche et le type de capteur DHT.

   .. note:: 
      Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino pour rechercher et installer **"DHT sensor library"** et **"ArduinoBLE"**.

   .. code-block:: arduino
   
       #include <DHT.h>
       #include <ArduinoBLE.h>
       #define DHTPIN 11
       #define DHTTYPE DHT11

2. Initialisation des services et caractéristiques BLE

   - Définissez les UUID pour le service de détection environnementale BLE et les caractéristiques. Nous utilisons les UUID prédéfinis fournis par |link_bluetooth_sig|. Le |link_sig_environmental_sensing| est assigné ``0x181A``, tandis que ``0x2A6E`` et ``0x2A6F`` sont réservés pour |link_sig_temperature_humidity|, respectivement.

   .. code-block:: arduino
   
       BLEService environmentalSensingService("181A");
       BLEShortCharacteristic temperatureCharacteristic("2A6E", BLERead | BLENotify);
       BLEUnsignedShortCharacteristic humidityCharacteristic("2A6F", BLERead | BLENotify);

3. Fonction Setup

   - Initialisez la communication série, le capteur DHT et le BLE.

   .. code-block:: arduino
   
       void setup() {
         Serial.begin(9600);
         dht.begin();
         if (!BLE.begin()) {
           Serial.println("starting Bluetooth® Low Energy module failed!");
           while (1)
             ;
         }
         setupBle();
       }

4. Boucle principale

   - Interrogez les événements BLE et mettez à jour les données du capteur à intervalles réguliers.

   - La ligne ``millis() - lastUpdateTime > updateInterval`` garantit que les données du capteur sont mises à jour toutes les updateInterval millisecondes.

   .. code-block:: arduino
   
       void loop() {
         BLE.poll();
         if (millis() - lastUpdateTime > updateInterval) {
           // Lisez les données du capteur et mettez à jour les caractéristiques BLE
         }
       }

5. Fonctions BLE et de débogage

   - Fonctions pour configurer le BLE, imprimer des informations de débogage et gérer les événements BLE.

   .. code-block:: arduino
   
       void printDHT(float h, float t) { /* ... */ }
       void setupBle() { /* ... */ }
       void blePeripheralConnectHandler(BLEDevice central) { /* ... */ }
       void blePeripheralDisconnectHandler(BLEDevice central) { /* ... */ }

   - ``printDHT(float h, float t)`` : Utilisé pour imprimer les données de température et d'humidité lues par le DHT11 sur le moniteur série. Cette fonction est destinée au débogage.

   - ``setupBle()`` : Initialise le Bluetooth, y compris le nom de diffusion, les caractéristiques et les services.

   - ``blePeripheralConnectHandler(BLEDevice central)`` et ``blePeripheralDisconnectHandler(BLEDevice central)`` : Ces fonctions gèrent les événements lorsque Bluetooth se connecte ou se déconnecte. Lorsqu'un appareil se connecte avec succès à l'UNO R4 via Bluetooth, la LED embarquée s'allume. Lorsque l'appareil se déconnecte, la LED s'éteint.

