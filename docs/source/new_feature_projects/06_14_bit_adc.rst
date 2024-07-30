.. note::

    Bonjour et bienvenue dans la communauté SunFounder des passionnés de Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez au cœur de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _new_adc:

Convertisseur analogique-numérique (ADC) (jusqu'à 14 bits)
=================================================================

Dans les projets électroniques modernes, il est essentiel de lire et de traiter avec précision les signaux analogiques. Les convertisseurs analogique-numérique (ADC) transforment les signaux analogiques en signaux numériques pour être traités par le microcontrôleur. L'Arduino Uno R4 a connu des avancées significatives dans ce domaine, grâce à son processeur plus puissant. Alors que la génération précédente, l'Arduino Uno R3, avait une résolution maximale de 10 bits, la résolution ADC de l'Arduino Uno R4 est désormais de 14 bits. Cette amélioration permet d'obtenir des valeurs plus précises à partir des signaux analogiques, améliorant ainsi la finesse et la précision de la collecte et du traitement des données.

Définir la résolution de l'ADC
------------------------------------

La résolution standard sur la carte Arduino est fixée à 10 bits (0-1023). L'UNO R4 WiFi prend en charge une résolution allant jusqu'à 14 bits (0-16383), fournissant des valeurs plus précises à partir des signaux analogiques. Pour mettre à jour la résolution, il suffit d'utiliser la commande ``analogReadResolution()``.

.. code-block:: arduino

   void setup() {
     // ouvrir une connexion série
     Serial.begin(9600);
   }
   
   void loop() {
     // lire l'entrée sur A0 à la résolution par défaut (10 bits)
     // et l'envoyer sur la connexion série
     analogReadResolution(10);
     Serial.print("ADC 10-bit (default) : ");
     Serial.print(analogRead(A0));
   
     // changer la résolution à 12 bits et lire A0
     analogReadResolution(12);
     Serial.print(", 12-bit : ");
     Serial.print(analogRead(A0));
   
     // changer la résolution à 14 bits et lire A0
     analogReadResolution(14);
     Serial.print(", 16-bit : ");
     Serial.print(analogRead(A0));
   
     // changer la résolution à 8 bits et lire A0
     analogReadResolution(8);
     Serial.print(", 8-bit : ");
     Serial.println(analogRead(A0));
   
     // un petit délai pour ne pas saturer le moniteur série
     delay(100);
   }


Remarques et avertissements
-----------------------------------

Lors de la définition de la résolution de l'ADC, prenez en compte les points suivants :

1. **Limites des capacités matérielles** : Si vous définissez la valeur ``analogReadResolution()`` à un niveau supérieur aux capacités de la carte, l'Arduino ne rapportera que sa résolution maximale, en remplissant les bits supplémentaires avec des zéros. Par exemple, utiliser l'Uno R4 avec ``analogReadResolution(16)`` donnera un nombre approximatif de 16 bits, avec les 14 premiers bits contenant la lecture réelle de l'ADC et les 2 derniers bits remplis de zéros.

2. **Réglages de résolution inférieure** : Si vous définissez la valeur ``analogReadResolution()`` à un niveau inférieur aux capacités de la carte, les bits de poids faible supplémentaires lus à partir de l'ADC seront supprimés. Cela vous permet de travailler avec une plage simplifiée si votre application ne nécessite pas une résolution complète.

Comprendre ces considérations vous aidera à utiliser efficacement les capacités de l'ADC de l'Arduino Uno R4, garantissant des performances optimales et une précision pour votre application spécifique.


**Référence**
- |link_analogReadResolution|
- |link_r4_minima_adc|
- |link_r4_wifi_adc|







