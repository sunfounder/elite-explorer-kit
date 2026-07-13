.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Einfacher Webserver
===========================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/new_feature_projects/wifi.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Dieses einfache Arduino-Programm dient dazu, einen grundlegenden WiFi-Webserver zu erstellen. Benutzer können damit den Ein- und Ausschaltzustand einer LED auf dem Arduino-Board über einen Webbrowser steuern.

**Ausführen des Codes**

.. note::

    * Die Datei ``01_simple_webserver.ino`` können Sie direkt unter dem Pfad ``elite-explorer-kit-main\iot_project\01_simple_webserver`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note::
    Im Code werden SSID und Passwort in ``arduino_secrets.h`` gespeichert. Bevor Sie dieses Beispiel hochladen, müssen Sie diese mit Ihren eigenen WiFi-Anmeldedaten ändern. Zusätzlich sollten Sie diese Informationen geheim halten, wenn Sie den Code teilen oder speichern, um Sicherheitsgründe zu gewährleisten.

.. literalinclude:: /_code/01_iot_webserver_secrets.h
   :language: cpp
   :caption: arduino_secrets.h

.. literalinclude:: /_code/01_iot_webserver.ino
   :language: cpp
   :linenos:
   :caption: 01_simple_webserver.ino


Nach dem Hochladen des Codes können Sie die IP-Adresse im seriellen Monitor sehen. Geben Sie diese IP-Adresse in Ihren Webbrowser ein, um die LED an Bord ein-/auszuschalten.

.. image:: img/01_webserver.png

**Wie funktioniert des?**

Hier ist eine Erklärung des Codes:

1. Header-Dateien und globale Variablen:

   * ``#include "WiFiS3.h"``: Diese beinhaltet die WiFi-Bibliothek für das Verbinden und Verwalten von WiFi. Diese Bibliothek ist im Arduino UNO R4 Core enthalten, eine zusätzliche Installation ist nicht erforderlich.
   * ``#include "arduino_secrets.h"``: Diese beinhaltet sensible WiFi-Verbindungsdaten wie SSID und Passwort.
   * ``ssid``, ``pass``, ``keyIndex``: Dies sind die Netzwerkanmeldeinformationen für die WiFi-Verbindung.
   * ``led``, ``status``, ``server``: Diese definieren den LED-Pin, den WiFi-Status und das Webserver-Objekt.

2. ``setup()``:

   * Beginnen Sie mit der seriellen Kommunikation.
   * Überprüfen Sie das Vorhandensein des WiFi-Moduls.
   * Überprüfen Sie, ob die Firmware-Version des WiFi-Moduls aktuell ist.
   * Versuchen Sie, sich mit dem WiFi-Netzwerk zu verbinden.
   * Starten Sie den Webserver.
   * Drucken Sie den WiFi-Status aus.

3. ``loop()``:

   * Überprüfen Sie auf neue Webclient-Verbindungen.
   * Wenn es Client-Verbindungen gibt, lesen Sie deren eingehende HTTP-Anfragen.
   * Basierend auf den Anfragen können Sie den Ein-/Ausschaltzustand der LED steuern. Wenn beispielsweise die Anfrage „GET /H“ lautet, wird die LED eingeschaltet; bei „GET /L“ wird sie ausgeschaltet.
   * Senden Sie eine HTTP-Antwort, um den Benutzer anzuleiten, wie er die LED steuern kann.
   * Trennen Sie die Verbindung zum Client.

4. ``printWifiStatus()``:

   * Drucken Sie die verbundene WiFi-SSID aus.
   * Drucken Sie die IP-Adresse des Arduino-Boards aus.
   * Drucken Sie die empfangene Signalstärke aus.
   * Erklären Sie, wie man diese Seite in einem Webbrowser ansehen kann.

