.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _fun_digital_dice:

Dé numérique
=======================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/05_fun_dice.mp4"  type="video/mp4">
      Votre navigateur ne supporte pas la balise vidéo.
   </video>

Ce code est conçu pour simuler un lancer de dé en utilisant un registre à décalage 74HC595 et un afficheur numérique à 7 segments. La simulation du lancer de dé est activée en secouant directement l'interrupteur à bascule. Dès cette action, l'afficheur numérique fait défiler des nombres aléatoires entre 1 et 6, simulant le lancer d'un dé. Après un bref intervalle, l'affichage s'arrête, montrant un nombre aléatoire qui indique le résultat du lancer de dé.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_tilt_switch`
        - \-
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7segment`
        - |link_7segment_buy|

**Câblage**

.. image:: img/05_dice_bb.png
    :width: 80%
    :align: center

.. raw:: html

   <br/>

**Schéma**

.. image:: img/05_digital_dice_schematic.png
   :width: 100%

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``05_digital_dice.ino`` sous le chemin ``elite-explorer-kit-main\fun_project\05_digital_dice`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/ff0528b0-a10d-49e8-8916-6cb1fdfdf9a2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Comment ça marche ?**

Voici une explication détaillée du code :

1. Initialisation des variables :

   ``dataPin``, ``clockPin``, ``latchPin`` : Broches pour le 74HC595.
   ``buttonPin`` : La broche numérique où le bouton est connecté.
   ``numbers[]`` : Un tableau pour stocker le codage représentant les chiffres de 1 à 6 sur un afficheur numérique à anode commune.


2. Variables volatiles :

   rolling : C'est une variable volatile indiquant si le dé est en cours de roulement. 
   Elle est déclarée comme volatile car elle est accessible à la fois dans la routine de service d'interruption et dans le programme principal.

3. ``setup()`` :

   Configure les modes des broches pertinentes.
   Configure la broche du bouton en mode entrée en utilisant la résistance pull-up interne.
   Assigne une interruption au bouton, qui appelle la fonction ``rollDice`` lorsque l'état du bouton change.

4. ``loop()`` :

   Vérifie si ``rolling`` est vrai. Si c'est le cas, il continue d'afficher un nombre aléatoire entre 1 et 6. Si le bouton a été pressé pendant plus de 500 millisecondes, le roulement s'arrête.

5. ``rollDice()`` :

   C'est la routine de service d'interruption pour le bouton. Elle vérifie si le bouton est pressé (niveau bas). Si c'est le cas, l'heure actuelle est enregistrée et le roulement commence.

6. ``displayNumber()`` :

   Cette fonction affiche un nombre sur le tube numérique. Elle envoie le nombre au tube numérique via le registre à décalage 74HC595.

