.. _cpn_motor:

DC Motor
===================

.. image:: img/motor.jpeg
    :align: center

This is a 3V DC motor. When you give a high level and a low level to each of the 2 terminals, it will rotate.

* **Length**: 25mm
* **Diameter**: 21mm
* **Shaft Diameter**: 2mm
* **Shaft Length**: 8mm
* **Voltage**: 3-6V
* **Current**: 0.35-0.4A
* **Speed at 3V**: 19000 RPM (Rotations Per Minute)
* **Weight**: Approximately 14g (for one unit)

Direct current (DC) motor is a continuous actuator that converts electrical energy into mechanical energy. DC motors make rotary pumps, fans, compressors, impellers, and other devices work by producing continuous angular rotation.

A DC motor consists of two parts, the fixed part of the motor called the **stator** and the internal part of the motor called the **rotor** (or **armature** of a DC motor) that rotates to produce motion.
The key to generating motion is to position the armature within the magnetic field of the permanent magnet (whose field extends from the north pole to the south pole). The interaction of the magnetic field and the moving charged particles (the current-carrying wire generates the magnetic field) produces the torque that rotates the armature.

.. image:: img/motor_sche.png
    :align: center

Current flows from the positive terminal of the battery through the circuit, through the copper brushes to the commutator, and then to the armature.
But because of the two gaps in the commutator, this flow reverses halfway through each complete rotation.
This continuous reversal essentially converts the DC power from the battery to AC, allowing the armature to experience torque in the right direction at the right time to maintain rotation.

**Example**

* :ref:`basic_motor` (Basic Project)
* :ref:`fun_smart_fan` (Fun Project)