.. _iot_security_system_ifttt:

Sicherheitssystem über IFTTT
============================================

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../_static/videos/iot_projects/03_iot_security_alert.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

Mit diesem Projekt erstellen wir ein Sicherheitsgerät, das einen PIR-Sensor verwendet, um Eindringlinge oder streunende Tiere, die Ihr Zuhause betreten, zu erkennen. Im Falle eines Einbruchs erhalten Sie eine E-Mail-Benachrichtigung.

Wir nutzen Webhooks als grundlegenden Dienst. Eine POST-Anfrage wird von UNO R4 an den IFTTT-Dienst gesendet.

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Verdrahtung**

.. image:: img/03-ifttt_pir_bb.png
    :width: 90%
    :align: center


**Schaltplan**

.. image:: img/03-ifttt_pir_schematic.png
   :width: 50%
   :align: center

**IFTTT einrichten**

IFTTT ist ein kostenloser Dienst, der verschiedene Methoden bietet, um verschiedene Datendienste miteinander zu verknüpfen.

Erstellen wir ein Applet, das auf einen Webhook (benutzerdefinierte URL) reagiert, der Daten an IFTTT sendet, welcher Ihnen dann eine E-Mail sendet.

Bitte folgen Sie den untenstehenden Schritten auf IFTTT.

1. Besuchen Sie |link_ifttt|, um sich anzumelden oder ein Konto zu erstellen.

   .. image:: img/03_ifttt_1.png
       :width: 90%

2. Klicken Sie auf **Create**.

   .. image:: img/03_ifttt_2.png
       :width: 90%

3. Fügen Sie ein **If This** Ereignis hinzu.

   .. image:: img/03_ifttt_3.png
       :width: 70%

4. Suchen Sie nach **Webhooks**.

   .. image:: img/03_ifttt_4.png
       :width: 70%

5. Wählen Sie **Receive a web request**.

   .. image:: img/03_ifttt_5.png
       :width: 90%

6. Geben Sie den Ereignisnamen ein (z. B. SecurityWarning) und klicken Sie auf **Create trigger**.

   .. image:: img/03_ifttt_6.png
       :width: 70%

7. Fügen Sie ein **Then That** Ereignis hinzu.

   .. image:: img/03_ifttt_7.png
       :width: 70%

8. Suchen Sie nach E-Mail.

   .. image:: img/03_ifttt_8.png
       :width: 80%

9. Wählen Sie **Send me an email**.

   .. image:: img/03_ifttt_9.png
       :width: 80%

10. Geben Sie den **Subject** und den **Body** ein, dann klicken Sie auf **Create action**.

   .. image:: img/03_ifttt_10.png
       :width: 70%

11. Klicken Sie auf **Continue** um die Einrichtung abzuschließen.

   .. image:: img/03_ifttt_11.png
       :width: 70%

12. Passen Sie nach Bedarf den Titelnamen an.

   .. image:: img/03_ifttt_12.png
       :width: 80%

13. Sie werden automatisch zur Seite mit den Applet-Details weitergeleitet, wo Sie sehen können, dass das Applet derzeit verbunden ist und Sie den Schalter zum Aktivieren/Deaktivieren umlegen können.

   .. image:: img/03_ifttt_13.png
       :width: 70%

14. Nachdem wir das IFTTT-Applet erstellt haben, benötigen wir auch den Webhooks-Schlüssel, den Sie von |link_webhooks| erhalten können, damit Ihr Gerät auf IFTTT zugreifen kann.

   .. image:: img/03_ifttt_14.png

15. Kopieren Sie den Webhooks-Schlüssel in „arduino_secrets.h“ und tragen Sie Ihr SSID und Passwort ein.

    .. code-block:: arduino
    
        #define SECRET_SSID "your_ssid"        // your network SSID (name)
        #define SECRET_PASS "your_password"        // your network password (used for WPA, or as a key for WEP)
        #define WEBHOOKS_KEY "your_key"

**Den Code ausführen**

