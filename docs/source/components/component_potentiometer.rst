.. note::

    Bonjour, bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez dans l'univers du Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux avant-premières.
    - **Réductions exclusives** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et des promotions festives.

    👉 Prêt à explorer et créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _cpn_potentiometer:

Potentiomètre
==================

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Le potentiomètre est également un composant résistif avec 3 bornes dont la valeur de résistance peut être ajustée selon une certaine variation régulière.

Les potentiomètres existent sous différentes formes, tailles et valeurs, mais ils ont tous les points communs suivants :

* Ils ont trois bornes (ou points de connexion).
* Ils ont un bouton, une vis ou un curseur qui peut être déplacé pour faire varier la résistance entre la borne centrale et l'une des bornes extérieures.
* La résistance entre la borne centrale et l'une des bornes extérieures varie de 0 Ω à la résistance maximale du potentiomètre à mesure que le bouton, la vis ou le curseur est déplacé.

Voici le symbole du circuit du potentiomètre.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Les fonctions du potentiomètre dans le circuit sont les suivantes :

#. Servir de diviseur de tension

    Le potentiomètre est une résistance ajustable en continu. Lorsque vous ajustez l'axe ou la poignée coulissante du potentiomètre, le contact mobile glisse sur la résistance. À ce stade, une tension peut être sortie en fonction de la tension appliquée sur le potentiomètre et de l'angle de rotation du bras mobile ou du déplacement effectué.

#. Servir de rhéostat

    Lorsque le potentiomètre est utilisé comme rhéostat, connectez la broche centrale et l'une des deux autres broches dans le circuit. Vous pouvez ainsi obtenir une valeur de résistance modifiée en douceur et en continu sur la course du contact mobile.

#. Servir de contrôleur de courant

    Lorsque le potentiomètre agit comme un contrôleur de courant, la borne de contact coulissante doit être connectée comme l'une des bornes de sortie.

Si vous souhaitez en savoir plus sur le potentiomètre, consultez : |link_potentiometer_wiki|.

**Exemple**

* :ref:`basic_potentiometer` (Projet de base)
* :ref:`fun_hue` (Projet amusant)

