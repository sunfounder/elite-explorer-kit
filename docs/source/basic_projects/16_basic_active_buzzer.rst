.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_active_buzzer:

Aktiver Summer
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_active_buzzer.html#ar-beep

Überblick
---------------

Der aktive Summer ist ein typisches digitales Ausgabegerät, das genauso einfach zu verwenden ist wie das Aufleuchten einer LED!

Das Kit enthält zwei Arten von Summern. 
Wir müssen den aktiven Summer verwenden. Drehen Sie sie um, die versiegelte Rückseite (nicht die offene Leiterplatte) ist die, die wir benötigen.

.. image:: img/16_buzzer.png
    :align: center
    :width: 70%

Benötigte Komponenten
-------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten. 

Es ist definitiv praktisch, ein komplettes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Sie können die Komponenten auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_buzzer`
        - \-

Verdrahtung
----------------------

.. note::
    Beim Anschließen des Summers achten Sie darauf, seine Pins zu überprüfen. Der längere Pin ist die Anode und der kürzere die Kathode. Es ist wichtig, sie nicht zu verwechseln, da sonst der Summer keinen Ton erzeugen wird.

.. image:: img/16-active_buzzer_bb.png
    :align: center
    :width: 70%

Schaltplan
-----------------------

.. image:: img/16_active_buzzer_schematic.png
    :align: center
    :width: 80%

Code
---------------

.. note::

    * Sie können die Datei ``16-active_buzzer.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\16-active_buzzer`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. literalinclude:: /_code/16_basic_active_buzzer.ino
   :language: cpp
   :linenos:
   :caption: 16-active_buzzer.ino

Nachdem der Code erfolgreich hochgeladen wurde, hören Sie jede Sekunde einen Piepton.
