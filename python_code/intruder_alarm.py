import machine
import utime

pir_sensor = machine.Pin(14, machine.Pin.IN)
buzzer = machine.Pin(15, machine.Pin.OUT)

def motion_detected(pin):
    for i in range(50):
        buzzer.toggle()
        utime.sleep_ms(100)

pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)
print("Intruder Alarm Start!")