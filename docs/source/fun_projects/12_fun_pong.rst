.. _fun_pong:

SPIEL - Pong
=================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/12_fun_pong.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Dies ist ein einfaches Pong-Spiel, das mit einem OLED-Display und einem Arduino-Board entwickelt wurde.
Im Pong-Spiel treten Spieler gegen den Computer an, indem sie einen vertikalen Schläger steuern, um einen hüpfenden Ball zurückzuprallen. 
Das Ziel ist es, zu verhindern, dass der Ball an der Kante Ihres Schlägers vorbeigeht, sonst erzielt der Gegner Punkte.

Die Spielmechanik kann in folgende Teile unterteilt werden:

1. Ballbewegung - Der Ball bewegt sich in seiner aktuellen Richtung mit einer festgelegten Geschwindigkeit. Jedes Mal, wenn der Ball mit einem Schläger kollidiert, nimmt seine Geschwindigkeit zu, was das Spiel herausfordernder macht.

2. Schlägerbewegung - Wird verwendet, um die Bewegung des Balls zu blockieren, der Schläger kann sich nach oben oder unten bewegen. Spieler steuern ihren eigenen Schläger mit Knöpfen, während der Schläger des Computers automatisch der Position des Balls folgt.

3. Punktzahl - Immer wenn der Ball über den linken oder rechten Rand des Bildschirms hinausgeht, erzielt der entsprechende Spieler oder CPU Punkte.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_oled`
        - |link_oled_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_power`
        - \-


**Verdrahtung**

.. image:: img/12_pong_bb.png
    :width: 100%
    :align: center


**Schaltplan**

.. image:: img/12_pong_schematic.png
    :width: 100%
    :align: center

**Code**

.. note::

    * Sie können die Datei ``12_pong_oled.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\fun_project\12_pong_oled`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note::
   Um die Bibliothek zu installieren, verwenden Sie den Arduino-Bibliotheksmanager und suchen Sie nach **„Adafruit SSD1306“** und **„Adafruit GFX“** und installieren Sie diese.


.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/86dbb549-d425-4f42-8b5b-28d486e3f7f8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Wie funktioniert des?**

Die Programmstruktur kann in die folgenden fünf Teile unterteilt werden:

1. Notwendige Bibliotheken importieren - Verwendet zur Steuerung des OLED-Bildschirms und zum Lesen von Tasteneingaben.

2. Konstanten und globale Variablen definieren:

   Definitionen für OLED-Bildschirmbreite und -höhe.
   Definitionen für Tasten und OLED-Reset-Pins.
   Position, Geschwindigkeit, Größe und Richtung des Balls und der Schläger.
   Punktzahlen für Spieler und CPU.

3. Initialisierung:

   Initialisieren Sie die serielle Kommunikation, den OLED-Bildschirm und zeigen Sie die anfängliche Oberfläche an.
   Stellen Sie Tasten als Eingänge ein und verbinden Sie Pull-up-Widerstände.
   Zeichnen Sie das Spielfeld.

4. Hauptschleife:

   Lesen Sie die Zustände der Tasten.
   Bewegen Sie den Ball basierend auf der eingestellten Aktualisierungsrate.
   Erkennen Sie Kollisionen zwischen dem Ball und den Schlägern oder Wänden und passen Sie die Richtung und Geschwindigkeit des Balls entsprechend an.
   Aktualisieren Sie den Bildschirm mit Punktzahlen basierend auf Punktereignissen.
   Aktualisieren Sie die Positionen der Schläger.

5. Zusätzliche Funktionen:

   ``crossesPlayerPaddle`` und ``crossesCpuPaddle`` - Wird verwendet, um zu erkennen, ob der Ball mit dem Schläger des Spielers oder der CPU kollidiert.
   
   ``drawCourt`` - Zeichnet das Spielfeld auf dem OLED-Bildschirm.

   ``displayScore`` - Zeigt die Punktzahlen des Spielers und der CPU auf dem Bildschirm an.

