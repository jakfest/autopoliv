#define WIFI_SSID "TP--Link"
#define WIFI_PASS "89508240145"
#define GOR1 2
#define GOR2 1
#define BOT_TOKEN "5710052332:AAFSjCW2vZW-nWMcd0GljNuNl3EHzd49_lc"
#define DATPOL 4
#define CHAT_ID "941712200, 5359426542"
char auth[] = "gk-47W3AoXa0ej2-HVK9vKgHty3BPqdW";
char ssid[] = "TP--Link";
char pass[] = "89508240145";

#include <WiFi.h>
#include <FastBot.h>


FastBot bot(BOT_TOKEN);


unsigned long currentMillis = 0;
unsigned long polive1 = 0, polive2 = 0;
unsigned long otchet1 = 0, otchet2 = 0;
unsigned long tmr = 1000000000000000, rab = 0, rabk = 1000000000;
boolean con = false;
int menuID = 0;
byte depth = 0;
boolean dat = true;
boolean gor_1 = false;
boolean gor_2 = false;
boolean con1 = false;
boolean con2 = false;
WiFiServer server(80);
String header;
String output26State = "off";
String output27State = "off";

const int output27 = 27;
unsigned long currentTime = millis();

unsigned long previousTime = 0; 

const long timeoutTime = 2000;




void setup() {

  start();
  Serial.begin(115200);
  pinMode(GOR1, OUTPUT);
  pinMode(GOR2, OUTPUT);
  bot.setChatID(CHAT_ID);
  bot.attach(newMsg);
  
  digitalWrite(GOR2, LOW);
  digitalWrite(GOR1, LOW);
  server.begin();
}

void newMsg(FB_msg& msg) {
  if (msg.text == "/start") {
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.inlineMenu("Главное", menu1);
    depth = 0;
    menuID = bot.lastBotMsg();
    bot.sendMessage("За работу", CHAT_ID); bot.sendMessage("За работу", CHAT_ID);
  }
  if (msg.data == "Water") {
    if (gor_1 == true && gor_2 == true) {
      String menu1 = F("Water first plant \t Water second plant \t Water first and second plant \n Back");
      bot.editMenu(menuID, menu1);
      depth = 1;
    }
    else if (gor_1 == true) {
      String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
      bot.editMenu(menuID, menu1);
      depth = 0;
      currentMillis = millis();
      rabk = 10000;
      polive1 = currentMillis;
      digitalWrite(GOR1, 1);
      bot.sendMessage("За работу", CHAT_ID);
      con1 = true;
    }
    else if (gor_2 == true) {
      String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
      bot.editMenu(menuID, menu1);
      depth = 0;
      currentMillis = millis();
      rabk = 10000;
      polive2 = currentMillis;
      digitalWrite(GOR2, 1);
      bot.sendMessage("За работу", CHAT_ID);
      con2 = true;
    }
    else{
       bot.sendMessage("Подключите горшок", CHAT_ID);
       String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
       bot.editMenu(menuID, menu1);
    }
  }
  if (msg.data == "Water first plant") {
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
    currentMillis = millis();
    rabk = 10000;
    polive1 = currentMillis;
    digitalWrite(GOR1, 1);
    bot.sendMessage("За работу", CHAT_ID);
    con1 = true;
  }
  if (msg.data == "Water second plant"){
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
    currentMillis = millis();
    rabk = 10000;
    polive2 = currentMillis;
    digitalWrite(GOR2, 1);
    bot.sendMessage("За работу", CHAT_ID);
    con2 = true;
  }
  if (msg.data == "Water first and second plant"){
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
    currentMillis = millis();
    rabk = 10000;
    polive1 = currentMillis;
    digitalWrite(GOR1, 1);
    con1 = true;
    polive2 = currentMillis;
    digitalWrite(GOR2, 1);
    bot.sendMessage("За работу", CHAT_ID);
    con2 = true;
  }
  if (msg.data == "Water for datchic") {
    dat = true;
  }
  if (msg.data == "Get time") {
    String menu1 = F("10 second \t 2 minutes \t 8 hour \t 16 hour  \n Back");
    bot.editMenu(menuID, menu1);
    depth = 1;
  }
  if (msg.data == "10 second") {
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    tmr = 10000;
    depth = 0;
  }
  if (msg.data == "2 minutes") {
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    tmr = 60000;
    depth = 0;
  }
  if (msg.data == "8 hour") {
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    tmr = 1000000000000000000;
    depth = 0;
  }
  if (msg.data == "16 hour") {
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    tmr = 1000000000000000000;
    depth = 0;
  }
  if (msg.data == "Settings") {
    String menu1 = F("Get or delete plant \t Power Modes \t Add Device \t Service Mode \t Offline Mode  \n Back");
    bot.editMenu(menuID, menu1);
    depth = 1;
  }
  if (msg.data == "Get or delete plant") {
    if (gor_1 == false && gor_2 == false) {
      String menu1 = F("Get first plant \t Get second plant \t Get first and second plant \n Back");
      bot.editMenu(menuID, menu1);
      depth = 1;
    }
    else if (gor_1 == true && gor_2 == true) {
      String menu1 = F("Delete first plant \t Delete second plant \t Delete first and second plant \n Back");
      bot.editMenu(menuID, menu1);
      depth = 1;
    }
    else if (gor_1 == true && gor_2 == false) {
      String menu1 = F("Delete first plant \t Get second plant \n Back");
      bot.editMenu(menuID, menu1);
      depth = 1;
    }
    else {
      String menu1 = F("Get first plant \t Delete second plant \n Back");
      bot.editMenu(menuID, menu1);
      depth = 1;
    }
  }
  if (msg.data == "Get first plant") {
    gor_1 = true;
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
  }
  if (msg.data == "Get second plant") {
    gor_2 = true;
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
  }
  if (msg.data == "Delete first plant") {
    gor_1 = false;
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
  }
  if (msg.data == "Delete second plant") {
    gor_2 = false;
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
  }
  if (msg.data == "Delete first and second plant") {
    gor_1 = false;
    gor_2 = false;
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
  }
  if (msg.data == "Get first and second plant") {
    gor_2 = true;
    gor_1 = true;
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
  }
  if (msg.data == "Back" && depth == 1) {
    String menu1 = F("Water \t Get time \t Water for datchic \n Settings");
    bot.editMenu(menuID, menu1);
    depth = 0;
  }
}

