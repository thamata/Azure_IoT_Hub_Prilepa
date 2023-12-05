# IoT Project using Microsoft Azure, CosmosDB and PowerBI

## Project structure
This project contains code for an esp32 microcontroller that communicates with Microsoft Azure, this includes connecting the device to Azure, recieving Json data from an arduino and sending the data back to Azure. The main executable being Azure_IoT_Hub_ESP32.ino
<br>
**This code is located in:** Azure_IoT_Hub_ESP32
<br><br>
This project also contains code for an arduino uno microcontroller that sends Json data to the esp32 using UDP over a local network.
<br>
**This code is located in:** UPD_Comm\WiFiUdpSendString_Arduino
##Setup
1. **Following this tutorial set up your IoT hub and add a new device, in my case this is the esp32**
   - https://learn.microsoft.com/en-us/azure/iot-hub/iot-hub-create-through-portal
2. **Replace the variables in the iot_configs.h file**
   - In the WiFi section set the parameters to match your local network, the same can be done for the other configs.h file
   - In the Azure IoT section set IOT_CONFIG_IOTHUB_FQDN to the hostname of your IoT hub, which can be found under the overview section of your IoT hub
   - Set IOT_CONFIG_DEVICE_ID to be the same as your device in device managment / devices in the IoT hub, in my case the device name is "ESP32"
   - Next select the device and copy the primary key and paste it after IOT_CONFIG_DEVICE_KEY
3. 
