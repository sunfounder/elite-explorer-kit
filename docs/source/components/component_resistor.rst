.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_resistor:

Widerstand
============

.. image:: img/resistor.png
    :width: 300

Ein Widerstand ist ein elektronisches Bauelement, das den Stromfluss in einem Zweig begrenzen kann.
Ein Festwiderstand ist eine Art Widerstand, dessen Widerstandswert nicht verändert werden kann, während der Widerstandswert eines Potentiometers oder eines variablen Widerstands angepasst werden kann.

Es gibt zwei allgemein verwendete Schaltungssymbole für Widerstände. Normalerweise ist der Widerstandswert darauf markiert. Wenn Sie also diese Symbole in einer Schaltung sehen, steht dies für einen Widerstand.

.. image:: img/resistor_symbol.png
    :width: 400

**Ω** ist die Einheit des Widerstands, und größere Einheiten umfassen KΩ, MΩ usw.
Ihre Beziehung kann wie folgt dargestellt werden: 1 MΩ = 1000 KΩ, 1 KΩ = 1000 Ω. Normalerweise ist der Wert des Widerstands darauf markiert.

Bei der Verwendung eines Widerstands müssen wir zuerst seinen Widerstandswert kennen. Hier sind zwei Methoden: Sie können die farbigen Bänder auf dem Widerstand beobachten oder ein Multimeter verwenden, um den Widerstand zu messen. Es wird empfohlen, die erste Methode zu verwenden, da sie bequemer und schneller ist.

.. image:: img/resistance_card.jpg

Wie auf der Karte gezeigt, steht jede Farbe für eine Zahl.

.. list-table::

   * - Schwarz
     - Braun
     - Rot
     - Orange
     - Gelb
     - Grün
     - Blau
     - Violett
     - Grau
     - Weiß
     - Gold
     - Silber
   * - 0
     - 1
     - 2
     - 3
     - 4
     - 5
     - 6
     - 7
     - 8
     - 9
     - 0,1
     - 0,01

Häufig verwendet werden 4- und 5-Band-Widerstände, bei denen es 4 bzw. 5 farbige Bänder gibt.

Normalerweise, wenn Sie einen Widerstand erhalten, kann es schwierig sein zu entscheiden, an welchem Ende Sie mit dem Lesen der Farbe beginnen sollen.
Der Tipp ist, dass der Abstand zwischen dem 4. und 5. Band vergleichsweise größer sein wird.

Daher können Sie den Abstand zwischen den beiden farbigen Bändern an einem Ende des Widerstands beobachten;
wenn dieser größer ist als jeder andere Bandabstand, dann können Sie von der gegenüberliegenden Seite lesen.

Lassen Sie uns sehen, wie man den Widerstandswert eines 5-Band-Widerstands wie unten gezeigt liest.

.. image:: img/220ohm.jpg
    :width: 500

Also sollte bei diesem Widerstand der Widerstandswert von links nach rechts gelesen werden.
Der Wert sollte in diesem Format sein: 1. Band 2. Band 3. Band x 10^Multiplikator (Ω) und der zulässige Fehler ist ±Toleranz%. 
So ist der Widerstandswert dieses Widerstands 2 (rot) 2 (rot) 0 (schwarz) x 10^0 (schwarz) Ω = 220 Ω,
und der zulässige Fehler ist ± 1% (braun).

.. list-table::Häufige Widerstandsfarbbänder
    :header-rows: 1

    * - Widerstand 
      - Farbband  
    * - 10Ω   
      - braun schwarz schwarz silber braun
    * - 100Ω   
      - braun schwarz schwarz schwarz braun
    * - 220Ω 
      - rot rot schwarz schwarz braun
    * - 330Ω 
      - orange orange schwarz schwarz braun
    * - 1kΩ 
      - braun schwarz schwarz braun braun
    * - 2kΩ 
      - rot schwarz schwarz braun braun
    * - 5.1kΩ 
      - grün braun schwarz braun braun
    * - 10kΩ 
      - braun schwarz schwarz rot braun 
    * - 100kΩ 
      - braun schwarz schwarz orange braun 
    * - 1MΩ 
      - braun schwarz schwarz grün braun 

Sie können mehr über Widerstände auf Wiki erfahren: `Widerstand – Wikipedia <https://en.wikipedia.org/wiki/Resistor>`_.

