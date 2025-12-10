- ARDUINO CODE:
#define BLYNK_TEMPLATE_ID "Template_id"
#define BLYNK_TEMPLATE_NAME "Template_name"
#define BLYNK_AUTH_TOKEN "########################"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "Wifi_ssid";
char pass[] = "wifi_pass";

// MQ135 analog pin
const int mq135Pin = A0;

// Single LED pin
const int ledPin = D1;

// Timing
unsigned long lastSendTime = 0;
const unsigned long sendInterval = 5000;  // every 5 sec

// Start a web server on port 80
WiFiServer server(80);

// AQI calculation (rough estimate)
int readAQI() {
  int analogValue = analogRead(mq135Pin);
  int aqi = map(analogValue, 0, 1023, 0, 500);
  return aqi;
}

// LED control
void updateLED(int aqi) {
  if (aqi >= 250) {
    digitalWrite(ledPin, HIGH); // Danger → LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Safe → LED OFF
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(ledPin, OUTPUT);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Start local web server
  server.begin();
  Serial.println("Web server started!");

  // Start Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Blynk connected!");
}

void loop() {
  Blynk.run();

  // ========== SEND TO BLYNK + LED CONTROL ==========
  if (millis() - lastSendTime > sendInterval) {
    lastSendTime = millis();

    int aqiValue = readAQI();
    Serial.print("AQI: ");
    Serial.println(aqiValue);

    // Update LED
    updateLED(aqiValue);

    // Send AQI to Blynk virtual pin V0
    Blynk.virtualWrite(V0, aqiValue);
  }

  // ========== HANDLE WEBPAGE ==========
  WiFiClient client = server.available();
  if (!client) return;

  // Wait for client request
  while (!client.available()) {
    delay(1);
  }

  // Read request
  String req = client.readStringUntil('\r');
  client.flush();

  // Build webpage dynamically
  int analog = analogRead(mq135Pin);
  int aqi = map(analog, 0, 1023, 0, 500);

  String ledStatus = (aqi >= 250) ? "ON (Dangerous AQI)" : "OFF (Safe AQI)";

  String webpage = 
    "<html>"
    "<head><title>AQI Monitor</title></head>"
    "<body style='font-family: Arial; text-align:center;'>"
    "<h1>AQI Monitoring System</h1>"
    "<h2>AQI Value: " + String(aqi) + "</h2>"
    "<h3>Sensor Raw Value: " + String(analog) + "</h3>"
    "<h3>LED Status: " + ledStatus + "</h3>"
    "<p>Page refreshes every 5 seconds</p>"
    "<script>setTimeout(()=>{location.reload();},5000);</script>"
    "</body>"
    "</html>";

  // Send response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
  client.println(webpage);
} 
