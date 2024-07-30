.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Comment construire le circuit
====================================

Beaucoup des objets que vous utilisez quotidiennement sont alimentés par l'électricité, comme les lumières de votre maison et l'ordinateur sur lequel vous lisez ceci.

Pour utiliser l'électricité, vous devez construire un circuit électrique. En gros, un circuit est un chemin par lequel l'électricité circule, ou un circuit électronique, et il est composé de dispositifs et de composants électriques (appareils) connectés d'une certaine manière, comme des résistances, des condensateurs, des sources d'alimentation et des interrupteurs.

.. image:: img/circuit.png
    :align: center
    :width: 250

.. raw:: html
    
    <br/>

Un circuit est un chemin fermé dans lequel les électrons se déplacent pour créer un courant électrique. Pour que le courant circule, il doit y avoir un chemin conducteur entre la borne positive de l'alimentation et la borne négative, ce qu'on appelle un circuit fermé (s'il est interrompu, on l'appelle un circuit ouvert).

La carte Arduino possède des broches de sortie d'alimentation (positives) et des broches de masse (négatives).
Vous pouvez utiliser ces broches comme les côtés positif et négatif de l'alimentation en branchant la source d'alimentation dans la carte.

.. image:: img/08_circuit_1.png
    :align: center
    :width: 70%

Avec l'électricité, vous pouvez créer des œuvres avec la lumière, le son et le mouvement.
Vous pouvez allumer une LED en connectant la broche longue à la borne positive et la broche courte à la borne négative.
Cependant, faire cela directement peut rapidement endommager non seulement la LED, mais aussi risquer de nuire aux broches de votre carte UNO R4. Pour éviter cela, il est essentiel d'ajouter une résistance de 1 kΩ dans le circuit, protégeant ainsi à la fois la LED et les broches de l'UNO R4.

Le circuit qu'ils forment est montré ci-dessous.

.. image:: img/08_circuit_2.png
    :align: center
    :width: 65%

.. raw:: html
    
    <br/>

Vous pouvez vous demander comment construire ce circuit. Tenir les fils à la main ou coller les broches et les fils ?

Dans cette situation, les breadboards sans soudure seront vos meilleurs alliés.

.. _bc_bb:

Bonjour, Breadboard !
------------------------------

Un breadboard est une plaque rectangulaire en plastique avec une multitude de petits trous.
Ces trous nous permettent d'insérer facilement des composants électroniques et de construire des circuits électroniques.
Les breadboards ne fixent pas de manière permanente les composants électroniques, nous pouvons donc facilement réparer un circuit et recommencer en cas de problème.

.. note::
    Il n'est pas nécessaire d'utiliser des outils spéciaux pour utiliser les breadboards. Cependant, de nombreux composants électroniques sont très petits, et une paire de pinces peut nous aider à mieux manipuler les petites pièces.

Sur Internet, nous pouvons trouver de nombreuses informations sur les breadboards.

* `Comment utiliser un Breadboard - Science Buddies <https://www.sciencebuddies.org/science-fair-projects/references/how-to-use-a-breadboard#pth-smd>`_

* `Qu'est-ce qu'un BREADBOARD ? - Makezine <https://cdn.makezine.com/uploads/2012/10/breadboardworkshop.pdf>`_

Voici quelques informations importantes sur les breadboards.

.. image:: ../components/img/breadboard_internal.png
    :align: center
    :width: 85%

.. raw:: html

   <br/>

#. Chaque groupe de demi-lignes (comme la colonne A-E de la ligne 1 ou la colonne F-J de la ligne 3) est connecté. Par conséquent, si un signal électrique entre par A1, il peut sortir par B1, C1, D1, E1, mais pas par F1 ou A2.

#. Dans la plupart des cas, les deux côtés du breadboard sont utilisés comme bus d'alimentation, et les trous de chaque colonne (environ 50 trous) sont connectés ensemble. En règle générale, les alimentations positives sont connectées aux trous près du fil rouge, et les alimentations négatives sont connectées aux trous près du fil bleu.

**Suivons la direction du courant pour construire le circuit !**

.. image:: img/08_circuit_3.png
    :align: center
    :width: 60%

.. raw:: html
    
    <br/>

1. Dans ce circuit, nous utilisons la broche 5V de la carte pour alimenter la LED. Utilisez un fil de connexion mâle-mâle (M2M) pour le connecter au bus d'alimentation rouge.
#. Pour protéger la LED et les broches de l'UNO R4, le courant doit passer par une résistance de 1k ohm. Connectez une extrémité (n'importe laquelle) de la résistance au bus d'alimentation rouge et l'autre extrémité à une rangée libre du breadboard.

   .. note::
        L'anneau de couleur de la résistance de 1000 ohms :ref:`cpn_resistor` est rouge, noir, noir, marron et marron.

#. Si vous prenez la LED, vous verrez que l'une de ses pattes est plus longue que l'autre. Connectez la patte longue à la même rangée que la résistance, et la patte courte à l'autre rangée.

   .. note::
        La patte longue est l'anode, qui représente le côté positif du circuit ; la patte courte est la cathode, qui représente le côté négatif.

        L'anode doit être connectée à la broche GPIO via une résistance ; la cathode doit être connectée à la broche GND.

