.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Arduino IoT Cloud
===========================

Cet exemple montre comment communiquer avec le Cloud Arduino IoT. Il permet de se connecter au Cloud Arduino IoT et d'interagir avec les variables cloud. Ici, nous envoyons les valeurs de température lues par le capteur DHT11 au Cloud Arduino IoT, nous permettant ainsi de les surveiller depuis le cloud.

.. image:: img/02_cloud.png

**Composants nécessaires**

Pour ce projet, nous avons besoin des composants suivants. 

Il est définitivement pratique d'acheter un kit complet, voici le lien : 

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

**Câblage**

.. image:: img/02_arduino_iot_cloud_bb.png
    :width: 90%
    :align: center

.. raw:: html
    
    <br/>


**Schéma**

.. image:: img/02_arduino_iot_cloud_schematic.png
  :width: 40%
  :align: center


**Installer l'agent Arduino Create**

1. Visitez l'adresse https://create.arduino.cc/getting-started/plugin/welcome.

2. Cliquez sur START.

  .. image:: img/02_install_agent_2.png
     :width: 95%

3. Choisissez la version adaptée à votre ordinateur, et un paquet d'installation sera téléchargé.

  .. image:: img/02_install_agent_3.png
     :width: 95%

4. Installez l'agent.

  .. image:: img/02_install_agent_4.png
    :width: 85%

5. Après l'installation, retournez à votre navigateur, et vous verrez l'interface suivante.

  .. image:: img/02_install_agent_5.png
     :width: 95%

6. Cliquez sur NEXT, puis vous pouvez accéder à l'éditeur web.

  .. image:: img/02_install_agent_6.png
     :width: 95%

**Utiliser le Cloud Arduino IoT**

1. Tout d'abord, vous devez vous connecter ou vous inscrire sur Arduino. 

  https://login.arduino.cc/login

2. Une fois connecté, cliquez sur IoT Cloud dans le coin supérieur droit.

   .. image:: img/02_iot_cloud_2.png


3. Créez une nouvelle chose.

   .. image:: img/02_iot_cloud_3.png
  
4. Associez votre appareil.

   .. image:: img/02_iot_cloud_4.png


5. Configurez un nouvel appareil.

   .. image:: img/02_iot_cloud_5.png


6. Choisissez votre carte Arduino.
 
   .. image:: img/02_iot_cloud_6.png


7. Attendez un moment, et votre UNO R4 WiFi sera détecté. Continuez en cliquant sur configure.
 
   .. image:: img/02_iot_cloud_7.png

 
8. Donnez un nom à votre appareil.

  .. image:: img/02_iot_cloud_8.png


9. Rendez votre appareil compatible IoT, et n'oubliez pas de sauvegarder la clé secrète.

  .. image:: img/02_iot_cloud_9.png


10. Attendez quelques minutes.

  .. image:: img/02_iot_cloud_10.png


.. 5. Sélectionnez Arduino UNO R4 WiFi.

.. .. image:: img/sp231016_164654.png

11. Configurez le WiFi.

  .. image:: img/02_iot_cloud_11.png


12. Ici, vous devrez entrer votre mot de passe WiFi et la clé secrète.

  .. image:: img/02_iot_cloud_12.png


13. Ajoutez une variable.

  .. image:: img/02_iot_cloud_13.png


14. Ici, nous voulons afficher la température dans le Cloud IoT, donc nous configurons une variable float en lecture seule.

  .. image:: img/02_iot_cloud_14.png


15. Après avoir terminé, allez au sketch.

  .. image:: img/02_iot_cloud_15.png


16. Ouvrez l'éditeur complet.

  .. image:: img/02_iot_cloud_16.png


17. Cliquez sur Libraries à droite, puis sur Library Manager.

  .. image:: img/02_iot_cloud_17.png


18. Recherchez la bibliothèque du capteur DHT et cochez-la.

  .. image:: img/02_iot_cloud_18.png


