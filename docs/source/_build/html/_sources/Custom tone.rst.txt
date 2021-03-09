Custom Tone
==========================================


We have used active buzzers in the previous chapters, this time we will use passive buzzers.

Like the active buzzer, the passive buzzer also uses the phenomenon of electromagnetic induction to work. The difference is that the passive buzzer has one less oscillating circuit, so that it cannot be directly energized to make a sound.
But this also allows the passive buzzer to adjust its own oscillation frequency and have a wider range, which can emit different syllables such as "doh, re, mi, fa, sol, la, ti".

Let the passive buzzer emit a melody!

Wiring
-------------------------

.. image:: img/buzzer.png

Two buzzers are included in the kit, and the one we need is the passive one. Reverse the buzzer, the one with the exposed PCB behind it is the one we want.

The buzzer needs a transistor to work, and here we use S8050.

.. image:: img/wiring_custom_tone.png

1. Connect 3V3 and GND of Pico to the power bus of the breadboard.
#. Connect the positive pin of the buzzer to the positive power bus.
#. Connect the cathode pin of the buzzer to the **collector** lead of the triode.
#. Connect the **base** lead of the transistor to the GP15 pin through a 1kΩ resistor.
#. Connect the **emitter** lead of the transistor to the negative power bus.

.. note::
    The color ring of the 1k ohm resistor is brown, black, black, brown and brown.

Code
--------------------

.. code-block:: python

    import machine
    import utime

    buzzer = machine.PWM(machine.Pin(15))

    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty_u16(30000)
        utime.sleep_ms(duration)
        pin.duty_u16(0)

    tone(buzzer,440,250)
    utime.sleep_ms(500)
    tone(buzzer,494,250)
    utime.sleep_ms(500)
    tone(buzzer,523,250)


How it works?
--------------------

We defined a ``tone()'' function to make the buzzer sound.

The passive buzzer will push the oscillator every time it receives a high level. If it is given a digital signal, the oscillator will be pushed all the time, but it does not oscillate and cannot sound.
Here we use the PWM method to create oscillations.

This function has three parameters:

* pin, the GPIO pin that controls the buzzer.
* frequency, the pitch of the buzzer is determined by the frequency, the higher the frequency, the higher the pitch.
* Duration, the duration of the tone.

We set the ``duty_u16()'' when the buzzer is oscillating to 30000, which is about 50%. It can be another number, and it only needs to generate a discontinuous electrical signal to oscillate.



What more？
-----------------------------

We can simulate the specific tone according to the fundamental frequency of the piano, so as to play a complete piece of music.

* `Piano key frequencies - Wikipedia <https://en.wikipedia.org/wiki/Piano_key_frequencies>`_


.. code-block:: python

    import machine
    import utime

    NOTE_C4 = 262
    NOTE_G3 = 196
    NOTE_A3 = 220
    NOTE_B3 = 247

    melody =[NOTE_C4,NOTE_G3,NOTE_G3,NOTE_A3,NOTE_G3,NOTE_B3,NOTE_C4]

    buzzer = machine.PWM(machine.Pin(15))

    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty_u16(30000)
        utime.sleep_ms(duration)
        pin.duty_u16(0)

    for note in melody:
        tone(buzzer,note,250)
        utime.sleep_ms(150)


