.. note::
    Ciao, benvenuto nella comunità degli appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci Raspberry Pi, Arduino e ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato alle nuove presentazioni di prodotto e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri nuovi prodotti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _new_led_matrix:

Matrice LED 12x8
========================================

L'Arduino UNO R4 WiFi è dotato di una matrice LED 12x8 integrata che può essere programmata per visualizzare una varietà di grafiche, animazioni, fungere da interfaccia o facilitare esperienze di gioco.

.. image:: img/unor4wifi.webp
    :width: 60%

In questa guida, forniamo un esempio semplice per aiutarti a visualizzare il modello desiderato sulla matrice LED.

Come memorizzare i dati della matrice LED in Arduino
---------------------------------------------------------

Per utilizzare la matrice LED, avrai bisogno della libreria ``Arduino_LED_Matrix``, che è installata insieme al core Renesas.

La libreria della matrice LED per l'UNO R4 WiFi funziona creando e caricando frame in un buffer per visualizzarli. Un frame, noto anche come "immagine," rappresenta ciò che è attualmente mostrato sulla matrice. In un'animazione composta da più immagini, ogni immagine è considerata un frame.

Per controllare la matrice LED 12x8 sull'UNO R4 WiFi, è necessario uno spazio minimo di memoria di 96 bit. La libreria offre due approcci per questo.

**Un approccio utilizza un array bidimensionale**, con zeri e uno per rappresentare se il LED corrispondente è spento o acceso. Ogni numero corrisponde a un LED sulla matrice LED. L'array seguente illustra un modello a forma di cuore.

