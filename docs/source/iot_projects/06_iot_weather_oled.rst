.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _iot_weathertime_screen:

WeatherTime Bildschirm
===============================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/06_iot_weather_oled.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Dieser Sketch verbindet sich mit einem WLAN-Netzwerk, holt jede Minute Wetterdaten von OpenWeatherMap ab, holt die aktuelle Zeit von einem NTP-Server und zeigt den Tag, die Zeit und die Wetterinformationen auf einem OLED-Bildschirm an.

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`uno_r4_wifi`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_oled`
        - |link_oled_buy|

**Verdrahtung**

.. image:: img/06_weather_oled_bb.png
    :width: 100%
    :align: center

**Schaltplan**

.. image:: img/06_weather_oled_schematic.png
    :width: 60%
    :align: center

**OpenWeather**

OpenWeather API-Schlüssel erhalten

.. .|link_openweather| ist ein Online-Dienst von OpenWeather Ltd, der weltweite Wetterdaten über eine API bereitstellt, einschließlich aktueller Wetterdaten, Prognosen, Nowcasts und historischer Wetterdaten für jeden geografischen Standort.

`OpenWeather <https://openweathermap.org/>`_ ist ein Online-Dienst von OpenWeather Ltd, der weltweite Wetterdaten über eine API bereitstellt, einschließlich aktueller Wetterdaten, Prognosen, Nowcasts und historischer Wetterdaten für jeden geografischen Standort.


#. Besuchen Sie OpenWeather, um sich anzumelden/ein Konto zu erstellen.

   .. image:: img/06_owm_1.png


#. Klicken Sie in der Navigationsleiste auf die API-Seite.

   .. image:: img/06_owm_2.png


#. Finden Sie **Current Weather Data** und klicken Sie auf Abonnieren.

   .. image:: img/06_owm_3.png


#. Unter **Current weather and forecasts collection** abonnieren Sie den entsprechenden Dienst. In unserem Projekt reicht die kostenlose Version aus.

   .. image:: img/06_owm_4.png


#. Kopieren Sie den Schlüssel von der Seite **API keys**.

   .. image:: img/06_owm_5.png

#. Kopieren Sie ihn in die ``arduino_secrets.h``.

   .. code-block:: Arduino

       #define SECRET_SSID "<SSID>"        // your network SSID (name)
       #define SECRET_PASS "<PASSWORD>"        // your network password 
       #define API_KEY "<OpenWeather_API_KEY>"
       #define LOCATION "<YOUR CITY>"

#. Stellen Sie die Zeitzone Ihres Standorts ein.

   Nehmen Sie als Beispiel die Hauptstadt Schwedens, Stockholm. Suchen Sie auf Google nach „Stockholm Zeitzone“.

   .. image:: img/06_weather_oled_01.png 

   In den Suchergebnissen sehen Sie „GMT+1“, also setzen Sie den Parameter der untenstehenden Funktion auf ``3600 * 1`` Sekunden.
   
   .. code-block:: Arduino

      timeClient.setTimeOffset(3600 * 1);  // Adjust for your time zone (this is +1 hour)

**Bibliothek installieren**

Um die Bibliothek zu installieren, verwenden Sie den Arduino-Bibliotheksmanager und suchen Sie nach „ArduinoMqttClient“, „FastLED“, „Adafruit GFX“ und „Adafruit SSD1306“ und installieren Sie diese.

``ArduinoJson.h``: Wird verwendet, um JSON-Daten zu verarbeiten (Daten, die von openweathermap erhalten werden).

``NTPClient.h``: Wird verwendet, um die Echtzeit zu erhalten.

``Adafruit_GFX.h``, ``Adafruit_SSD1306.h``: Wird für das OLED-Modul verwendet.

**Code ausführen**


