You can open the Raspberry Config Tool:

`sudo raspi-config`

In order to host something on local internet, host on an open port with the Rpi's IP address as the hostname.

You can see what ports are open on this Rpi or other computers on the network using this command:

`sudo nmap -O 192.168.1.170`

Scan for hosts on your local network:

`nmap -sP -PI -PT 192.168.1.220/24`


You can stop or run an apache server on on port 80 with:

`sudo service apache2 restart`

Start it with:

`sudo service apache2 stop`

Bluetooth:

Python scripts for finding and connecting to bluetooth devies canbe found in the py server
portion of the home server project.


Arduino:


Here is how to upload code to the arduino from the raspberry pi: https://medium.com/@somesh557/arduino-with-raspberry-pi-headless-mode-a0516d78e3bc


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
	`sudo ino serial  -b 600`

	Build and uplooad for arduino mega.
	`sudo ino build -m mega2560 && sudo ino upload -m mega2560`

	Build, upload, and port the serial monitor to the terminal.
	`sudo ino build -m mega2560 && sudo ino upload -m mega2560 && sudo ino serial -b 600`
