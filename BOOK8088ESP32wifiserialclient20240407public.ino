#include <WiFi.h>
#define SRL Serial
const char* ssid = "MAINFRAME"; // ADJUST
const char* password = "DOSmachine"; // ADJUST
unsigned char ch;
void setup() {
  SRL.begin(9600);
  SRL.println("SETUP COMMENCING...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); SRL.println("Connecting to WiFi...");
  }
  SRL.println("CONNECTED."); delay(500);
  WiFiClient client; 
  while (!client.connect(WiFi.gatewayIP(), 8088)) { delay(1000); SRL.println("NO LISTENER."); }
  for (;;) {
    while (client.connected()) {
    if (client.available()) {
      ch = client.read(); SRL.write((unsigned char) ch);
    }
    if (SRL.available()) {
      ch = SRL.read(); client.write((unsigned char) ch);
    }
}}}
void loop() {}

// iSH on iOS: apk add busybox busybox-extras, then telnetd -p 8088 -l bash
// try ecl, lynx and vi or nano 
