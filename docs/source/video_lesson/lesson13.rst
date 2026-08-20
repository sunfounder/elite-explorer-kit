.. note::

    Hallo, willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Community auf Facebook! Tauche tiefer in Raspberry Pi, Arduino und ESP32 mit gleichgesinnten Enthusiasten ein.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie nach dem Kauf auftretende Probleme und technische Herausforderungen mit Hilfe unserer Community und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Tutorials aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Sonderrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Verlosungen**: Nehmen Sie an Verlosungen und Feiertagsaktionen teil.

    👉 Bereit, mit uns zu entdecken und zu gestalten? Klicken Sie auf [|link_sf_facebook|] und treten Sie noch heute bei!

LEKTION 13: Dimmbares LED gesteuert von einem Potentiometer
==============================================================

Diese Lektion zeigt, wie man eine dimmbare LED mit einem Potentiometer und einem Arduino erstellt, basierend auf den vorherigen Lektionen zum Lesen von Analogwerten und zur Steuerung von Ausgaben über PWM. Hier ist eine kurze Übersicht darüber, was Sie lernen werden:

1. **Überprüfung der vorherigen Hausaufgaben**: Rückblick auf die Aufgabe aus Lektion 12, die die Verwendung eines Potentiometers zur Steuerung der Helligkeit einer LED beinhaltete.
2. **Einrichten der Schaltung**: Detaillierte Anweisungen zum richtigen Anschließen eines Potentiometers und einer LED an den Arduino, um sicherzustellen, dass jede Komponente für das Experiment richtig konfiguriert ist.
3. **Den Code schreiben**: Schritt-für-Schritt-Codieranweisungen zum Lesen des Analogwerts vom Potentiometer und zur Verwendung dieses Werts zur Anpassung der LED-Helligkeit über PWM. Dies beinhaltet mathematische Berechnungen zur Übersetzung des variablen Widerstands des Potentiometers in einen Spannungswert, den der Arduino zur Steuerung der LED verwenden kann.
4. **Debugging-Tipps**: Anleitung zur Fehlersuche bei häufigen Problemen wie falschen Messwerten vom Potentiometer oder Fehlern im PWM-Ausgang, die die LED-Helligkeit beeinflussen.
5. **Hausaufgabe**: Erweiterung des Projekt der Lektion durch Experimentieren mit verschiedenen Zuordnungen der Potentiometermesswerte zur LED-Helligkeit, um lineares versus exponentielles Skalieren und seine Wahrnehmungseffekte auf die LED-Dimmung zu verstehen.

**Video**

.. raw:: html

    <iframe width="100%" 
        style="aspect-ratio: 16/9; max-width: 100%;"
        src="https://www.youtube.com/embed/PXf51k0alGU?si=o9Q1tTC1X1B9teef" 
        title="YouTube video player" 
        frameborder="0" 
        allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" 
        allowfullscreen>
    </iframe>

