.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _fun_hue:

HueDial
========================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/03_fun_huedial.mp4"  type="video/mp4">
      Votre navigateur ne supporte pas la balise vidéo.
   </video>

Cet exemple contrôle la couleur d'une LED RVB en fonction de la position d'un bouton rotatif. Différentes positions du bouton correspondent à différentes valeurs de TEINTE, qui sont ensuite traduites en valeurs de couleur RVB, entraînant un changement de couleur pour la LED RVB.

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
    *   - :ref:`cpn_rgb_led`
        - |link_rgb_led_buy|
    *   - :ref:`potentiometer`
        - |link_potentiometer_buy|

**Câblage**

.. image:: img/03_hue_dial_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**Schéma**

.. image:: img/03_hue_schematic.png
   :width: 80%
   :align: center

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``03_huedial.ino`` sous le chemin ``elite-explorer-kit-main\fun_project\03_huedial`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/0ad800d4-77bb-454f-8976-a078da71ec35/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Comment ça marche ?**

Voici une explication détaillée du code :

1. Définition des variables globales :

   ``redPin``, ``greenPin`` et ``bluePin`` : Ces variables définissent les broches PWM connectées respectivement aux LEDs rouges, vertes et bleues.
   ``KNOB_PIN`` : Définit la broche d'entrée analogique connectée au bouton rotatif.

2. ``setup()`` :

   Configurez les broches pour la LED RVB en sortie.
   Par défaut, les broches analogiques sont configurées en entrée, il n'est donc pas nécessaire de définir le mode d'entrée pour la broche du bouton.

3. ``loop()`` :

   Lisez la valeur du bouton rotatif. Cette valeur varie de 0 à 1023.
   Normalisez la valeur du bouton à une plage de 0 à 1.
   Convertissez la valeur normalisée en une valeur de TEINTE allant de 0 à 360.
   Convertissez la valeur de TEINTE en valeurs RVB.
   Mettez à jour la couleur de la LED en utilisant ces valeurs RVB.

4. ``setColor()`` :

   Définissez les valeurs PWM appropriées pour chaque broche de LED en utilisant la fonction ``analogWrite()`` pour définir la couleur de la LED RVB.

5. ``HUEtoRGB()`` :

   Cette fonction convertit les valeurs de TEINTE en valeurs RVB en utilisant la méthode de conversion HSL en RVB, mais se concentre uniquement sur le composant TEINTE, en gardant la saturation et la luminosité à 100%.
   L'algorithme est divisé en 6 étapes, chacune couvrant 60 degrés.
   Il calcule les valeurs RVB pour chaque étape de TEINTE, puis les échelonne à une plage de 0-255, qui est la plage attendue pour la fonction ``analogWrite()``.