#. Utilisez un fil de connexion mâle-mâle (M2M) pour connecter la patte courte de la LED au bus d'alimentation négatif du breadboard.
#. Connectez la broche GND de la carte au bus d'alimentation négatif à l'aide d'un fil de connexion.

Attention aux courts-circuits
---------------------------------
Les courts-circuits peuvent se produire lorsque deux composants qui ne devraient pas être connectés le sont "accidentellement".
Ce kit comprend des résistances, des transistors, des condensateurs, des LEDs, etc., qui ont de longues pattes métalliques pouvant se toucher et provoquer un court-circuit. Certains circuits sont simplement empêchés de fonctionner correctement lorsqu'un court-circuit se produit. Parfois, un court-circuit peut endommager les composants de manière permanente, en particulier entre l'alimentation et le bus de masse, ce qui peut rendre le circuit très chaud, faire fondre le plastique du breadboard et même brûler les composants !

Par conséquent, assurez-vous toujours que les pattes de tous les composants électroniques sur le breadboard ne se touchent pas.

Orientation du circuit
----------------------------------
Les circuits ont une orientation, et celle-ci joue un rôle important pour certains composants électroniques. Certains dispositifs ont une polarité, ce qui signifie qu'ils doivent être connectés correctement en fonction de leurs pôles positif et négatif. Les circuits construits avec la mauvaise orientation ne fonctionneront pas correctement.

.. image:: img/08_circuit_4.png
    :align: center
    :width: 60%

.. raw:: html
    
    <br/>

Si vous inversez la LED dans ce simple circuit que nous avons construit précédemment, vous constaterez qu'elle ne fonctionne plus.

En revanche, certains dispositifs n'ont pas de direction, comme les résistances dans ce circuit, vous pouvez donc essayer de les inverser sans affecter le fonctionnement normal des LEDs.

La plupart des composants et modules portant des étiquettes telles que "+", "-", "GND", "VCC" ou ayant des pattes de différentes longueurs doivent être connectés au circuit d'une manière spécifique.

Protection du circuit
-------------------------------------

Le courant est la vitesse à laquelle les électrons passent par un point dans un circuit électrique complet. À son niveau le plus basique, le courant = débit. Un ampère (AM-pir), ou ampère, est l'unité internationale utilisée pour mesurer le courant. Il exprime la quantité d'électrons (parfois appelée "charge électrique") passant par un point dans un circuit sur une période donnée.

La force motrice (tension) derrière le flux de courant est appelée tension et est mesurée en volts (V).

La résistance (R) est la propriété du matériau qui restreint le flux de courant, et elle est mesurée en ohms (Ω).

Selon la loi d'Ohm (tant que la température reste constante), le courant, la tension et la résistance sont proportionnels.
Le courant d'un circuit est proportionnel à sa tension et inversement proportionnel à sa résistance.

Par conséquent, courant (I) = tension (V) / résistance (R).

* `Loi d'Ohm - Wikipedia <https://en.wikipedia.org/wiki/Ohm%27s_law>`_

À propos de la loi d'Ohm, nous pouvons faire une simple expérience.

.. image:: img/08_circuit_5.png
    :width: 55%

En changeant le fil reliant 5V à 3.3V, la LED devient plus faible.
Si vous changez la résistance de 1000 ohms à 2000 ohms (anneau de couleur : rouge, noir, noir, marron et marron), vous remarquerez que la LED devient plus faible qu'avant. Plus la résistance est grande, plus la LED est faible.

La plupart des modules emballés ne nécessitent qu'un accès à la tension appropriée (généralement 3,3 V ou 5 V), comme le module à ultrasons.

Cependant, dans vos circuits auto-construits, vous devez être conscient de la tension d'alimentation et de l'utilisation des résistances pour les dispositifs électriques.

Par exemple, les LEDs consomment généralement 20 mA de courant, et leur chute de tension est d'environ 1,8 V. Selon la loi d'Ohm, si nous utilisons une alimentation de 5 V, nous devons connecter une résistance d'au moins 160 ohms ((5-1,8)/20 mA) pour ne pas brûler la LED.

Contrôler un circuit avec Arduino
--------------------------------------

Maintenant que nous avons une compréhension de base de la programmation Arduino et des circuits électroniques, il est temps d'aborder la question la plus cruciale : Comment contrôler les circuits avec Arduino ?

En termes simples, la façon dont Arduino contrôle un circuit est en changeant le niveau des broches de la carte. Par exemple, lors du contrôle d'une LED embarquée, il s'agit d'écrire un signal de niveau haut ou bas sur la broche 13.

Essayons maintenant de programmer la carte Arduino pour contrôler le clignotement de la LED sur le breadboard. Construisez le circuit de manière à ce que la LED soit connectée à la broche 9.

.. image:: img/08_circuit_6.png
    :width: 400
    :align: center

Ensuite, téléversez ce sketch sur la carte de développement Arduino.

.. code-block:: C

    int ledPin = 9;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
    }

Ce sketch est très similaire à celui que nous avons utilisé pour contrôler le clignotement de la LED embarquée, la différence est que la valeur de ``ledPin`` a été changée à 9.
C'est parce que cette fois nous essayons de contrôler le niveau de la broche 9.

Vous pouvez maintenant voir la LED sur le breadboard clignoter.
