.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _new_rtc:

Echtzeituhr
========================================

Die RTC (Real-Time Clock, Echtzeituhr) ist in den Mikrocontroller des UNO R4 WiFi (RA4M1) integriert. Die RTC ist ein autonomes Uhrenmodul, das auch dann funktioniert, wenn die Hauptstromversorgung unterbrochen ist, dank einer Backup-Stromquelle wie einer Batterie. Dies macht die RTC äußerst vielseitig einsetzbar, beispielsweise für die Planung zeitgesteuerter Aufgaben in Hausautomatisierungssystemen oder zur Zeitstempelung einzelner Datenpunkte in Datenlogger-Anwendungen.

.. note::
    Der UNO R4 WiFi verfügt über einen VRTC-Pin, der den Betrieb der integrierten RTC auch bei Stromausfall des Boards aufrechterhält. Um diese Funktion zu nutzen, sollte eine Spannung zwischen 1,6 und 3,6 V an den VRTC-Pin angelegt werden.



Geplante Wiederkehrende Aufgaben
++++++++++++++++++++++++++++++++++++++++++++

In bestimmten Anwendungsfällen müssen Sie möglicherweise spezifische Aufgaben in regelmäßigen Abständen ausführen. Um periodische Unterbrechungen einzurichten, müssen Sie zunächst eine periodische Rückruffunktion initialisieren. Unten finden Sie ein Arduino-Codebeispiel, das eine periodische Unterbrechung verwendet, um eine LED alle 2 Sekunden blinken zu lassen.


**Code Hochladen**

Öffnen Sie die Datei ``03-rtc.ino``, die sich im Verzeichnis ``elite-explorer-kit-main\r4_new_feature\03-rtc`` befindet, oder fügen Sie den folgenden Code in Ihre Arduino IDE ein.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/48777cc6-f8a5-4646-b221-36c883ed5a62/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Code-Erklärung**

1. Initialisierung von Komponenten und Bibliotheken

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
   
   - ``#include "RTC.h"``: Bindet die RTC-Bibliothek ein.
   - ``volatile bool irqFlag = false;``: Deklariert eine volatile Boolesche Flagge. ``volatile`` stellt sicher, dass die Variable durch einen Interrupt sicher zugegriffen oder geändert werden kann. Weitere Details zu ``volatile`` finden Sie in der `Arduino-Volatile-Dokumentation <https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/>`_.
   - ``bool ledState = false;``: Deklariert eine Boolesche Variable, um den Zustand der LED zu verfolgen.
   - ``const int led = LED_BUILTIN;``: Deklariert eine Konstante für den eingebauten LED-Pin.
   - ``pinMode(led, OUTPUT);``: Stellt den LED-Pin als Ausgang ein.
   - ``Serial.begin(9600);``: Initialisiert die serielle Kommunikation mit 9600 Baud.
   - ``RTC.begin();``: Initialisiert die RTC.

   .. raw:: html
    
        <br/>

2. Einrichtung der Echtzeituhr

   .. code-block:: arduino
   
     RTCTime mytime(30, Month::JUNE, 2023, 13, 37, 00, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
     RTC.setTime(mytime);
   
   - ``RTCTime mytime(...);``: Erstellt ein ``RTCTime``-Objekt und initialisiert es mit einem spezifischen Datum und Uhrzeit.
   - ``RTC.setTime(mytime);``: Stellt die RTC mit der initialisierten Zeit ein.
   
   Periodische Rückruffunktion Einrichten und Überprüfen
   
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
   
   - ``RTC.setPeriodicCallback(...);``: Legt eine periodische Rückruffunktion fest, die alle 2 Sekunden ausgelöst wird. Der Zeitraum kann mit den folgenden Enumerationen angegeben werden:

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

   - ``void loop() {...}``: Überprüft, ob der Rückruf ausgelöst wurde. Wenn ja, ändert den Zustand der LED.
   - ``void periodicCallback() {...}``: Die Rückruffunktion setzt ``irqFlag = true``, wenn sie ausgelöst wird.


**Referenz**

- |link_r4_rtc|
