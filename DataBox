#include <SPI.h>
#include <WiFiNINA.h>
#include "arduino_secrets.h"

// Configure the pins used for the ESP32 connection
#define SPIWIFI       SPI  // The SPI port
#define SPIWIFI_SS    10   // Chip select pin
#define ESP32_RESETN  5   // Reset pin
#define SPIWIFI_ACK   7   // a.k.a BUSY or READY pin
#define ESP32_GPIO0   6

///////please enter your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your network SSID (name)
char pass[] = SECRET_PASS;        // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;     // the Wifi radio's status
int keyIndex = 0;
WiFiServer server(80);
String readString;

void setup()
{
  Serial.begin(9600);

  while (status != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(3000);
  }
  server.begin();
  Serial.print("You're connected to the network with ");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}

void loop()
{
  WiFiClient client = server.available();
  if (client)
  {
    Serial.println("new client");
    boolean currentLineIsBlank = true;
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        if (readString.length() < 500)
        {
          readString += c;
          Serial.write(c);
          if (c == '\n' && currentLineIsBlank)
          {
            client.println("HTTP/1.1 200 OK"); //send new page
            client.println("Content-Type: text/html");
            client.println("Connection: close");  // the connection will be closed after completion of the response
            client.println("Refresh: 60");
            client.println();

            client.println("<html>");
            client.println("<body>");

            client.println("<center><h1>Please choose the start date and end date</h1>");
            client.println("<br>");
            client.println("<br>");
            client.println("<form action=\"http://192.168.0.109/\">");

            client.println("<label for=\"StartDate\">StartDate:</label>");
            client.println("<input type=\"StartDate\" id=\"StartDate\" name=\"StartDate\">");
            client.println("<br>");
            client.println("<br>");
            client.println("<label for=\"EndDate\">EndDate:</label>");
            client.println("<input type=\"EndDate\" id=\"EndDate\" name=\"EndDate\">");
            client.println("<br>");
            client.println("<br>");
            client.println("<input type=\"submit\">");

            client.println("</form>");

            client.println("</body>");
            client.println("</html>");

            client.println("<meta http-equiv=\"refresh\" content=\"4\">");

            delay(3);
            readString = "";
            delay(5);
            client.stop();
            Serial.println("client disonnected");
          }
        }
      }
    }
  }
}
