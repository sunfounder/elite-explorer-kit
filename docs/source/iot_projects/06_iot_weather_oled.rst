.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_weathertime_screen:

Écran MétéoTemps
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/06_iot_weather_oled.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Ce sketch se connecte à un réseau Wi-Fi, récupère les données météorologiques d'OpenWeatherMap toutes les minutes, obtient l'heure actuelle d'un serveur NTP et affiche le jour, l'heure et les informations météorologiques sur un écran OLED.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

**Câblage**

.. image:: img/06_weather_oled_bb.png
    :width: 100%
    :align: center

**Schéma**

.. image:: img/06_weather_oled_schematic.png
    :width: 60%
    :align: center

**OpenWeather**

Obtenez des clés API OpenWeather

.. .|link_openweather| est un service en ligne, propriété de OpenWeather Ltd, qui fournit des données météorologiques mondiales via API, y compris des données météorologiques actuelles, des prévisions, des nowcasts et des données météorologiques historiques pour n'importe quel emplacement géographique.

`OpenWeather <https://openweathermap.org/>`_ est un service en ligne, propriété de OpenWeather Ltd, qui fournit des données météorologiques mondiales via API, y compris des données météorologiques actuelles, des prévisions, des nowcasts et des données météorologiques historiques pour n'importe quel emplacement géographique.

#. Visitez OpenWeather pour vous connecter/créer un compte.

   .. image:: img/06_owm_1.png

#. Cliquez sur la page API depuis la barre de navigation.

   .. image:: img/06_owm_2.png

#. Trouvez **Current Weather Data** et cliquez sur Subscribe.

   .. image:: img/06_owm_3.png

#. Sous **Current weather and forecasts collection**, abonnez-vous au service approprié. Dans notre projet, la version gratuite est suffisante.

   .. image:: img/06_owm_4.png

#. Copiez la clé depuis la page **API keys**.

   .. image:: img/06_owm_5.png

#. Copiez-la dans le fichier ``arduino_secrets.h``.

   .. code-block:: Arduino

       #define SECRET_SSID "<SSID>"        // votre SSID réseau (nom)
       #define SECRET_PASS "<PASSWORD>"    // votre mot de passe réseau 
       #define API_KEY "<OpenWeather_API_KEY>"
       #define LOCATION "<YOUR CITY>"

#. Définissez le fuseau horaire de votre emplacement.

   Prenons la capitale de la Suède, Stockholm, comme exemple. Recherchez "stockholm timezone" sur Google.

   .. image:: img/06_weather_oled_01.png 

   Dans les résultats de recherche, vous verrez "GMT+1", donc vous définissez le paramètre de la fonction ci-dessous à ``3600 * 1`` secondes.
   
   .. code-block:: Arduino

      timeClient.setTimeOffset(3600 * 1);  // Ajustez pour votre fuseau horaire (c'est +1 heure)

**Installer la bibliothèque**

Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez "ArduinoMqttClient", "FastLED", "Adafruit GFX" et "Adafruit SSD1306" et installez-les.

``ArduinoJson.h``: Utilisé pour gérer les données JSON (données obtenues d'OpenWeatherMap).

``NTPClient.h``: Utilisé pour obtenir l'heure en temps réel.

``Adafruit_GFX.h``, ``Adafruit_SSD1306.h``: Utilisé pour le module OLED.

**Exécuter le code**

.. note::

    * Vous pouvez ouvrir le fichier ``06_weather_oled.ino`` sous le chemin ``elite-explorer-kit-main\iot_project\06_weather_oled`` directement.
    * Ou copier ce code dans Arduino IDE.

.. note::
    Dans le code, le SSID et le mot de passe sont stockés dans ``arduino_secrets.h``. Avant de télécharger cet exemple, vous devez les modifier avec vos propres identifiants WiFi. De plus, pour des raisons de sécurité, assurez-vous que ces informations restent confidentielles lors du partage ou du stockage du code.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/5f667ac1-bb24-4681-9fa1-db19fcfdd48a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Comment ça marche ?**

1. Bibliothèques et définitions :

   #. ``WiFiS3.h`` : Probablement une bibliothèque spécifique à un certain module Wi-Fi ou carte pour gérer les connexions Wi-Fi.
   #. ``ArduinoJson.h`` : Cette bibliothèque est utilisée pour décoder (et encoder) les données JSON.
   #. ``arduino_secrets.h`` : Un fichier séparé où les données sensibles (comme les identifiants Wi-Fi) sont stockées. C'est une bonne pratique de garder les identifiants hors du code principal.
   #. **NTPClient & WiFiUdp** : Utilisés pour récupérer l'heure actuelle d'un serveur NTP (Network Time Protocol).
   #. **Bibliothèques Adafruit** : Utilisées pour gérer l'affichage OLED.
   #. **Diverses variables globales** : Y compris les identifiants Wi-Fi, les détails du serveur et plus, qui seront utilisés tout au long du script.

2. ``setup()`` :

   #. Initialise la communication série.
   #. Vérifie et affiche la version du firmware du module Wi-Fi.
   #. Tente de se connecter au réseau Wi-Fi en utilisant le SSID et le mot de passe fournis.
   #. Affiche le statut du Wi-Fi connecté (SSID, IP, force du signal).
   #. Initialise l'écran OLED.
   #. Démarre le client NTP pour obtenir l'heure actuelle et définit un décalage horaire (dans ce cas, 8 heures, ce qui peut correspondre à un fuseau horaire spécifique).

3. ``read_response()`` :

   #. Lit la réponse du serveur, en recherchant spécifiquement les données JSON (indiquées par ``{`` et ``}``).
   #. Si des données JSON sont trouvées, elles sont décodées pour extraire des détails météorologiques tels que la température, l'humidité, la pression, la vitesse du vent et la direction du vent.
   #. Appelle la fonction ``displayWeatherData`` pour afficher les informations météorologiques sur l'écran OLED.

4. ``httpRequest()`` :

   #. Ferme toute connexion existante pour s'assurer que le socket du module Wi-Fi est libre.
   #. Tente de se connecter au serveur OpenWeatherMap.
   #. Si connecté, envoie une requête GET HTTP pour récupérer les données météorologiques pour un emplacement spécifique défini par ``LOCATION`` (probablement défini dans ``arduino_secrets.h`` ou ailleurs).
   #. Enregistre l'heure à laquelle la requête a été effectuée.

5. ``loop()`` :

   #. Appelle la fonction ``read_response`` pour traiter les données entrantes du serveur.
   #. Met à jour l'heure depuis le serveur NTP.
   #. Vérifie s'il est temps de faire une autre requête au serveur météorologique (basé sur ``postingInterval``). Si c'est le cas, appelle la fonction ``httpRequest``.

6. ``printWifiStatus()`` :

   #. Le SSID du réseau connecté.
   #. L'adresse IP locale de la carte.
   #. La force du signal (RSSI).

7. ``displayWeatherData()`` :

   #. Efface l'écran OLED.
   #. Affiche le jour actuel de la semaine.
   #. Affiche l'heure actuelle au format HH:MM.
   #. Affiche les données météorologiques fournies (température, humidité, pression et vitesse du vent).

