.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_tilt_switch:

Kippschalter
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.17_tilt_switch.html#ar-tilt

Übersicht
---------------

In dieser Lektion erfahren Sie mehr über den Kippschalter. Kippschalter können eingesetzt werden, um die Neigung von Objekten zu erkennen, was in der Praxis von großem Wert ist. Sie können zur Beurteilung der Neigung von Brücken, Gebäuden, Übertragungsleitungstürmen usw. verwendet werden und haben daher eine wichtige Leitfunktion bei der Durchführung von Wartungsarbeiten.

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
    *   - :ref:`cpn_tilt_switch`
        - \-

Verdrahtung
---------------------

In diesem Beispiel wird der digitale Pin 2 verwendet, um das Signal des Kippschalters zu lesen.

.. image:: img/04-tilt_switch_bb.png
   :align: center
   :width: 85%

Schaltplan
-----------------------

.. image:: img/04_tilt_switch_schematic.png
   :align: center
   :width: 70%


Code
----------

.. note::

    * Sie können die Datei ``04-tilt_switch.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\04-tilt_switch`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. literalinclude:: /_code/04_basic_tilt_switch.ino
   :language: cpp
   :linenos:
   :caption: 04-tilt_switch.ino

Sobald die Codes auf das Uno R4-Board hochgeladen wurden, können Sie den seriellen Monitor öffnen, um die Pin-Lesungen zu betrachten. Die Lesungen zeigen entweder „1“ oder „0“ an, je nachdem, ob der Kippschalter in einer vertikalen Position ist (wobei die interne Metallkugel Kontakt mit den Drahtstiften hat) oder geneigt ist.
