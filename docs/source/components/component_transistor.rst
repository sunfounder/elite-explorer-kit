.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_transistor:

Transistor
============

.. image:: img/npn_pnp.png
    :width: 300

Ein Transistor ist ein Halbleitergerät, das den Strom durch Strom steuert. Seine Funktion besteht darin, schwache Signale in Signale mit größerer Amplitude zu verstärken und wird auch als kontaktloser Schalter verwendet.

Ein Transistor ist eine dreischichtige Struktur, die aus P-Typ- und N-Typ-Halbleitern besteht. Diese bilden intern drei Regionen. Die dünnere in der Mitte ist die Basisregion; die anderen beiden sind entweder N-Typ oder P-Typ – die kleinere Region mit intensiven Majoritätsträgern ist die Emitterregion, während die andere die Kollektorregion ist. Diese Zusammensetzung ermöglicht es dem Transistor, als Verstärker zu fungieren.
Aus diesen drei Regionen entstehen jeweils drei Pole, die Basis (b), Emitter (e) und Kollektor (c) genannt werden. Sie bilden zwei P-N-Übergänge, nämlich den Emitterübergang und den Kollektorübergang. Die Richtung des Pfeils im Transistorschaltungssymbol gibt die des Emitterübergangs an.

* `P-N-Übergang – Wikipedia <https://en.wikipedia.org/wiki/P-n_junction>`_

Basierend auf dem Halbleitertyp können Transistoren in zwei Gruppen eingeteilt werden, die NPN- und PNP-Typen. Aus der Abkürzung können wir entnehmen, dass die ersteren aus zwei N-Typ-Halbleitern und einem P-Typ bestehen und dass die letzteren das Gegenteil sind. Siehe die Abbildung unten.

.. note::
    Der s8550 ist ein PNP-Transistor und der s8050 ist der NPN-Typ. Sie sehen sehr ähnlich aus, und wir müssen sorgfältig prüfen, um ihre Etiketten zu sehen.


.. image:: img/transistor_symbol.png
    :width: 600

Wenn ein High-Level-Signal durch einen NPN-Transistor fließt, wird er aktiviert. Ein PNP-Typ benötigt jedoch ein Low-Level-Signal zur Steuerung. Beide Transistortypen werden häufig für kontaktlose Schalter verwendet, wie in diesem Experiment.

Stellen Sie den Transistor mit der Etikettenseite zu uns und den Pins nach unten. Die Pins von links nach rechts sind Emitter(e), Basis(b) und Kollektor(c).

.. image:: img/ebc.png
    :width: 150


* |link_s8050_datasheet|
* |link_s8550_datasheet|

**Beispiel**

* :ref:`basic_relay` (Grundprojekt)
* :ref:`basic_active_buzzer` (Grundprojekt)
* :ref:`basic_passive_buzzer` (Grundprojekt)

