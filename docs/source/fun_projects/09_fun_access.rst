.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _fun_access:

Zugangskontrollsystem
======================================

.. raw:: html

   <video loop controls style = "max-width:100%">
      <source src="../_static/videos/fun_projects/09_fun_access.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Die Hauptfunktion dieses Codes besteht darin, die Benutzerauthentifizierung mit einem RFID-Modul durchzuführen.
Wenn die Authentifizierung erfolgreich ist, steuert er einen Schrittmotor, um die Tür zu öffnen, und gibt über einen Summer einen Ton aus, um das Ergebnis der Authentifizierung anzuzeigen.
Scheitert die Authentifizierung, wird die Tür nicht geöffnet.

Sie können den seriellen Monitor öffnen, um die ID Ihrer RFID-Karte zu sehen und das Passwort in diesem Code neu zu konfigurieren.

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
    *   - :ref:`cpn_mfrc522`
        - |link_mfrc522_rfid_buy|
    *   - :ref:`cpn_stepper_motor`
        - |link_stepper_motor_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_power`
        - \-


**Verdrahtung**

.. image:: img/09_access_bb.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Schaltplan**

.. image:: img/09_access_schematic.png
    :width: 100%
    :align: center

.. raw:: html

   <br/>

**Code**

.. note::

    * Sie können die Datei ``09_access_control_system.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\fun_project09_access_control_system`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note::

    * Hier wird die ``RFID1``-Bibliothek verwendet. Die Bibliothek finden Sie im Verzeichnis ``elite-explorer-kit-main/library/``, oder Sie können hier :download:`RFID1.zip </_static/RFID1.zip>` klicken, um sie herunterzuladen. Sehen Sie sich :ref:`manual_install_lib` für eine Anleitung zur Installation an.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/3486dd4e-a76e-478f-b5a4-a86281f7f374/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Wie funktioniert des?**

Hier ist eine schrittweise Erklärung des Codes:

1. **Bibliotheksdateien einbinden**: Sie haben drei Bibliotheksdateien eingebunden: ``rfid1.h``, ``Stepper.h`` und ``Wire.h``. Diese Bibliotheken werden verwendet, um mit dem RFID-Modul, dem Schrittmotor und für die I2C-Kommunikation zu kommunizieren.

2. **Konstantendefinitionen**: Sie haben einige Konstanten definiert, darunter ``ID_LEN`` (Länge der ID), ``stepsPerRevolution`` (Schritte pro Umdrehung für den Schrittmotor), ``rolePerMinute`` (Geschwindigkeit des Schrittmotors), sowie die vier Schrittmotorpins (IN1, IN2, IN3, IN4), Buzzerpin (``buzPin``) und Variablen im Zusammenhang mit der Authentifizierung.

3. **Variablendefinitionen**: Sie haben Variablen wie ein Array definiert, um die gelesene Benutzer-ID (``userIdRead``), authentifizierte Benutzer-ID (``userId``) und eine boolesche Variable (``approved``) zur Anzeige einer erfolgreichen Authentifizierung zu speichern.

4. **Objektinstanzen**: Sie haben Instanzen von zwei Objekten erstellt: ``RFID1 rfid`` und ``Stepper stepper`` zur Interaktion mit dem RFID-Modul und Schrittmotor.

5. ``setup()``: In der Funktion ``setup()`` initialisieren Sie die Geschwindigkeit des Schrittmotors, stellen den Buzzerpin als Ausgang ein und initialisieren das RFID-Modul.

6. ``loop()``: In der Funktion ``loop()`` läuft Ihre Hauptlogik. Wenn ``approved`` 0 ist (noch nicht authentifiziert), ruft es die Funktion ``rfidRead()`` auf, um Daten vom RFID-Modul zu lesen und löscht dann das Array ``userIdRead``. Wenn ``approved`` 1 ist (erfolgreiche Authentifizierung), ruft es die Funktion ``openDoor()`` auf, um die Tür zu öffnen, und setzt ``approved`` auf 0 zurück.

7. ``beep()``: Diese Funktion steuert den Summer basierend auf den bereitgestellten Parametern ``duration`` und ``frequency``.

8. ``verifyPrint()``: Diese Funktion erzeugt unterschiedliche Summergeräusche basierend auf dem Parameter ``result``, um anzuzeigen, ob die Authentifizierung erfolgreich war.

9. ``openDoor()``: Diese Funktion steuert den Schrittmotor, um die Tür bis zu einem bestimmten Winkel (``doorStep``) zu öffnen und wartet dann eine Weile, bevor die Tür geschlossen wird.

10. ``rfidRead()``: Diese Funktion liest Daten vom RFID-Modul, ruft zuerst ``getId()`` auf, um die Benutzer-ID zu erhalten, und dann ``idVerify()``, um zu überprüfen, ob die Benutzer-ID mit der authentifizierten ID übereinstimmt.

11. ``getId()``: Diese Funktion holt die Benutzer-ID vom RFID-Modul und speichert sie im Array ``userIdRead``. Sie gibt einen Piepton aus, wenn das Lesen fehlschlägt.

12. ``idVerify()``: Diese Funktion überprüft, ob die Benutzer-ID mit der authentifizierten ID übereinstimmt, und erzeugt einen Ton, der eine erfolgreiche oder fehlgeschlagene Authentifizierung anzeigt.

