.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_ws2812:

Striscia LED RGB WS2812
============================

Panoramica
-----------------

In questa lezione, imparerai a conoscere i LED NeoPixel e come controllarli utilizzando la libreria FastLED su un Arduino Uno R4. I LED NeoPixel sono ampiamente utilizzati in varie applicazioni come decorazioni domestiche, indossabili e illuminazione per eventi. La libreria FastLED semplifica il processo di programmazione di questi LED. Qui, una catena di 8 LED NeoPixel è collegata a un Arduino, e ogni LED nella sequenza si illumina momentaneamente di blu prima di spegnersi, passando al LED successivo nella catena. Questo esempio di base può servire come base per schemi di luce più complessi o progetti di illuminazione interattiva.

Componenti Necessari
---------------------------

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
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

Cablaggio
----------------------

.. image:: img/12-ws2812_bb.png
    :align: center

Schema Elettrico
-----------------------

.. image:: img/12_ws2812_schematic.png
    :align: center
    :width: 80%

Codice
---------------

.. note::

    * Puoi aprire direttamente il file ``12-ws2812.ino`` nel percorso ``elite-explorer-kit-main\basic_project\12-ws2812``.
    * Oppure copia questo codice nell'Arduino IDE.

.. note::
    Per installare la libreria, usa l'Arduino Library Manager e cerca **"FastLED"** per installarla.

.. important::
    Con il rilascio di |link_fastled_3_7_0|, la libreria FastLED supporta ora ufficialmente l'Arduino UNO R4. Pertanto, non è più necessario installare manualmente la versione di sviluppo. Aggiorna o installa semplicemente la libreria FastLED utilizzando l'Arduino Library Manager.

.. warning::
    **[Obsoleto]** Poiché la libreria |link_FastLED_lib| non ha ancora rilasciato ufficialmente una versione che supporti Arduino R4, dovrai scaricare :download:`l'ultima versione del codice di sviluppo della libreria FastLED <https://codeload.github.com/FastLED/FastLED/zip/refs/heads/master>` e sovrascrivere i file esistenti della libreria FastLED. Per istruzioni dettagliate su come farlo, consulta la sezione :ref:`manual_install_lib`. (Questa nota verrà ritirata quando la libreria FastLED rilascerà ufficialmente un aggiornamento che supporti l'Arduino UNO R4.)

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/6c9b8c2c-6cea-4ea8-a959-e579ca98f35d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/12_basic_ws2812.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

Dopo aver caricato correttamente il codice, vedrai ogni LED nella catena di 8 LED NeoPixel illuminarsi uno alla volta di blu. Il programma ripeterà continuamente questa sequenza, spegnendo ogni LED prima di passare al successivo. Con un breve ritardo tra ogni LED, l'effetto di illuminazione apparirà come un punto blu in movimento lungo la catena.

Analisi del Codice
------------------------

1. Importare la Libreria e Configurare le Costanti

   - Importare la libreria ``FastLED`` per utilizzare le sue funzioni.
   - Definire il numero di LED e il pin dati a cui sono collegati.
   
   .. code-block:: arduino
   
      #include <FastLED.h>  // Includere la libreria FastLED
      #define NUM_LEDS 8    // Numero di LED nella catena
      #define DATA_PIN 6    // Pin dati per il controllo dei LED

2. Inizializzare l'Array dei LED
   
   Creare un array di tipo ``CRGB`` per memorizzare le informazioni sui colori di ciascun LED.

   .. code-block:: arduino

      CRGB leds[NUM_LEDS];  // Array per memorizzare i dati dei colori dei LED

3. Inizializzare i LED nel Setup

   Utilizzare ``FastLED.addLeds`` per inizializzare i LED.

   .. code-block:: arduino

      void setup() {
        FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // Inizializzare i LED
      }

4. Controllare i LED nel Loop
   
   Ciclo attraverso ogni LED per impostarlo su blu, visualizzarlo, cancellarlo e quindi ritardare.

   - L'array ``leds`` serve come buffer di colore per la tua striscia LED. Ogni elemento in questo array corrisponde a un singolo LED sulla tua striscia fisica e il suo valore di colore determina il colore che il LED visualizzerà. L'ordine degli elementi nell'array corrisponde all'ordine dei LED sulla striscia, partendo dal primo LED (che corrisponde a ``leds[0]``) fino all'ultimo LED. Per cambiare il colore di un LED specifico sulla tua striscia, basta modificare l'elemento corrispondente nell'array ``leds``. Puoi usare |fastled_color| o impostare i colori utilizzando RGB (Prendendo come esempio il verde, usa ``leds[dot] = CRGB::Green`` o ``leds[dot] = CRGB(0, 255, 0);``).

   - La funzione ``FastLED.show();`` aggiorna la striscia LED con i nuovi dati di colore, rendendo visibili le modifiche. È come premere il pulsante "pubblica" per la tua striscia LED dopo aver apportato modifiche e regolazioni nel codice.

   .. raw:: html

     <br/>

   .. code-block:: arduino

      void loop() {
        for (int dot = 0; dot < NUM_LEDS; dot++) {
          leds[dot] = CRGB::Blue;   // Imposta il LED corrente su blu
          FastLED.show();           // Aggiorna i LED
          leds[dot] = CRGB::Black;  // Cancella il LED corrente
          delay(30);                // Attendi un breve periodo prima di passare al LED successivo
        }
      }
