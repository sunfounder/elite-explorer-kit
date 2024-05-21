.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _fun_light_array:

Lichtempfindliches Array
==========================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/fun_projects/04_fun_lightarray.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Dieses Programm wandelt die Messwerte eines lichtabhängigen Widerstands in eine entsprechende Anzahl beleuchteter LED-Lichter um und schafft so einen einfachen Indikator für die Helligkeit des Lichts.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|


**Verdrahtung**

.. image:: img/04_light_sensitive_array_bb.png
    :width: 70%
    :align: center

.. raw:: html

   <br/>

**Schaltplan**

.. image:: img/04_light_sensitive_array_schematic.png
   :width: 60%

**Code**

.. note::

    * Sie können die Datei ``04_light_sensitive_array.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\fun_project\04_light_sensitive_array`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/9da7af57-c002-41a0-bc84-372e91885d52/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

**Wie funktioniert das?**

Hier ist eine schrittweise Erklärung des Codes:

1. Konstanten- und Variablendefinitionen:

   ``NbrLEDs``: Definiert die Anwesenheit von 8 LEDs.
   ``ledPins[]``: LEDs sind an die Arduino-Pins 5 bis 12 angeschlossen.
   ``photocellPin``: Der Fotowiderstand ist an den A0-Pin des Arduino angeschlossen.
   ``sensorValue``: Diese Variable speichert den vom Fotowiderstand gelesenen Wert.
   ``ledLevel``: Diese Variable speichert die Anzahl der LEDs basierend auf der Umwandlung des sensorValue.

2. ``setup()``:

   Konfiguriert die Pins 5 bis 12 als Ausgang, um die LEDs anzusteuern.

3. ``loop()``:

   Liest den analogen Wert des Fotowiderstands vom Pin A0, typischerweise im Bereich von 0 bis 1023.
   Verwendet die Funktion map, um den Wert des Fotowiderstands von 300-1023 auf den Bereich 0-8 abzubilden.
   Das bedeutet, dass, wenn die Messung des lichtabhängigen Widerstands 300 beträgt, keine LEDs leuchten werden;
   wenn die Messung 1023 oder höher ist, werden alle 8 LEDs leuchten.
   
   Die nachfolgende for-Schleife überprüft jede LED. Wenn ihr Index kleiner als ledLevel ist,
   wird die LED eingeschaltet; andernfalls wird sie ausgeschaltet.

