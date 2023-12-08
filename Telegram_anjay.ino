#include <WiFi.h>
#include <HTTPClient.h>

// Define your Telegram bot token and chat ID
#define TELEGRAM_BOT_TOKEN "6636643821:AAH7bgSxUlo5D-h1l5kRr5R2cwvTHzRgUx8"
#define TELEGRAM_CHAT_ID "1235344117"

// Define your Wi-Fi credentials
#define WIFI_SSID "DESI"
#define WIFI_PASSWORD "gaadapassword"

// Function to send a message to Telegram using HTTP requests
void sendTelegramNotification(String message) {
  HTTPClient http;
  String url = "https://api.telegram.org/bot" + String(TELEGRAM_BOT_TOKEN) +
               "/sendMessage?chat_id=" + String(TELEGRAM_CHAT_ID) +
               "&text=" + message;

  http.begin(url);

  int httpResponseCode = http.GET();
  if (httpResponseCode > 0) {
    Serial.print("Telegram notification sent successfully. Response code: ");
    Serial.println(httpResponseCode);
  } else {
    Serial.print("Error sending Telegram notification. Response code: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void setup() {
  // Set up Serial Monitor
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Set ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
}

void loop() {
  // Your main code goes here, you can add additional functionality if needed

  // Example: Send a Telegram notification with the message "anjaaayyy"
  sendTelegramNotification("ANJJJJJJIIIIIIIIII!!!!!!!!");

  // Delay for a while before sending another message (adjust as needed)
  delay(1000);
}