.. code-block:: arduino
   
   // Utilizza un array bidimensionale per rappresentare una matrice LED 12x8.
   byte frame[8][12] = {
     { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
     { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
     { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
     { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
     { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
   };

**Un altro approccio utilizza un array di interi a 32 bit** per mantenere lo stato della matrice LED. Questo metodo è più compatto ma leggermente più complesso. Ogni ``unsigned long`` contiene 32 bit. Pertanto, per una matrice LED 12x8, che contiene 96 LED, avrai bisogno di almeno tre variabili ``unsigned long``.

1. Ogni ``unsigned long`` contiene 32 bit, e puoi pensare a questi bit come lo stato di una parte specifica di una matrice LED.
2. Queste variabili ``unsigned long`` formano un array che racchiude lo stato completo della matrice LED.

Ecco un frammento di codice che utilizza tre variabili `unsigned long` per rappresentare una matrice LED 12x8.

.. code-block:: arduino

   // Utilizza un array di interi a 32 bit per memorizzare la matrice LED.
   unsigned long frame[] = {
     0x3184a444, // Stato dei primi 32 LED
     0x42081100, // Stato dei successivi 32 LED
     0xa0040000  // Stato degli ultimi 32 LED
   };

Per visualizzare meglio gli stati LED, questi valori possono essere convertiti in forma binaria, dove ogni bit rappresenta sequenzialmente lo stato di ogni LED da sinistra a destra e dall'alto in basso. Un 0 indica spento e un 1 acceso.

.. code-block:: arduino

   0x3184a444 -> 110001100001001010010001000100
   0x42081100 -> 1000010000010000001000100000000
   0xa0040000 -> 10100000000001000000000000000000

Mostrare il modello sulla matrice LED
-----------------------------------------

Una volta pronto il tuo modello, il passo successivo è trasmettere questi dati alla matrice LED 12x8. Questo di solito comporta l'invocazione delle funzioni della libreria e il passaggio dell'array o delle variabili contenenti gli stati LED a queste funzioni.

1. Utilizzo di un array bidimensionale

   Per visualizzare il modello memorizzato in un array 2D, puoi utilizzare il seguente codice:
   
   .. code-block:: arduino
   
      #include <Arduino_LED_Matrix.h>
   
      ArduinoLEDMatrix matrix;
   
      // Array 2D predefinito
      byte frame[8][12] = {
           { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
           { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
           { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
           { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
           { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
      };
   
      void setup() {
        // Inizializza la matrice LED
        matrix.begin();
      }
   
      void loop() {
        // Mostra il modello sulla matrice LED
        matrix.renderBitmap(frame, 8, 12);
        delay(1000);
      }
   
   In questo codice, usiamo la funzione ``matrix.renderBitmap(frame, 8, 12);`` per visualizzare la matrice LED. Qui, 8 e 12 rappresentano rispettivamente le righe e le colonne della matrice LED.

2. Utilizzo di un array di interi a 32 bit
   
   Per visualizzare il modello memorizzato in un array di ``unsigned long``, usa il seguente codice:
   
   .. code-block:: arduino
   
      #include "Arduino_LED_Matrix.h"
      
      ArduinoLEDMatrix matrix;
      
      void setup() {
        matrix.begin();
      }
      
      const uint32_t heart[] = {
          0x3184a444,
          0x44042081,
          0x100a0040
      };
        
      void loop(){
        matrix.loadFrame(heart);
        delay(500);
      }
   
   In questo caso, è necessario utilizzare la funzione ``matrix.loadFrame(heart)`` per visualizzare il modello sulla matrice LED.


Editor di matrice LED Arduino
-----------------------------------------

Consiglio di utilizzare un array ``unsigned long`` per memorizzare lo stato della matrice LED, poiché risparmia memoria sull'Arduino. Anche se questo metodo potrebbe non essere molto intuitivo, puoi usare il |link_led_matrix_editor| come aiuto, che ti aiuta a generare un array ``unsigned long``.

Con il |link_led_matrix_editor| e la libreria ``Arduino_LED_Matrix``, puoi comodamente creare icone o animazioni e visualizzarle sulla scheda UNO R4 WiFi. Tutto quello che devi fare è disegnare, scaricare il file ``.h`` e chiamare la funzione ``matrix.play()`` nel tuo sketch per costruire facilmente il tuo prossimo progetto.



#. Apri l'Editor di Matrice LED

   .. image:: img/04_led_matrix_editor_1.png
     :width: 80%

#. Disegna il tuo modello nella tela centrale

   .. image:: img/04_led_matrix_editor_2.png
     :width: 80%

#. Imposta l'intervallo del frame in millisecondi

   .. image:: img/04_led_matrix_editor_3.png
     :width: 80%

#. Puoi creare un nuovo frame vuoto o copiare e creare un nuovo frame dal frame corrente.

   .. image:: img/04_led_matrix_editor_4.png
     :width: 80%

#. Esporta il file header ``.h``

   .. image:: img/04_led_matrix_editor_5.png
     :width: 80%

   .. image:: img/04_led_matrix_editor_6.png

   Dopo aver cliccato OK, riceverai un file chiamato ``animation.h``.


Visualizzazione delle Animazioni
-----------------------------------------

Nei passaggi precedenti, abbiamo ottenuto un file ``.h`` che memorizza una serie di fotogrammi insieme alle loro durate. Ora procediamo a visualizzarli sulla matrice LED.

#. Prima di tutto, crea uno sketch. Puoi aprire il file ``04-led_matrix.ino`` situato nel percorso ``elite-explorer-kit-main\r4_new_feature\04-led_matrix``, oppure copiare questo codice nell'**Arduino IDE**.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/f3712371-7c3d-4a4b-bd98-f74fe43269ed/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Se stai usando il codice dal percorso ``elite-explorer-kit-main\r4_new_feature\04-led_matrix``, troverai una scheda chiamata ``animation.h`` nell'Arduino IDE. Aprila e sostituisci il codice esistente con il file .h ottenuto dal sito web.

   .. image:: img/04_animation_h_file.png
     :width: 80%

#. Se hai creato il tuo sketch, devi copiare il file ``.h`` ottenuto dalla pagina web nella stessa directory dello sketch.

#. Dopo aver configurato il codice desiderato nell'Arduino IDE e averlo caricato sul tuo Arduino UNO R4 WiFi, la tua matrice LED dovrebbe ora visualizzare il modello che hai definito.

   .. raw:: html
   
      <video loop autoplay muted style = "max-width:100%">
         <source src="../_static/videos/new_feature_projects/led_matrix.mp4"  type="video/mp4">
         Il tuo browser non supporta il tag video.
      </video>

   Congratulazioni! Hai programmato con successo la matrice LED 12x8 del tuo Arduino UNO R4 WiFi!


**Riferimenti**

- |link_r4_led|

**Altri Progetti**

* :ref:`fun_snake` (Progetto Divertente)


