.. note::

    Hallo, willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Community auf Facebook! Tauchen Sie tiefer in Raspberry Pi, Arduino und ESP32 mit gleichgesinnten Enthusiasten ein.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie nach dem Kauf auftretende Probleme und technische Herausforderungen mit Hilfe unserer Community und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Tutorials aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Sonderrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Verlosungen**: Nehmen Sie an Verlosungen und Feiertagsaktionen teil.

    👉 Bereit, mit uns zu entdecken und zu gestalten? Klicken Sie auf [|link_sf_facebook|] und treten Sie noch heute bei!

LEKTION 19: Farbmischung mit einer RGB-LED
===========================================

Diese Lektion zeigt, wie Sie mit dem Arduino ein benutzergesteuertes RGB-LED-System erstellen können, bei dem der Benutzer über den seriellen Monitor verschiedene Farben auswählen kann. Hier ist eine kurze Übersicht darüber, was Sie lernen werden:

1. **Überprüfung der vorherigen Hausaufgabe**: Rückblick auf die Aufgabe aus Lektion 18, bei der es darum ging, eine RGB-LED zu steuern, um verschiedene Farben durch Mischen von roten, grünen und blauen Lichtern zu erzeugen.
2. **Einrichten der Schaltung**: Detaillierte Anweisungen zum korrekten Anschließen einer RGB-LED und ihrer Strombegrenzungswiderstände an den Arduino. Jeder Farbkanal (rot, grün, blau) ist mit einem digitalen Pin (Pins 9, 10 und 11) verbunden, und der gemeinsame Kathodenanschluss (langes Bein) ist mit Masse verbunden.
3. **Code schreiben**: Schritt-für-Schritt-Anleitung zum Schreiben des Codes, um:
   - Die Pins für jeden Farbkanal der RGB-LED zu definieren.
   - Den seriellen Monitor für Benutzereingaben einzurichten.
   - Analog Write-Befehle zu verwenden, um die Helligkeit jedes Farbkanals anzupassen und verschiedene Farben zu mischen.
   - Benutzereingaben in Kleinbuchstaben umzuwandeln, um verschiedene Fälle zu behandeln.
   - Verschiedene Benutzereingaben zu verarbeiten, um spezifische Farben (rot, grün, blau, cyan, magenta, gelb, orange, weiß) durch Mischen der RGB-Werte entsprechend zu erzeugen.
4. **Debugging-Tipps**: Hinweise zur Fehlerbehebung bei häufigen Problemen wie:
   - Sicherstellung der richtigen Groß- und Kleinschreibung und Syntax im Code.
   - Überprüfung auf fehlende Semikolons und falsche geschweifte Klammern.
   - Anpassung der RGB-Werte, um die korrekte Farbausgabe durch Feinabstimmung der Helligkeitsstufen zu erzielen.
5. **Praktische Anwendungen**: Beispiele für das Mischen von Farben mit RGB-Werten, um eine Vielzahl von Farben zu erzeugen.
6. **Hausaufgabe**: Lassen Sie die RGB-LED in einer Sequenz aus rot, grün, blau blinken, warten Sie eine Sekunde und wiederholen Sie diese Sequenz 25 Mal. Stellen Sie sicher, dass das Programm nach 25 Zyklen stoppt. Erstellen Sie ein kurzes Video der Lösung, veröffentlichen Sie es auf YouTube und verlinken Sie auf die Lektion zur Überprüfung.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/YniHyGypG9w?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

