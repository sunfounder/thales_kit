Servo
==========

Servo is a position (angle) servo device, which is suitable for those control systems that require constant angle changes and can be maintained. It has been widely used in high-end remote control toys, such as airplanes, submarine models, and remote control robots.

Now, try to make the servo sway!

Wring
---------

.. image:: ../img/wiring_swing_servo.png

1. Press the Servo Arm into the Servo output shaft. If necessary, fix it with screws.
#. Connect **VBUS** (not 3V3) and GND of Pico to the power bus of the breadboard.
#. Connect the red lead of the servo to the positive power bus with a jumper.
#. Connect the yellow lead of the servo to the GP15 pin with a jumper wire.
#. Connect the brawn lead of the servo to the negative power bus with a jumper wire.


Code
-------

After clicking Start in the upper left corner, the code starts to run. we can see the Servo Arm swinging back and forth from 0° to 180°.

.. image:: img/servo.png
    :width: 300

* [servo pin (15) set angle to (180)] Rotate the servo connected to the current ping port (ping 15) by 180 degrees.
* [servo pin (15) set angle to (0)] Let the servo connected to the current ping port (ping 15) rotate back to the initial position.   