.. note::

    * Sie können die Datei ``03_ifttt_pir.ino`` direkt im Pfad ``elite-explorer-kit-main\iot_project\03_ifttt_pir`` öffnen.
    * Oder kopieren Sie diesen Code in die Arduino IDE.

.. note::
    Im Code werden SSID und Passwort in ``arduino_secrets.h`` gespeichert. Bevor Sie dieses Beispiel hochladen, müssen Sie sie mit Ihren eigenen WLAN-Anmeldeinformationen ändern. Außerdem sollten Sie aus Sicherheitsgründen diese Informationen vertraulich halten, wenn Sie den Code teilen oder speichern.

.. warning::
   Um zu verhindern, dass Ihr Postfach überflutet wird, debuggen Sie bitte den :ref:`cpn_pir` vorher, bevor Sie den Code für dieses Projekt ausführen.


.. raw:: html

   <iframe src=https://create.arduino.cc/editor/sunfounder01/adec1608-4642-4469-bdf4-8dc3e3e4ce4d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
 
**Wie funktioniert des?**

1. Einbinden der erforderlichen Bibliotheken und Header-Dateien:

   * ``"WiFiS3.h"``: Wird verwendet, um Wi-Fi-Verbindungen zu verwalten.
   * ``"arduino_secrets.h"``: Enthält den Namen und das Passwort des Wi-Fi-Netzwerks, um sensible Informationen zu schützen.

2. Definition einiger globaler Variablen und Konstanten:

   * ``ssid``: Name des Wi-Fi-Netzwerks.
   * ``pass``: Wi-Fi-Netzwerkpasswort.
   * ``status``: Status der Wi-Fi-Verbindung.
   * ``client``: Client zur Kommunikation mit dem Wi-Fi-Server.
   * ``server``: Adresse des IFTTT Webhook-Servers.
   * ``event``: Name des IFTTT Webhook-Ereignisses.
   * ``webRequestURL``: Konstruierte URL für das Senden von HTTP-Anfragen, einschließlich des Webhook-Ereignisnamens und -schlüssels.
   * ``pirPin``: Digitaler Pin, an den der PIR-Sensor angeschlossen ist.
   * ``motionDetected``: Flag-Variable zur Verfolgung der Bewegungserkennung.

3. ``setup()`` Funktion:

   * Initialisiert die serielle Kommunikation.
   * Überprüft das Vorhandensein des Wi-Fi-Moduls und gibt dessen Firmware-Version aus.
   * Versucht, eine Verbindung zum Wi-Fi-Netzwerk herzustellen, mit Wiederholungen bei Misserfolg.
   * Setzt den an den PIR-Sensor angeschlossenen Pin auf Eingabemodus.

4. ``readResponse()`` Funktion:

   * Liest HTTP-Antwortdaten vom IFTTT-Server und gibt sie auf der seriellen Konsole aus.

5. ``loop()`` Funktion:

   * Ruft die Funktion ``readResponse()`` auf, um HTTP-Antwortdaten zu lesen.
   * Überprüft die Bewegung mithilfe des PIR-Sensors. Wenn eine Bewegung erkannt wird und zuvor nicht erkannt wurde:
       * Gibt „Motion detected!“ auf der Konsole aus.
       * Ruft die Funktion ``triggerIFTTTEvent()`` auf, um eine HTTP-Anfrage an den IFTTT-Server zu senden und das Webhook-Ereignis auszulösen.
       * Setzt das Flag ``motionDetected`` auf ``true``, um anzuzeigen, dass eine Bewegung erkannt wurde.
   * Wenn keine Bewegung erkannt wird, setzt das Flag ``motionDetected`` auf ``false``.

6. ``triggerIFTTTEvent()`` Funktion:

   * Stellt eine Verbindung mit dem IFTTT-Server her.
   * Sendet eine HTTP-GET-Anfrage, einschließlich der URL des Webhook-Ereignisses und anderer HTTP-Header.

7. ``printWifiStatus()`` Funktion:

   * Gibt Informationen über das verbundene Wi-Fi-Netzwerk aus, einschließlich SSID, IP-Adresse und Signalstärke (RSSI) auf der seriellen Konsole.
