.. _cpn_servo:

Servomotor
===========

.. image:: img/servo.png
    :align: center

Ein Servomotor besteht im Allgemeinen aus den folgenden Teilen: Gehäuse, Welle, Getriebesystem, Potentiometer, Gleichstrommotor und eingebettetes Board.

So funktioniert es: Der Mikrocontroller sendet PWM-Signale an den Servo, und dann empfängt das eingebettete Board im Servo die Signale über den Signaleingang und steuert den Motor im Inneren zur Drehung. Infolgedessen treibt der Motor das Getriebesystem an und motiviert dann die Welle nach der Verzögerung. Die Welle und das Potentiometer des Servos sind miteinander verbunden. Wenn sich die Welle dreht, treibt sie das Potentiometer an, sodass das Potentiometer ein Spannungssignal an das eingebettete Board ausgibt. Dann bestimmt das Board die Drehrichtung und -geschwindigkeit basierend auf der aktuellen Position, sodass es genau an der definierten Position stoppen und dort halten kann.

.. image:: img/servo_internal.png
    :align: center

Der Winkel wird durch die Dauer eines Impulses bestimmt, der auf den Steuerdraht aufgebracht wird. Dies wird als Pulsbreitenmodulation bezeichnet. Der Servo erwartet alle 20 ms einen Impuls. Die Länge des Impulses bestimmt, wie weit der Motor dreht. Zum Beispiel bewirkt ein 1,5 ms langer Impuls, dass der Motor in die 90-Grad-Position (Neutrale Position) dreht.
Wenn ein Impuls an einen Servo gesendet wird, der kürzer als 1,5 ms ist, dreht sich der Servo in eine Position und hält seine Ausgangswelle um eine bestimmte Anzahl von Grad gegen den Uhrzeigersinn vom Neutralpunkt. Wenn der Impuls breiter als 1,5 ms ist, tritt das Gegenteil ein. Die minimale Breite und die maximale Breite des Impulses, der den Servo anweist, sich in eine gültige Position zu drehen, sind Funktionen jedes Servos. Im Allgemeinen wird der minimale Impuls etwa 0,5 ms breit und der maximale Impuls 2,5 ms breit sein.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Beispiel**

* :ref:`basic_servo` (Grundprojekt)
* :ref:`fun_smart_can` (Spaßprojekt)

