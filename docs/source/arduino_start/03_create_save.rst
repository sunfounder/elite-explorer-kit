.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Comment créer, ouvrir ou enregistrer un sketch ?
============================================================

#. Lorsque vous ouvrez l'IDE Arduino pour la première fois ou créez un nouveau sketch, vous verrez une page comme celle-ci, où l'IDE Arduino crée un nouveau fichier pour vous, appelé "sketch".

   .. image:: img/sp221014_173458.png

   Ces fichiers sketch ont un nom temporaire régulier, à partir duquel vous pouvez identifier la date de création du fichier. ``sketch_oct14a.ino`` signifie premier sketch du 14 octobre, ``.ino`` est le format de fichier de ce sketch.

#. Maintenant, essayons de créer un nouveau sketch. Copiez le code suivant dans l'IDE Arduino pour remplacer le code original.

   .. image:: img/create1.png

   .. code-block:: Arduino

       void setup() {
           // put your setup code here, to run once:
           pinMode(13,OUTPUT); 
       }

       void loop() {
           // put your main code here, to run repeatedly:
           digitalWrite(13,HIGH);
           delay(500);
           digitalWrite(13,LOW);
           delay(500);
       }

#. Appuyez sur ``Ctrl+S`` ou cliquez sur **Fichier** -> **Enregistrer**. Le sketch est enregistré par défaut dans : ``C:\Users\{your_user}\Documents\Arduino``, vous pouvez le renommer ou choisir un nouveau chemin pour l'enregistrer.

   .. image:: img/create2.png

#. Après avoir enregistré avec succès, vous verrez que le nom dans l'IDE Arduino a été mis à jour.

   .. image:: img/create3.png

Veuillez continuer avec la section suivante pour apprendre comment téléverser ce sketch créé sur votre carte Arduino.
