# Book8088ESP32SerialWifiBridge
Connect a Book 8088 v2 to a gateway IP (e.g. a phone), bridging COM1: to port 8088 of said IP e.g. for telnet - which would allow you to browse the internet from your iPhone over your DOS laptop.


You need an ESP32 microcontroller board (and a way to power it, e.g. over a 9v battery clip), and a MAX232 RS232-to-TTL adapter (assuming one that has already a DB9 serial port connector). Upload the sketch to the ESP32 board, minding the need to adjust the NAME and the PASSWORD to the Hotspot data of the phone you wish to connect the ESP32 to over Wifi. You connect then the MAX232 adapter to the ESP32 board, with RX and TX being the first two pins (0 and 1) of the ESP32 board, and powering the MAX232 adapter over GND and 5V.


Then you connect your ESP32 board to the Book 8088 v2 modern DOS laptop at its COM1: port. Fire up a terminal emulator on the Book 8088 v2 with the settings COM1:, 9600 baud, 8 bits, no parity, 1 stop bit. On the other side, e.g. on a phone, turn on the Wifi hotspot with the same name and password as you adjusted in the sketch for the ESP32 board. As the ESP32 is turned on, it will begin to display to the Book 8088 v2 over the terminal emulator its connection attempts to the hotspot.


When it successfully connects, you should see on the screen of the Book 8088 v2 the message "CONNECTED". Thereupon you will see a message saying "NO LISTENER", as it has connected already to the hotspot - but not yet to any program running there.


On your phone, fire up iSH (and on Android: Termux), and start e.g. a telnet server with the command "telnetd -p 8088 -l bash" on iOS (or "busybox telnetd -p 8088 -l bash" on Android on Termux) and as soon as you do, your ESP32 will connect to the Telnet server and you will be able to control this Telnet environment via your Book 8088 v2 modern DOS laptop, starting browsers as links and lynx, editors as nano or vi, or programming e.g. in Common Lisp via ECL, etc.


For a live demo, see:


https://youtu.be/1s342z776hA
