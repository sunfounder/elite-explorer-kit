.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_motor:

Gleichstrommotor
===================

.. image:: img/motor.jpeg
    :align: center

Dies ist ein 3V Gleichstrommotor. Wenn Sie an jeden der 2 Anschlüsse ein hohes und ein niedriges Niveau anlegen, wird er sich drehen.

* **Länge**: 25mm
* **Durchmesser**: 21mm
* **Wellendurchmesser**: 2mm
* **Wellenlänge**: 8mm
* **Spannung**: 3-6V
* **Strom**: 0,35-0,4A
* **Geschwindigkeit bei 3V**: 19000 U/min (Umdrehungen pro Minute)
* **Gewicht**: Ungefähr 14g (für eine Einheit)

Ein Gleichstrommotor ist ein kontinuierlicher Aktuator, der elektrische Energie in mechanische Energie umwandelt. Gleichstrommotoren sorgen dafür, dass rotierende Pumpen, Ventilatoren, Kompressoren, Impeller und andere Geräte durch kontinuierliche Winkelrotation funktionieren.

Ein Gleichstrommotor besteht aus zwei Teilen, dem festen Teil des Motors, der als **Stator** bezeichnet wird, und dem inneren Teil des Motors, der als **Rotor** (oder **Anker** eines Gleichstrommotors) bezeichnet wird und sich dreht, um Bewegung zu erzeugen.
Der Schlüssel zur Erzeugung von Bewegung ist es, den Anker innerhalb des Magnetfeldes des Permanentmagneten zu positionieren (dessen Feld sich vom Nordpol zum Südpol erstreckt). Die Wechselwirkung des Magnetfeldes und der bewegten geladenen Partikel (der stromführende Draht erzeugt das Magnetfeld) erzeugt das Drehmoment, das den Anker dreht.

.. image:: img/motor_sche.png
    :align: center

Der Strom fließt vom positiven Pol der Batterie durch den Schaltkreis, über die Kupferbürsten zum Kommutator und dann zum Anker.
Aber wegen der zwei Lücken im Kommutator kehrt dieser Fluss auf halbem Weg jeder vollständigen Drehung um.
Diese kontinuierliche Umkehr wandelt die Gleichstromleistung der Batterie im Wesentlichen in Wechselstrom um, wodurch der Anker das Drehmoment in der richtigen Richtung zur richtigen Zeit erfährt, um die Rotation aufrechtzuerhalten.

**Beispiel**

* :ref:`basic_motor` (Grundprojekt)
* :ref:`fun_smart_fan` (Spaßprojekt)
