/* ================================== *
 *  Author: Cristian Crazy
 *  To support a friend's friend.
 *  --
 *  #NOTA: SULLA ESP32 DA USARE
 *  LA LIBRERIA <WiFi.h>. NON CAMBIA
 *  NIENTE. IMPORTARLA DA MENU
 *  [SKETCH -> #INCLUDE LIBRERIA -> WiFi]
 *  --
 *  Reading sensor(s) and commit
 *  on webserver using HTTP GET on AD
 *  and PHP to manage the ws.
 * ================================== */

#include <WiFiNINA.h>
#include "sensor.c"

/* HTTP EndPoint Config */
#define ENDPOINT "bunny.cristiancrazy.it"

/* WiFi Config */
const char* WiFiSSID = "[SSIDHERE]"; // Your network SSID
const char* WiFiPASS = "[PASSWORD HERE]"; // Your network PASSWORD
WiFiClient client;

void setup() {
  Serial.begin(9600);
  //while (!Serial); // wait for serial port to connect. 
  
  Serial.println("Init Sensor");
  initSensors();

  /* Init WiFi Connection and check endpoint */
    
  WiFi.begin(WiFiSSID, WiFiPASS); // Connetti WiFi
  delay(10000);
  if(WiFi.status() != WL_CONNECTED){ // Verifica connessione WiFi
    Serial.println("Impossibile connettersi all'AP.");
    while(true);
  }else{
    Serial.println("Connesso.");
    Serial.print("IP: ");
    Serial.print((IPAddress)WiFi.localIP()); // Ottieni IP dell'Arduino
    Serial.println();
  }
  

  if(WiFi.ping(ENDPOINT) < 0){ // Verifica connessione con il sito da raggiungere
    Serial.println("Impossibile raggiungere il Server: " + (String)ENDPOINT);  
  }
}

void loop() {
  if(client.connect(ENDPOINT, 80)){ // Connetti al sito web
    String value = String(readTemp()); // Leggi sensore(i)
    // Send a full GET REQUEST --> Invia una richiesta di tipo HTTP GET alla homepage del sito
    client.println("GET /?action=commit&value=" + value + " HTTP/1.1"); // Dopo ? c'è query string con parametri da inviare al sito
    client.println("Host: " + (String)ENDPOINT); // Specifica il nome del sito
    client.println("Connection: Close"); 
    client.println();
  }else{
    Serial.println("Errore di connessione");  
  }
  delay(10000);
}