19. Maintenant, nous devons éditer le code. Vous pouvez voir que l'éditeur a déjà préparé le code lié au Cloud IoT pour vous. Vous n'avez qu'à ajouter les fonctionnalités spécifiques dont vous avez besoin. Dans cet exemple, nous avons ajouté du code pour lire la température à l'aide du capteur DHT11.

  .. code-block::
      :emphasize-lines: 1,2,3,22,23,24,32,55,56
  
      // Bibliothèque du capteur DHT - Version: Dernière 
      #include <DHT.h>
      #include <DHT_U.h>
  
      /* 
      Sketch généré par le Cloud Arduino IoT "Sans titre"
      https://create.arduino.cc/cloud/things/260edac8-34f9-4e2e-9214-ba0c20994220 
  
      Description des variables du Cloud Arduino IoT
  
      Les variables suivantes sont automatiquement générées et mises à jour lorsque des modifications sont apportées à la chose
  
      float temperature;
  
      Les variables marquées comme LECTURE/ÉCRITURE dans la chose Cloud auront également des fonctions
      qui sont appelées lorsque leurs valeurs sont modifiées depuis le tableau de bord.
      Ces fonctions sont générées avec la chose et ajoutées à la fin de ce sketch.
      */
  
      #include "thingProperties.h"
  
      #define DHTPIN 11     
      #define DHTTYPE DHT11 
      DHT dht(DHTPIN, DHTTYPE);
  
      void setup() {
          // Initialisez la communication série et attendez l'ouverture du port :
          Serial.begin(9600);
          // Ce délai donne la possibilité d'attendre un moniteur série sans bloquer s'il n'est pas trouvé
          delay(1500); 
  
          dht.begin();
  
          // Défini dans thingProperties.h
          initProperties();
  
          // Connectez-vous au Cloud Arduino IoT
          ArduinoCloud.begin(ArduinoIoTPreferredConnection);
          
          /*
              La fonction suivante vous permet d'obtenir plus d'informations
              relatives à l'état du réseau et à la connexion au Cloud IoT ainsi que des erreurs
              plus le nombre est élevé, plus l'information est granulaire.
              La valeur par défaut est 0 (seulement les erreurs).
              Le maximum est 4
          */
          setDebugMessageLevel(2);
          ArduinoCloud.printDebugInfo();
      }
  
      void loop() {
          ArduinoCloud.update();
          // Votre code ici 
          
          float temp = dht.readTemperature();  
          temperature = temp;
          
      }
 
20. Téléchargez le code. Vous pourriez être invité à mettre à jour ; suivez les invites pour terminer.

  .. image:: img/02_iot_cloud_20.png


21. Retournez au CLOUD IoT.

  .. image:: img/02_iot_cloud_21.png


22. Cliquez sur le menu dans le coin supérieur gauche.
  
  .. image:: img/02_iot_cloud_22.png


23. Cliquez sur le tableau de bord.
  
  .. image:: img/02_iot_cloud_23.png


24. Créez un tableau de bord.
  
  .. image:: img/02_iot_cloud_24.png


25. De nombreux widgets sont disponibles ; ici, nous choisissons un widget de valeur pour afficher la température.

  .. image:: img/02_iot_cloud_25.png


26. Après avoir cliqué, une interface de paramètres de widget apparaîtra, où vous pourrez connecter le widget à la variable cloud que vous avez créée précédemment.

  .. image:: img/02_iot_cloud_26.png


27. Maintenant, vous pouvez voir les lectures des capteurs sur le Cloud Arduino IoT.

  .. image:: img/02_iot_cloud_27.png


**Comment ça fonctionne ?**

Après avoir configuré le Cloud IoT (configuration de l'appareil, configuration du réseau, création de variables cloud), vous remarquerez que le sketch sur le cloud se met à jour automatiquement. Ainsi, la plupart du code est déjà écrit pour vous.

Ouvrez l'éditeur, et vous verrez que ce sketch contient quatre fichiers :

``main.ino``: Utilisé pour initialiser l'Arduino et exécuter les tâches principales de la boucle. De plus, il inclut la logique de connexion et de communication avec le Cloud Arduino IoT.

``thingProperties.h``: Ce fichier est utilisé pour définir des variables et des fonctions dans le Cloud Arduino IoT. Il contient les déclarations des variables cloud et leurs fonctions de rappel associées. Dans le code fourni, il est utilisé pour initialiser les propriétés cloud (par exemple, la variable température) et se connecter au Cloud Arduino IoT.

``Secret``: Utilisé pour stocker des informations sensibles ou privées, telles que les mots de passe WiFi ou les clés API. Ces informations sensibles ne sont généralement pas exposées directement dans le code mais sont stockées dans le fichier Secret pour améliorer la sécurité.

``ReadMe.adoc``: Contient la documentation du projet ou d'autres informations pertinentes pour une meilleure compréhension et utilisation du projet. Ce fichier ne contient généralement pas de code exécutable mais plutôt des informations documentaires et descriptives.

Nous devons ajouter du code pour le capteur DHT11. Ce code est identique à celui que vous utiliseriez sur votre IDE local. La seule différence est que vous devez assigner la valeur lue par le DHT11 à la variable cloud ``temperature``.

(Remarque : Vous ne devez jamais modifier ``thingProperties.h`` et ``Secret``. Ils seront modifiés lorsque vous apportez des changements en utilisant l'éditeur Thing.)

