.. note::
    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue abilità.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci dei nuovi prodotti e anteprime esclusive.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _new_adc:

Convertitore Analogico-Digitale (ADC) (fino a 14 bit)
==============================================================

Nei progetti elettronici contemporanei, leggere e elaborare con precisione i segnali analogici è essenziale. I convertitori analogico-digitali (ADC) trasformano i segnali analogici in segnali digitali per la gestione da parte del microcontrollore. L'Arduino Uno R4 ha visto notevoli progressi in questo ambito, grazie al suo processore più potente. Mentre la generazione precedente, l'Arduino Uno R3, aveva una risoluzione massima di 10 bit, la risoluzione ADC dell'Arduino Uno R4 è ora di 14 bit. Questo miglioramento consente di ottenere valori più precisi dai segnali analogici, migliorando la raffinatezza e l'accuratezza della raccolta e dell'elaborazione dei dati.

Impostare la risoluzione dell'ADC
-----------------------------------------

La risoluzione standard sulla scheda Arduino è impostata a 10 bit (0-1023). L'UNO R4 WiFi supporta una risoluzione fino a 14 bit (0-16383), fornendo valori più precisi dai segnali analogici. Per aggiornare la risoluzione, è sufficiente utilizzare il comando ``analogReadResolution()``.

.. code-block:: arduino

   void setup() {
     // apri una connessione seriale
     Serial.begin(9600);
   }
   
   void loop() {
     // legge l'ingresso su A0 alla risoluzione predefinita (10 bit)
     // e invia il dato sulla connessione seriale
     analogReadResolution(10);
     Serial.print("ADC 10-bit (default) : ");
     Serial.print(analogRead(A0));
   
     // cambia la risoluzione a 12 bit e leggi A0
     analogReadResolution(12);
     Serial.print(", 12-bit : ");
     Serial.print(analogRead(A0));
   
     // cambia la risoluzione a 14 bit e leggi A0
     analogReadResolution(14);
     Serial.print(", 14-bit : ");
     Serial.print(analogRead(A0));
   
     // cambia la risoluzione a 8 bit e leggi A0
     analogReadResolution(8);
     Serial.print(", 8-bit : ");
     Serial.println(analogRead(A0));
   
     // un piccolo ritardo per non sovraccaricare il monitor seriale
     delay(100);
   }


Note e Avvertenze
---------------------

Quando imposti la risoluzione dell'ADC, considera i seguenti punti:

1. **Limiti delle Capacità Hardware**: Se imposti il valore di ``analogReadResolution()`` superiore alle capacità della scheda, l'Arduino riporterà solo la sua risoluzione massima, riempiendo i bit extra con zeri. Ad esempio, utilizzando l'Uno R4 con ``analogReadResolution(16)`` otterrai un numero approssimato a 16 bit, con i primi 14 bit contenenti la lettura reale dell'ADC e gli ultimi 2 bit riempiti con zeri.

2. **Impostazioni di Risoluzione Inferiori**: Se imposti il valore di ``analogReadResolution()`` inferiore alle capacità della scheda, i bit meno significativi extra letti dall'ADC verranno scartati. Questo ti permette di lavorare con un intervallo semplificato se la tua applicazione non richiede la risoluzione completa.

Comprendere queste considerazioni ti aiuterà a utilizzare efficacemente le capacità dell'ADC dell'Arduino Uno R4, garantendo prestazioni e accuratezza ottimali per la tua specifica applicazione.

**Riferimenti**
- |link_analogReadResolution|
- |link_r4_minima_adc|
- |link_r4_wifi_adc|







