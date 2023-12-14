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
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c585dd77-2e8a-4839-a908-d22e1d6e93aa/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Sobald der Code erfolgreich hochgeladen wurde, zeigt der serielle Monitor den Wert der Bodenfeuchtigkeit an.

Durch Einführen des Moduls in den Boden und Bewässerung desselben wird der Wert des Bodenfeuchtigkeitssensors kleiner.
