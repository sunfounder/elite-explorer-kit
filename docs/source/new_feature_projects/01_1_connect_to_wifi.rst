.. note::

    Bonjour et bienvenue dans la communauté SunFounder des passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Connectez-vous au Wi-Fi
==========================

Ce tutoriel vous guidera à travers les étapes essentielles pour connecter votre carte Arduino à un réseau Wi-Fi. Vous apprendrez à initialiser le module Wi-Fi, à vérifier son firmware et à rejoindre en toute sécurité un réseau en utilisant son SSID et son mot de passe. Une fois connecté, vous découvrirez comment surveiller des détails importants du réseau, tels que les adresses IP et MAC de votre appareil, ainsi que la force du signal du réseau, directement depuis la console série. Ce tutoriel sert à la fois de guide pratique pour la connectivité Wi-Fi et d'introduction à la surveillance du réseau avec Arduino, vous aidant à établir et à maintenir une connexion Wi-Fi fiable.

1. Téléchargez le code
========================

Ouvrez le fichier ``01-wifi_connect.ino`` sous le chemin ``elite-explorer-kit-main\r4_new_feature\01-wifi_connect``, ou copiez ce code dans **Arduino IDE**.

.. note:: 
      Le support Wi-Fi® est activé via la bibliothèque intégrée ``WiFiS3`` qui est fournie avec l'Arduino UNO R4 Core. L'installation du core installe automatiquement la bibliothèque ``WiFiS3``.

Vous devez encore créer ou modifier ``arduino_secrets.h``, remplacez ``SECRET_SSID`` et ``SECRET_PASS`` par le nom et le mot de passe du Wi-Fi auquel vous souhaitez vous connecter. Le fichier doit contenir :

.. code:: arduino

    //arduino_secrets.h header file
    #define SECRET_SSID "yournetwork"
    #define SECRET_PASS "yourpassword"

.. raw:: html
       
   <iframe src=https://create.arduino.cc/editor/sunfounder01/a41ac638-31da-464c-b5d3-e70f2aacd29c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ouvrez le moniteur série, et vous verrez un contenu similaire à celui ci-dessous. Arduino affichera les adresses IP et MAC de votre appareil, ainsi que la force du signal du réseau.

.. image:: img/01_1_wifi.png
    :width: 100%

2. Explication du code
========================

1. Inclusion des bibliothèques et des données secrètes

   .. code-block:: arduino

      #include <WiFiS3.h>
      #include "arduino_secrets.h" 

   - ``WiFiS3`` est une bibliothèque qui fournit des fonctions pour la connectivité Wi-Fi. L'installation du core R4 installe automatiquement la bibliothèque WiFiS3.
   - ``arduino_secrets.h`` est un fichier séparé où vous gardez votre SSID et votre mot de passe pour qu'ils ne soient pas exposés dans votre code principal. Stocker le réseau et le mot de passe séparément réduit le risque de partager accidentellement les identifiants Wi-Fi.

   .. raw:: html

      <br/>

2. Déclaration des variables globales

   .. code-block:: arduino

      char ssid[] = SECRET_SSID;
      char pass[] = SECRET_PASS;
      int status = WL_IDLE_STATUS;

   - ``ssid`` et ``pass`` contiennent le nom et le mot de passe de votre réseau.
   - ``status`` stockera l'état actuel de votre connexion Wi-Fi.

   .. raw:: html

      <br/>

3. Fonction ``setup()``

   L'interface série est initialisée avec un débit en bauds de 9600. La ligne ``while (!Serial);`` s'assure que le programme attend jusqu'à ce que la connexion série soit établie.

   .. code-block:: arduino

      void setup() {
          //Initialisez la série et attendez que le port s'ouvre :
          Serial.begin(9600);
          while (!Serial) {
            ; // attendez que le port série se connecte. Nécessaire uniquement pour le port USB natif
          }
          ...
      }

   Ensuite, le code vérifie si le module Wi-Fi est disponible ou non. Sinon, le programme s'arrête, interrompant ainsi toute exécution ultérieure.

   .. code-block:: arduino

     ...
     // vérifiez la présence du module Wi-Fi :
     if (WiFi.status() == WL_NO_MODULE) {
         Serial.println("Échec de la communication avec le module Wi-Fi !");
         // ne continuez pas
         while (true);
     }
     ...

   Dans cette partie du code, nous vérifions si la version du firmware de l'Uno R4 Wi-Fi est à jour. Si ce n'est pas la version la plus récente, une invite de mise à niveau sera affichée. Vous pouvez vous référer à :ref:`update_firmware` pour la mise à niveau du firmware.

   .. https://forum.arduino.cc/t/radio-module-firmware-version-0-2-0-is-now-available/1147361

   .. code-block:: arduino

      ...
      String fv = WiFi.firmwareVersion();
      if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
          Serial.println("Please upgrade the firmware");
      }
      ...

4. Fonction ``loop()``

   .. code-block:: arduino

      void loop() {
        // vérifiez la connexion au réseau toutes les 10 secondes :
        delay(10000);
        printCurrentNet();
      }

   - Toutes les 10 secondes, la fonction ``printCurrentNet()`` est appelée pour afficher les détails du réseau actuel.

**Référence**

- |link_r4_wifi|
