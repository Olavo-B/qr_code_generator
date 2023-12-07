#include <WiFi.h>
#include <ESPAsyncWebSrv.h>
#include <qr_code_generator.h>

const char *ssid = "OLAVO_NET";
const char *password = "38224804ocg";

AsyncWebServer server(80);
qr_code_generator qr;


String inputData;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Serve HTML page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", "<html><body><form action='/save' method='post'><input type='text' name='data'><input type='submit' value='Save'></form></body></html>");
  });

  // Handle form submission
  server.on("/save", HTTP_POST, [](AsyncWebServerRequest *request){
    if(request->hasParam("data", true)){
      inputData = request->getParam("data", true)->value();
      Serial.println(inputData);
      qr.generateQrCode(inputData.c_str());
      // request->send(200, "text/plain", "Data saved: " + inputData);
      request->send(200, "text/html", "<html><body><img src='" + qr.getUrlString() + "'></body></html>");
    } else {
      request->send(400, "text/plain", "Bad Request");
    }
  });

  server.begin();
}

void loop() {
  // Nothing to do here
}
