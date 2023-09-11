#include <Arduino.h>

void setup()
{
  pinMode(RGB_BUILTIN, OUTPUT);
  digitalWrite(RGB_BUILTIN, LOW);

  Serial.begin(115200);
  Serial.println("Start blinky");
}

void loop()
{
  Serial.println("LED ON");
  digitalWrite(RGB_BUILTIN, LOW);
  delay(1000);

  Serial.println("LED OFF");
  digitalWrite(RGB_BUILTIN, HIGH);
  delay(1000);

  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);

  Serial.println("Hardware info");
  Serial.printf("%d cores Wifi %s%s\n", chip_info.cores, (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
                (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");
  Serial.printf("Silicon revision: %d\n", chip_info.revision);
  Serial.printf("%dMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
                (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embeded" : "external");

  // get chip id
  auto chipId = String((uint32_t)ESP.getEfuseMac(), HEX);
  chipId.toUpperCase();

  Serial.printf("Chip id: %s\n", chipId.c_str());


  Serial.printf("%dMB PSRAM\n", ESP.getPsramSize() / (1024 * 1024));
}