RGB LED Strip
======================

WS2812 is a intelligent control LED light source that the control circuit and RGB chip are integrated in a package of 5050 components. It internal include intelligent digital port data latch and signal reshaping amplification drive circuit. Also include a precision internal oscillator and a 12V voltage programmable constant current control part, effectively ensuring the pixel point light color height consistent.

The data transfer protocol use single NZR communication mode. 
After the pixel power-on reset, the DIN port receive data from controller, the first pixel collect initial 24bit data then sent to the internal data latch, the other data which reshaping by the internal signal reshaping amplification circuit sent to the next cascade pixel through the DO port. After transmission for each pixel，the signal to reduce 24bit. 
pixel adopt auto reshaping transmit technology, making the pixel cascade number is not limited the signal transmission, only depend on the speed of signal transmission.


Wiring
----------------------------

.. image:: img/wiring_rgb_strip.png

1. 将LED Strip 的VCC连接Pico的VBUS。
#. 将LED Strip 的GND连接Pico的GND。
#. 将LED Strip 的DIN连接Pico的GP0。

.. warning::
    您需要注意的一件事是电流。
    虽然Pico中可以使用任意LED灯珠数量的LED Strip，然而其VBUS引脚的功率却是有限的。
    在这里，我们将使用八个LED，这是安全的。
    但是如果您要使用更多的LED，则需要了解限制条件，并可能需要添加单独的电源。
    

Code
---------------------

以下是Sunfounder封装好的ws2812的library。你需要将其存入Pico，将其命名为 **ws2812.py** 作为library使用。


.. code-block:: python

    import array, time
    import rp2
    from rp2 import PIO, StateMachine, asm_pio

    @asm_pio(sideset_init=PIO.OUT_LOW, out_shiftdir=PIO.SHIFT_LEFT, autopull=True, pull_thresh=24)
    def ws2812():
        T1 = 2
        T2 = 5
        T3 = 3
        label("bitloop")
        out(x, 1).side(0)[T3 - 1]
        jmp(not_x, "do_zero").side(1)[T1 - 1]
        jmp("bitloop").side(1)[T2 - 1]
        label("do_zero")
        nop().side(0)[T2 - 1]

    class WS2812():
        
        def __init__(self, pin, num):
            # Configure the number of WS2812 LEDs.
            self.led_nums = num
            self.pin = pin
            self.sm = StateMachine(0, ws2812, freq=8000000, sideset_base=self.pin)
            # Start the StateMachine, it will wait for data on its FIFO.
            self.sm.active(1)
            
            self.buf = array.array("I", [0 for _ in range(self.led_nums)])

        def write(self):
            self.sm.put(self.buf, 8)

        def write_all(self, value):
            for i in range(self.led_nums):
                self.__setitem__(i, value)
            self.write()

        def list_to_hex(self, color):
            if isinstance(color, list) and len(color) == 3:
                c = (color[0] << 8) + (color[1] << 16) + (color[2])
                return c
            elif isinstance(color, int):
                value = (color & 0xFF0000)>>8 | (color & 0x00FF00)<<8 | (color & 0x0000FF)
                return value
            else:
                raise ValueError("Color must be 24-bit  RGB hex or list of 3 8-bit RGB")

        def hex_to_list(self, color):
            if isinstance(color, list) and len(color) == 3:
                return color
            elif isinstance(color, int):
                r = color >> 8 & 0xFF
                g = color >> 16 & 0xFF
                b = color >> 0 & 0xFF
                return [r, g, b]
            else:
                raise ValueError("Color must be 24-bit  RGB hex or list of 3 8-bit RGB")

        def __getitem__(self, i):
            return self.hex_to_list(self.buf[i])

        def __setitem__(self, i, value):
            value = self.list_to_hex(value)
            self.buf[i] = value

然后，新建一个new file，在这里调用方才储存好的ws2812 library。


.. code-block:: python

    import machine 
    from ws2812 import WS2812

    ws = WS2812(machine.Pin(0),8)

    ws[0] = [64,154,227]
    ws[1] = [128,0,128]
    ws[2] = [50,150,50]
    ws[3] = [255,30,30]
    ws[4] = [0,128,255]
    ws[5] = [99,199,0]
    ws[6] = [128,128,128]
    ws[7] = [255,100,0]
    ws.write()


让我们选中一些心仪的颜色，在RGB LED Strip上面显示出来！

How it works?
--------------------------
在ws2812 library中，我们将相关功能集成到了WS2812类中。

你可以通过以下的语句来使用RGB LED Strip

import ws2812 library

.. code-block:: python

    from ws2812 import WS2812

声明一个WS2812类型的变量，命名为ws，它连接到"pin"，有"number"个灯珠。

.. code-block:: python

    ws = WS2812(pin,number)

ws是一个array对象，每一个元素对应着一颗灯珠，如ws[0]为第一个，ws[7]为第八个。
我们可以为每个灯珠赋于颜色值，这些值 must be 24-bit RGB hex or list of 3 8-bit RGB。
比如说红色的值为"0xFF0000"或者"[255,0,0]"。

.. code-block:: python

    ws[i] = color_value

然后用这个语句为LED Strip写入颜色。

.. code-block:: python

    ws.write()


你也可以直接用以下语句让所有LED亮出相同的颜色。

.. code-block:: python

    ws.write_all(color_value)


What more?
--------------------------

我们可以随机生成颜色，制作一条colorful flowing light

.. code-block:: python

    import machine 
    from ws2812 import WS2812
    import utime
    import urandom

    ws = WS2812(machine.Pin(0),8)

    def flowing_light():
        for i in range(7,0,-1):
            ws[i] = ws[i-1]
        ws[0] = int(urandom.uniform(0, 0xFFFFFF))  
        ws.write()
        utime.sleep_ms(80)

    while True:
        flowing_light()
        print(ws[0])