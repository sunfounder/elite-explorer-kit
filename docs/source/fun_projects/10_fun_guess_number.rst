.. _fun_guess_number:

SPIEL - Zahl Erraten
============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/10_fun_guess_game.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

„Zahl Erraten“ ist ein unterhaltsames Partyspiel, bei dem du und deine Freunde abwechselnd eine Zahl (0~99) eingeben. 
Der Bereich wird mit jeder Eingabe enger, bis ein Spieler die Antwort richtig errät. 
Der Spieler, der richtig rät, wird zum Verlierer erklärt und einer Strafe unterzogen. 
Zum Beispiel, wenn die geheime Zahl 51 ist, die die Spieler nicht sehen können, und Spieler 1 gibt 50 ein, 
ändert sich die Bereichsanzeige auf 50~99. Wenn Spieler 2 70 eingibt, wird der Bereich zu 50~70. 
Wenn Spieler 3 51 eingibt, ist er der Unglückliche. 
In diesem Spiel verwenden wir eine IR-Fernbedienung, um Zahlen einzugeben, und ein LCD, um Ergebnisse anzuzeigen.

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
    *   - :ref:`cpn_i2c_lcd1602`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_ir_receiver`
        - |link_receiver_buy|



**Verdrahtung**

.. image:: img/10_guess_number_bb.png
    :width: 90%
    :align: center


**Schaltplan**

.. image:: img/10_guess_number_schematic.png
   :width: 100%
   :align: center

**Code**

.. note::

    * Sie können die Datei ``10_guess_number.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\fun_project\10_guess_number`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note::
   Um die Bibliothek zu installieren, verwenden Sie den Arduino-Bibliotheksmanager und suchen Sie nach **„IRremote“** und **„LiquidCrystal I2C“** und installieren Sie diese.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/935cd2e8-23e1-4af8-bdf5-94ac00f10e8b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**Wie funktioniert des?**

1. Bibliotheksimporte und globale Variablendefinitionen:

   Drei Bibliotheken werden importiert: ``Wire`` für die I2C-Kommunikation, ``LiquidCrystal_I2C`` zur Steuerung des LCD-Displays und ``IRremote`` zum Empfangen von Signalen der Infrarot-Fernbedienung.
   Mehrere globale Variablen werden definiert, um den Spielstand und die Einstellungen zu speichern.

2. ``setup()`` 

   Initialisieren Sie das LCD-Display und schalten Sie die Hintergrundbeleuchtung ein.
   Initialisieren Sie die serielle Kommunikation mit einer Baudrate von 9600.
   Starten Sie den Infrarotempfänger.
   Rufen Sie die Funktion ``initNewValue()`` auf, um den anfänglichen Spielzustand einzustellen.

3. ``loop()`` 

   Überprüfen Sie, ob ein Signal von der Infrarot-Fernbedienung empfangen wurde.
   Dekodieren Sie das empfangene Infrarotsignal.
   Aktualisieren Sie den Spielstand oder führen Sie entsprechende Aktionen basierend auf dem dekodierten Wert (Zahl oder Befehl) aus.

4. ``initNewValue()`` 

   Verwenden Sie ``analogRead``, um den Zufallszahlensamen zu initialisieren und zu gewährleisten, dass jedes Mal unterschiedliche Zufallszahlen generiert werden.
   Generieren Sie eine Zufallszahl zwischen 0 und 98 als Glückszahl (die Zahl, die die Spieler erraten müssen).
   Setzen Sie die Hinweise für die obere und untere Grenze zurück.
   Zeigen Sie eine Begrüßungsnachricht auf dem LCD an.
   Setzen Sie die Eingabenummer zurück.

5. ``detectPoint()`` 

   Überprüfen Sie das Verhältnis zwischen der Eingabenummer des Spielers und der Glückszahl.
   Wenn die Eingabenummer größer als die Glückszahl ist, aktualisieren Sie den Hinweis für die obere Grenze.
   Wenn die Eingabenummer kleiner als die Glückszahl ist, aktualisieren Sie den Hinweis für die untere Grenze.
   Wenn der Spieler die richtige Zahl eingibt, setzen Sie die Eingabe zurück und geben Sie wahr zurück.

6. ``lcdShowInput()`` 

   Zeigen Sie die Eingabe des Spielers und die aktuellen Hinweise für die obere und untere Grenze auf dem LCD an.
   Wenn der Spieler richtig rät, zeigen Sie eine Erfolgsmeldung an und pausieren Sie für 5 Sekunden, bevor Sie das Spiel neu starten.

