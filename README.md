## Using the GPIO of the BeagleBone Black through kernel drivers on Linux - a simple test

This program is the result of training on how to use the BeagleBone Black's GPIO pins to do something useful, such as blinking LEDs. The purpose of all this is that, if I could turn on a led, then I could use some more complex modules (such as displays and analog components).

This project was carried out on an Ubuntu Linux pc, in a Texas Instruments environment. Therefore, all file systems and the ARM toolset are available for use. 

To compile it, just run on the console (the ARM compiler on PATH is required): 

```(bash)
arm-linux-gnueabihf-g++ blink-leds-BBB.cpp -o blink-leds-BBB
```

and transfer to your board (via NFS or SD card).

### Connection

(print aqui)

### Demo videos

(os 3 vídeos aq)
