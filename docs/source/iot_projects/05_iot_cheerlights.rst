.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

CheerLights
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/05_iot_cheerlights.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

CheerLights est un réseau mondial de lumières synchronisées qui peuvent être contrôlées par n'importe qui. Rejoignez la communauté |link_cheerlights| de changement de couleur de LED, qui permet aux LEDs du monde entier de changer de couleur simultanément. Placez vos LEDs dans un coin de votre bureau pour vous rappeler que vous n'êtes pas seul.

Dans ce cas, nous utilisons également MQTT, mais au lieu de publier nos propres messages, nous nous abonnons au sujet "cheerlights". Cela nous permet de recevoir des messages envoyés par d'autres personnes sur le sujet "cheerlights" et d'utiliser ces informations pour changer la couleur de notre bande LED en conséquence.

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
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Câblage**

.. image:: img/05_cheerlight_bb.png
    :width: 100%
    :align: center

**Schéma**

.. image:: img/05_cheerlight_schematic.png
    :width: 50%
    :align: center

.. raw:: html

   <br/>

**Installer la bibliothèque**

Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez "ArduinoMqttClient" et "FastLED" et installez-les.

``ArduinoMqttClient.h``: Utilisé pour la communication MQTT.

``FastLED.h``: Utilisé pour piloter la bande LED RGB.

.. important::
    Avec la sortie de |link_fastled_3_7_0|, la bibliothèque FastLED prend désormais en charge officiellement l'Arduino UNO R4. Vous n'avez donc plus besoin d'installer manuellement la version de développement. Mettez simplement à jour ou installez la bibliothèque FastLED en utilisant le gestionnaire de bibliothèques Arduino.

.. warning::
    **[Périmé]** Étant donné que la bibliothèque |link_FastLED_lib| n'a pas encore publié officiellement une version prenant en charge l'Arduino R4, vous devrez télécharger :download:`la dernière version de développement de la bibliothèque FastLED <https://codeload.github.com/FastLED/FastLED/zip/refs/heads/master>` et remplacer les fichiers existants de la bibliothèque FastLED. Pour des instructions détaillées sur la façon de le faire, veuillez vous référer à la section :ref:`manual_install_lib`. (Cette note sera retirée lorsque la bibliothèque FastLED publiera officiellement une mise à jour prenant en charge l'Arduino UNO R4.)

**Exécuter le code**


.. note::

    * Vous pouvez ouvrir le fichier ``05_cheerlight.ino`` sous le chemin ``elite-explorer-kit-main\iot_project\05_cheerlight`` directement.
    * Ou copier ce code dans Arduino IDE.

.. note::
    Dans le code, le SSID et le mot de passe sont stockés dans ``arduino_secrets.h``. Avant de télécharger cet exemple, vous devez les modifier avec vos propres identifiants WiFi. De plus, pour des raisons de sécurité, assurez-vous que ces informations restent confidentielles lors du partage ou du stockage du code.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/9d7ad736-9725-499f-a6ea-91602120d53e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Contrôler les appareils @CheerLights mondiaux**

#. Rejoignez le |link_discord_server| et utilisez le bot CheerLights pour définir la couleur. Tapez simplement ``/cheerlights`` dans n'importe quel canal du **serveur Discord CheerLights** pour activer le bot.

   .. image:: img/05_iot_cheerlights_1.png

#. Suivez les instructions fournies par le bot pour définir la couleur. Cela vous permettra de contrôler les appareils CheerLights dans le monde entier.

   .. image:: img/05_iot_cheerlights_2.png

**Comment ça marche ?**

Voici les principales parties du code et leurs fonctions :

1. Inclure les bibliothèques requises :

   * ``WiFiS3.h`` : Utilisé pour gérer les connexions Wi-Fi.
   * ``ArduinoMqttClient.h`` : Utilisé pour gérer les connexions MQTT.
   * ``FastLED.h`` : Utilisé pour contrôler les bandes LED NeoPixel.

2. Définir quelques constantes :

   * ``NUM_LEDS`` : Le nombre de LEDs sur la bande LED.
   * ``DATA_PIN`` : La broche de données connectée à l'Arduino pour contrôler la bande LED.
   * ``arduino_secrets.h`` : Fichier en-tête contenant le nom et le mot de passe du réseau Wi-Fi pour protéger les informations sensibles.
   * ``broker`` : Adresse du serveur MQTT.
   * ``port`` : Port du serveur MQTT.
   * ``topic`` : Le sujet MQTT auquel s'abonner.

3. Définir quelques variables globales :

   * ``CRGB leds[NUM_LEDS]`` : Un tableau pour stocker les données de couleur des LEDs.
   * ``colorName`` : Un tableau de noms de couleurs pris en charge par le projet CheerLights.
   * ``colorRGB`` : Un tableau de codes de couleurs RGB correspondant aux noms de couleurs.

4. Fonction ``setup()`` :

   * Initialiser la communication série.
   * Vérifier si le module Wi-Fi est présent et afficher sa version du firmware.
   * Tenter de se connecter au réseau Wi-Fi ; si cela échoue, attendre 10 secondes et réessayer.
   * Après une connexion réussie, se connecter au broker MQTT (serveur) et s'abonner au sujet spécifié.
   * Initialiser la bande LED NeoPixel.

5. Fonction ``loop()`` :

   * Appeler périodiquement la fonction ``mqttClient.poll()`` pour recevoir les messages MQTT et envoyer des signaux keep-alive MQTT.
   * Ajouter un délai de 5 secondes pour éviter une connexion continue.

6. Les fonctions ``printWifiData()`` et ``printCurrentNet()`` sont utilisées pour afficher les informations sur le réseau Wi-Fi et la connexion.

7. La fonction ``printMacAddress()`` est utilisée pour imprimer l'adresse MAC au format hexadécimal.

8. La fonction ``onMqttMessage()`` est une fonction de rappel déclenchée lorsqu'un message MQTT est reçu. Elle affiche le sujet et le contenu du message reçu, convertissant le contenu du message en minuscules. Si le sujet est "cheerlights", elle appelle la fonction ``setColor()`` pour définir la couleur de la bande LED.

9. La fonction ``setColor()`` prend un nom de couleur comme paramètre, puis cherche une couleur correspondante dans le tableau ``colorName``. Si une couleur correspondante est trouvée, elle définit la couleur de la bande LED sur la valeur RGB correspondante et met à jour la couleur de la bande LED en utilisant la fonction ``FastLED.show()``.

