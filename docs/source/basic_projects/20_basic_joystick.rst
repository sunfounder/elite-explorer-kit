.. _basic_joystick:

Joystick-Modul
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/joystick_ps2_uno.html#joystick-uno


Überblick
---------------

Ein Joystick ist ein Eingabegerät, das aus einem auf einer Basis schwenkbaren Stick besteht und seinen Winkel oder seine Richtung an das zu steuernde Gerät meldet. Joysticks werden häufig zur Steuerung von Videospielen und Robotern verwendet. Hier wird ein Joystick PS2 verwendet.

Benötigte Komponenten
-------------------------

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - Elite Explorer Kit
        - 300+
        - |link_Elite_Explorer_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

Verdrahtung
----------------------

.. image:: img/20-joystick_bb.png
    :align: center
    :width: 70%

Schaltplan
---------------------

Dieses Modul hat zwei analoge Ausgänge (entsprechend den X,Y-Biaxial-Versätzen).

In diesem Experiment verwenden wir das Uno-Board, um die Bewegungsrichtung des Joystick-Knopfes zu erkennen.

.. image:: img/20_joystick_schematic.png
    :align: center 
    :width: 70%

Code
-------

.. note::

    * Sie können die Datei ``20-joystick.ino`` direkt im Pfad ``elite-explorer-kit-main\basic_project\20-joystick`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ac0f9910-e53e-43a3-a5ae-ec4d3a3f4aa1/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nun, wenn Sie den Rocker bewegen, ändern sich die Koordinaten der X- und Y-Achse auf dem Serial Monitor entsprechend. Wenn Sie den Knopf drücken, wird auch die Koordinate Z=0 angezeigt.


Code-Analyse
-------------------

Der Code verwendet den seriellen Monitor, um den Wert der VRX- und VRY-Pins des Joystick ps2 auszugeben.

.. code-block:: arduino

    void loop()
    {
        Serial.print("X: "); 
        Serial.print(analogRead(xPin), DEC);  // print the value of VRX in DEC
        Serial.print("|Y: ");
        Serial.print(analogRead(yPin), DEC);  // print the value of VRX in DEC
        Serial.print("|Z: ");
        Serial.println(digitalRead(swPin));  // print the value of SW
        delay(50);
    }