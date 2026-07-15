.. note::

    Ciao, benvenuto nella comunità di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e agli sneak peek.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e omaggi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _basic_mfrc522:

Modulo RFID-RC522
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.35_rfid-rc522_module.html

Panoramica
-------------

In questa lezione, imparerai a utilizzare un modulo RFID. RFID sta per Radio Frequency Identification. Il suo principio di funzionamento prevede la comunicazione dati senza contatto tra il lettore e l'etichetta per identificare il target. Le applicazioni dell'RFID sono estese, inclusi chip per animali, immobilizzatori, controllo accessi, controllo parcheggi, automazione delle linee di produzione, gestione dei materiali e altro ancora.

Componenti necessari
-------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|

Circuito Fritzing
---------------------

In questo esempio, inseriamo l'RFID nel breadboard. Collega i 3.3V dell'RFID ai 3.3V, GND a GND, RST al pin 2, SDA al pin 6, SCK al pin 5, MOSI al pin 4, MISO al pin 3 e IRQ al pin 7.

.. image:: img/08-rfid_bb.png
   :align: center

Schema Elettrico
-------------------------

.. image:: img/08_mfrc522_schematic.png
   :align: center
   :width: 70%

Codice
-----------

.. note::

    * Puoi aprire il file ``08-mfrc522.ino`` dal percorso ``elite-explorer-kit-main\basic_project\08-mfrc522`` direttamente.
    * Qui viene utilizzata la libreria ``RFID1``. La libreria può essere trovata nella directory ``elite-explorer-kit-main/library/``, oppure puoi cliccare qui :download:`RFID1.zip </_static/RFID1.zip>` per scaricarla. Consulta :ref:`manual_install_lib` per un tutorial su come installarla.

.. literalinclude:: /_code/08_basic_mfrc522.ino
   :language: cpp
   :linenos:
   :caption: 08-mfrc522.ino

Caricato il codice sulla scheda Uno, puoi avvicinare la tua scheda RFID (chiave segreta) al lettore RFID. Il modulo leggerà le informazioni della scheda e le stamperà sul monitor seriale.  

Analisi del Codice
-------------------

Le funzioni del modulo sono incluse nella libreria ``rfid1.h``.

.. code-block:: arduino

    #include <rfid1.h>

**Funzioni della Libreria:**

.. code-block:: arduino

    RFID1 rfid;

Crea una nuova istanza della classe rfid1 che rappresenta un particolare
modulo RFID collegato al tuo Arduino.

.. code-block:: arduino

    void begin(IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN,SDA_PIN,RST_PIN)

Configurazione dei pin.

* ``IRQ_PIN,SCK_PIN,MOSI_PIN,MISO_PIN``: i pin utilizzati per la comunicazione SPI.
* ``SDA_PIN``: Adattatore dati sincrono.
* ``RST_PIN``: I pin utilizzati per il reset.

.. code-block:: arduino

    void init()

Inizializza l'RFID.

.. code-block:: arduino

    uchar request(uchar reqMode, uchar *TagType);

Cerca la scheda e legge il tipo di scheda, e la funzione restituirà lo stato di lettura corrente dell'RFID e restituirà MI_OK se ha successo.

* ``reqMode``: Metodi di ricerca. PICC_REQIDL è definito come comando 0x26 (Cerca le schede che non sono in modalità sleep nell'area dell'antenna).
* ``*TagType``: Viene utilizzato per memorizzare il tipo di scheda, e il suo valore può essere 4 byte (ad esempio 0x0400).

.. code-block:: arduino

    char * readCardType(uchar *TagType)

Questa funzione decodifica il numero esadecimale a quattro cifre di ``*tagType``
 nel tipo di scheda specifico e restituisce una stringa. Se viene passato 0x0400, 
 verrà restituito "MFOne-S50".

.. code-block:: arduino

    uchar anticoll(uchar *serNum);

Previeni conflitti e leggi il numero di serie della scheda. La funzione restituirà 
lo stato di lettura corrente dell'RFID. Restituisce MI_OK se ha successo.

* ``*serNum``: Viene utilizzato per memorizzare il numero di serie della scheda e restituire il numero di serie della scheda a 4 byte. Il 5° byte è il byte di ricontrollo (ad esempio, l'ID della mia scheda magnetica è 5AE4C955).

