.. note::

    Hallo, willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Community auf Facebook! Tauche tiefer in Raspberry Pi, Arduino und ESP32 mit gleichgesinnten Enthusiasten ein.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie nach dem Kauf auftretende Probleme und technische Herausforderungen mit Hilfe unserer Community und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Tutorials aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Sonderrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Verlosungen**: Nehmen Sie an Verlosungen und Feiertagsaktionen teil.

    👉 Bereit, mit uns zu entdecken und zu gestalten? Klicken Sie auf [|link_sf_facebook|] und treten Sie noch heute bei!

LEKTION 18: Steuerung einer RGB-LED mit einem Arduino
=======================================================

Diese Lektion zeigt, wie man eine RGB-LED mit einem Arduino verwendet, um durch die Kombination von rotem, grünem und blauem Licht verschiedene Farben zu erzeugen, basierend auf früheren Lektionen über die Steuerung von LEDs und die Nutzung der PWM-Fähigkeiten des Arduino. Hier ist eine kurze Übersicht darüber, was Sie lernen werden:

1. **Überprüfung der vorherigen Hausaufgabe**: Rückblick auf die Aufgabe aus Lektion 17, bei der eine Schaltung mit drei LEDs (rot, gelb und grün) erstellt und basierend auf Benutzereingaben gesteuert wurde.
2. **Einrichten der Schaltung**: Detaillierte Anweisungen zum korrekten Anschließen einer RGB-LED an den Arduino. Die RGB-LED hat vier Beine: ein gemeinsamer Ground und drei für die roten, grünen und blauen LEDs. Jeder Farbkanal benötigt einen separaten Strombegrenzungswiderstand, um Übersprechen zu verhindern und einen ordnungsgemäßen Betrieb zu gewährleisten.
3. **Code schreiben**: Schritt-für-Schritt-Anleitung zum Schreiben des Codes, um:
   - Die Pins für jeden Farbkanal der RGB-LED zu definieren.
   - Den seriellen Monitor für Benutzereingaben einzurichten.
   - Digitale Schreibbefehle zu verwenden, um jeden Farbkanal ein- und auszuschalten.
   - Benutzereingaben in Kleinbuchstaben umzuwandeln, um verschiedene Fälle zu behandeln.
4. **Praktische Anwendungen**: Beispiele zur Steuerung der RGB-LED, um verschiedene Farben zu erzeugen, indem verschiedene Kombinationen der roten, grünen und blauen LEDs eingeschaltet werden.
5. **Hausaufgabe**: Das Projekt erweitern, indem der Benutzer nach spezifischen Farben gefragt wird, einschließlich rot, grün, blau, cyan, magenta, gelb, orange und weiß.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/ASHBCGGeEPk?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

