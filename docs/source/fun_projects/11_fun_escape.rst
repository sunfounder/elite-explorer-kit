.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _fun_escape:

JEU - Évasion
==================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/11_fun_escape_square.mp4"  type="video/mp4">
      Votre navigateur ne supporte pas la balise vidéo.
   </video>

Ce jeu s'appelle "Évasion".
L'objectif du joueur est d'incliner le capteur MPU6050 pour déplacer un pixel sur la matrice LED et tenter de le manœuvrer à travers une ouverture dans la bordure de la matrice (la sortie).

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
    *   - :ref:`cpn_gy87`
        - \-


**Câblage**

.. image:: img/11_escape_bb.png
    :width: 80%
    :align: center


**Schéma**

.. image:: img/11_escape_schematic.png
   :width: 70%
   :align: center


**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``11_escape_square.ino`` sous le chemin ``elite-explorer-kit-main\fun_project\11_escape_square`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. note::
   Pour installer la bibliothèque, utilisez le gestionnaire de bibliothèque Arduino et recherchez **"Adafruit MPU6050"** et installez-la.

.. literalinclude:: /_code/11_fun_escape.ino
   :language: cpp
   :linenos:
   :caption: 11_escape_square.ino

**Comment ça marche ?**

Voici une explication détaillée du code :

1. Importation des bibliothèques et variables globales :

   Les bibliothèques importées incluent la matrice LED, Wire (pour la communication I2C), MPU6050 (capteur de mouvement), et ``Adafruit_Sensor``.
   Initialisation des objets MPU6050 et matrice LED.
   Définition des variables globales telles que pixelX et pixelY (position du pixel), gapStart et side (position de départ de l'ouverture et quel côté), level (niveau de difficulté du jeu), et plus.

2. ``setup()``:

   Initialiser la matrice LED et dessiner la matrice avec l'ouverture.
   Initialiser la communication série et vérifier si le capteur MPU6050 démarre correctement, en réglant sa plage d'accélération à 2g.

3. ``loop()``:

   Mettre à jour périodiquement la position du pixel en fonction des lectures du capteur MPU6050.
   Déplacer périodiquement la position de l'ouverture.
   Charger la nouvelle disposition du pixel et la rendre sur la matrice LED.
   Vérifier si le pixel est passé par l'ouverture. 
   Si c'est le cas, attendre 1,5 seconde pour afficher le succès, augmenter la difficulté du jeu et réinitialiser la position du pixel.

4. Autres fonctions :

   * ``drawSquareWithGap()``: Dessiner une bordure 8x8 et créer une ouverture à l'intérieur.
   * ``createGap()``: Créer une ouverture de longueur 2 sur le côté spécifié.
   * ``moveGap()``: Déplacer la position de l'ouverture en fonction du côté actuel et de gapStart, en changeant de côté si nécessaire.
   * ``movePixelBasedOnMPU()``: Lire les données d'accélération du MPU6050. Déplacer la position du pixel en fonction des données d'accélération (réinitialiser si le pixel sort des limites ou entre dans les murs).
   * ``resetPixel()``: Réinitialiser la position du pixel au centre de la matrice.
   * ``checkPixelPosition()``: Vérifier si le pixel est sur l'ouverture. Si c'est le cas, augmenter le niveau de difficulté du jeu et définir le drapeau de passage à vrai.

