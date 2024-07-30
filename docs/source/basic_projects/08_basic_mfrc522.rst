.. note::

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez plus profondément dans le monde des Raspberry Pi, Arduino et ESP32 avec d'autres passionnés.

    **Pourquoi rejoindre ?**

    - **Support d'experts** : Résolvez les problèmes après-vente et les défis techniques avec l'aide de notre communauté et de notre équipe.
    - **Apprendre & Partager** : Échangez des astuces et des tutoriels pour améliorer vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux nouvelles annonces de produits et aux aperçus exclusifs.
    - **Réductions spéciales** : Profitez de réductions exclusives sur nos produits les plus récents.
    - **Promotions festives et cadeaux** : Participez à des concours et à des promotions de vacances.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd'hui !

.. _basic_mfrc522:

Module RFID-RC522
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.35_rfid-rc522_module.html

Aperçu
-------------

Dans cette leçon, vous apprendrez à utiliser un module RFID. RFID signifie Radio Frequency Identification (Identification par radiofréquence). Son principe de fonctionnement implique une communication de données sans contact entre le lecteur et l'étiquette pour identifier la cible. Les applications de la RFID sont nombreuses, notamment les puces pour animaux, les systèmes antivol, le contrôle d'accès, la gestion des parkings, l'automatisation des chaînes de production, la gestion des matériaux, et bien plus encore.

Composants nécessaires
-------------------------

Dans ce projet, nous avons besoin des composants suivants.

Il est très pratique d'acheter un kit complet, voici le lien :

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nom
        - ÉLÉMENTS DANS CE KIT
        - LIEN
    *   - Kit Elite Explorer
        - 300+
        - |link_Elite_Explorer_kit|

Vous pouvez également les acheter séparément via les liens ci-dessous.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUCTION DES COMPOSANTS
        - LIEN D'ACHAT

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|

Circuit Fritzing
---------------------

Dans cet exemple, nous insérons le module RFID dans la plaque de prototypage. Connectez le 3.3V du RFID au 3.3V, GND à GND, RST à la broche 2, SDA à la broche 6, SCK à la broche 5, MOSI à la broche 4, MISO à la broche 3 et IRQ à la broche 7.

.. image:: img/08-rfid_bb.png
   :align: center

Schéma de connexion
-------------------------

.. image:: img/08_mfrc522_schematic.png
   :align: center
   :width: 70%

Code
-----------

.. note::

    * Vous pouvez ouvrir le fichier ``08-mfrc522.ino`` sous le chemin ``elite-explorer-kit-main\basic_project\08-mfrc522`` directement.
    * La bibliothèque ``RFID1`` est utilisée ici. Vous pouvez la trouver dans le répertoire ``elite-explorer-kit-main/library/``, ou cliquez ici :download:`RFID1.zip </_static/RFID1.zip>` pour la télécharger. Consultez :ref:`manual_install_lib` pour un tutoriel sur la manière de l'installer.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/9a4e9be9-78f5-4bf0-8b44-ca6e44092dc1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Une fois le code téléchargé sur la carte Uno, approchez votre carte RFID (clé secrète) du lecteur RFID. Le module lira les informations de la carte et les imprimera ensuite sur le moniteur série.

Analyse du code
-------------------

Les fonctions du module sont incluses dans la bibliothèque ``rfid1.h``.

.. code-block:: arduino

    #include <rfid1.h>

**Fonctions de la bibliothèque :**

.. code-block:: arduino

    RFID1 rfid;

Créer une nouvelle instance de la classe rfid1 qui représente un module
RFID particulier attaché à votre Arduino.

.. code-block:: arduino

    void begin(IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN,SDA_PIN,RST_PIN)

Configuration des broches.

* ``IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN`` : les broches utilisées pour la communication SPI.
* ``SDA_PIN`` : Adaptateur de données synchrones.
* ``RST_PIN`` : Les broches utilisées pour la réinitialisation.

.. code-block:: arduino

    void init()

Initialiser le RFID.

.. code-block:: arduino

    uchar request(uchar reqMode, uchar *TagType);

Rechercher une carte et lire le type de carte, et la fonction renverra l'état de lecture actuel du RFID et renverra MI_OK si elle réussit.

* ``reqMode`` : Méthodes de recherche. PICC_REQIDL est défini par des bits de commande 0x26 (Rechercher les cartes qui ne sont pas en mode veille dans la zone de l'antenne).
* ``*TagType`` : Il est utilisé pour stocker le type de carte, et sa valeur peut être de 4 octets (par exemple, 0x0400).

.. code-block:: arduino

    char * readCardType(uchar *TagType)

Cette fonction décode le nombre hexadécimal à quatre chiffres de ``*tagType``
en type de carte spécifique et renvoie une chaîne. Si 0x0400 est passé,
"MFOne-S50" sera renvoyé.

.. code-block:: arduino

    uchar anticoll(uchar *serNum);

Prévenir les conflits et lire le numéro de série de la carte. La fonction
renverra l'état de lecture actuel du RFID. Elle renvoie MI_OK si elle réussit.

* ``*serNum`` : Il est utilisé pour stocker le numéro de série de la carte et renvoyer le numéro de série de 4 octets. Le 5ème octet est un octet de vérification (par exemple, mon ID de carte magnétique est 5AE4C955).
