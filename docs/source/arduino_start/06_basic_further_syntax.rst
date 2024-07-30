.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Règles d'écriture des sketches
==================================


Si vous demandez à un ami d'allumer les lumières, vous pouvez dire "Allume les lumières.", ou "Lumières allumées, mec.", vous pouvez utiliser le ton que vous voulez.

Cependant, si vous voulez que la carte Arduino fasse quelque chose pour vous, vous devez suivre les règles de programmation Arduino pour taper les commandes.

Ce chapitre contient les règles de base du langage Arduino et vous aidera à comprendre comment traduire le langage naturel en code.

Bien sûr, c'est un processus qui prend du temps pour se familiariser, et c'est aussi la partie la plus sujette aux erreurs pour les débutants. Donc, si vous faites souvent des erreurs, ce n'est pas grave, essayez juste quelques fois de plus.


Point-virgule ``;``
----------------------

Tout comme l'écriture d'une lettre, où vous mettez un point à la fin de chaque phrase pour indiquer la fin, le langage Arduino exige que vous utilisiez ``;`` pour indiquer la fin de la commande.

Prenons l'exemple familier du clignotement de la LED embarquée. Un sketch correct devrait ressembler à ceci.

Exemple :

.. code-block:: C

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

Ensuite, examinons les deux sketches suivants et devinons s'ils peuvent être correctement reconnus par Arduino avant de les exécuter.

Sketch A :

.. code-block:: C
    :emphasize-lines: 8,9,10,11

    void setup() {
        // placez votre code d'initialisation ici, il s'exécutera une seule fois :
        pinMode(13,OUTPUT); 
    }

    void loop() {
        // placez votre code principal ici, il s'exécutera en boucle :
        digitalWrite(13,HIGH)
        delay(500)
        digitalWrite(13,LOW)
        delay(500)
    }

Sketch B :

.. code-block:: C
    :emphasize-lines: 8,9,10,11,12,13,14,15,16

    void setup() {
        // placez votre code d'initialisation ici, il s'exécutera une seule fois :
        pinMode(13,OUTPUT);
    }
    
    void loop() {
        // placez votre code principal ici, il s'exécutera en boucle :
        digitalWrite(13,
    HIGH);  delay
        (500
        );
        digitalWrite(13,
        
        LOW);
                delay(500)
        ;
    }

Le résultat est que **Sketch A** signale une erreur et que **Sketch B** fonctionne.

* Les erreurs dans **Sketch A** sont dues à l'absence de ``;``, et bien qu'il semble normal, Arduino ne peut pas le lire.
* **Sketch B** semble inhumain, mais en fait, l'indentation, les sauts de ligne et les espaces dans les instructions sont des éléments qui n'existent pas dans les programmes Arduino. Pour le compilateur Arduino, il apparaît donc comme dans l'exemple.

Cependant, ne rédigez pas votre code comme **Sketch B**, car ce sont généralement des personnes naturelles qui écrivent et consultent le code, alors ne vous compliquez pas la vie.


Accolades ``{}``
--------------------

Les accolades ``{}`` sont l'un des composants principaux du langage de programmation Arduino, et elles doivent apparaître par paires. 
Une meilleure convention de programmation consiste à insérer une structure nécessitant des accolades en tapant l'accolade droite directement après avoir tapé l'accolade gauche, puis à déplacer le curseur entre les accolades pour insérer l'instruction.



Commentaires ``//``
----------------------

Le commentaire est la partie du sketch que le compilateur ignore. Ils sont généralement utilisés pour expliquer le fonctionnement du programme.

Si nous écrivons deux barres obliques adjacentes dans une ligne de code, le compilateur ignorera tout jusqu'à la fin de la ligne.

Si nous créons un nouveau sketch, il est accompagné de deux commentaires, et si nous supprimons ces deux commentaires, le sketch ne sera pas affecté de quelque manière que ce soit.

.. code-block:: C
    :emphasize-lines: 2,7

    void setup() {
        // placez votre code d'initialisation ici, il s'exécutera une seule fois :

    }

    void loop() {
        // placez votre code principal ici, il s'exécutera en boucle :

    }


