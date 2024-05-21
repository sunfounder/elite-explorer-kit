.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_potentiometer:

Potentiometer
===============

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Ein Potentiometer ist ebenfalls eine Widerstandskomponente mit 3 Anschlüssen, und sein Widerstandswert kann gemäß einer regelmäßigen Variation eingestellt werden.

Potentiometer gibt es in verschiedenen Formen, Größen und Werten, aber sie haben alle folgende Gemeinsamkeiten:

* Sie haben drei Anschlüsse (oder Verbindungspunkte).
* Sie haben einen Knopf, eine Schraube oder einen Schieber, der bewegt werden kann, um den Widerstand zwischen dem mittleren Anschluss und einem der beiden äußeren Anschlüsse zu variieren.
* Der Widerstand zwischen dem mittleren Anschluss und einem der beiden äußeren Anschlüsse variiert von 0 Ω bis zum maximalen Widerstand des Potentiometers, wenn der Knopf, die Schraube oder der Schieber bewegt wird.

Hier ist das Schaltungssymbol eines Potentiometers.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400


Die Funktionen des Potentiometers im Schaltkreis sind wie folgt:

#. Dient als Spannungsteiler

    Ein Potentiometer ist ein kontinuierlich einstellbarer Widerstand. Wenn Sie die Welle oder den Schiebegriff des Potentiometers einstellen, wird der bewegliche Kontakt auf dem Widerstand gleiten. In diesem Moment kann eine Spannung ausgegeben werden, abhängig von der Spannung, die an das Potentiometer angelegt wird, und dem Winkel, den der bewegliche Arm gedreht hat, oder dem Weg, den er zurückgelegt hat.

#. Dient als Rheostat

    Wenn das Potentiometer als Rheostat verwendet wird, verbinden Sie den mittleren Pin und einen der anderen 2 Pins im Schaltkreis. So können Sie einen stufenlos und kontinuierlich veränderten Widerstandswert innerhalb des Weges des beweglichen Kontakts erhalten.

#. Dient als Stromregler

    Wenn das Potentiometer als Stromregler wirkt, muss der Schiebekontaktanschluss als einer der Ausgangsanschlüsse verbunden werden.

Wenn Sie mehr über Potentiometer erfahren möchten, siehe: |link_potentiometer_wiki|.

**Beispiel**

* :ref:`basic_potentiometer` (Grundprojekt)
* :ref:`fun_hue` (Spaßprojekt)

