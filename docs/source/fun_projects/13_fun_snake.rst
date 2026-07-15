.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _fun_snake:

JEU - Snake
=========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/13_fun_snake.mp4"  type="video/mp4">
      Votre navigateur ne supporte pas la balise vidéo.
   </video>

Cet exemple implémente le jeu classique Snake sur une matrice LED 8x12 en utilisant la carte R4 Wifi.
Les joueurs contrôlent la direction du serpent à l'aide d'un joystick à double axe.

**Composants nécessaires**

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

**Câblage**

.. image:: img/13_snake_bb.png
    :width: 80%
    :align: center


**Schéma**

.. image:: img/13_snake_schematic.png
   :width: 80%
   :align: center


**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``13_snake.ino`` sous le chemin ``elite-explorer-kit-main\fun_project\13_snake`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. literalinclude:: /_code/13_fun_snake.ino
   :language: cpp
   :linenos:
   :caption: 13_snake.ino


**Comment ça marche ?**

Voici une explication détaillée du code :

1. Définition et initialisation des variables

   Importez la bibliothèque ``Arduino_LED_Matrix`` pour les opérations sur la matrice LED.
   matrix est une instance de la matrice LED.
   ``frame`` et ``flatFrame`` sont des tableaux utilisés pour stocker et traiter les informations de pixels à l'écran.
   Le serpent est représenté comme un tableau de structures ``Point``, où chaque point a une coordonnée x et y.
   food représente la position de la nourriture.
   ``direction`` est la direction de déplacement actuelle du serpent.

2. ``setup()`` 

   Initialisez les axes X et Y du joystick comme entrées.
   Démarrez la matrice LED.
   Initialisez la position de départ du serpent au centre de l'écran.
   Générez la position initiale de la nourriture de manière aléatoire.

3. ``loop()`` 

   Déterminez la direction du serpent en fonction des lectures du joystick.
   Déplacez le serpent.
   Vérifiez si la tête du serpent entre en collision avec la nourriture. 
   Si c'est le cas, le serpent grandit et de la nouvelle nourriture est générée à un nouvel emplacement.
   Vérifiez si le serpent entre en collision avec lui-même. Si c'est le cas, réinitialisez le jeu.
   Dessinez l'état actuel du jeu (positions du serpent et de la nourriture) sur la matrice LED.
   Ajoutez un délai pour contrôler la vitesse du jeu.

4. ``moveSnake()`` 

   Déplacez chaque partie du serpent à la position de la partie précédente, en commençant par la queue et en allant vers la tête.
   Déplacez la tête du serpent en fonction de sa direction.

5. ``generateFood()`` 

   Générez toutes les positions possibles pour la nourriture.
   Vérifiez si chaque position chevauche une partie du serpent. Si elle ne chevauche pas, la position est considérée comme une position possible pour la nourriture.
   Sélectionnez aléatoirement une position possible pour la nourriture.

6. ``drawFrame()`` 

   Effacez le cadre actuel.
   Dessinez le serpent et la nourriture sur le cadre.
   Aplatissez le tableau à deux dimensions frame en un tableau à une dimension (flatFrame) et chargez-le sur la matrice LED.
