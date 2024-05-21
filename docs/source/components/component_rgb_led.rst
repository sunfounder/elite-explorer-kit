.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_rgb_led:

RGB-LED
=================

.. image:: img/rgb_led.png
    :width: 100
    
RGB-LEDs emittieren Licht in verschiedenen Farben. Eine RGB-LED verpackt drei LEDs in den Farben Rot, Grün und Blau in eine durchsichtige oder halbdurchsichtige Kunststoffhülle. Sie kann verschiedene Farben anzeigen, indem sie die Eingangsspannung der drei Pins ändert und diese überlagert, was laut Statistik 16.777.216 unterschiedliche Farben erzeugen kann.

.. image:: img/rgb_light.png
    :width: 600

RGB-LEDs können in gemeinsame Anode und gemeinsame Kathode eingeteilt werden. In diesem Kit wird letztere verwendet. Die **gemeinsame Kathode**, oder CC, bedeutet, dass die Kathoden der drei LEDs verbunden sind. Nachdem Sie sie mit GND verbunden und die drei Pins eingesteckt haben, leuchtet die LED in der entsprechenden Farbe auf.

Ihr Schaltungssymbol wird wie folgt dargestellt.

.. image:: img/rgb_symbol.png
    :width: 300

Eine RGB-LED hat 4 Pins: der längste ist GND; die anderen sind Rot, Grün und Blau. Berühren Sie ihre Kunststoffhülle und Sie werden eine Kerbe finden. Der Pin, der der Kerbe am nächsten ist, ist der erste Pin, markiert als Rot, dann GND, Grün und Blau der Reihe nach.

.. image:: img/rgb_pin.jpg
    :width: 200

**Beispiel**

* :ref:`basic_rgb_led` (Grundprojekt)
* :ref:`fun_hue` (Spaßprojekt)

