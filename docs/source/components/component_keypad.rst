.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_keypad:

Tastenfeld
========================

Ein Tastenfeld ist ein rechteckiges Array aus 12 oder 16 OFF-(ON)-Tasten. 
Ihre Kontakte sind über einen Header zugänglich, der für die Verbindung mit einem Flachbandkabel oder das Einsetzen in eine gedruckte Schaltplatine geeignet ist. 
Bei einigen Tastenfeldern verbindet jede Taste mit einem separaten Kontakt im Header, während alle Tasten eine gemeinsame Masse teilen.

.. image:: img/keypad314.png

Häufiger sind die Tasten matrixcodiert, was bedeutet, dass jede von ihnen ein einzigartiges Paar von Leitern in einer Matrix überbrückt. 
Diese Konfiguration eignet sich für das Abfragen durch einen Mikrocontroller, der so programmiert werden kann, dass er nacheinander einen Ausgangsimpuls an jede der vier horizontalen Leitungen sendet. 
Während jedes Impulses überprüft er die verbleibenden vier vertikalen Leitungen der Reihe nach, um festzustellen, welche davon, wenn überhaupt, ein Signal trägt. 
Pull-up- oder Pull-down-Widerstände sollten zu den Eingangsleitungen hinzugefügt werden, um ein unvorhersehbares Verhalten der Eingänge des Mikrocontrollers zu verhindern, wenn kein Signal vorhanden ist.

**Beispiel**

* :ref:`basic_keypad` (Grundprojekt)

