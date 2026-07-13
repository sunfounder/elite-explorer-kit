.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _basic_moisture:

Bodenfeuchtigkeit
==========================

.. https://docs.sunfounder.com/projects/3in1-kit-r4/en/latest/basic_project/ar_moisture.html

Übersicht
---------------

In der Landwirtschaft können Pflanzen anorganische Elemente nicht direkt aus dem Boden aufnehmen. Stattdessen dient das im Boden vorhandene Wasser als Lösungsmittel, um diese Elemente aufzulösen.

Pflanzen absorbieren Feuchtigkeit aus dem Boden durch ihr Wurzelsystem, um Nährstoffe aufzunehmen und das Wachstum zu fördern.

Während des Wachstums und der Entwicklung von Kulturen gibt es unterschiedliche Anforderungen an die Bodentemperatur. Daher ist die Verwendung eines Bodenfeuchtigkeitssensors notwendig.

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
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

Verdrahtung
----------------------

.. image:: img/03-soil_moisture_bb.png
    :align: center
    :width: 80%

Schaltplan
-----------------------

.. image:: img/03_moisture_schematic.webp
    :align: center
    :width: 70%

Code
---------------

.. note::

    * Öffnen Sie die Datei ``03-moisture.ino`` unter dem Pfad ``elite-explorer-kit-main\basic_project\03-moisture``.
    * Oder kopieren Sie diesen Code in die **Arduino IDE**.
    
.. literalinclude:: /_code/03_basic_moisture.ino
   :language: cpp
   :linenos:
   :caption: 03-moisture.ino
    
Sobald der Code erfolgreich hochgeladen wurde, zeigt der serielle Monitor den Wert der Bodenfeuchtigkeit an.

Durch Einführen des Moduls in den Boden und Bewässerung desselben wird der Wert des Bodenfeuchtigkeitssensors kleiner.
