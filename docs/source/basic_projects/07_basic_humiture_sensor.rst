.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_humiture_sensor:

Module Capteur de Température et d'Humidité
===============================================

.. https://docs.sunfounder.com/projects/3in1-kit/en/latest/basic_project/ar_dht11.html#ar-dht11

Aperçu
---------------

L'humidité et la température sont étroitement liées, tant du point de vue de la quantité physique elle-même que de la vie quotidienne des gens.
La température et l'humidité de l'environnement humain affectent directement la fonction de régulation thermique et l'effet de transfert de chaleur du corps humain.
Elles influent également sur l'activité cognitive et l'état mental, affectant ainsi l'efficacité de nos études et de notre travail.

La température est l'une des sept quantités physiques de base du Système international d'unités, utilisée pour mesurer le degré de chaleur ou de froid d'un objet.
Le degré Celsius est l'une des échelles de température les plus utilisées dans le monde, exprimée par le symbole "℃".

L'humidité est la concentration de vapeur d'eau présente dans l'air.
L'humidité relative de l'air est couramment utilisée dans la vie quotidienne et s'exprime en %HR. L'humidité relative est étroitement liée à la température.
Pour un certain volume de gaz scellé, plus la température est élevée, plus l'humidité relative est faible, et plus la température est basse, plus l'humidité relative est élevée.

Le dht11, un capteur numérique de température et d'humidité, est fourni dans ce kit. Il utilise un capteur d'humidité capacitif et une thermistance pour mesurer l'air ambiant et envoie un signal numérique sur la broche de données.

Composants nécessaires
-------------------------

Dans ce projet, nous avons besoin des composants suivants.

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

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_dht11`
        - |link_humiture_buy|



Câblage
----------------------

.. image:: img/07-dht11_bb.png
    :align: center

Schéma
-----------------------

.. image:: img/07_humiture_schematic.png
    :align: center
    :width: 40%

Code
---------------

.. note::

    * Vous pouvez ouvrir le fichier ``07-humiture_sensor.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\07-humiture_sensor`` directement.
    * Ou copier ce code dans l'IDE Arduino.

.. note:: 
    Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"DHT sensor library"** et installez-la. 

.. literalinclude:: /_code/07_basic_humiture_sensor.ino
   :language: cpp
   :linenos:
   :caption: 07-humiture_sensor.ino


Après avoir téléchargé le code avec succès, vous verrez le Moniteur Série imprimer en continu la température et l'humidité, et à mesure que le programme tourne, ces deux valeurs deviendront de plus en plus précises.

Analyse du code
------------------------

#. Inclusion des bibliothèques nécessaires et définition des constantes.
   Cette partie du code inclut la bibliothèque du capteur DHT et définit le numéro de broche et le type de capteur utilisés dans ce projet.

   .. note:: 
      Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèques Arduino et recherchez **"DHT sensor library"** et installez-la. 

   .. code-block:: arduino
    
      #include <DHT.h>
      #define DHTPIN 11       // Définir la broche utilisée pour connecter le capteur
      #define DHTTYPE DHT11  // Définir le type de capteur

#. Création de l'objet DHT.
   Ici, nous créons un objet DHT en utilisant le numéro de broche et le type de capteur définis.

   .. code-block:: arduino

      DHT dht(DHTPIN, DHTTYPE);  // Créer un objet DHT

#. Cette fonction est exécutée une fois lorsque l'Arduino démarre. Nous initialisons la communication série et le capteur DHT dans cette fonction.

   .. code-block:: arduino

      void setup() {
        Serial.begin(9600);
        Serial.println(F("DHT11 test!"));
        dht.begin();  // Initialize the DHT sensor
      }

#. Boucle principale.
   La fonction ``loop()`` s'exécute continuellement après la fonction setup. Ici, nous lisons les valeurs d'humidité et de température, calculons l'indice de chaleur et imprimons ces valeurs sur le moniteur série. Si la lecture du capteur échoue (retourne NaN), un message d'erreur est imprimé.

   .. note::
    
      L'|link_heat_index| est une manière de mesurer la sensation de chaleur extérieure en combinant la température de l'air et l'humidité. Il est aussi appelé "température ressentie" ou "température apparente".

   .. code-block:: arduino

      void loop() {
        delay(2000);
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        float f = dht.readTemperature(true);
        if (isnan(h) || isnan(t) || isnan(f)) {
          Serial.println(F("Failed to read from DHT sensor!"));
          return;
        }
        float hif = dht.computeHeatIndex(f, h);
        float hic = dht.computeHeatIndex(t, h, false);
        Serial.print(F("Humidity: "));
        Serial.print(h);
        Serial.print(F("%  Temperature: "));
        Serial.print(t);
        Serial.print(F("°C "));
        Serial.print(f);
        Serial.print(F("°F  Heat index: "));
        Serial.print(hic);
        Serial.print(F("°C "));
        Serial.print(hif);
        Serial.println(F("°F"));
      }
