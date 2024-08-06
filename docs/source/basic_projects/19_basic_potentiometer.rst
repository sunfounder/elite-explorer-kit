.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_potentiometer:

Potenziometro
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/controlling_an_led_by_potentiometer_uno.html


Panoramica
--------------------

In questa lezione, vedremo come cambiare la luminosità di un LED utilizzando un potenziometro e ricevere i dati del potenziometro nel Serial Monitor per vedere il cambiamento dei suoi valori.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`led`
        - |link_led_buy|
    *   - :ref:`cpn_potentiometer`
        - |link_potentiometer_buy|


Cablaggio
----------------------

.. image:: img/19-potentiometer_bb.png
    :align: center
    :width: 70%

Schema Elettrico
---------------------------

In questo esperimento, il potenziometro viene utilizzato come divisore di tensione, collegando dispositivi a tutti i suoi tre pin. Collega il pin centrale del potenziometro al pin A0 e gli altri due pin rispettivamente a 5V e GND. Pertanto, la tensione del potenziometro varia tra 0 e 5V. Ruota la manopola del potenziometro e la tensione sul pin A0 cambierà. Poi converti quella tensione in un valore digitale (0-1024) con il convertitore AD nella scheda di controllo. Attraverso la programmazione, possiamo utilizzare il valore digitale convertito per controllare la luminosità del LED sulla scheda di controllo.

.. image:: img/19_potentiometer_schematic.png
   :align: center
   :width: 70%

Codice
---------------

.. note::

    * Puoi aprire direttamente il file ``19-potentiometer.ino`` nel percorso ``elite-explorer-kit-main\basic_project\19-potentiometer``.
    * Oppure copia questo codice nell'Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fb09e333-4057-40d8-8485-0de2d88c06c1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato il codice sulla scheda Uno, puoi aprire il monitor seriale per osservare i valori letti dal potenziometro. Girando la manopola del potenziometro, il valore letto cambierà di conseguenza. La lettura analogica grezza del potenziometro varierà da \(0\) a \(1023\). Contemporaneamente, il codice ridimensiona questo valore a un intervallo di \(0\) a \(255\), che viene anche visualizzato sul monitor seriale. Questo valore scalato viene poi utilizzato per controllare la luminosità del LED collegato. Il LED diventerà più luminoso o più fioco in base al valore scalato. Vale la pena notare che, sebbene l'intervallo teorico del potenziometro sia \(0\) a \(1023\), l'intervallo effettivo può variare leggermente a causa delle tolleranze hardware.

Analisi del Codice
--------------------------

#. Inizializzazione e Setup (Impostazione dei Pin e Inizializzazione della Comunicazione Seriale)

   Prima di entrare nel loop, definiamo quali pin stiamo utilizzando e inizializziamo la comunicazione seriale.

   .. code-block:: arduino

      const int analogPin = 0;  // Pin di ingresso analogico collegato al potenziometro
      const int ledPin = 9;     // Pin di uscita digitale collegato al LED

      void setup() {
        Serial.begin(9600);  // Inizializza la comunicazione seriale con una velocità di trasmissione di 9600 baud
      }

#. Lettura dell'Ingresso Analogico (Ottenere Dati dal Potenziometro)

   In questo segmento, leggiamo i dati analogici dal potenziometro e li stampiamo sul monitor seriale.

   .. code-block:: arduino

        inputValue = analogRead(analogPin);  // Leggi il valore analogico dal potenziometro
        Serial.print("Input: ");             // Stampa "Input: " sul monitor seriale
        Serial.println(inputValue);          // Stampa il valore di input grezzo sul monitor seriale

#. Mappatura e Scalatura (Conversione dei Dati del Potenziometro)

   Scalamo i dati grezzi del potenziometro, che sono nell'intervallo da 0 a 1023, a un nuovo intervallo da 0 a 255.

   ``map(value, fromLow, fromHigh, toLow, toHigh)`` viene utilizzato per convertire un numero da un intervallo all'altro. Ad esempio, se il valore è compreso nell'intervallo di ``fromLow`` e ``fromHigh``, verrà convertito in un valore corrispondente all'interno dell'intervallo di ``toLow`` e ``toHigh``, mantenendo la proporzionalità tra i due intervalli.

   In questo caso, poiché il pin del LED (pin 9) ha un intervallo di 0-255, dobbiamo mappare i valori nell'intervallo di 0-1023 per adattarli allo stesso intervallo di 0-255.

   .. code-block:: arduino

      outputValue = map(inputValue, 0, 1023, 0, 255);  // Mappa il valore di input a un nuovo intervallo

#. Controllo del LED e Output Seriale

   Infine, controlliamo la luminosità del LED in base al valore scalato e stampiamo il valore scalato per il monitoraggio.

   .. code-block:: arduino

      Serial.print("Output: ");                        // Stampa "Output: " sul monitor seriale
      Serial.println(outputValue);                     // Stampa il valore di output scalato sul monitor seriale
      analogWrite(ledPin, outputValue);                // Controlla la luminosità del LED in base al valore scalato
      delay(1000);                                     // Attendi 1 secondo
