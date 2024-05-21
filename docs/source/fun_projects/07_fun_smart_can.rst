.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _fun_smart_can:

Smarter Mülleimer
=====================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/07_fun_smartcan.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Dies ist ein Arduino-Code, der entwickelt wurde, um einen intelligenten Mülleimer zu steuern.
Wenn sich ein Objekt in einem Bereich von 20 Zentimetern vor dem Mülleimer befindet, öffnet sich der Deckel automatisch.
Dieses Projekt nutzt einen SG90-Servomotor und einen HC-SR04-Ultraschall-Entfernungssensor.

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

    *   - KOMPONENTENVORSTELLUNG
        - KAUF-LINK

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**Verdrahtung**

.. image:: img/07_smart_trash_can_bb.png
    :width: 70%
    :align: center


**Schaltplan**

.. image:: img/07_smart_trash_can_schematic.png
   :width: 90%
   :align: center

**Code**

.. note::

    * Sie können die Datei ``07_smart_trash_can.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\fun_project\07_smart_trash_can`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/509f1bee-6e38-4106-bea7-9b06cdb3719f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


**Wie funktioniert des?**

Hier ist eine schrittweise Erklärung des Codes:

1. Bibliotheken importieren und Konstanten/Variablen definieren:

   Die Bibliothek ``Servo.h`` wird importiert, um den SG90-Servomotor zu steuern.
   Parameter für den Servomotor, Ultraschallsensor und andere erforderliche Konstanten und Variablen werden definiert.

2. ``setup()``:

   Initialisieren Sie die serielle Kommunikation mit dem Computer mit einer Baudrate von 9600.
   Konfigurieren Sie die Trigger- und Echopins des Ultraschallsensors.
   Befestigen Sie den Servomotor an seinem Steuerpin und setzen Sie seine Anfangsposition auf den geschlossenen Winkel. Nachdem der Winkel eingestellt wurde, wird der Servomotor abgetrennt, um Energie zu sparen.

3. ``loop()``:

   Messen Sie die Entfernung dreimal und speichern Sie die Werte jeder Messung.
   Berechnen Sie die durchschnittliche Entfernung aus den drei Messungen.
   Wenn die durchschnittliche Entfernung weniger als oder gleich 20 Zentimetern (definierter Abstandsschwellenwert) beträgt, dreht sich der Servomotor auf den offenen Winkel (0 Grad).
   Andernfalls kehrt der Servomotor nach einer einsekündigen Verzögerung in die geschlossene Position (90 Grad) zurück. Der Servomotor wird abgetrennt, wenn er nicht verwendet wird, um Energie zu sparen.

4. ``readDistance()``:

   Senden Sie einen Impuls an den Triggerpin des Ultraschallsensors.
   Messen Sie die Impulsbreite des Echopins und berechnen Sie den Entfernungswert.
   Diese Berechnung verwendet die Schallgeschwindigkeit in der Luft, um die Entfernung basierend auf der Pulsdauer zu berechnen.

