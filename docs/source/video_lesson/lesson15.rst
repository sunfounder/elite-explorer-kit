.. note::

    Hallo, willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Community auf Facebook! Tauche tiefer in Raspberry Pi, Arduino und ESP32 mit gleichgesinnten Enthusiasten ein.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie nach dem Kauf auftretende Probleme und technische Herausforderungen mit Hilfe unserer Community und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Tutorials aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Sonderrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Verlosungen**: Nehmen Sie an Verlosungen und Feiertagsaktionen teil.

    👉 Bereit, mit uns zu entdecken und zu gestalten? Klicken Sie auf [|link_sf_facebook|] und treten Sie noch heute bei!

LEKTION 15: Steuerung einer LED basierend auf Benutzereingaben vom seriellen Monitor
========================================================================================

Diese Lektion zeigt, wie man ein benutzerinteraktives Programm mit dem Arduino erstellt, wobei der Schwerpunkt auf der Erfassung von Benutzereingaben über den seriellen Monitor und der Durchführung verschiedener Operationen basierend auf diesen Eingaben liegt. Hier ist eine kurze Übersicht darüber, was Sie lernen werden:

1. **Überprüfung der vorherigen Hausaufgabe**: Rückblick auf die Aufgabe aus Lektion 14, bei der die Helligkeit einer LED durch Benutzereingaben über den seriellen Monitor gesteuert wurde.
2. **Einrichten der Schaltung**: Anweisungen zum korrekten Anschließen einer LED und eines Widerstands an den Arduino, wobei sichergestellt wird, dass jede Komponente ordnungsgemäß für das Experiment konfiguriert ist.
3. **Code schreiben**: Schritt-für-Schritt-Anleitung zum Schreiben von Code, der Benutzereingaben vom seriellen Monitor liest und zur Anpassung der LED-Helligkeit verwendet. Dies beinhaltet mathematische Berechnungen zur Umwandlung der Benutzereingabe in einen Wert, den der Arduino zur Steuerung der LED-Helligkeit verwenden kann.
4. **Exponentielle Skalierung**: Erklärung der exponentiellen Skalierung, um sicherzustellen, dass die wahrgenommene Helligkeit der LED über den Bereich der Benutzereingaben hinweg gleichmäßig ansteigt.
5. **Debugging-Tipps**: Tipps zur Fehlerbehebung bei häufigen Problemen wie falschen Messwerten oder Fehlern in der Ausgabe, die die LED-Helligkeit beeinflussen.
6. **Hausaufgabe**: Erstellen eines Programms, das den Benutzer nach einem Helligkeitswert (zwischen 0 und 10) für eine LED fragt und dann die LED-Helligkeit entsprechend einstellt.

**Video**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/d-Ma3u7GngA?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

