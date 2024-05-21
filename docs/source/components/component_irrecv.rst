.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_ir_receiver:

Infrarotempfänger
=================================

IR-Empfänger
----------------------------

.. image:: img/infrared-receiver_01.png
    :width: 60%

* S: Signalausgang
* +: VCC
* -: GND

.. Ein Infrarotempfänger ist eine Komponente, die Infrarotsignale empfängt und unabhängig Infrarotstrahlen empfangen und Signale ausgeben kann, die mit TTL-Pegel kompatibel sind. Er ist in der Größe ähnlich einem normalen, in Kunststoff verpackten Transistor und eignet sich für alle Arten von Infrarot-Fernbedienungen und Infrarot-Übertragungen.

SL838 ist ein kleiner Empfänger für Infrarot-Fernsteuerungssysteme. Er enthält eine schnelle und hochempfindliche Fotodiode und einen Vorverstärker und ist mit Epoxidharz verpackt, um einen Infrarotfilter zu bilden. Sein Hauptvorteil ist, dass er auch in gestörter Umgebung zuverlässig funktioniert.

Infrarot- oder IR-Kommunikation ist eine beliebte, kostengünstige und einfach zu verwendende drahtlose Kommunikationstechnologie. Infrarotlicht hat eine etwas längere Wellenlänge als sichtbares Licht, daher ist es für das menschliche Auge nicht wahrnehmbar - ideal für drahtlose Kommunikation. Ein gängiges Modulationsschema für die Infrarotkommunikation ist die 38KHz-Modulation.

* Kann für Fernbedienungen verwendet werden
* Breiter Betriebsspannungsbereich: 2,7~5V
* Interner Filter für PCM-Frequenz
* TTL- und CMOS-Kompatibilität
* Starke Störfestigkeit
* RoHS-konform

Fernbedienung
-------------------------

.. image:: img/infrared-receiver_02.jpeg
    :width: 70%

Dies ist eine Mini-Dünn-Infrarot-Fernbedienung mit 21 Funktionstasten und einer Übertragungsdistanz von bis zu 8 Metern, die sich für die Bedienung einer Vielzahl von Geräten in einem Kinderzimmer eignet.

* Größe: 85x39x6mm
* Reichweite der Fernbedienung: 8-10m
* Batterie: 3V Knopfzellen-Lithium-Mangan-Batterie
* Infrarot-Trägerfrequenz: 38KHz
* Oberflächenklebematerial: 0,125mm PET
* Effektive Lebensdauer: mehr als 20.000 Mal


**Beispiel**

* :ref:`basic_irrecv` (Grundprojekt)
* :ref:`fun_guess_number` (Spaßprojekt)
