.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_diode:

Diode
=================

Eine Diode ist eine elektronische Komponente mit zwei Elektroden. Sie ermöglicht es dem Strom, nur in eine Richtung zu fließen, was oft als "Gleichrichter"-Funktion bezeichnet wird.
Somit kann eine Diode als elektronische Version eines Rückschlagventils betrachtet werden.

Aufgrund ihrer unidirektionalen Leitfähigkeit wird die Diode in fast allen elektronischen Schaltungen einer gewissen Komplexität verwendet. Sie ist eines der ersten Halbleiterbauelemente und hat ein breites Anwendungsspektrum.

Je nach Einsatzklassifizierung kann sie in Detektor-Dioden, Gleichrichter-Dioden, Begrenzer-Dioden, Spannungsregler-Dioden usw. unterteilt werden.

Gleichrichter-Dioden und Spannungsregler-Dioden sind in diesem Kit enthalten.

**Gleichrichter-Diode**

.. image:: img/in4007_diode.png
.. image:: img/symbol_rectifier_diode.png
    :width: 200

Eine Gleichrichter-Diode ist eine Halbleiterdiode, die verwendet wird, um Wechselstrom (AC) in Gleichstrom (DC) unter Verwendung der Gleichrichterbrücken-Anwendung zu gleichrichten. Die Alternative der Gleichrichter-Diode durch die Schottky-Barriere wird hauptsächlich in der Digitaltechnik geschätzt. Diese Diode ist in der Lage, Stromwerte zu leiten, die von mA bis zu einigen kA reichen und Spannungen bis zu einigen kV.

Die Gestaltung von Gleichrichter-Dioden kann mit Siliziummaterial erfolgen und sie sind in der Lage, hohe elektrische Stromwerte zu leiten. Diese Dioden sind nicht berühmt, aber es werden noch Ge- oder Galliumarsenid-basierte Halbleiterdioden verwendet. Ge-Dioden haben eine geringere zulässige Rückwärtsspannung sowie eine geringere zulässige Sperrschichttemperatur. Die Ge-Diode hat gegenüber der Si-Diode den Vorteil eines niedrigen Schwellenspannungswerts bei Betrieb in Vorwärtsrichtung.

* |link_general_purpose_diode|


**Zener-Diode**

Eine Zener-Diode ist eine spezielle Art von Diode, die zuverlässig den Stromfluss "rückwärts" ermöglicht, wenn eine bestimmte festgelegte Rückwärtsspannung, bekannt als Zener-Spannung, erreicht wird.

Diese Diode ist ein Halbleiterbauelement, das einen sehr hohen Widerstand bis zur kritischen Rückwärtsdurchbruchspannung aufweist. An diesem kritischen Durchbruchpunkt verringert sich der Rückwärts-Widerstand auf einen sehr kleinen Wert, und der Strom steigt, während die Spannung in diesem Bereich mit niedrigem Widerstand konstant bleibt.

.. image:: img/zener_diode.png
.. image:: img/symbol-zener-diode.jpg


* |link_zener_diode|

**Beispiel**

 * :ref:`basic_relay` (Grundprojekt)

