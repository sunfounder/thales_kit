Swinging Servo
===================

In this kit, in addition to LED and passive buzzer, there is also a device controlled by PWM signal, Servo.

Servo is a position (angle) servo device, which is suitable for those control systems that require constant angle changes and can be maintained. It has been widely used in high-end remote control toys, such as airplanes, submarine models, and remote control robots.

Now, try to make the servo sway!

Wiring
-------------------------

.. image:: img/wiring_swing_servo.png

1. Press the Servo Arm into the Servo output shaft. If necessary, fix it with screws.
#. Connect **VBUS** (not 3V3) and GND of Pico to the power bus of the breadboard.
#. Connect the red lead of the servo to the positive power bus with a jumper.
#. Connect the yellow lead of the servo to the GP15 pin with a jumper wire.
#. Connect the black lead of the servo to the negative power bus with a jumper wire.


Code
--------------------

.. code-block:: python

    import machine
    import utime

    servo = machine.PWM(machine.Pin(15))
    servo.freq(50)

    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    def servo_write(pin,angle):
        pulse_width=interval_mapping(angle, 0, 180, 0.5,2.5)
        duty=int(interval_mapping(pulse_width, 0, 20, 0,65535))
        pin.duty_u16(duty)

    while True:
        for angle in range(180):
            servo_write(servo,angle)
            utime.sleep_ms(20)
        for angle in range(180,-1,-1):
            servo_write(servo,angle)
            utime.sleep_ms(20)


            When the program is running, we can see the Servo Arm swinging back and forth from 0° to 180°. The program will always run because of the ``while True`` loop, we need to press the Stop key to end the program.

How it works?
--------------------
We defined the ``servo_write()'' function to make the servo run.

This function has two parameters:

* pin, the GPIO pin that controls the servo.
* Angle, the angle of the shaft output.

In this function, ``interval_mapping()`` is called to map the angle range 0 ~ 180 to the pulse width range 0.5 ~ 2.5ms.

.. code-block:: python

    pulse_width=interval_mapping(angle, 0, 180, 0.5,2.5)

Why is it 0.5~2.5? This is determined by the working mode of the steering gear.

.. image:: img/servo1.png

It works like this: The microcontroller sends out PWM signals to the servo, and then the embedded board in the servo receives the signals through the signal pin and controls the motor inside to turn. 
As a result, the motor drives the gear system and then motivates the shaft after deceleration. 
The shaft and potentiometer of the servo are connected together. 
When the shaft rotates, it drives the potentiometer, so the potentiometer outputs a voltage signal to the embedded board. 
Then the board determines the direction and speed of rotation based on the current position, so it can stop exactly at the right position as defined and hold there.

.. image:: img/servo3.png

The angle is determined by the duration of a pulse that is applied to the control wire. The servo expects to see a pulse every 20 ms (That's why we set the pwm frequency to 50hz).

The length of the pulse will determine how far the motor turns. 
For example, a 1.5ms pulse will make the motor turn to the 90 degree position (neutral position). 
When a pulse is sent to a servo that is less than 1.5 ms, the servo rotates to a position and holds its output shaft some degrees counterclockwise from the neutral point. 
When the pulse is wider than 1.5 ms the opposite occurs. The minimal width and the maximum width of pulse that will command the servo to turn to a valid position are functions of each servo. 
Generally the minimum pulse will be about 0.5 ms wide and the maximum pulse will be 2.5 ms wide.

Next, convert the pulse width from period to duty. Since duty_u16() cannot have decimals when used (the value cannot be a float type), we used ``int()`` to force the duty to be converted to an int type.

.. code-block:: python

    duty=int(interval_mapping(pulse_width, 0, 20, 0,65535))

Finally, write the duty value into duty_u16().