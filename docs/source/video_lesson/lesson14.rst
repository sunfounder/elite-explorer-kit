.. note::

    Hallo, willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Community auf Facebook! Tauche tiefer in Raspberry Pi, Arduino und ESP32 mit gleichgesinnten Enthusiasten ein.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie nach dem Kauf auftretende Probleme und technische Herausforderungen mit Hilfe unserer Community und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Tutorials aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Sonderrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Verlosungen**: Nehmen Sie an Verlosungen und Feiertagsaktionen teil.

    👉 Bereit, mit uns zu entdecken und zu gestalten? Klicken Sie auf [|link_sf_facebook|] und treten Sie noch heute bei!

LEKTION 14: Benutzereingaben über den seriellen Monitor lesen
================================================================

Diese Lektion zeigt, wie man ein benutzerinteraktives Programm mit dem Arduino erstellt, wobei der Schwerpunkt auf der Erfassung von Benutzereingaben über den seriellen Monitor und der Durchführung verschiedener Operationen basierend auf diesen Eingaben liegt. Hier ist eine kurze Übersicht darüber, was Sie lernen werden:

1. **Einführung in Benutzereingaben über den seriellen Monitor**: Eine Einführung in das Konzept des Lesens von Benutzereingaben über den seriellen Monitor des Arduino, was für interaktive Projekte unerlässlich ist.
2. **Einrichten der seriellen Kommunikation**: Detaillierte Anweisungen zum Einrichten der seriellen Kommunikation im Arduino-Code, unter Verwendung von Serial.begin(9600) zur Initialisierung des seriellen Monitors.
3. **Lesen verschiedener Datentypen**: Schritt-für-Schritt-Anleitung zum Lesen verschiedener Datentypen vom Benutzer:
    - **Integer**: Verwenden von Serial.parseInt(), um Ganzzahlwerte zu lesen.
    - **Float**: Verwenden von Serial.parseFloat(), um Gleitkommazahlen zu lesen.
    - **Strings**: Verwenden von Serial.readString(), um Zeichenfolgen zu lesen.
4. **Implementieren einer While-Schleife zum Warten auf Benutzereingaben**: Erklärung, wie eine While-Schleife implementiert wird, um auf Benutzereingaben zu warten und sicherzustellen, dass das Programm nicht fortfährt, bis der Benutzer die erforderlichen Daten eingegeben hat.
5. **Fehlerbehandlung bei seriellen Eingaben**: Tipps zur Behandlung von Fehlern im Zusammenhang mit falschen Datentypen und zur Sicherstellung, dass der serielle Monitor auf 'Keine Zeilenende' eingestellt ist, um zu verhindern, dass zusätzliche Zeichen als Eingabe gelesen werden.
6. **Praktische Anwendung und Beispielcode**: Ein Beispielprojekt, bei dem der Benutzer nach einer Zahl, einer Fließkommazahl und einer Zeichenfolge gefragt wird, um zu demonstrieren, wie diese Eingaben effektiv erfasst und verwendet werden. Der bereitgestellte Code zeigt, wie nach Eingaben gefragt, darauf gewartet und dann die Eingaben gelesen und verarbeitet werden.
7. **Hausaufgabe**: Erstellen eines Programms, das den Benutzer nach einem Helligkeitswert (zwischen 0 und 255) für eine LED fragt und dann die Helligkeit der LED entsprechend einstellt.

**Video**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/GpsP5zySI_A?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

