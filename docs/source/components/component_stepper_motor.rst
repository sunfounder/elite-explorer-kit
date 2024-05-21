.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _cpn_stepper_motor:

Schrittmotor
=========================

.. image:: img/stepper_motor2.jpeg
   :align: center

Schrittmotoren können aufgrund ihres einzigartigen Designs ohne Rückkopplungsmechanismen mit hoher Genauigkeit gesteuert werden. Die Welle eines Schrittmotors, die mit einer Serie von Magneten ausgestattet ist, wird von einer Serie elektromagnetischer Spulen gesteuert, die in einer bestimmten Abfolge positiv und negativ geladen sind und ihn präzise vorwärts oder rückwärts in kleinen "Schritten" bewegen.

**Prinzip**

Es gibt zwei Arten von Schrittmotoren, Unipolare und Bipolare, und es ist sehr wichtig zu wissen, mit welchem Typ man arbeitet. In diesem Experiment werden wir einen Unipolaren Schrittmotor verwenden.

Der Schrittmotor ist ein vierphasiger Motor, der eine Unipolar-Gleichstromversorgung verwendet. Solange man alle Phasenwicklungen des Motors mit einer angemessenen zeitlichen Abfolge elektrifiziert, kann man ihn schrittweise drehen lassen. Das Schaltbild eines vierphasigen reaktiven Schrittmotors:

.. image:: img/stepper_motor3.png
   :align: center

In der Abbildung, in der Mitte des Motors, ist ein Rotor - ein zahnradförmiger Permanentmagnet. Um den Rotor herum, von 0 bis 5, sind Zähne. Dann weiter außen gibt es 8 Magnetpole, wobei jeweils zwei gegenüberliegende durch Spulenwicklung verbunden sind. So bilden sie vier Paare von A bis D, was als Phase bezeichnet wird. Es hat vier Anschlussdrähte, die mit den Schaltern SA, SB, SC und SD verbunden werden. Daher sind die vier Phasen im Schaltkreis parallel und die zwei Magnetpole in einer Phase sind in Serie.

**So funktioniert ein 4-Phasen-Schrittmotor:**

Am Anfang ist Schalter SB eingeschaltet, Schalter SA, SC und SD sind ausgeschaltet, und B-Phasen-Magnetpole sind mit Zahn 0 und 3 des Rotors ausgerichtet. Gleichzeitig erzeugen Zahn 1 und 4 versetzte Zähne mit den C- und D-Phasenpolen. Zahn 2 und 5 erzeugen versetzte Zähne mit den D- und A-Phasenpolen. Wenn Schalter SC eingeschaltet ist, Schalter SB, SA und SD sind ausgeschaltet, dreht sich der Rotor unter dem Magnetfeld der C-Phasenwicklung und dem zwischen Zahn 1 und 4. Dann richten sich Zahn 1 und 4 mit den Magnetpolen der C-Phasenwicklung aus. Während Zahn 0 und 3 versetzte Zähne mit den A- und B-Phasenpolen erzeugen und Zahn 2 und 5 versetzte Zähne mit den Magnetpolen der A- und D-Phasenpolen. Die ähnliche Situation setzt sich fort. Erregen Sie die A-, B-, C- und D-Phasen der Reihe nach, und der Rotor dreht sich in der Reihenfolge A, B, C und D.

Der vierphasige Schrittmotor hat drei Betriebsmodi: Einzelschritt-Vierer-Schritt, Doppelschritt-Vierer-Schritt und Achterschritt. Der Schrittwinkel für den Einzelschritt-Vierer-Schritt und Doppelschritt-Vierer-Schritt sind gleich, aber das Antriebsmoment für den Einzelschritt-Vierer-Schritt ist kleiner. Der Schrittwinkel des Achterschritts ist halb so groß wie der des Einzelschritt-Vierer-Schritts und Doppelschritt-Vierer-Schritts. Daher kann der Achterschritt-Betriebsmodus ein hohes Antriebsmoment beibehalten und die Steuerungsgenauigkeit verbessern. In diesem Experiment lassen wir den Schrittmotor im Achterschritt-Modus arbeiten.

**ULN2003-Modul**

.. image:: img/uln2003.png
    :align: center

Um den Motor im Schaltkreis zu verwenden, muss eine Treiberplatine verwendet werden. Schrittmotor-Treiber-ULN2003 ist ein 7-Kanal-Inverterschaltkreis. Das heißt, wenn das Eingangsende auf hohem Niveau ist, ist das Ausgangsende des ULN2003 auf niedrigem Niveau und umgekehrt. Wenn wir hohes Niveau an IN1 liefern und niedriges Niveau an IN2, IN3 und IN4, dann ist das Ausgangsende OUT1 auf niedrigem Niveau und alle anderen Ausgangsenden sind auf hohem Niveau. So leuchtet D1 auf, Schalter SA ist eingeschaltet und der Schrittmotor dreht sich einen Schritt. Der ähnliche Fall wiederholt sich immer wieder. Geben Sie dem Schrittmotor also eine bestimmte zeitliche Abfolge, und er wird schrittweise rotieren. Der ULN2003 wird hier verwendet, um bestimmte zeitliche Abfolgen für den Schrittmotor bereitzustellen.


**Beispiel**

* :ref:`basic_stepper_motor` (Grundprojekt)
* :ref:`fun_access` (Spaßprojekt)
