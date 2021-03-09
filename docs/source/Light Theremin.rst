Light Theremin
=========================

Thereman is an electronic musical instrument that does not require physical contact. It produces different tones by sensing the position of the player's hand.
There are two LC oscillator working units that sense the distributed capacitance of the human body and the earth to produce oscillation frequency and size change respectively.
We cannot reproduce the same instrument through Pico, but we can use photoresistor and passive buzzer to achieve similar gameplay.


Wiring
--------------------

.. image:: img/wiring_light_theremin.png

1. Connect 3V3 and GND of Pico to the power bus of the breadboard.
#. Connect one end of the photoresistor to the negative power bus, and the other end in series with a 10kΩ resistor to the positive power bus.
#. Use a jumper wire to connect GP28 between the two resistors.
#. Insert the LED into the breadboard, connect its anode pin to the GP16 in series with a 220Ω resistor, and connect its cathode pin to the negative power bus.
#. Insert the passive buzzer and S8050 transistor into the breadboard. The anode pin of the buzzer is connected to the positive power bus, the cathode pin is connected to the **collector** lead of the triode, and the **base** lead of the triode is connected to the GP15 pin through a 1kΩ resistor. **emitter** lead is connected to the negative power bus.

.. note::
    The color ring of the 22Ωresistor is red, red, black, black and brown.
    The color ring of the 10kΩ resistor is brown, black, black, red and brown.

Code
--------------------

.. code-block:: python

    import machine
    import utime

    led = machine.Pin(16, machine.Pin.OUT)
    photoresistor = machine.ADC(28) 
    buzzer = machine.PWM(machine.Pin(15))

    light_low=65535
    light_high=0

    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty_u16(30000)
        utime.sleep_ms(duration)
        pin.duty_u16(0)

    # calibrate the photoresistor max & min values.
    timer_init_start = utime.ticks_ms()
    led.value(1)    
    while utime.ticks_diff(utime.ticks_ms(), timer_init_start)<5000:
        light_value = photoresistor.read_u16()
        if light_value > light_high:
            light_high = light_value
        if light_value < light_low:
            light_low = light_value   
    led.value(0)    

    # play
    while True:
        light_value  = photoresistor.read_u16()
        pitch = int(interval_mapping(light_value,light_low,light_high,50,6000))
        if pitch > 50 :
            tone(buzzer,pitch,20)
        utime.sleep_ms(10)

When the program runs, the LED will light up, and we will have five seconds to calibrate the detection range of the photoresistor. This is because each time we use it, we may be in a different light environment (such as the light intensity at noon and dusk is not the same).
At this time, we need to swing our hands up and down above the photoresistor, and the movement range of the hand will be calibrated to the playing range of this instrument.
After five seconds, the LED will go out and we can wave our hands on the photoresistor to play.


