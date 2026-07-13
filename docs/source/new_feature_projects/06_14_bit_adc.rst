.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _new_adc:

Analog-Digital-Wandler (ADC) (bis zu 14 Bit)
=============================================

In zeitgenössischen Elektronikprojekten ist das genaue Lesen und Verarbeiten analoger Signale unerlässlich. Analog-Digital-Wandler (ADCs) wandeln analoge Signale in digitale um, sodass Mikrocontroller sie verarbeiten können. Der Arduino Uno R4 hat in diesem Bereich dank seines leistungsfähigeren Prozessors erhebliche Fortschritte gemacht. Während die vorherige Generation, der Arduino Uno R3, eine maximale Auflösung von 10 Bit hatte, beträgt die ADC-Auflösung des Arduino Uno R4 nun 14 Bit. Diese Verbesserung ermöglicht präzisere Werte aus analogen Signalen, was die Verfeinerung und Genauigkeit der Datenerfassung und -verarbeitung erhöht.

ADC-Auflösung einstellen
-------------------------

Die Standardauflösung auf der Arduino-Platine ist auf 10 Bit (0-1023) eingestellt. Der UNO R4 WiFi unterstützt bis zu 14 Bit (0-16383) Auflösung und liefert somit präzisere Werte aus analogen Signalen. Um die Auflösung zu aktualisieren, müssen Sie nur den Befehl ``analogReadResolution()`` verwenden.

.. code-block:: arduino

   void setup() {
     // Serielle Verbindung öffnen
     Serial.begin(9600);
   }
   
   void loop() {
     // Eingang an A0 mit der Standardauflösung (10 Bit) lesen
     // und über die serielle Verbindung ausgeben
     analogReadResolution(10);
     Serial.print("ADC 10-Bit (Standard) : ");
     Serial.print(analogRead(A0));
   
     // Auflösung auf 12 Bit ändern und A0 lesen
     analogReadResolution(12);
     Serial.print(", 12-Bit : ");
     Serial.print(analogRead(A0));
   
     // Auflösung auf 14 Bit ändern und A0 lesen
     analogReadResolution(14);
     Serial.print(", 14-Bit : ");
     Serial.print(analogRead(A0));
   
     // Auflösung auf 8 Bit ändern und A0 lesen
     analogReadResolution(8);
     Serial.print(", 8-Bit : ");
     Serial.println(analogRead(A0));
   
     // Eine kleine Verzögerung, um den Serial Monitor nicht zu überlasten
     delay(100);
   }

Hinweise und Warnungen
-----------------------

Beim Einstellen der ADC-Auflösung sind folgende Punkte zu beachten:

1. **Grenzen der Hardware-Fähigkeiten**: Wenn Sie den Wert von ``analogReadResolution()`` höher einstellen als die Fähigkeiten der Platine, meldet der Arduino nur die höchstmögliche Auflösung und füllt die zusätzlichen Bits mit Nullen auf. Beispielsweise ergibt die Verwendung des Uno R4 mit ``analogReadResolution(16)`` eine angenäherte 16-Bit-Zahl, bei der die ersten 14 Bits den tatsächlichen ADC-Wert enthalten und die letzten 2 Bits mit Nullen aufgefüllt sind.

2. **Niedrigere Auflösungseinstellungen**: Wenn Sie den Wert von ``analogReadResolution()`` niedriger einstellen als die Fähigkeiten der Platine, werden die zusätzlichen niederwertigen Bits des ADC verworfen. Dies ermöglicht Ihnen die Arbeit mit einem vereinfachten Bereich, falls Ihre Anwendung keine volle Auflösung erfordert.

Das Verständnis dieser Überlegungen wird Ihnen helfen, die ADC-Fähigkeiten des Arduino Uno R4 effektiv zu nutzen und eine optimale Leistung und Genauigkeit für Ihre spezifische Anwendung sicherzustellen.


**Referenz**

- |link_analogReadResolution|
- |link_r4_minima_adc|
- |link_r4_wifi_adc|
