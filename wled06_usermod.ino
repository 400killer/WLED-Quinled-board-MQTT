//starts dht service on boot
void userSetup()
{
   // Start the DS18B20 sensor
  sensors.begin(); 
}
    
//gets called every time WiFi is (re-)connected. Initialize own network interfaces here
void userConnected()
{

}

void userLoop()
{
  temptimer = millis();
  // Publishes new temperature every 60 seconds
  if (temptimer - lastMeasure > 60000) {
    lastMeasure = temptimer;
    //Check if MQTT Connected
    if (mqtt != nullptr){
      sensors.requestTemperatures(); 
      float temperatureF = sensors.getTempFByIndex(0);
      //charater string populated with user device topic
      char subuf[38];
      //publish temperature to MQTT
      strcpy(subuf, mqttDeviceTopic);
      strcat(subuf, "/temperature");
      mqtt->publish(subuf, 0, true, String(temperatureF).c_str());
    return;}
  return;}
return;
}
