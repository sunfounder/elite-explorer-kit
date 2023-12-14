.. _basic_stepper_motor:

Schrittmotor
==========================

.. https://docs.sunfounder.com/projects/r4-basic-kit/en/latest/projects/stepper_motor_uno.html#stepper-uno

Überblick
---------------

In dieser Lektion lernen Sie, wie man Schrittmotoren steuert, speziell das Modell 28BYJ-48, unter Verwendung eines ULN2003-Treibers und eines Arduino Uno R4. Schrittmotoren werden in einer Vielzahl von Anwendungen wie 3D-Druckern, CNC-Maschinen, Robotik und sogar in gängigen Haushaltsgeräten verwendet. Ihre präzise Steuerung ermöglicht komplexe Bewegungen, was sie ideal für Projekte macht, die eine hohe Positionsgenauigkeit erfordern.

In diesem Projekt konfigurieren wir den 28BYJ-48-Schrittmotor so, dass er sich in beide Richtungen – im Uhrzeigersinn und gegen den Uhrzeigersinn – mit verschiedenen Geschwindigkeiten dreht. Solche Schrittmotoren werden oft in automatisierten Systemen verwendet, um Objekte zu drehen oder Mechanismen anzutreiben, die eine präzise Steuerung erfordern. Beispielsweise können sie in automatischen Vorhängen verwendet werden, die sich zu bestimmten Zeiten oder unter bestimmten Bedingungen öffnen oder schließen. Wenn Sie verstehen, wie man die Drehung und Geschwindigkeit eines Schrittmotors steuert, sind Sie auf dem besten Weg, sie in Ihre eigenen elektronischen Projekte zu integrieren.

Benötigte Komponenten
-------------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

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
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_power`
        - \-


Verdrahtung
----------------------

.. warning::
    Aufgrund des hohen Stromverbrauchs des Schrittmotors ist es ratsam, eine externe 5V-Stromversorgung zu verwenden, anstatt sich auf den Arduino zu verlassen.

    Obwohl es möglich ist, den Schrittmotor direkt vom Arduino zu betreiben, wird dies nicht empfohlen, da es elektrisches Rauschen auf dessen Stromversorgungsleitungen verursachen kann, was möglicherweise zu Schäden am Arduino führt.

.. image:: img/26-stepper_motor_bb.png
    :align: center


Schaltplan
-----------------------

.. image:: img/26_stepper_motor_schematic.png
   :align: center
   :width: 80%


Code
---------------

.. note::

    * Sie können die Datei ``26-stepper_motor.ino`` direkt im Pfad ``elite-explorer-kit-main\basic_project\26-stepper_motor.rst`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ce640f07-39a0-418a-9114-901df676ff32/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code auf das Arduino Uno Board hochgeladen wurde, beginnt der 28BYJ-48 Schrittmotor sich zu drehen, angetrieben durch den ULN2003 Treiber. Zunächst dreht sich der Motor im Uhrzeigersinn mit einer Geschwindigkeit von 5 Umdrehungen pro Minute (RPM) für eine vollständige Umdrehung. Nachdem die Drehung im Uhrzeigersinn abgeschlossen ist, hält der Motor für 1 Sekunde an.

Anschließend dreht sich der Motor in die entgegengesetzte Richtung, gegen den Uhrzeigersinn, mit einer erhöhten Geschwindigkeit von 15 RPM für eine weitere vollständige Umdrehung. Wieder hält der Motor nach der Drehung gegen den Uhrzeigersinn für 1 Sekunde an. Der Zyklus aus Drehung und Pause setzt sich unendlich fort, solange das Arduino mit Strom versorgt wird.



Code-Analyse
-----------------

1. **Initialisierung des Schrittmotors**

   .. code-block:: arduino
   
       #include <Stepper.h>  // Include the Stepper library

       #define STEPS 2038                   // Define the number of steps per revolution for the motor
       Stepper stepper(STEPS, 2, 3, 4, 5);  // Initialize stepper object and set pin connections (IN1, IN2, IN3, IN4)

   Binden Sie die Kopfdatei ``Stepper.h`` ein, setzen Sie die Schritte auf 2038 und initialisieren Sie den Schrittmotor mit der Funktion stepper().

   ``STEPS``: Die Anzahl der Schritte in einer Umdrehung Ihres Motors. Für diesen Schrittmotor beträgt dieser Wert 2038.

   ``Stepper(steps, pin1, pin2, pin3, pin4)``: Diese Funktion erstellt eine neue Instanz der Stepper-Klasse, die einen bestimmten Schrittmotor repräsentiert, der an Ihrem Arduino-Board angeschlossen ist. Die Pins pin1, pin2, pin3 und pin4 entsprechen den IN1-, IN2-, IN3- und IN4-Pins am ULN2003-Treiber.
   

2. **loop() Funktion**

   .. code-block:: arduino
   
      void loop() {
        // Rotate clockwise at 5 RPM
        stepper.setSpeed(5);
        stepper.step(STEPS);  // Rotate one full revolution clockwise
        delay(1000);          // Wait for 1 second
      
        // Rotate counter-clockwise at 15 RPM
        stepper.setSpeed(15);
        stepper.step(-STEPS);  // Rotate one full revolution counter-clockwise
        delay(1000);           // Wait for 1 second
      }
   
   Das Hauptprogramm dreht den Schrittmotor kontinuierlich, einmal eine volle Drehung im Uhrzeigersinn mit 5 U/min und dann einmal eine volle Drehung gegen den Uhrzeigersinn mit 15 U/min.


   - ``setSpeed(rpms)``: Legt die Motorgeschwindigkeit in Umdrehungen pro Minute (U/min) fest. Diese Funktion bringt den Motor nicht zum Drehen, sondern legt nur die Geschwindigkeit fest, mit der er sich dreht, wenn Sie step() aufrufen.

     - ``rpms``: die Geschwindigkeit, mit der sich der Motor in Umdrehungen pro Minute drehen soll – eine positive Zahl (long)
   
   .. raw::html

        <br/>

   
   - ``step(steps)``: Diese Funktion dreht den Motor um eine bestimmte Anzahl von Schritten, wobei die in der letzten setSpeed()-Aufruf festgelegte Geschwindigkeit verwendet wird. Es ist wichtig zu beachten, dass diese Funktion blockierend arbeitet, das heißt, sie wartet, bis der Motor seine Bewegung abgeschlossen hat, bevor die Steuerung zur nächsten Zeile Ihres Skripts weitergeht.
   
     Wenn Sie beispielsweise die Geschwindigkeit auf 1 U/min einstellen und step(2038) bei einem Motor mit 2038 Schritten aufrufen, würde es eine volle Minute dauern, bis diese Funktion ausgeführt wird. Um eine präzisere Steuerung zu erreichen, wird empfohlen, eine höhere Geschwindigkeit beizubehalten und nur wenige Schritte bei jedem Aufruf von step() zu machen.
   
     - ``steps``: die Anzahl der Schritte, um den Motor zu drehen – positiv für eine Richtung, negativ für die andere (int).





