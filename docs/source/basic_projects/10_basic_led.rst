.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_led:

LED-Modul
==========================

Genau wie das Drucken von „Hallo, Welt!“ der erste Schritt beim Erlernen der Programmierung ist, so ist das Ansteuern einer LED die traditionelle Einführung in die physische Programmierung.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

Verdrahtung
----------------------

.. image:: img/10-led_bb.png
    :align: center
    :width: 60%


Schaltplan
-----------------------

.. image:: img/10_led_schematic.png
    :align: center
    :width: 80%


Code
---------------

.. note::

   * Sie können die Datei ``10-led.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\10-led`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. literalinclude:: /_code/10_basic_led.ino
   :language: cpp
   :linenos:
   :caption: 10-led.ino

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/basic_projects/10_basic_led.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Nachdem der Code erfolgreich hochgeladen wurde, sehen Sie, wie die an den digitalen Pin 9 des Arduino-Boards angeschlossene LED zu blinken beginnt. Die LED leuchtet eine halbe Sekunde lang auf und schaltet sich dann für eine weitere halbe Sekunde aus, wobei dieser Zyklus kontinuierlich wiederholt wird, solange das Programm läuft.

Code-Analyse
------------------------

Hier verbinden wir die LED mit dem digitalen Pin 9, daher müssen wir eine ``int`` Variable namens ``ledPin`` zu Beginn des Programms deklarieren und den Wert 9 zuweisen.

.. code-block:: arduino

    const int ledPin = 9;


Jetzt initialisieren wir den Pin in der ``setup()``-Funktion, wo Sie den Pin auf ``OUTPUT`` -Modus einstellen müssen.

.. code-block:: arduino

    void setup() {
        pinMode(ledPin, OUTPUT);
    }

In ``loop()``, wird ``digitalWrite()`` verwendet, um dem ledPin ein 5V-High-Level-Signal zu liefern, was Spannungsunterschiede zwischen den LED-Pins erzeugt und die LED aufleuchten lässt.

.. code-block:: arduino

    digitalWrite(ledPin, HIGH);

Wenn das Level-Signal auf LOW geändert wird, wird das Signal von ledPin auf 0 V zurückgeführt, um die LED auszuschalten.

.. code-block:: arduino

    digitalWrite(ledPin, LOW);


Ein Intervall zwischen An- und Ausschalten ist erforderlich, damit Menschen die Veränderung sehen können, 
daher verwenden wir einen ``delay(1000)`` -Code, um den Controller 1000 ms lang nichts tun zu lassen.

.. code-block:: arduino

    delay(1000);   
