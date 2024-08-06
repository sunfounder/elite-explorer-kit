.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Giveaway Festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _basic_mpr121:

MPR121
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.24_mpr121_module.html#ar-mpr121


Panoramica
---------------

In questa lezione, imparerai a usare il MPR121. È una buona opzione quando vuoi aggiungere molti interruttori touch al tuo progetto. L'elettrodo del MPR121 può essere esteso con un conduttore. Se colleghi un filo a una banana, puoi trasformare la banana in un interruttore touch, realizzando così progetti come il pianoforte di frutta.

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
    *   - :ref:`cpn_mpr121`
        - \-

Cablaggio
----------------------

In questo esempio, inseriamo il MPR121 nella breadboard. Collega il GND del MPR121 a GND, 3.3V a 3V3, IRQ al pin digitale 2, SCL al pin SCL(A5) e SDA al pin SDA(A4). Ci sono 12 elettrodi per il rilevamento touch. 

.. note::
    Il MPR121 è alimentato a 3.3V, non a 5V.

.. image:: img/23-mpr121_bb.png
    :align: center
    :width: 70%

Schema Elettrico
------------------------

.. image:: img/23_mpr121_schematic.png
   :align: center
   :width: 70%

Codice
----------

.. note::

    * Puoi aprire direttamente il file ``23-mpr121.ino`` nel percorso ``elite-explorer-kit-main\basic_project\23-mpr121``.
    * La libreria ``Adafruit MPR121`` viene utilizzata qui, puoi installarla dal **Library Manager**.

        .. image:: img/22_mpr121_lib.png
            :align: center

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/de0aa390-de85-43ab-87f7-f380c67c65e8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo aver caricato il codice sulla scheda UNO, lo stato di tocco dei pin MPR121 "1" e "0" verrà registrato in un array booleano a 12 bit. Questo array verrà quindi stampato sul monitor seriale.

Analisi del Codice
-----------------------
Questo codice facilita la comunicazione e il funzionamento del sensore touch MPR121. Può rilevare lo stato degli elettrodi touch e stampare informazioni sugli elettrodi toccati o rilasciati sull'interfaccia seriale. Se sono necessari dati dettagliati del sensore, il codice pertinente può essere decommentato.

Ecco un'analisi del codice:

#. Importa Librerie:

   .. code-block:: arduino

       #include <Wire.h>
       #include "Adafruit_MPR121.h"

   * ``Wire.h``: Utilizzata per la comunicazione I2C.
   * ``Adafruit_MPR121.h``: La libreria Adafruit per il funzionamento del sensore touch MPR121.

#. Definisci la Macro ``_BV``:

   .. code-block:: arduino

       #ifndef _BV
       #define _BV(bit) (1 << (bit)) 
       #endif
   
   ``_BV(bit)`` definisce una macro che converte un dato bit nel valore binario corrispondente, simile a 1 << bit.

#. Inizializza l'istanza della classe ``Adafruit_MPR121``:

   .. code-block:: arduino

       Adafruit_MPR121 cap = Adafruit_MPR121();

   Crea un'istanza della classe ``Adafruit_MPR121`` chiamata ``cap``. L'oggetto ``cap`` verrà utilizzato per comunicare e operare con il sensore touch MPR121.

#. Funzione ``setup()``:

   Inizializza la comunicazione seriale a un baud rate di 9600. poi inizializza il sensore touch MPR121 con l'indirizzo I2C predefinito di 0x5A. Se l'inizializzazione fallisce, stampa un messaggio di errore ed entra in un ciclo infinito.

   .. code-block:: arduino

       void setup() {
           Serial.begin(9600);
           
           while (!Serial) { // necessario per evitare che leonardo/micro partano troppo velocemente!
               delay(10);
           }
           
           Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
           
           // L'indirizzo predefinito è 0x5A, se collegato a 3.3V è 0x5B
           // Se collegato a SDA è 0x5C e se a SCL è 0x5D
           if (!cap.begin(0x5A)) {
               Serial.println("MPR121 not found, check wiring?");
               while (1);
           }
           Serial.println("MPR121 found!");
       }

#. Funzione ``loop()``:

   * Ottieni lo stato attuale del tocco, restituito come intero a 16 bit.


     .. code-block:: arduino

         currtouched = cap.touched();

   * Itera attraverso lo stato di 12 elettrodi (numerati da 0 a 11).

     .. code-block:: arduino

         for (uint8_t i=0; i<12; i++) {
             // se *è* toccato e *non era* toccato prima, avvisa!
             if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
                 Serial.print(i); Serial.println(" touched");
             }
             // se *era* toccato e ora *non è*, avvisa!
             if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
                 Serial.print(i); Serial.println(" released");
             }
         }

     * Se un elettrodo è toccato e non era toccato prima, stampa "x toccato," dove x è il numero dell'elettrodo.
     * Se un elettrodo era toccato prima ma non è toccato ora, stampa "x rilasciato."

   * Aggiorna ``lasttouched`` per memorizzare lo stato attuale del tocco per il confronto nella prossima iterazione.

     .. code-block:: arduino

         lasttouched = currtouched;

   * Informazioni di Debug (Sezione Opzionale):

     .. code-block:: arduino

         // informazioni di debug, cosa
         Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
         Serial.print("Filt: ");
         for (uint8_t i=0; i<12; i++) {
             Serial.print(cap.filteredData(i)); Serial.print("\t");
         }
         Serial.println();
         Serial.print("Base: ");
         for (uint8_t i=0; i<12; i++) {
             Serial.print(cap.baselineData(i)); Serial.print("\t");
         }
         Serial.println();
         
         // metti un ritardo per non sovraccaricare
         delay(100);