Les commentaires sont très utiles en programmation, et plusieurs usages courants sont listés ci-dessous.

* Usage A : Dites-vous ou dites aux autres ce que fait cette section de code.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT);  // Réglez le pin 13 en mode sortie, il contrôle la LED embarquée
    }

    void loop() {
        digitalWrite(13,HIGH); // Activez la LED embarquée en mettant le pin 13 à HIGH
        delay(500); // Maintenez l'état pendant 500 ms
        digitalWrite(13, LOW); // Éteignez la LED embarquée
        delay(500);// Maintenez l'état pendant 500 ms
    }

* Usage B : Invalidez temporairement certaines instructions (sans les supprimer) et décommentez-les lorsque vous avez besoin de les utiliser, ainsi vous n'avez pas besoin de les réécrire. Ceci est très utile lors du débogage du code et de la tentative de localisation des erreurs du programme.

.. code-block:: C
    :emphasize-lines: 3,4,5,6

    void setup() {
        pinMode(13,OUTPUT);
        // digitalWrite(13, HIGH);
        // delay(1000);
        // digitalWrite(13, LOW);
        // delay(1000);
    }

    void loop() {
        digitalWrite(13,HIGH);
        delay(200);
        digitalWrite(13,LOW);
        delay(200);
    }    

.. note:: 
    Utilisez le raccourci ``Ctrl+/`` pour vous aider à commenter ou décommenter rapidement votre code.

Commentaires ``/**/``
-----------------------

Même utilisation que ``//`` pour les commentaires. Ce type de commentaire peut s'étendre sur plusieurs lignes, et une fois que le compilateur lit ``/*``, il ignore tout ce qui suit jusqu'à ce qu'il rencontre ``*/``.

Exemple 1 :

.. code-block:: C
    :emphasize-lines: 1,8,9,10,11

    /* Clignoter */

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        /*
        Le code suivant fera clignoter la LED embarquée
        Vous pouvez modifier le nombre dans delay() pour changer la fréquence de clignotement
        */
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }


``#define``
--------------

C'est un outil utile en C++.

.. code-block:: C

    #define identifier token-string

Le compilateur remplace automatiquement ``identifier`` par ``token-string`` lorsqu'il le lit, ce qui est généralement utilisé pour les définitions de constantes.

Par exemple, voici un sketch utilisant define, ce qui améliore la lisibilité du code.

.. code-block:: C
    :emphasize-lines: 1,2

    #define ONBOARD_LED 13
    #define DELAY_TIME 500

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
        delay(DELAY_TIME); 
        digitalWrite(ONBOARD_LED,LOW); 
        delay(DELAY_TIME);
    }

Pour le compilateur, il apparaît en fait comme ceci.

.. code-block:: C

    void setup() {
        pinMode(13,OUTPUT); 
    }

    void loop() {
        digitalWrite(13,HIGH); 
        delay(500); 
        digitalWrite(13,LOW); 
        delay(500);
    }

Nous pouvons voir que l'``identifier`` est remplacé et n'existe pas à l'intérieur du programme.
Par conséquent, il y a plusieurs précautions à prendre lors de son utilisation.

1. Un ``token-string`` ne peut être modifié manuellement et ne peut être converti en d'autres valeurs par des calculs dans le programme.

2. Évitez d'utiliser des symboles tels que ``;``. Par exemple :

.. code-block:: C
    :emphasize-lines: 1

    #define ONBOARD_LED 13;

    void setup() {
        pinMode(ONBOARD_LED,OUTPUT); 
    }

    void loop() {
        digitalWrite(ONBOARD_LED,HIGH); 
    }

Le compilateur le reconnaîtra comme suit, ce qui sera signalé comme une erreur.

.. code-block:: C
    :emphasize-lines: 2,6

    void setup() {
        pinMode(13;, OUTPUT); 
    }

    void loop() {
        digitalWrite(13;, HIGH); 
    }

.. note:: 
    Une convention de dénomination pour ``#define`` est de mettre l'``identifier`` en majuscules pour éviter toute confusion avec les variables.