.. note::

    * Sie können die Datei ``06_weather_oled.ino`` direkt unter dem Pfad ``elite-explorer-kit-main\iot_project\06_weather_oled`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note::
    Im Code werden SSID und Passwort in ``arduino_secrets.h`` gespeichert. Bevor Sie dieses Beispiel hochladen, müssen Sie sie mit Ihren eigenen WLAN-Anmeldeinformationen ändern. Außerdem sollten Sie aus Sicherheitsgründen diese Informationen vertraulich halten, wenn Sie den Code teilen oder speichern.

.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/5f667ac1-bb24-4681-9fa1-db19fcfdd48a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



**Wie funktioniert des?**


1. Bibliotheken und Definitionen:

   #. ``WiFiS3.h``: Dies ist wahrscheinlich eine spezifische Bibliothek für ein bestimmtes WLAN-Modul oder Board zur Verwaltung von WLAN-Verbindungen.
   #. ``ArduinoJson.h``: Diese Bibliothek wird für das Dekodieren (und Kodieren) von JSON-Daten verwendet.
   #. ``arduino_secrets.h``: Eine separate Datei, in der sensible Daten (wie WLAN-Zugangsdaten) gespeichert sind. Dies ist eine gute Praxis, um Zugangsdaten aus dem Hauptcode herauszuhalten.
   #. **NTPClient & WiFiUdp**: Diese werden verwendet, um die aktuelle Zeit von einem NTP-Server (Network Time Protocol) zu holen.
   #. **Adafruit-Bibliotheken**: Verwendet für die Verwaltung des OLED-Displays.
   #. **Verschiedene globale Variablen**: Dazu gehören WLAN-Zugangsdaten, Serverdetails und mehr, die im gesamten Skript verwendet werden.

2. ``setup()``:

   #. Initialisiert die serielle Kommunikation.
   #. Überprüft und druckt die Firmware-Version des WLAN-Moduls aus.
   #. Versucht, eine Verbindung zum WLAN-Netzwerk mit der bereitgestellten SSID und dem Passwort herzustellen.
   #. Gibt den Status des verbundenen WLANs aus (SSID, IP, Signalstärke).
   #. Initialisiert das OLED-Display.
   #. Startet den NTP-Client, um die aktuelle Zeit zu holen und legt einen Zeitversatz fest (in diesem Fall 8 Stunden, was einer bestimmten Zeitzone entsprechen könnte).

3. ``read_response()``:

   #. Liest die Antwort vom Server, insbesondere auf der Suche nach JSON-Daten (gekennzeichnet durch ``{`` und ``}``).
   #. Wenn JSON-Daten gefunden werden, werden die Daten dekodiert, um Wetterdetails wie Temperatur, Feuchtigkeit, Druck, Windgeschwindigkeit und Windrichtung zu extrahieren.
   #. Ruft die Funktion ``displayWeatherData`` auf, um die Wetterinformationen auf dem OLED-Bildschirm anzuzeigen.

4. ``httpRequest()``:

   #. Schließt alle bestehenden Verbindungen, um sicherzustellen, dass der Socket des WLAN-Moduls frei ist.
   #. Versucht, eine Verbindung zum OpenWeatherMap-Server herzustellen.
   #. Wenn verbunden, sendet es eine HTTP-GET-Anfrage, um die Wetterdaten für einen spezifischen Ort zu holen, der durch ``LOCATION`` definiert wird (wahrscheinlich definiert in ``arduino_secrets.h`` oder anderswo).
   #. Zeichnet die Zeit auf, zu der die Anfrage gestellt wurde.

5. ``loop()``:

   #. Ruft die Funktion ``read_response`` auf, um alle eingehenden Daten vom Server zu verarbeiten.
   #. Aktualisiert die Zeit vom NTP-Server.
   #. Überprüft, ob es Zeit ist, eine weitere Anfrage an den Wetter-Server zu stellen (basierend auf dem ``postingInterval``). Wenn ja, ruft es die Funktion ``httpRequest`` auf.

6. ``printWifiStatus()``:

   #. Die SSID des verbundenen Netzwerks.
   #. Die lokale IP-Adresse des Boards.
   #. Die Signalstärke (RSSI).

7. ``displayWeatherData()``:

   #. Löscht den OLED-Bildschirm.
   #. Zeigt den aktuellen Wochentag an.
   #. Zeigt die aktuelle Uhrzeit im HH:MM-Format an.
   #. Zeigt die bereitgestellten Wetterdaten an (Temperatur, Feuchtigkeit, Druck und Windgeschwindigkeit).

