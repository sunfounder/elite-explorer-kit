.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_keypad:

Tastierino
==========================

.. https://docs.sunfounder.com/projects/vincent-kit-de/en/latest/arduino/2.19_keypad.html#ar-keypad

Panoramica
-------------

In questa lezione, imparerai a usare un tastierino. Il tastierino può essere applicato a vari tipi di dispositivi, tra cui telefoni cellulari, fax, forni a microonde e così via. È comunemente usato per l'input dell'utente.

Componenti Necessari
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

Puoi anche acquistarli separatamente dai link seguenti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE DEI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_keypad`
        - |link_keypad_buy|

Cablaggio
----------------------

.. image:: img/21-keypad_bb.png
    :align: center

Schema Elettrico
----------------------

.. image:: img/21_keypad_schematic.png
   :align: center
   :width: 70%

Codice
-----------


.. note::

    * Puoi aprire direttamente il file ``21-keypad.ino`` nel percorso ``elite-explorer-kit-main\basic_project\21-keypad``.
    * Per installare la libreria, usa il Gestore Librerie di Arduino e cerca **"Adafruit Keypad"** e installala. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/25fd4116-92d4-4ee4-b3ba-6707f4334629/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato il codice sulla scheda UNO, sul monitor seriale, puoi vedere il valore del tasto attualmente premuto sul tastierino.

Analisi del Codice
----------------------

1. Inclusione della Libreria

   Iniziamo includendo la libreria ``Adafruit_Keypad``, che ci permette di interfacciarci facilmente con il tastierino.

   .. code-block:: arduino

     #include "Adafruit_Keypad.h"

   .. note::

      * Per installare la libreria, usa il Gestore Librerie di Arduino e cerca **"Adafruit Keypad"** e installala. 


2. Configurazione del Tastierino

   .. code-block:: arduino

     const byte ROWS = 4;
     const byte COLS = 4;
     char keys[ROWS][COLS] = {
       { '1', '2', '3', 'A' },
       { '4', '5', '6', 'B' },
       { '7', '8', '9', 'C' },
       { '*', '0', '#', 'D' }
     };
     byte rowPins[ROWS] = { 2, 3, 4, 5 };
     byte colPins[COLS] = { 8, 9, 10, 11 };

   - Le costanti ``ROWS`` e ``COLS`` definiscono le dimensioni del tastierino.
   - ``keys`` è un array 2D che memorizza l'etichetta di ciascun pulsante del tastierino.
   - ``rowPins`` e ``colPins`` sono array che memorizzano i pin Arduino collegati alle righe e colonne del tastierino.

   .. raw:: html

      <br/>


3. Inizializzazione del Tastierino

   Crea un'istanza di ``Adafruit_Keypad`` chiamata ``myKeypad`` e inizializzala.

   .. code-block:: arduino

     Adafruit_Keypad myKeypad = Adafruit_Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

4. Funzione setup()

   Inizializza la comunicazione Serial e il tastierino personalizzato.

   .. code-block:: arduino

     void setup() {
       Serial.begin(9600);
       myKeypad.begin();
     }

5. Ciclo Principale

   Controlla gli eventi dei tasti e visualizzali nel Monitor Seriale.

   .. code-block:: arduino

     void loop() {
       myKeypad.tick();
       while (myKeypad.available()) {
         keypadEvent e = myKeypad.read();
         Serial.print((char)e.bit.KEY);
         if (e.bit.EVENT == KEY_JUST_PRESSED) Serial.println(" pressed");
         else if (e.bit.EVENT == KEY_JUST_RELEASED) Serial.println(" released");
       }
       delay(10);
     }

