.. note::

    Hallo, willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Community auf Facebook! Tauche tiefer in Raspberry Pi, Arduino und ESP32 mit gleichgesinnten Enthusiasten ein.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie nach dem Kauf auftretende Probleme und technische Herausforderungen mit Hilfe unserer Community und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Tutorials aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Sonderrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Verlosungen**: Nehmen Sie an Verlosungen und Feiertagsaktionen teil.

    👉 Bereit, mit uns zu entdecken und zu gestalten? Klicken Sie auf [|link_sf_facebook|] und treten Sie noch heute bei!

LEKTION 17: Steuerung mehrerer LEDs über den seriellen Monitor
================================================================

Diese Lektion zeigt, wie man mit dem Arduino ein benutzergesteuertes LED-System erstellt, bei dem der Benutzer verschiedene LEDs basierend auf Eingaben über den seriellen Monitor ein- und ausschalten kann. Hier ist eine kurze Übersicht darüber, was Sie lernen werden:

1. **Überprüfung der vorherigen Hausaufgabe**: Rückblick auf die Aufgabe aus Lektion 16, bei der eine Schaltung mit drei LEDs (rot, gelb und grün) erstellt und basierend auf Benutzereingaben gesteuert wurde.
2. **Einrichten der Schaltung**: Detaillierte Anweisungen zum korrekten Anschließen der drei LEDs und ihrer Strombegrenzungswiderstände an den Arduino. Das lange Bein (Anode) jeder LED wird mit einem digitalen Pin verbunden, und das kurze Bein (Kathode) wird über einen Widerstand mit der Masse verbunden.
3. **Code schreiben**: Schritt-für-Schritt-Anleitung zum Schreiben des Codes, um:Die Pins für jede LED zu definieren,Den seriellen Monitor für Benutzereingaben einzurichten,If-Anweisungen zu verwenden, um die angegebene LED einzuschalten und sicherzustellen, dass alle anderen LEDs ausgeschaltet sind,Benutzereingaben in Kleinbuchstaben umzuwandeln, um verschiedene Fälle zu behandeln.
4. **Debugging-Tipps**: Tipps zur Fehlerbehebung bei häufigen Problemen wie fehlenden Semikolons, falschen geschweiften Klammern und Sicherstellung, dass alle LEDs korrekt ausgeschaltet sind, wenn eine neue LED eingeschaltet wird.
5. **Praktische Anwendungen**: Beispiele für die Verwendung von If-Anweisungen zur Verarbeitung von Benutzereingaben und Steuerung mehrerer Ausgänge (LEDs) basierend auf diesen Eingaben.
6. **Hausaufgabe**: Das Projekt erweitern, indem der Benutzer sowohl nach der LED-Farbe als auch nach der gewünschten Helligkeit gefragt wird.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/Ai7uqYHt_Yc?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

