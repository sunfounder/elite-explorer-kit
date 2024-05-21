.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_audio_speaker:

Audio-Modul und Lautsprecher
================================

**Audioverstärker-Modul**

.. image:: img/audio_module.jpg
    :width: 500
    :align: center

Das Audioverstärker-Modul enthält einen HXJ8002-Audioleistungsverstärker-Chip. Dieser Chip ist ein Leistungsverstärker mit niedriger Stromversorgung, der 3W durchschnittliche Audioleistung für eine 3Ω BTL-Last mit geringer harmonischer Verzerrung (unter 10% Schwellenverzerrung bei 1KHz) von einer 5V DC-Stromquelle liefern kann. Dieser Chip kann Audiosignale ohne Kopplungskondensatoren oder Bootstrap-Kondensatoren verstärken.

Das Modul kann mit einer 2,0V bis 5,5V DC Stromquelle mit 10mA Betriebsstrom (0,6uA für typischen Standby-Strom) betrieben werden und erzeugt einen kraftvollen verstärkten Klang in einen 3Ω, 4Ω oder 8Ω Impedanzlautsprecher. Dieses Modul verfügt über eine verbesserte Pop- und Klickschaltung zur deutlichen Reduzierung des Übergangsgeräusches beim Ein- und Ausschalten. Die kleine Größe neben hoher Effizienz und niedriger Stromversorgung machen es weit verbreitet in tragbaren und batteriebetriebenen Projekten und Mikrocontrollern einsetzbar.


* **IC**: HXJ8002
* **Eingangsspannung**: 2V ~ 5.5V
* **Standby-Modus Strom**: 0.6uA (typischer Wert)
* **Ausgangsleistung**: 3W (3Ω Last), 2.5W (4Ω Last), 1.5W (8Ω Last)
* **Ausgangslautsprecherimpedanz**: 3Ω, 4Ω, 8Ω
* **Größe**: 19.8mm x 14.2mm

**Lautsprecher**

.. image:: img/speaker_pic.png
    :width: 300
    :align: center

* **Größe**: 20x30x7mm
* **Impedanz**: 8ohm
* **Nennleistung**: 1.5W
* **Maximale Eingangsleistung**: 2.0W
* **Kabellänge**: 10cm

.. image:: img/2030_speaker.png

Die Größentabelle ist wie folgt:

* :download:`2030 Lautsprecher-Datenblatt <https://github.com/sunfounder/sf-pdf/raw/master/datasheet/2030-speaker-datasheet.pdf>`


**Beispiel**

* :ref:`basic_audio_speaker` (Grundprojekt)
* :ref:`fun_welcome` (Spaßprojekt)
* :ref:`fun_fruit_piano` (Spaßprojekt)
* :ref:`new_dac`

