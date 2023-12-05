/*
  WiFi UDP Send and Receive String

  This sketch waits for a UDP packet on localPort using the WiFi module.
  When a packet is received an Acknowledge packet is sent to the client on port remotePort

  created 30 December 2012
  by dlf (Metodo2 srl)

  Find the full UNO R4 WiFi Network documentation here:
  https://docs.arduino.cc/tutorials/uno-r4-wifi/wifi-examples#wi-fi-udp-send-receive-string
 */


// https://opendata-download-metfcst.smhi.se/api/category/pmp3g/version/2/geotype/point/lon/16.0533/lat/59.3279/data.json

#include <WiFiS3.h>
#include <ArduinoJson.h>
#include "configs.h"

int status = WL_IDLE_STATUS;
const char * ssid = IOT_CONFIG_WIFI_SSID;
const char * pass = IOT_CONFIG_WIFI_PASSWORD;


const char * udpAddress = "192.168.100.185";    // local address of esp32
unsigned int localPort = 3333;                  // local port

WiFiUDP Udp;

static void SendPacket(){
  // Create JSON
  StaticJsonDocument<256> doc;

  doc["temperature"] = random(15.0, 32.0);
  doc["humidity"] = random(70, 90);

  Serial.println("Message sent: ");
  serializeJsonPretty(doc, Serial);

  char buffer[256];
  serializeJson(doc, buffer);

  Udp.beginPacket(udpAddress,localPort);
  Udp.write(buffer);
  Udp.endPacket();
}

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.println("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("Connected to WiFi");
  printWifiStatus();

  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  Udp.begin(localPort);
}

void loop() {
  SendPacket();
  Serial.println();

  delay(10000);
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
