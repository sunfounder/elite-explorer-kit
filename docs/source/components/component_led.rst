.. _cpn_led:

LED
==========

.. image:: img/LED.png
    :width: 400

Die Halbleiter-Leuchtdiode ist eine Art von Bauteil, das elektrische Energie durch PN-Übergänge in Lichtenergie umwandeln kann. Nach der Wellenlänge kann sie in Laserdiode, Infrarot-Leuchtdiode und sichtbare Leuchtdiode eingeteilt werden, die üblicherweise als Leuchtdiode (LED) bekannt ist.
                    
Die Diode hat eine unidirektionale Leitfähigkeit, sodass der Stromfluss so erfolgt, wie der Pfeil im Schaltungssymbol der Abbildung anzeigt. Sie können nur die Anode mit positiver Energie und die Kathode mit negativer versorgen. So leuchtet die LED auf.

.. image:: img/led_symbol.png

Eine LED hat zwei Pins. Der längere ist die Anode und der kürzere die Kathode. Achten Sie darauf, sie nicht verkehrt herum anzuschließen. In der LED gibt es einen festen Vorwärtsspannungsabfall, daher kann sie nicht direkt mit dem Stromkreis verbunden werden, da die Versorgungsspannung diesen Abfall übertreffen und die LED verbrennen lassen kann. Die Vorwärtsspannung der roten, gelben und grünen LED beträgt 1,8 V und die der weißen 2,6 V. Die meisten LEDs können einen maximalen Strom von 20 mA aushalten, daher müssen wir einen Strombegrenzungswiderstand in Reihe schalten.

Die Formel für den Widerstandswert lautet wie folgt:

    R = (Vsupply – VD)/I

**R** steht für den Widerstandswert des Strombegrenzungswiderstands, **Vsupply** für die Versorgungsspannung, **VD** für den Spannungsabfall und **I** für den Arbeitsstrom der LED.

Hier ist die detaillierte Einführung für die LED: |link_led_wiki|.

**Beispiel**

* :ref:`basic_led` (Grundprojekt)
* :ref:`basic_relay` (Grundprojekt)
* :ref:`fun_light_array` (Spaßprojekt)
* :ref:`fun_smart_fan` (Spaßprojekt)

