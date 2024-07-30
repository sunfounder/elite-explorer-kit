.. note::

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts sur Facebook ! Plongez plus profondément dans l'univers de Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes post-vente et les défis techniques grâce à l'aide de notre communauté et de notre équipe.
    - **Apprendre et partager** : Échangez des conseils et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux avant-goûts.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos derniers produits.
    - **Promotions festives et concours** : Participez à des concours et promotions de fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

Variable
========

La variable est l'un des outils les plus puissants et critiques d'un programme. Elle nous aide à stocker et à appeler des données dans nos programmes.

Le fichier sketch suivant utilise des variables. Il stocke les numéros de broche de la LED embarquée dans la variable ``ledPin`` et un nombre "500" dans la variable ``delayTime``.

.. code-block:: C
    :emphasize-lines: 1,2

    int ledPin = 13;
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

Attendez, est-ce que cela fait un doublon avec ce que fait ``#define`` ? La réponse est NON.

* Le rôle de ``#define`` est de simplement et directement remplacer du texte, il n'est pas considéré par le compilateur comme faisant partie du programme. 
* Une ``variable``, en revanche, existe dans le programme et est utilisée pour stocker et appeler des valeurs. Une variable peut également modifier sa valeur dans le programme, ce que define ne peut pas faire.

Le fichier sketch ci-dessous ajoute automatiquement à la variable et cela fera clignoter la LED embarquée plus longtemps après chaque clignotement.

.. code-block:: C

    int ledPin = 13;
    int delayTime = 500;

    void setup() {
        pinMode(ledPin,OUTPUT); 
    }

    void loop() {
        digitalWrite(ledPin,HIGH); 
        delay(delayTime); 
        digitalWrite(ledPin,LOW); 
        delay(delayTime);
        delayTime = delayTime+200; // Chaque exécution augmente la valeur de 200
    }

Déclarer une variable
-------------------------

Déclarer une variable signifie créer une variable. 

Pour déclarer une variable, vous avez besoin de deux choses : le type de données et le nom de la variable. Le type de données doit être séparé du nom de la variable par un espace, et la déclaration de la variable doit se terminer par un ``;``.

Prenons cette variable comme exemple.

.. code-block:: C

    int delayTime;

**Type de données**

Ici, ``int`` est un type de données appelé type entier, qui peut être utilisé pour stocker des nombres entiers de -32768 à 32766. Il ne peut pas non plus être utilisé pour stocker des décimales.

Les variables peuvent contenir différents types de données autres que des entiers. Le langage Arduino (qui, rappelez-vous, est du C++) prend en charge quelques-uns d'entre eux (seuls les plus fréquemment utilisés et utiles sont listés ici) :

* ``float`` : Stocker un nombre décimal, par exemple 3.1415926.
* ``byte`` : Peut contenir des nombres de 0 à 255.
* ``boolean`` : Ne contient que deux valeurs possibles, ``True`` ou ``False``, même s'il occupe un octet en mémoire.
* ``char`` : Contient un nombre de -127 à 127. Comme il est marqué comme un ``char``, le compilateur essaiera de le faire correspondre à un caractère de la |link_ascii|.
* ``string`` : Peut stocker une chaîne de caractères, par exemple ``Halloween``.

**Nom de la variable**

Vous pouvez nommer la variable comme vous le souhaitez, par exemple ``i``, ``apple``, ``Bruce``, ``R2D2``, ``Sectumsempra``, mais il y a quelques règles de base à suivre.

1. Décrivez son utilisation. Ici, j'ai nommé la variable delayTime, donc vous pouvez facilement comprendre ce qu'elle fait. Cela fonctionne si je nomme la variable ``barryAllen``, mais cela confond la personne qui regarde le code.

2. Utilisez une nomenclature régulière. Vous pouvez utiliser CamelCase comme je l'ai fait, avec le T initial dans ``delayTime`` pour qu'il soit facile de voir que la variable se compose de deux mots. Vous pouvez aussi utiliser UnderScoreCase pour écrire la variable comme ``delay_time``. Cela n'affecte pas l'exécution du programme, mais cela aide le programmeur à lire le code si vous utilisez la nomenclature que vous préférez.

3. N'utilisez pas de mots clés. Comme lorsque nous tapons "int", l'IDE Arduino le colorera pour vous rappeler que c'est un mot avec un but spécial et ne peut pas être utilisé comme nom de variable. Changez le nom de la variable si elle est colorée. 

4. Les symboles spéciaux ne sont pas autorisés. Par exemple, espace, #, $, /, +, %, etc. La combinaison de lettres anglaises (sensibles à la casse), de traits de soulignement et de chiffres (mais les chiffres ne peuvent pas être utilisés comme premier caractère d'un nom de variable) est suffisamment riche.

**Attribuer une valeur à une variable**

Une fois que nous avons déclaré la variable, il est temps de stocker les données. Nous utilisons l'opérateur d'affectation (c'est-à-dire ``=``) pour mettre une valeur dans la variable.

Nous pouvons attribuer des valeurs à la variable dès que nous la déclarons.

.. code-block:: C

    int delayTime = 500;

Il est également possible de lui attribuer une nouvelle valeur à un moment donné.

.. code-block:: C

    int delayTime; // pas de valeur
    delayTime = 500; // la valeur est 500
    delayTime = delayTime + 200; // la valeur est 700
