.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Structure d'un programme Arduino
======================================

Jetons un coup d'œil au nouveau fichier sketch. Bien qu'il ne comporte que quelques lignes de code, il s'agit en fait d'un sketch "vide". 
Téléverser ce sketch sur la carte de développement ne provoquera aucune action.

.. code-block:: C

    void setup() {
    // placez votre code d'initialisation ici, il s'exécutera une seule fois :

    }

    void loop() {
    // placez votre code principal ici, il s'exécutera en boucle :

    }

Si nous supprimons ``setup()`` et ``loop()`` pour rendre le sketch vraiment ``vide``, vous constaterez qu'il ne passe pas la vérification. 
Ils sont l'équivalent du squelette humain et sont indispensables.

Lors de l'exécution d'un sketch, ``setup()`` est exécuté en premier, et le code à l'intérieur (entre les ``{}``) est exécuté après la mise sous tension ou le réinitialisation de la carte, une seule fois. 
``loop()`` est utilisé pour écrire la fonctionnalité principale, et le code à l'intérieur s'exécutera en boucle après l'exécution de ``setup()``.

Pour mieux comprendre ``setup()`` et ``loop()``, utilisons quatre sketches. Leur but est de faire clignoter la LED embarquée de l'Arduino. Veuillez exécuter chaque expérience à tour de rôle et noter leurs effets spécifiques.

* Sketch 1 : Faire clignoter la LED embarquée en continu.

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // placez votre code d'initialisation ici, il s'exécutera une seule fois :
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // placez votre code principal ici, il s'exécutera en boucle :
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

* Sketch 2 : Faire clignoter la LED embarquée une seule fois. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7

    void setup() {
        // placez votre code d'initialisation ici, il s'exécutera une seule fois :
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(13,LOW);
        delay(500);
    }

    void loop() {
        // placez votre code principal ici, il s'exécutera en boucle :
    }

* Sketch 3 : Faire clignoter la LED embarquée lentement une fois puis clignoter rapidement. 

.. code-block:: C
    :emphasize-lines: 4,5,6,7,12,13,14,15

    void setup() {
        // placez votre code d'initialisation ici, il s'exécutera une seule fois :
        pinMode(13,OUTPUT);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
    }

    void loop() {
        // placez votre code principal ici, il s'exécutera en boucle :
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

* Sketch 4 : Provoquer une erreur.

.. code-block:: C
    :emphasize-lines: 6,7,8,9

    void setup() {
        // placez votre code d'initialisation ici, il s'exécutera une seule fois :
        pinMode(13,OUTPUT);
    }

    digitalWrite(13,HIGH);
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);

    void loop() {
        // placez votre code principal ici, il s'exécutera en boucle :
    }    

Avec l'aide de ces sketches, nous pouvons résumer plusieurs caractéristiques de ``setup-loop``.

* ``loop()`` s'exécutera en boucle après la mise sous tension de la carte. 
* ``setup()`` ne s'exécutera qu'une seule fois après la mise sous tension de la carte. 
* Après la mise sous tension de la carte, ``setup()`` s'exécutera en premier, suivi de ``loop()``. 
* Le code doit être écrit à l'intérieur des accolades ``{}`` de ``setup()`` ou ``loop()``, en dehors du cadre, il y aura une erreur.

.. note::  
    Les instructions telles que ``digitalWrite(13, HIGH)`` sont utilisées pour contrôler la LED embarquée, et nous parlerons de leur utilisation en détail dans les chapitres suivants.
