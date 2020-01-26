## Control an Arduino with a Raspberry Pi via Bluetooth and an http server.

Requirements:

- Internet connection

- Raspberry Pi

- Bluetooth module <intorobotics.com/pick-right-bluetooth-module-diy-arduino-project/>

- Arduino

- An ethernet cable (Rpi2 has builtin wifi but it is very slow)

### Raspberry Pi Config
Connect the ethernet cable to your Rpi.

Before proceeding, make sure you enable bluetooth on the Rpi. If you don't,
any attempts to send or read data over bluetooth will result in:

`bluetooth.btcommon.BluetoothError: (111, 'Connection refused')`

Use the following article to enable bluetooth on your Rpi:

<https://www.cnet.com/how-to/how-to-setup-bluetooth-on-a-raspberry-pi-3/>

In order to host something on local internet, host on an open port with the Rpi's IP address as the hostname.
In order to do this, we will need to find what port the Rpi is listening over your local internet.

You can see what ports are open on this Rpi or other computers on the network using this command on your local computer:

`sudo nmap -O 192.168.1.170`

Scan for hosts on your local network:

`nmap -sP -PI -PT 192.168.1.220/24`

Once you find the Rpi's IP, connect to it via ssh:

`ssh 'username'@'ip_address'`

Once connected to the Rpi:

Open the Raspberry Config Tool to setup your Rpi.

`sudo raspi-config`

Follow this guide in order to allow python to access the Raspberry Pi's bluetooth module.

<http://blog.davidvassallo.me/2014/05/11/android-linux-raspberry-pi-bluetooth-communication/>

Find Python scripts for hosting an http server and connecting to bluetooth devices in `/raspi_arduino/py_server/`.

Run `python server.py` to start the Flask http server.


## Uploading to the Aruino from a Raspberry Pi.
<https://medium.com/@somesh557/arduino-with-raspberry-pi-headless-mode-a0516d78e3bc>

Initialize a project folder for Arduino code.

`ino init`

`cd src`

`vim sketch.ino`

Upload to the board.

Build.

`sudo ino build`

Upload.

`sudo ino upload`

Upload to a specific board type:

`sudo ino build -m mega2560`

`sudo ino upload -m mega2560`

Start a serial port.
Specify the Baud rate with `-b`. -600 baud rate seems to work for mega.

`sudo ino serial  -b 9600`

Build and uplooad for arduino mega.

`sudo ino build -m mega2560 && sudo ino upload -m mega2560`

Build, upload, and port the serial monitor to the terminal.

`sudo ino build -m mega2560 && sudo ino upload -m mega2560 && sudo ino serial -b 9600`