void loop() {
  bot.tick();
  currentMillis = millis();
  if (currentMillis - otchet1 >= tmr && con1 == false) {
    rabk = 15000;
    polive1 = currentMillis;
    digitalWrite(GOR1, 1);
  }
  if (currentMillis - otchet2 >= tmr && con2 == false) {
    rabk = 15000;
    polive2 = currentMillis;
    digitalWrite(GOR2, 1);
  }
  if (currentMillis - polive1 >= rabk && con1 == true) {
    otchet1 = currentMillis;
    digitalWrite(GOR1, 0);
  }
  if (currentMillis - polive2 >= rabk && con2 == true) {
    otchet2 = currentMillis;
    digitalWrite(GOR2, 0);
  }
  
   WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /26/1") >= 0) {
              Serial.println("GPIO 26 1");
              output26State = "1";
              digitalWrite(GOR1, HIGH);
            } else if (header.indexOf("GET /26/0") >= 0) {
              Serial.println("GPIO 26 0");
              output26State = "0";
              digitalWrite(GOR1, LOW);
            } else if (header.indexOf("GET /27/1") >= 0) {
              Serial.println("GPIO 27 1");
              output27State = "1";
              digitalWrite(GOR2, HIGH);
            } else if (header.indexOf("GET /27/0") >= 0) {
              Serial.println("GPIO 27 0");
              output27State = "0";
              digitalWrite(GOR2, LOW);
            }
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 26  
            client.println("<p>GPIO 26 - State " + output26State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (output26State=="0") {
              client.println("<p><a href=\"/26/1\"><button class=\"button\">1</button></a></p>");
            } else {
              client.println("<p><a href=\"/26/0\"><button class=\"button button2\">0</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 27  
            client.println("<p>GPIO 27 - State " + output27State + "</p>");
            // If the output27State is off, it displays the ON button       
            if (output27State=="0") {
              client.println("<p><a href=\"/27/1\"><button class=\"button\">1</button></a></p>");
            } else {
              client.println("<p><a href=\"/27/0\"><button class=\"button button2\">0</button></a></p>");
            }
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
void start() {
  delay(2000);
  Serial.begin(115200);
  Serial.println();
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {

    if (millis() > 150000) ESP.restart();
  }
  Serial.println("Connected");
}
