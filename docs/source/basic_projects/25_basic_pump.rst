.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_pump:

Wasserpumpe
==========================

Überblick
---------------

Die Wasserpumpe ist auch ein Motor, der die mechanische Energie des Motors oder anderer externer Energie durch eine spezielle Struktur umwandelt, um die Flüssigkeit zu transportieren.



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
    *   - :ref:`cpn_pump`
        - 
    *   - :ref:`cpn_ta6586`
        - \-
    *   - :ref:`cpn_power`
        - \-



Verdrahtung
----------------------

.. image:: img/25-pump_bb.png
    :align: center
    :width: 80%

.. raw:: html
  
  <br/> 


Schaltplan
-----------------------

.. image:: img/25_pump_schematic.png


Code
---------------

.. note::

   * Sie können die Datei ``25-pump.ino`` direkt im Pfad ``elite-explorer-kit-main\basic_project\25-pump`` öffnen.
   * Oder kopieren Sie diesen Code in die **Arduino IDE**.

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/8a530528-aa58-4306-acc9-01632ae5e99a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Befestigen Sie den Schlauch an der Pumpe und positionieren Sie sie im Becken. Sobald der Code erfolgreich hochgeladen wurde, schaltet sich die Wasserpumpe ein und bleibt fünf Sekunden lang aktiv.
Bitte achten Sie bei diesem Experiment darauf, dass der Stromkreis vom Wasser ferngehalten wird, um mögliche Kurzschlüsse zu vermeiden.


Code-Analyse
--------------------------

Der Motor kann betrieben werden, indem man eine Spannungsdifferenz zwischen den Kupferplatten auf beiden Seiten des Motors herstellt.

.. code-block:: arduino
    
   digitalWrite(motorBI, HIGH);
   digitalWrite(motorFI, LOW);
