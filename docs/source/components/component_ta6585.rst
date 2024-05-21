.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_ta6586:

TA6586 - Motorsteuerungs-Chip
=================================

.. image:: img/ta6586.png

TA6586 ist ein monolithischer IC, der für das Ansteuern von bidirektionalen Gleichstrommotoren entwickelt wurde. Er verfügt über zwei Logikeingangspins zur Steuerung der Richtung, vorwärts und rückwärts.
Die Schaltung weist eine gute Störfestigkeit, einen geringen Standby-Strom und einen niedrigen Ausgangssättigungsspannungsabfall auf. Sie hat eine eingebaute Klemmdiode, um den Aufprall der Freisetzung des induktiven Laststroms umzukehren, was sie in der Anwendung beim Antrieb von Relais, Gleichstrommotoren, Schrittmotoren oder beim Schalten von Leistung sicher und zuverlässig macht.
TA6586 eignet sich für Spielzeugfahrzeuge, ferngesteuerte Flugzeugmotoren, automatische Ventilmotoren, elektromagnetische Schlossantriebe, Präzisionsinstrumente und andere Schaltungen.

**Merkmale**

* Geringer Standby-Strom: ≦2uA
* Breiter Versorgungsspannungsbereich
* Integrierte Bremsfunktion
* Thermischer Abschaltschutz
* Überstrombegrenzung und Kurzschlussschutzfunktion
* DIP8 Pb-freies Gehäuse.

**Pin-Funktion**

.. image:: img/ta6586_pin1.png
    :width: 30%

.. image:: img/ta6586_pin.png
    :width: 75%


**Eingangswahrheitstabelle**

.. image:: img/ta6586_priciple.png
    :width: 95%

**Beispiel**

* :ref:`basic_motor` (Grundprojekt)
* :ref:`basic_pump` (Grundprojekt)
* :ref:`fun_smart_fan` (Spaßprojekt)
* :ref:`fun_plant_monitor` (Spaßprojekt)
