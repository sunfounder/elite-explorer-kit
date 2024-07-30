.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _add_libraries:

Comment ajouter des bibliothèques ? (Important)
==================================================

Une bibliothèque est un ensemble de code ou de fonctions pré-écrites qui étendent les capacités de l'IDE Arduino. Les bibliothèques fournissent du code prêt à l'emploi pour diverses fonctionnalités, vous permettant de gagner du temps et des efforts dans la programmation de fonctions complexes.


Utilisation du gestionnaire de bibliothèques
------------------------------------------------

De nombreuses bibliothèques sont disponibles directement via le gestionnaire de bibliothèques Arduino. Vous pouvez accéder au gestionnaire de bibliothèques en suivant ces étapes :

#. Dans le **gestionnaire de bibliothèques**, vous pouvez rechercher la bibliothèque souhaitée par nom ou parcourir différentes catégories.

   .. note::

      Dans les projets nécessitant l'installation de bibliothèques, des indications vous indiqueront quelles bibliothèques installer. Suivez les instructions fournies, comme "La bibliothèque du capteur DHT est utilisée ici, vous pouvez l'installer depuis le gestionnaire de bibliothèques." Installez simplement les bibliothèques recommandées comme indiqué.

   .. image:: img/install_lib3.png

#. Une fois que vous avez trouvé la bibliothèque que vous souhaitez installer, cliquez dessus, puis cliquez sur le bouton **Installer**.

   .. image:: img/install_lib2.png

#. L'IDE Arduino téléchargera et installera automatiquement la bibliothèque pour vous.

.. _manual_install_lib:

Installation manuelle
-----------------------

Certaines bibliothèques ne sont pas disponibles via le **gestionnaire de bibliothèques** et doivent être installées manuellement. Pour installer ces bibliothèques, suivez ces étapes :

#. Ouvrez l'IDE Arduino et allez dans **Sketch** -> **Include Library** -> **Add .ZIP Library**.

   .. image:: img/add_lib_zip.png

#. Naviguez jusqu'au répertoire où se trouvent les fichiers de la bibliothèque, comme le dossier ``elite-explorer-kit-main/library/``, sélectionnez le fichier de la bibliothèque et cliquez sur **Ouvrir**.

   .. image:: img/rfid_choose.png

#. Une fois l'installation terminée, vous recevrez une notification confirmant que la bibliothèque a été ajoutée avec succès à votre IDE Arduino. La prochaine fois que vous aurez besoin d'utiliser cette bibliothèque, vous n'aurez pas besoin de répéter le processus d'installation.

   .. image:: img/rfid_success.png

#. Répétez le même processus pour ajouter d'autres bibliothèques.


Emplacement des bibliothèques
----------------------------------

Les bibliothèques installées en utilisant l'une des méthodes ci-dessus se trouvent dans le répertoire de bibliothèques par défaut de l'IDE Arduino, qui se trouve généralement à l'emplacement ``C:\Users\xxx\Documents\Arduino\libraries``.

Si votre répertoire de bibliothèques est différent, vous pouvez le vérifier en allant dans **Fichier** -> **Préférences**.

.. image:: img/install_lib1.png



**Référence**

* |link_install_arduino_lib|