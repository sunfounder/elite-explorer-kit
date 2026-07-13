.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _new_dac:

Digital-Analog-Wandler (DAC)
========================================

Das Arduino Uno R4 WiFi ist mit einem integrierten DAC (Digital-Analog-Wandler) ausgestattet. Ein DAC ist entscheidend für die Umwandlung digitaler Signale in ihre analogen Gegenstücke, eine Funktionalität, die besonders wichtig in Anwendungen wie der Audiobearbeitung, der Erzeugung analoger Signale und anderen Szenarien ist, die präzise analoge Ausgaben erfordern.

Der DAC auf dem Uno R4 WiFi bietet eine Auflösung von bis zu 12 Bit und liefert echte analoge Ausgabefähigkeiten, die die Leistung von PWM-Pins übertreffen.

.. image:: img/07_dac.png
  :width: 70%

Musik mit DAC abspielen
+++++++++++++++++++++++++++

**Schaltplan**

.. image:: img/07_dac_bb.png
  :width: 100%
  :align: center

**Code Hochladen**

Öffnen Sie die Datei ``07-dac.ino``, die sich unter ``elite-explorer-kit-main\r4_new_feature\07-dac`` befindet, oder fügen Sie den folgenden Code in Ihre Arduino IDE ein.

.. note:: 
    Bitte platzieren Sie die Datei ``pitches.h`` im selben Verzeichnis wie den Code, um eine ordnungsgemäße Funktion zu gewährleisten.

.. literalinclude:: /_code/pitches.h
   :language: cpp
   :caption: pitches.h

.. literalinclude:: /_code/07_dac.ino
   :language: cpp
   :linenos:
   :caption: 07-dac.ino

Dieses Projekt nutzt das Arduino und den DAC (Digital-Analog-Wandler), um die ikonische Melodie von Super Mario Bros zu spielen. Es verwendet eine Bibliothek namens ``analogWave`` zur Erzeugung von Sinuswellen und eine weitere Bibliothek, ``pitches.h``, zur Definition der Notenfrequenzen.

- ``melody[]``: Dieses Array enthält die zu spielenden Noten zusammen mit ihren Dauern. Noten werden durch vordefinierte Töne (z.B. ``NOTE_E5``) dargestellt, und Dauern werden in Form von Schlägen repräsentiert (z.B. 4 für eine Viertelnote). Sie können versuchen, Ihre eigene Melodie zu komponieren, indem Sie die Noten und Dauern im Array melody[] ändern. Wenn Sie interessiert sind, gibt es ein Repository auf GitHub (|link_arduino_songs|), das Arduino-Code für verschiedene Lieder bereitstellt. Obwohl deren Ansatz von diesem Projekt abweichen mag, können Sie sich an ihren Noten und Dauern orientieren. (Ersetzen Sie einfach das ``melody[]`` im entsprechenden Track durch den Code in diesem Projekt.)

- ``tempo`` : Das Tempo für dieses Projekt ist auf 200 BPM (Beats Per Minute) eingestellt, das zur Berechnung der Dauer jeder Note verwendet wird. Die Änderung dieses Werts verändert die Geschwindigkeit der Songaufführung.

- **Sinuswellengenerator**: Die Funktion ``sine`` der Bibliothek ``analogWave`` initialisiert einen 10 Hz Sinuswellengenerator, der zur Ausgabe der Noten über den DAC verwendet wird.

- **Notendauer**: Basierend auf dem eingestellten Tempo und der Schlagzahl für jede Note wird die Dauer jeder Note berechnet.

- **Spielen und Pause**: Jede Note wird für 85% ihrer berechneten Dauer gespielt, gefolgt von einer 15% Pause, um zwischen den Noten zu unterscheiden.

- **Schleife**: Nachdem die Melodie abgespielt wurde, setzt der Code automatisch zurück und beginnt erneut zu spielen.

Dies ist ein Beispiel, das demonstriert, wie man Arduino und externe Hardware (DAC) zur Musikgenerierung verwendet. Es zeigt auch, wie man Arrays und Schleifen verwendet, um die Logik der Musikwiedergabe zu vereinfachen.


**Referenz**

- |link_r4_dac|
