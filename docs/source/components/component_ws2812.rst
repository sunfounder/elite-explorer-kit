.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_ws2812:

WS2812 RGB 8 LEDs Streifen
============================

.. image:: img/ws2812b.png

Der WS2812 RGB 8 LEDs Streifen besteht aus 8 RGB-LEDs. 
Nur ein Pin ist erforderlich, um alle LEDs zu steuern. Jede RGB-LED hat einen WS2812-Chip, der unabhängig gesteuert werden kann. 
Es kann eine 256-stufige Helligkeitsanzeige realisieren und eine vollständige echte Farbanzeige von 16.777.216 Farben darstellen. 
Gleichzeitig enthält der Pixel einen intelligenten digitalen Schnittstellendatenrastsignalformungsverstärkerantriebsschaltkreis, und es ist ein Signalformungsschaltkreis integriert, um effektiv sicherzustellen, dass die Farbhöhe des Pixel-Punktlichts konsistent ist.

Er ist flexibel, kann angedockt, gebogen und nach Belieben geschnitten werden, und die Rückseite ist mit Klebeband ausgestattet, das nach Belieben auf unebenen Oberflächen befestigt werden kann und in engen Räumen installiert werden kann.

**Merkmale**

* Arbeitsspannung: DC5V
* IC: Ein IC steuert eine RGB-LED
* Verbrauch: 0,3 W pro LED
* Arbeitstemperatur: -15-50
* Farbe: Vollfarb-RGB
* RGB-Typ: 5050RGB (Integrierter IC WS2812B)
* Dicke des Lichtstreifens: 2mm
* Jede LED kann individuell gesteuert werden

**WS2812B Einführung**

* |link_ws2812b_datasheet|

WS2812B ist eine intelligente Steuerungs-LED-Lichtquelle, bei der der Steuerkreis und der RGB-Chip in einem 5050-Komponentenpaket integriert sind. Es beinhaltet intern einen intelligenten digitalen Port-Datenrast- und Signalsignalaufbereitungsverstärkerantriebsschaltkreis. Ebenfalls enthalten ist ein präziser interner Oszillator und ein 12V programmierbarer Konstantstromsteuerungsteil, der effektiv sicherstellt, dass die Pixel-Punktlichtfarbhöhe konsistent ist.

Das Datenübertragungsprotokoll verwendet den einzelnen NZR-Kommunikationsmodus. Nach dem Einschalten des Pixels setzt sich der DIN-Port zurück und empfängt Daten vom Controller, das erste Pixel sammelt die ersten 24 Bit Daten und sendet sie an den internen Datenrast, die anderen Daten, die durch den internen Signalsignalaufbereitungsverstärkerkreis umgeformt wurden, werden über den DO-Port an das nächste Kaskadenpixel gesendet. Nach der Übertragung für jedes Pixel reduziert sich das Signal um 24 Bit. Pixel verwenden die Autoumformungsübertragungstechnologie, so dass die Anzahl der Pixelkaskaden nicht durch die Signalübertragung begrenzt wird, sondern nur von der Geschwindigkeit der Signalübertragung abhängt.

LED mit niedriger Ansteuerspannung, Umweltschutz und Energieeinsparung, hohe Helligkeit, große Streuwinkel, gute Konsistenz, geringe Leistung, lange Lebensdauer und andere Vorteile. Der in LED integrierte Steuerchip vereinfacht den Schaltkreis, reduziert das Volumen und erleichtert die Installation.

.. Beispiel
.. -------------------

.. :ref:`RGB LED Streifen`


**Beispiel**

* :ref:`basic_ws2812` (Grundprojekt)
* :ref:`iot_cheerlights` (IoT-Projekt)

