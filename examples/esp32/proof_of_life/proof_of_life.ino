#include <qr_code_generator.h>
#include <HTTPClient.h>

qr_code_generator qr;
WiFiServer server(80);

const char *password = "vida1234";
const char *ssid = "Olavo";


void setup() {


  // Connect to Wi-Fi network with SSID and password
  printf("Connecting to ");
  printf(ssid);
  printf("\n");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      printf(".");
  }
  // Print local IP address and start web server

  printf("WiFi connected.\n");
  printf("\n");
  server.begin();


  Serial.begin(115200);
  // put your setup code here, to run once:
  qr.generateQrCode("rato");
  qr.getQrCode();
  // getQrCode();

  

  

}

void loop() {
  // put your main code here, to run repeatedly:


}
