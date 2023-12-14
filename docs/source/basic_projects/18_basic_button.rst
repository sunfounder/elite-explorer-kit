.. _basic_button:

Taster
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/de/latest/projects/controlling_led_by_button_uno.html#button-uno


Überblick
----------------

In dieser Lektion lernen Sie, wie Sie eine LED mit einem Arduino und einem Taster steuern können. Taster und LEDs sind grundlegende Komponenten in einer Vielzahl elektronischer Geräte, wie Fernbedienungen, Taschenlampen und interaktiven Installationen. In dieser Einrichtung wird ein Taster als Eingabegerät verwendet, um den Zustand einer LED zu steuern, die als Ausgabegerät dient.

Der Taster ist mit Pin 12 auf dem Arduino Uno R4 Board verbunden, und die LED ist mit Pin 13 verbunden. Wenn der Taster gedrückt wird, sendet er ein Signal an den Arduino, das die LED einschaltet. Umgekehrt, wenn der Taster losgelassen wird, erlischt die LED. Dieser einfache, aber effektive Mechanismus kann die Grundlage für komplexere Projekte sein, wie zum Beispiel Hausautomationssysteme, interaktive Displays und vieles mehr.

Am Ende dieser Lektion werden Sie verstehen, wie man Eingaben von einem Taster liest und sie verwendet, um eine LED zu steuern, und damit ein grundlegendes Verständnis für Ein-/Ausgabeoperationen mit Arduino erlangen.

Benötigte Komponenten
-------------------------

In diesem Projekt benötigen wir folgende Komponenten.

Es ist definitiv bequem, ein ganzes Set zu kaufen, hier ist der Link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Sie können diese auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_capacitor`
        - |link_capacitor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|


Verdrahtung
----------------------

.. image:: img/18-button_bb.png
    :align: center
    :width: 70%


Schaltplan
------------------------

Verbinden Sie ein Ende des Tasters mit Pin 12, der mit einem Pull-Down-Widerstand und einem 0,1uF (104) Kondensator verbunden ist (um Zittern zu eliminieren und ein stabiles Level auszugeben, wenn der Taster arbeitet). Verbinden Sie das andere Ende des Widerstands mit GND und einen der Pins am anderen Ende des Tasters mit 5V. Wenn der Taster gedrückt wird, ist Pin 12 auf 5V (HIGH) und setzt gleichzeitig Pin 13 (integriert mit einer LED) auf High. Dann lassen Sie den Taster los (Pin 12 wechselt auf LOW) und Pin 13 ist Low. So werden wir sehen, dass die LED aufleuchtet und erlischt, wenn der Taster gedrückt und losgelassen wird.

.. image:: img/18_button_schematic.png
    :align: center
    :width: 70%


Code
---------------

.. note::

    * Sie können die Datei ``18-button.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\basic_project\18-button`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/a710eb54-9447-4542-ac98-c9a7e1ec4256/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Code-Analyse
-------------------

#. Konstanten und Variablen definieren

   In diesem Abschnitt werden die Pinnummern für den Taster und die LED definiert. Außerdem wird eine Variable ``buttonState`` deklariert, um den aktuellen Zustand des Tasters zu speichern.
 
   .. code-block:: arduino
 
     const int buttonPin = 12;
     const int ledPin = 13;
     int buttonState = 0;

#. Setup-Funktion

   Die ``setup()``-Funktion wird einmal ausgeführt, wenn das Arduino-Board startet. Die Pin-Modi für den Taster und die LED werden mit der Funktion ``pinMode`` eingestellt.
 
   .. code-block:: arduino
 
     void setup() {
       pinMode(buttonPin, INPUT);
       pinMode(ledPin, OUTPUT);
     }

#. Hauptschleife

   Die ``loop()``-Funktion wird wiederholt ausgeführt. Innerhalb dieser Schleife wird die Funktion ``digitalRead()`` verwendet, um den Zustand des Tasters zu lesen. Je nachdem, ob der Taster gedrückt ist oder nicht, wird die LED ein- oder ausgeschaltet.
 
   .. code-block:: arduino
 
     void loop() {
       buttonState = digitalRead(buttonPin);
       if (buttonState == HIGH) {
         digitalWrite(ledPin, HIGH);
       } else {
         digitalWrite(ledPin, LOW);
       }
     }