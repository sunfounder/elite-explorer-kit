.. note::

    Bonjour, bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _fun_welcome:

Bienvenue
========================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/01_fun_welcome.mp4"  type="video/mp4">
      Votre navigateur ne supporte pas la balise vidéo.
   </video>

Dans ce projet, nous utiliserons un capteur PIR pour détecter la présence humaine et un haut-parleur pour simuler une sonnette, similaire aux sonnettes d'entrée dans les magasins de proximité.
Lorsqu'un piéton apparaît dans la zone de détection du capteur PIR, le haut-parleur sonne, imitant une sonnette.

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|
    *   - :ref:`cpn_audio_speaker`
        - \-


**Câblage**

.. image:: img/01_welcome_bb.png
    :width: 90%
    :align: center

.. raw:: html

   <br/>

**Schéma**

.. image:: img/01_welcome_schematic.png
   :width: 100%

**Code**

.. note::

    * Vous pouvez ouvrir le fichier ``01_welcome.ino`` sous le chemin ``elite-explorer-kit-main\fun_project\01_welcome`` directement.
    * Ou copiez ce code dans l'IDE Arduino.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/b9791d5d-169d-4603-9fc3-8081138811fa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**Comment ça marche ?**

Voici une explication étape par étape du code :

1. Inclure les fichiers d'en-tête :

   Inclure deux fichiers d'en-tête, ``analogWave.h`` et ``pitches.h``. Le fichier ``analogWave.h`` contient la définition de la classe ``analogWave``, tandis que ``pitches.h`` contient les définitions des notes musicales.

2. Instancier les objets et définir les constantes :

   Créer un objet ``wave`` en utilisant la classe ``analogWave`` et définir ``PIR_PIN`` comme étant 2, qui est la broche connectée au capteur PIR.

3. Tableau des mélodies :

   Le tableau ``melody`` définit une mélodie musicale, chaque note étant suivie d'un nombre représentant sa durée. 
   Les nombres négatifs représentent des notes pointées (augmentant la durée de 50%).

4. Variables globales :

   Définir quelques variables globales pour partager les données entre les fonctions.

5. ``setup()`` :

   Initialiser ``PIR_PIN`` comme une entrée et définir la fréquence de l'onde sinusoïdale à 10 Hz en utilisant ``wave.sine(10)``.

6. ``loop()`` :

   Surveiller continuellement la valeur du capteur PIR.
   Si une présence humaine est détectée (pirValue est HIGH), appeler la fonction ``playMelody()`` pour jouer la mélodie et attendre 10 secondes pour éviter la lecture répétitive de la mélodie.

7. ``playMelody()`` :

   Cette fonction calcule la durée de chaque note en fonction des données dans le tableau ``melody`` et joue la note correspondante. Il y a une courte pause entre les notes.
   La fonction définit la fréquence de l'onde en utilisant ``wave.freq()`` et contrôle la durée des notes et les pauses entre les notes en utilisant la fonction ``delay()``.

   Note : Assurez-vous que le fichier d'en-tête ``pitches.h`` existe bien avant d'exécuter ce code.

