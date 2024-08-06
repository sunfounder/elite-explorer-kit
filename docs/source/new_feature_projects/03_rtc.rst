.. note::

    Ciao, benvenuto nella Community degli Appassionati di Raspberry Pi, Arduino e ESP32 di SunFounder su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del team.
    - **Apprendi e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima alle nuove presentazioni di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri ultimi prodotti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni speciali.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _new_rtc:

Orologio in Tempo Reale
========================================

L'RTC (Real-Time Clock) è integrato nel microcontrollore (RA4M1) dell'UNO R4 WiFi. L'RTC è un modulo di orologio autonomo in grado di funzionare anche quando l'alimentazione principale è scollegata, grazie a una fonte di alimentazione di backup come una batteria. Questo rende l'RTC estremamente versatile per varie applicazioni come la pianificazione di compiti temporizzati nei sistemi di automazione domestica o la marcatura temporale dei singoli punti dati nelle applicazioni di registrazione dati.

.. note::
    L'UNO R4 WiFi dispone di un pin VRTC che mantiene il funzionamento dell'RTC integrato anche quando la scheda perde alimentazione. Per utilizzare questa funzione, applica una tensione compresa tra 1,6 e 3,6 V al pin VRTC.

Compiti Ripetitivi Pianificati
++++++++++++++++++++++++++++++++++++++++++++

In determinati casi d'uso, potresti aver bisogno di eseguire specifici compiti a intervalli regolari. Per stabilire interruzioni periodiche, è necessario prima inizializzare una funzione di callback periodica. Di seguito è riportato un esempio di codice Arduino che utilizza un'interruzione periodica per lampeggiare un LED ogni 2 secondi.


**Carica il Codice**

Apri il file ``03-rtc.ino`` situato in ``elite-explorer-kit-main\r4_new_feature\03-rtc``, oppure incolla il seguente codice nel tuo Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/48777cc6-f8a5-4646-b221-36c883ed5a62/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Spiegazione del Codice**

1. Inizializzazione dei Componenti e delle Librerie

   .. code-block:: arduino
   
     #include "RTC.h"
     volatile bool irqFlag = false;
     bool ledState = false;
     const int led = LED_BUILTIN;
   
     void setup() {
       pinMode(led, OUTPUT);
       Serial.begin(9600);
       RTC.begin();
     }
   
   - ``#include "RTC.h"``: Includi la libreria RTC.
   - ``volatile bool irqFlag = false;``: Dichiarazione di un flag booleano volatile. ``volatile`` assicura che la variabile possa essere accessa o modificata in sicurezza da un'interruzione. Per ulteriori dettagli su ``volatile``, consulta la `documentazione volatile di Arduino <https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/>`_.
   - ``bool ledState = false;``: Dichiarazione di un booleano per tenere traccia dello stato del LED.
   - ``const int led = LED_BUILTIN;``: Dichiarazione di una costante per il pin LED integrato.
   - ``pinMode(led, OUTPUT);``: Imposta il pin del LED come output.
   - ``Serial.begin(9600);``: Inizializza la comunicazione seriale a 9600 baud rate.
   - ``RTC.begin();``: Inizializza l'RTC.

   .. raw:: html
    
        <br/>

2. Configurazione dell'Orologio in Tempo Reale

   .. code-block:: arduino
   
     RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
     RTC.setTime(mytime);
   
   - ``RTCTime mytime(...);``: Crea un oggetto ``RTCTime`` e lo inizializza con una data e ora specifiche.
   - ``RTC.setTime(mytime);``: Imposta l'RTC con l'ora inizializzata.
   
   Configurazione e Controllo della Callback Periodica
   
   .. code-block:: arduino
   
     if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_2_SEC)) {
       Serial.println("ERROR: periodic callback not set");
     }
   
     void loop() {
       if (irqFlag) {
         Serial.println("Timed CallBack");
         ledState = !ledState;
         digitalWrite(led, ledState);
         irqFlag = false;
       }
     }
   
     void periodicCallback() {
       irqFlag = true;
     }
   
   - ``RTC.setPeriodicCallback(...);``: Imposta una callback periodica che viene triggerata ogni 2 secondi. Il periodo può essere specificato utilizzando le seguenti enumerazioni:

      - ``ONCE_EVERY_2_SEC``
      - ``ONCE_EVERY_1_SEC``
      - ``N2_TIMES_EVERY_SEC``
      - ``N4_TIMES_EVERY_SEC``
      - ``N8_TIMES_EVERY_SEC``
      - ``N16_TIMES_EVERY_SEC``
      - ``N32_TIMES_EVERY_SEC``
      - ``N64_TIMES_EVERY_SEC``
      - ``N128_TIMES_EVERY_SEC``
      - ``N256_TIMES_EVERY_SEC``

   - ``void loop() {...}``: Verifica se la callback è stata triggerata. Se sì, alterna lo stato del LED.
   - ``void periodicCallback() {...}``: La funzione di callback imposta ``irqFlag = true`` quando è triggerata.


**Riferimenti**

- |link_r4_rtc|
