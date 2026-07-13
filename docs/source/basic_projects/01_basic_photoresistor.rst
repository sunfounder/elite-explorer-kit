.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_photoresistor:

Fotowiderstand
==========================

.. https://docs.sunfounder.com/projects/vincent-kit/en/latest/arduino/2.26_photoresistor.html

Übersicht
---------------

In dieser Lektion lernen Sie den Fotowiderstand kennen. Fotowiderstände finden in vielen elektronischen Geräten Anwendung, wie zum Beispiel in Belichtungsmessern von Kameras, Radioweckern, Alarmanlagen (als Strahlendetektoren), kleinen Nachtlichtern, Außenuhren, Straßenlaternen mit Solarenergie und mehr. Ein Fotowiderstand in einer Straßenlampe steuert das Ein- und Ausschalten des Lichts. Umgebungslicht, das auf den Fotowiderstand fällt, bewirkt, dass Straßenlampen ein- oder ausgeschaltet werden.

Benötigte Komponenten
-------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Sie können die Komponenten auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Verdrahtung
----------------------

In diesem Beispiel verwenden wir den analogen Pin (A0), um den Wert des Fotowiderstands zu lesen. Ein Pin des Fotowiderstands wird mit 5V verbunden, der andere mit A0. Außerdem wird ein 10kΩ Widerstand benötigt, bevor der andere Pin mit GND verbunden wird.

.. image:: img/01-photoresistor_bb.png
    :align: center
    :width: 80%

Schaltplan
-----------------------

.. image:: img/01_photoresistor_schematic.png
    :align: center
    :width: 70%

Code
---------------

.. note::

    * Sie können die Datei ``01-fotowiderstand`` direkt im Pfad ``elite-explorer-kit-main\basic_project\01-fotowiderstand`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.




.. literalinclude:: /_code/01_basic_photoresistor.ino
   :language: cpp
   :linenos:
   :caption: 01-fotowiderstand.ino

Nachdem Sie den Code auf das Uno-Board hochgeladen haben, können Sie den seriellen Monitor öffnen, um den ausgelesenen Wert des Pins zu sehen. Wenn das Umgebungslicht stärker wird, steigt auch der Messwert entsprechend an, und der Lesebereich des Pins liegt zwischen 「0」 und 「1023」. Jedoch kann der tatsächliche Lesebereich aufgrund der Umgebungsbedingungen und der Eigenschaften des Fotowiderstands kleiner sein als der theoretische Bereich.
