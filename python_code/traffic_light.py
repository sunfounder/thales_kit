import machine
import utime
import _thread

led_red = machine.Pin(15, machine.Pin.OUT)
led_yellow = machine.Pin(14, machine.Pin.OUT)
led_green = machine.Pin(13, machine.Pin.OUT)
button = machine.Pin(16, machine.Pin.IN)

global button_status
button_status = 0

def button_thread():
    global button_status
    while True:
        if button.value() == 1:
            button_status = 1

_thread.start_new_thread(button_thread, ())

while True:
    if button_status == 1:
        led_red.value(1)
        utime.sleep(10)
    button_status = 0

    led_red.value(1)
    utime.sleep(5)
    led_red.value(0)

    led_yellow.value(1)
    utime.sleep(2)
    led_yellow.value(0)

    led_green.value(1)
    utime.sleep(5)
    led_green.value(0)

    led_yellow.value(1)
    utime.sleep(2)
    led_yellow.value(0)