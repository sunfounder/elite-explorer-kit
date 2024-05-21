.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_ultrasonic:

Ultraschallmodul
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

Ein Ultraschallsensor ist ein Gerät zur Messung der Entfernung zu einem Objekt mit Ultraschallwellen. Es besitzt zwei Sonden: eine sendet Ultraschallwellen aus, die andere empfängt diese und wandelt die Übertragungszeit in eine Distanz um. Dies ermöglicht die Ermittlung des Abstands zwischen dem Gerät und einem Hindernis. In der Praxis erweist es sich als sehr praktisch und funktionell.

Das Modul bietet eine berührungslose Messfunktion von 2 cm bis 400 cm, mit einer Genauigkeit von bis zu 3 mm. Es gewährleistet eine stabile Signalübertragung bis zu einer Entfernung von 5 m; darüber hinaus nimmt die Signalstärke ab und verschwindet bei etwa 7 m.

Das Modul umfasst Ultraschallsender, -empfänger und Steuerschaltkreise. Die grundlegenden Prinzipien sind wie folgt:

#. Ein IO-Flip-Flop verarbeitet ein Hochpegelsignal von mindestens 10us.

#. Das Modul sendet automatisch acht 40kHz-Signale und prüft, ob ein Pulssignal zurückkehrt.

#. Wenn das Signal zurückkehrt, wird die Dauer des Hochpegelausgangs des IOs zur Zeit vom Aussenden bis zum Zurückkehren der Ultraschallwelle. Hier gilt: Testdistanz = (Hochzeit x Schallgeschwindigkeit (340 m/s) / 2.

Das Timing-Diagramm ist unten dargestellt.

.. image:: img/ultrasonic228.png

Sie müssen nur einen kurzen 10us-Impuls an den Trigger-Eingang senden, um die Entfernungsmessung zu starten. Das Modul sendet dann einen 8-Zyklus-Burst von Ultraschall mit 40 kHz aus und erhöht sein Echo. Die Entfernung kann durch das Zeitintervall zwischen dem Senden des Trigger-Signals und dem Empfangen des Echosignals berechnet werden.

Formel: us / 58 = Zentimeter oder us / 148 = Zoll; oder: die Entfernung = Hochpegelzeit * Geschwindigkeit (340M/S) / 2; es wird empfohlen, einen Messzyklus von über 60ms zu verwenden, um Signalüberschneidungen zwischen Trigger- und Echosignal zu vermeiden.

**Beispiel**

* :ref:`basic_ultrasonic_sensor` (Grundprojekt)
* :ref:`fun_smart_can` (Spaßprojekt)

