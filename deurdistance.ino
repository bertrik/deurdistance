#include <Arduino.h>

#include <WiFiManager.h>
#include <PubSubClient.h>
#include <VL53L0X.h>

#define PIN_SHDN    D3

static WiFiManager wifiManager;
static WiFiClient wifiClient;
static PubSubClient mqttClient(wifiClient);
static VL53L0X lidar;

void setup(void)
{
    Serial.begin(115200);

    // disable shutdown
    pinMode(PIN_SHDN, INPUT_PULLUP);

    // init lidar
    lidar.init();
    lidar.setTimeout(500);
    lidar.setMeasurementTimingBudget(200000);

//    Wifi.begin("revspace-pub-2.4ghz", "");
}

void loop(void)
{
    int range = lidar.readRangeSingleMillimeters();
    
    Serial.print("Distance: ");
    Serial.println(range);
    
    delay(1000);
}

