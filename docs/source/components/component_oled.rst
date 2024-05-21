.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_oled:

OLED-Display-Modul
==========================

.. image:: img/oled.png
    :width: 300
    :align: center

Einführung
---------------------------
Ein OLED-Display (Organic Light-Emitting Diode) ist ein Gerät, das Texte, Grafiken und Bilder auf einem dünnen und flexiblen Bildschirm anzeigen kann, indem es organische Materialien verwendet, die Licht abgeben, wenn ein elektrischer Strom angelegt wird.

Der Hauptvorteil eines OLED-Displays besteht darin, dass es sein eigenes Licht emittiert und keine andere Hintergrundlichtquelle benötigt. Dadurch haben OLED-Displays oft einen besseren Kontrast, eine bessere Helligkeit und Blickwinkel im Vergleich zu LCD-Displays.

Ein weiteres wichtiges Merkmal von OLED-Displays ist die tiefe Schwarzstufe. Da jeder Pixel in einem OLED-Display sein eigenes Licht emittiert, kann zur Erzeugung der schwarzen Farbe der einzelne Pixel ausgeschaltet werden.

Aufgrund des geringeren Stromverbrauchs (nur beleuchtete Pixel verbrauchen Strom) sind OLED-Displays auch bei batteriebetriebenen Geräten wie Smartwatches, Gesundheitstrackern und anderen Wearables beliebt.

Prinzip
---------------------------
Ein OLED-Display-Modul besteht aus einem OLED-Panel und einem OLED-Treiberchip, der auf der Rückseite des Moduls montiert ist. Das OLED-Panel besteht aus vielen kleinen Pixeln, die unterschiedliche Lichtfarben erzeugen können. Jeder Pixel besteht aus mehreren Schichten organischer Materialien, die zwischen zwei Elektroden (Anode und Kathode) eingeschlossen sind. Wenn elektrischer Strom durch die Elektroden fließt, emittieren die organischen Materialien Licht unterschiedlicher Wellenlängen, abhängig von ihrer Zusammensetzung.

Der OLED-Treiberchip ist ein Chip, der die Pixel des OLED-Panels über ein seriellen Kommunikationsprotokoll namens I2C (Inter-Integrated Circuit) steuern kann.

Der OLED-Treiberchip wandelt die Signale vom Arduino in Befehle für das OLED-Panel um. Der Arduino kann Daten an den OLED-Treiberchip senden, indem er eine Bibliothek verwendet, die das I2C-Protokoll steuern kann. Eine solche Bibliothek ist die Adafruit SSD1306-Bibliothek. Mit dieser Bibliothek können Sie das OLED-Displaymodul initialisieren, die Helligkeitsstufe einstellen, Texte, Grafiken oder Bilder ausgeben usw.

**Beispiel**

* :ref:`basic_oled` (Grundprojekt)
* :ref:`fun_pong` (Spaßprojekt)
* :ref:`iot_weathertime_screen` (IoT-Projekt)
