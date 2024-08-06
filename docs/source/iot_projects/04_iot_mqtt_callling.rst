.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _iot_mqtt_publish:

Système d'appel via MQTT
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/04_iot_mqtt_callling.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Le Message Queuing Telemetry Transport (MQTT) est un protocole de messagerie simple. Il est également le protocole de messagerie le plus largement utilisé dans le domaine de l'Internet des objets (IoT).

Les protocoles MQTT définissent comment les appareils IoT échangent des données. Ils fonctionnent de manière événementielle et sont interconnectés en utilisant le modèle Publish/Subscribe. L'expéditeur (Publisher) et le récepteur (Subscriber) communiquent via des Topics. Un appareil publie un message sur un sujet spécifique, et tous les appareils abonnés à ce sujet reçoivent le message.

Dans cette section, nous allons créer un système de sonnerie de service utilisant UNO R4, HiveMQ (un service gratuit de broker MQTT public) et quatre boutons. Chacun des quatre boutons correspond à une table de restaurant, et lorsque qu'un client appuie sur un bouton, vous pourrez voir quelle table a besoin de service sur HiveMQ.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|


**Câblage**

.. image:: img/04_mqtt_button_bb.png
   :width: 70%
   :align: center

**Schéma**

.. image:: img/04_mqtt_button_schematic.png
   :width: 50%
   :align: center

**Comment jouer ?**

HiveMQ est une plateforme de messagerie basée sur un broker et un client MQTT qui facilite le transfert rapide, efficace et fiable de données vers les appareils IoT.

1. Ouvrez |link_hivemq| dans votre navigateur web.

2. Connectez le client au proxy public par défaut.

   .. image:: img/04_mqtt_1.png

3. Cliquez sur **Add New Topic Subscription**.

   .. image:: img/04_mqtt_2.png

4. Entrez les sujets que vous souhaitez suivre et cliquez sur **Subscribe**. Assurez-vous que les sujets que vous définissez ici sont uniques pour éviter de recevoir des messages d'autres utilisateurs, et faites attention à la sensibilité à la casse. 

   Dans ce code d'exemple, nous avons défini le sujet comme ``SunFounder MQTT Test``. Si vous avez apporté des modifications, assurez-vous que le sujet dans le code correspond au sujet abonné sur la page web.

   .. image:: img/04_mqtt_3.png


**Installer la bibliothèque**

Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez "ArduinoMqttClient" et installez-la.

``ArduinoMqttClient.h`` : Utilisé pour la communication MQTT.

**Exécuter le Code**

.. note::

    * Vous pouvez ouvrir le fichier ``04_mqtt_button.ino`` sous le chemin ``elite-explorer-kit-main\iot_project\04_mqtt_button`` directement.
    * Ou copier ce code dans Arduino IDE.

.. note::
    Dans le code, le SSID et le mot de passe sont stockés dans ``arduino_secrets.h``. Avant de télécharger cet exemple, vous devez les modifier avec vos propres identifiants WiFi. De plus, pour des raisons de sécurité, assurez-vous que ces informations restent confidentielles lors du partage ou du stockage du code.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/7a4acdf8-beed-47d4-ada8-cbaab0f3477f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Après avoir exécuté le code, revenez à |link_hivemq|, et lorsque vous appuyez sur l'un des boutons de la breadboard, vous verrez l'invite Messages sur HiveMQ.

    .. image:: img/04_mqtt_4.png
  
**Comment ça marche ?**

Ce code est pour un projet basé sur Arduino qui se connecte au Wi-Fi et communique avec un broker MQTT en utilisant le protocole MQTT. De plus, il peut détecter si quatre boutons sont pressés et envoyer les messages correspondants au broker MQTT.

Voici une explication détaillée du code :

1. **Inclure les bibliothèques pertinentes** :

   .. code-block:: Arduino
       
       #include <WiFiS3.h>
       #include <ArduinoMqttClient.h>

2. **Inclure les informations sensibles** :

   * Le fichier ``arduino_secrets.h`` contient le SSID et le mot de passe du réseau Wi-Fi.
   
   .. code-block:: Arduino
       
       #include "arduino_secrets.h" 
       char ssid[] = SECRET_SSID;   
       char pass[] = SECRET_PASS;   

3. **Initialiser les variables** :

   * Variables pour gérer les connexions Wi-Fi et MQTT.
   * Initialiser les broches des boutons et les états des boutons.

4. ``setup()`` :

   * Initialiser la communication série.
   * Vérifier la présence du module Wi-Fi et tenter de se connecter au Wi-Fi.
   * Imprimer les données réseau.
   * Tenter de se connecter au broker MQTT.
   * S'abonner aux sujets MQTT.
   * Définir les boutons en mode entrée.

5. ``loop()`` :

   * Maintenir la connexion MQTT active.
   * Vérifier si chaque bouton est pressé, et si oui, envoyer des messages MQTT.

6. **Autres fonctions utilitaires** :

   * ``printWifiData()`` : Imprime les informations sur le réseau Wi-Fi actuellement connecté.
   * ``printCurrentNet()`` : Imprime les données pertinentes sur le réseau actuel.
   * ``printMacAddress(byte mac[])`` : Imprime l'adresse MAC.
   * ``onMqttMessage(int messageSize)`` : Fonction de rappel déclenchée lorsqu'un message est reçu du broker MQTT. Elle imprime le sujet et le contenu du message reçu.
   * ``sendButtonMessage(int buttonNumber)`` : Utilisez cette fonction pour envoyer des messages MQTT lorsque un bouton est pressé.

