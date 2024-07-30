.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Comment téléverser un sketch sur la carte ?
=================================================

Dans cette section, vous apprendrez comment téléverser le sketch créé précédemment sur la carte Arduino, ainsi que quelques considérations à prendre en compte.

**1. Choisissez la carte et le port**

Les cartes de développement Arduino sont généralement fournies avec un câble USB. Vous pouvez l'utiliser pour connecter la carte à votre ordinateur.

Sélectionnez la **Carte** et le **Port** corrects dans l'IDE Arduino. En général, les cartes Arduino sont automatiquement reconnues par l'ordinateur et se voient attribuer un port, que vous pouvez sélectionner ici.

    .. image:: img/04_upload_1.png
        :width: 90%


Si votre carte est déjà branchée mais non reconnue, vérifiez si le logo **INSTALLÉ** apparaît dans la section **Arduino UNO R4 Boards** du **Gestionnaire de cartes**. Si ce n'est pas le cas, faites défiler un peu vers le bas et cliquez sur **INSTALLER**.

Recherchez **"UNO R4"** dans le **Gestionnaire de cartes** et vérifiez si la bibliothèque correspondante est installée.

    .. image:: img/04_upload_2.png
        :width: 90%

Rouvrir l'IDE Arduino et rebrancher la carte Arduino résoudra la plupart des problèmes. Vous pouvez également cliquer sur **Outils** -> **Carte** ou **Port** pour les sélectionner.


**2. Vérifiez le sketch**

Après avoir cliqué sur le bouton Vérifier, le sketch sera compilé pour voir s'il y a des erreurs.

    .. image:: img/04_upload_3.png
        :width: 90%

Vous pouvez l'utiliser pour trouver des erreurs si vous supprimez des caractères ou tapez quelques lettres par erreur. À partir de la barre de messages, vous pouvez voir où et quel type d'erreurs se sont produites.

    .. image:: img/04_upload_4.png
        :width: 90%

S'il n'y a pas d'erreurs, vous verrez un message comme celui ci-dessous.

    .. image:: img/04_upload_5.png
        :width: 90%


**3. Téléverser le sketch**

Après avoir terminé les étapes ci-dessus, cliquez sur le bouton **Téléverser** pour téléverser ce sketch sur la carte.

    .. image:: img/04_upload_6.png
        :width: 90%

En cas de succès, vous verrez l'invite suivante.

    .. image:: img/04_upload_7.png
        :width: 90%

En même temps, la LED embarquée clignotera.

    .. image:: img/04_upload_8.png
        :width: 400
        :align: center

.. raw:: html
    
    <br/>

La carte Arduino exécutera automatiquement le sketch après l'application de l'alimentation une fois le sketch téléversé. Le programme en cours d'exécution peut être écrasé en téléversant un nouveau sketch.
