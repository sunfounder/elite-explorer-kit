.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _new_hid:

USB HID
========================================

Das Arduino Uno R4 WiFi ist nicht nur ein leistungsfähiges Entwicklungsboard; es bietet auch eingebaute Unterstützung für Human Interface Devices (HID). Dies ermöglicht es Ihnen, das Board zur Emulation von Geräten wie Mäusen und Tastaturen zu verwenden und so Ihren Projekten eine neue Ebene der Interaktivität hinzuzufügen.

HID, oder Human Interface Devices, sind eine Kategorie von Computergeräten, die für die direkte Interaktion mit Menschen konzipiert sind, typischerweise zu Eingabezwecken. Zu dieser Kategorie gehören Geräte wie Tastaturen, Mäuse und Spielcontroller. Mit dem Arduino Uno R4 WiFi können Sie diese Geräte emulieren und so eine Vielzahl von Möglichkeiten für DIY-Projekte freischalten.

Maussteuerung
-------------------

Die Steuerung einer Maus mit dem Arduino Uno R4 WiFi ist einfach. Mit dem Befehl ``Mouse.move(x,y)`` können Sie die Mausbewegung leicht steuern. Bei der Aktualisierung der Cursorposition ist sie immer relativ zur vorherigen Position des Cursors.

Hier ist ein einfaches Beispiel, das die Steuerung des Mauszeigers mit einem Knopf demonstriert.

**Schaltplan**

.. image:: img/05_hid_1_bb.png
  :width: 70%
  :align: center

**Code Hochladen**

Öffnen Sie die Datei ``05-hid_mouse.ino``, die sich unter ``elite-explorer-kit-main\r4_new_feature\05-hid_mouse`` befindet, oder fügen Sie den folgenden Code in Ihre Arduino IDE ein.

.. warning::
    Wenn Sie den Befehl ``Mouse.move()`` verwenden, übernimmt das Arduino die Kontrolle über die Maus Ihres Computers! Um sicherzustellen, dass Sie die Kontrolle über Ihren Computer nicht verlieren, während Sie einen Sketch mit dieser Funktion ausführen, richten Sie ein zuverlässiges Steuerungssystem ein, bevor Sie ``Mouse.move()`` aufrufen. Dieser Sketch enthält einen Druckknopf, um die Maus zu aktivieren, sodass sie erst nach Betätigung des Knopfes funktioniert.

.. warning:: 
    Aufgrund der Multi-Prozessor-Architektur des UNO R4 WiFi-Boards können beim Hochladen von Code, der HID-Funktionen verwendet, Fehler wie **„No device found on...“** auftreten.
    
    Um in solchen Fällen hochzuladen, folgen Sie diesen Schritten:
    
    1. Drücken Sie schnell zweimal hintereinander die „RESET“-Taste auf dem Board. Die mit „L“ markierte LED sollte zu pulsieren beginnen.
    
    2. Wählen Sie aus dem Arduino-IDE-Menü den Port des Boards aus. Der Port kann sich nach dem Reset ändern, stellen Sie also sicher, dass er korrekt ausgewählt ist.

.. literalinclude:: /_code/05_hid_mouse.ino
   :language: cpp
   :linenos:
   :caption: 05-hid_mouse.ino

Neben der Steuerung der Mausbewegung können Sie auch Mausklicks verwalten. Für weitere Informationen siehe |link_r4_usb_mouse|.

.. _new_hid_keyboard:

Tastatursteuerung
-------------------

Das Arduino Uno R4 WiFi bietet auch Tastaturemulationsfähigkeiten. Es ermöglicht Ihnen, nicht nur einzelne Tastenanschläge zu senden, sondern auch komplexe Tastenkombinationen auszuführen.

.. warning::
   Wenn Sie den Befehl ``Keyboard.print()`` verwenden, übernimmt das Arduino die Kontrolle über die Tastatur Ihres Computers! Um sicherzustellen, dass Sie die Kontrolle über Ihren Computer nicht verlieren, während Sie einen Sketch mit dieser Funktion ausführen, richten Sie ein zuverlässiges Steuerungssystem ein, bevor Sie ``Keyboard.print()`` aufrufen. Dieser Sketch enthält einen Druckknopf, um die Tastatur zu aktivieren, sodass sie erst nach Betätigung des Knopfes funktioniert.

**Beispielcode für das Senden von Tastenkombinationen**
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

In diesem Beispiel ist das Arduino Uno R4 WiFi so konfiguriert, dass es zwei häufig verwendete Tastenkombinationen emuliert: „Strg+C“ zum Kopieren und „Strg+V“ zum Einfügen. Zwei physische Knöpfe, die mit dem Arduino verbunden sind, dienen als Auslöser. Der Knopf, der mit Pin 7 verbunden ist, initiiert die Kopieraktion, während der mit Pin 8 verbundene Knopf das Einfügen auslöst.

Bei Betätigung eines der Knöpfe verwendet das Arduino die Funktionen ``Keyboard.press()`` und ``Keyboard.releaseAll()``, um die jeweiligen Tastenkombinationen zu imitieren. Dieses Beispiel veranschaulicht, wie Sie eine dedizierte Hardware-Schnittstelle für spezifische Aufgaben entwerfen können, um repetitive Aktionen ohne Tastatureinsatz zu erleichtern. Dies könnte besonders vorteilhaft in Arbeitsumgebungen sein, die schnelle Datenmanipulation erfordern, oder in Zugänglichkeitseinrichtungen, die von vereinfachten Steuerungen profitieren.

**Schaltplan**

.. image:: img/05_hid_2_bb.png
  :width: 70%
  :align: center

**Code Hochladen**

Öffnen Sie die Datei ``05-hid_keyboard.ino``, die sich unter ``elite-explorer-kit-main\r4_new_feature\05-hid_keyboard`` befindet, oder fügen Sie den folgenden Code in Ihre Arduino IDE ein.

.. literalinclude:: /_code/05_hid_keyboard.ino
   :language: cpp
   :linenos:
   :caption: 05-hid_keyboard.ino



Vorsichtsmaßnahmen und Tipps
------------------------------

1. **Hinweis zu Maus- und Tastaturbibliotheken**: Wenn entweder die Maus- oder die Tastaturbibliothek kontinuierlich läuft, könnte dies die Programmierung Ihres Boards beeinträchtigen. Funktionen wie ``Mouse.move()`` und ``Keyboard.print()`` übernehmen die Kontrolle über Ihren angeschlossenen Computer und sollten nur aufgerufen werden, wenn Sie bereit sind, sie zu verwalten. Es wird empfohlen, ein Steuerungssystem, wie einen physischen Schalter oder spezifische Eingabesteuerungen, zu verwenden, um diese Funktionalität umzuschalten.

2. **Wenn Sie Probleme beim Hochladen des Codes haben**: Aufgrund der Multi-Prozessor-Architektur des UNO R4 WiFi-Boards können beim Hochladen von Code, der HID-Funktionalitäten verwendet, Fehler wie ``„Kein Gerät gefunden auf...“`` auftreten.

   Um unter solchen Umständen hochzuladen, folgen Sie diesen Schritten:
   
   1. Drücken Sie schnell zweimal hintereinander die „RESET“-Taste auf dem Board. Die mit „L“ markierte LED sollte zu pulsieren beginnen.
   
   2. Wählen Sie aus dem Arduino-IDE-Menü den Port des Boards aus. Der Port kann sich nach dem Reset ändern, stellen Sie also sicher, dass er korrekt ausgewählt ist.




**Referenz**

- |link_r4_usb_hid|
- |link_r4_usb_mouse|
- |link_r4_usb_keyboard|