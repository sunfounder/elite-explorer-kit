.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_oled:

OLED
==========================

.. https://docs.sunfounder.com/projects/ultimate-sensor-kit/en/latest/components_basic/22-component_oled.html

Panoramica
---------------

In questa lezione imparerai a conoscere i display OLED utilizzando il driver SSD1306. I display OLED (diodi organici a emissione di luce) sono ampiamente utilizzati in vari dispositivi elettronici come smartwatch, telefoni cellulari e persino televisori. L'SSD1306 è un driver OLED/PLED CMOS a chip singolo con controller per sistemi di visualizzazione grafica a matrice di punti a diodi organici/polimerici a emissione di luce. Offre un output visivo nitido e chiaro attraverso i diodi a base di materiale organico che emettono luce quando una corrente elettrica li attraversa.

Nel codice fornito, un display OLED è interfacciato con una scheda Arduino tramite il protocollo I2C. Il codice utilizza la libreria Adafruit SSD1306 per controllare il display. Il programma copre varie funzionalità come:

1. Visualizzazione del testo: "Hello world!" viene stampato sullo schermo.
2. Testo invertito: Il testo "Hello world!" viene visualizzato in uno schema di colori invertito.
3. Dimensione del carattere: Il testo "Hello!" viene visualizzato con una dimensione del carattere aumentata.
4. Visualizzazione numerica: Vengono visualizzati i numeri 123456789.
5. Caratteri ASCII: Viene visualizzata una serie di caratteri ASCII.
6. Scorrimento: Il testo scorre orizzontalmente sul display.
7. Visualizzazione di bitmap: Viene visualizzata un'immagine bitmap predefinita sullo schermo OLED.

Questo display OLED può essere utilizzato in una moltitudine di applicazioni, tra cui orologi digitali, mini console di gioco, display informativi e così via. Offre un ottimo modo per fornire un'interfaccia utente in dispositivi compatti e portatili.

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
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

Cablaggio
----------------------

.. image:: img/15-oled_bb.png
    :align: center

Schema Elettrico
-----------------------

.. image:: img/15_oled_schematic.png
    :align: center
    :width: 70%

Codice
---------------

.. note::

    * Puoi aprire direttamente il file ``15-oled.ino`` nel percorso ``elite-explorer-kit-main\basic_project\15-oled``.
    * Oppure copia questo codice nell'Arduino IDE.

    .. note:: 
      Per installare la libreria, utilizza l'Arduino Library Manager e cerca **"Adafruit SSD1306"** e **"Adafruit GFX"** e installala. 

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ec580f40-78b4-42c2-af7c-bb5bc05a7c23/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/15_basic_oled.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

   <br/><br/>

Analisi del Codice
------------------------

1. **Inclusione della Libreria e Definizioni Iniziali**:
   Le librerie necessarie per l'interfacciamento con l'OLED sono incluse. Successivamente, vengono fornite le definizioni relative alle dimensioni dell'OLED e all'indirizzo I2C.


   - **Adafruit SSD1306**: Questa libreria è progettata per aiutare con l'interfacciamento del display OLED SSD1306. Fornisce metodi per inizializzare il display, controllarne le impostazioni e visualizzare i contenuti.
   - **Adafruit GFX Library**: Questa è una libreria grafica di base per visualizzare testo, produrre colori, disegnare forme, ecc., su vari schermi, inclusi gli OLED.

   .. note:: 
      Per installare la libreria, utilizza l'Arduino Library Manager e cerca **"Adafruit SSD1306"** e **"Adafruit GFX"** e installala. 

   .. code-block:: arduino
    
      #include <SPI.h>
      #include <Wire.h>
      #include <Adafruit_GFX.h>
      #include <Adafruit_SSD1306.h>

      #define SCREEN_WIDTH 128  // Larghezza del display OLED in pixel
      #define SCREEN_HEIGHT 64  // Altezza del display OLED in pixel

      #define OLED_RESET -1
      #define SCREEN_ADDRESS 0x3C

2. **Dati Bitmap**:
   Dati bitmap per visualizzare un'icona personalizzata sullo schermo OLED. Questi dati rappresentano un'immagine in un formato che l'OLED può interpretare.

   Puoi usare questo strumento online chiamato |link_image2cpp| che può trasformare la tua immagine in un array. 

   La parola chiave ``PROGMEM`` indica che l'array è memorizzato nella memoria del programma del microcontrollore Arduino. Memorizzare i dati nella memoria del programma (PROGMEM) invece che nella RAM può essere utile per grandi quantità di dati, che altrimenti occuperebbero troppo spazio nella RAM.

   .. code-block:: arduino

      static const unsigned char PROGMEM sunfounderIcon[] = {...};

3. **Funzione Setup (Inizializzazione e Visualizzazione)**:
   La funzione ``setup()`` inizializza l'OLED e visualizza una serie di schemi, testi e animazioni.

   .. code-block:: arduino

      void setup() {
         ...  // Inizializzazione seriale e dell'oggetto OLED
         ...  // Visualizzazione di vari testi, numeri e animazioni
      }
