.. note::

    Hallo, willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Community auf Facebook! Tauchen Sie tiefer in Raspberry Pi, Arduino und ESP32 mit gleichgesinnten Enthusiasten ein.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie nach dem Kauf auftretende Probleme und technische Herausforderungen mit Hilfe unserer Community und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Tutorials aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Sonderrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Verlosungen**: Nehmen Sie an Verlosungen und Feiertagsaktionen teil.

    👉 Bereit, mit uns zu entdecken und zu gestalten? Klicken Sie auf [|link_sf_facebook|] und treten Sie noch heute bei!

LEKTION 21: Verständnis von While-Schleifen
===============================================

Diese Lektion zeigt, wie man While-Schleifen in Arduino verwendet, um ein benutzergesteuertes RGB-LED-Blinksystem basierend auf Eingaben über den seriellen Monitor zu erstellen. Hier ist eine kurze Übersicht darüber, was Sie lernen werden:

1. **Überprüfung der vorherigen Hausaufgabe**: Rückblick auf die Aufgabe aus Lektion 20, bei der es darum ging, eine RGB-LED in einer Rot-Grün-Blau-Sequenz eine vom Benutzer angegebene Anzahl von Malen zu blinken, wobei eine While-Schleife anstelle einer For-Schleife verwendet wurde.
2. **Einrichten der Schaltung**: Detaillierte Anweisungen zum korrekten Anschließen einer RGB-LED und ihrer Strombegrenzungswiderstände an den Arduino. Jeder Farbkanal (rot, grün, blau) ist mit einem PWM-Digital-Pin (Pins 9, 10 und 11) verbunden, und der gemeinsame Kathodenanschluss (langes Bein) ist mit Masse verbunden.
3. **Code schreiben**: Schritt-für-Schritt-Anleitung zum Schreiben des Codes, um:
   - Die Pins für jeden Farbkanal der RGB-LED zu definieren.
   - Den seriellen Monitor für Benutzereingaben einzurichten.
   - Digital-Write-Befehle zu verwenden, um den Ein/Aus-Zustand jedes Farbkanals zu steuern.
   - Eine While-Schleife zu implementieren, um die Anzahl der Blinkzyklen basierend auf den Benutzereingaben zu steuern.
   - Sicherzustellen, dass das Programm nach der angegebenen Anzahl von Blinks stoppt.
4. **Debugging-Tipps**: Hinweise zur Fehlerbehebung bei häufigen Problemen wie:
   - Korrektur von Syntaxfehlern im Code.
   - Sicherstellung, dass das Programm die richtige Anzahl von Zyklen durchläuft.
   - Korrekte Handhabung der Benutzereingaben und Beendigung des Programms nach den angegebenen Zyklen.
   - Initialisierung und Inkrementierung von Schleifenzählern.
5. **Praktische Anwendungen**: Beispiele für die Verwendung von While-Schleifen, um eine Sequenz von Aktionen eine bestimmte Anzahl von Malen zu wiederholen. Die Lektion betont die Bedeutung der Benutzereingaben zur Steuerung des Programmverhaltens und stellt sicher, dass der Schleifenzähler korrekt verwaltet wird.
6. **Testen und Debuggen**: Betonung der gründlichen Überprüfung des Codes unter verschiedenen Bedingungen, um die Zuverlässigkeit sicherzustellen.
7. **Hausaufgabe**: Wiederholung der Blinksequenz eine vom Benutzer angegebene Anzahl von Malen ohne Verwendung einer For-Schleife. Sicherstellung, dass das Programm nach der angegebenen Anzahl von Blinks stoppt.

**Video**

.. raw:: html

    <iframe width="700" height="500" src="https://www.youtube.com/embed/Cw_i7l_RFVE?si=o9Q1tTC1X1B9teef" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

