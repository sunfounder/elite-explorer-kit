.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Serveur Web Simple
===========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/new_feature_projects/wifi.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Ce programme Arduino simple est conçu pour créer un serveur web WiFi de base, permettant aux utilisateurs de contrôler l'état d'allumage et d'extinction d'une LED sur la carte Arduino via un navigateur web.

**Exécution du code**

.. note::

    * Vous pouvez ouvrir le fichier ``01_simple_webserver.ino`` sous le chemin ``elite-explorer-kit-main\iot_project\01_simple_webserver`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. note::
    Dans le code, le SSID et le mot de passe sont stockés dans ``arduino_secrets.h``. Avant de télécharger cet exemple, vous devez les modifier avec vos propres identifiants WiFi. De plus, pour des raisons de sécurité, assurez-vous que ces informations restent confidentielles lors du partage ou du stockage du code.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/7ed8f58d-2ed8-4dc9-82cb-7e49b6977ea1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Après avoir téléchargé le code, vous pourrez voir l'adresse IP dans le moniteur série. Vous pouvez entrer cette adresse IP dans votre navigateur web pour allumer/éteindre la LED intégrée.

.. image:: img/01_webserver.png

**Comment ça fonctionne ?**

Voici une explication du code :

1. Fichiers d'en-tête et variables globales :

   * ``#include "WiFiS3.h"`` : Inclut la bibliothèque WiFi pour se connecter et gérer le WiFi. Cette bibliothèque est incluse avec Arduino UNO R4 Core, donc aucune installation supplémentaire n'est requise.
   * ``#include "arduino_secrets.h"`` : Inclut les données sensibles de connexion WiFi telles que le SSID et le mot de passe.
   * ``ssid``, ``pass``, ``keyIndex`` : Ces éléments sont les identifiants réseau utilisés pour la connexion WiFi.
   * ``led``, ``status``, ``server`` : Définissent la broche de la LED, le statut WiFi et l'objet serveur web.

2. ``setup()`` :

   * Commence la communication série.
   * Vérifie la présence du module WiFi.
   * Vérifie si la version du firmware du module WiFi est à jour.
   * Tente de se connecter au réseau WiFi.
   * Démarre le serveur web.
   * Imprime le statut WiFi.

3. ``loop()`` :

   * Vérifie les nouvelles connexions des clients web.
   * S'il y a des connexions clients, lit leurs requêtes HTTP entrantes.
   * En fonction des requêtes, vous pouvez contrôler l'état d'allumage/extinction de la LED. Par exemple, si la requête est "GET /H", elle allume la LED ; si c'est "GET /L", elle éteint la LED.
   * Envoie une réponse HTTP pour instruire l'utilisateur sur la manière de contrôler la LED.
   * Déconnecte le client.

4. ``printWifiStatus()`` :

   * Imprime le SSID WiFi connecté.
   * Imprime l'adresse IP de la carte Arduino.
   * Imprime la force du signal reçu.
   * Explique comment visualiser cette page dans un navigateur web.

