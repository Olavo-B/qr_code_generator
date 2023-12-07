#include <qr_code_generator.h>
#include <HTTPClient.h>

qr_code_generator qr;
const String url = "http://api.qrserver.com/v1/create-qr-code/?data=HelloWorld!&size=100x100";

WiFiServer server(80);

const char *password = "vida1234";
const char *ssid = "Olavo";

void getQrCode()
{
  HTTPClient http;
  http.useHTTP10(true);
  http.begin("http://api.qrserver.com/v1/create-qr-code/?data=HelloWorld!&size=100x100");
  int code = http.GET();
  String result = http.getString();

  Serial.print("HTTP code: ");
  Serial.println(code);

  Serial.print("Result: ");
  Serial.println(result);
  
}

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
  // getQrCode();

  

  

}

void loop() {
  // put your main code here, to run repeatedly:


}
