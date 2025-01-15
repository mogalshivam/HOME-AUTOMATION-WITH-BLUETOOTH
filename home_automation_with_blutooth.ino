#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX (Pin 10) and TX (Pin 11)

int relayPin1 = 8;  
int relayPin2 = 9;  
int relayPin3 = 7;  
int relayPin4 = 6;  

char incomingCommand;  
boolean isDevice1On = false;
boolean isDevice2On = false;
boolean isDevice3On = false;
boolean isDevice4On = false;

void setup() {
  
  Serial.begin(9600);
  BTSerial.begin(9600);  
  
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);


  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
  digitalWrite(relayPin3, LOW);
  digitalWrite(relayPin4, LOW);

  Serial.println("Home Automation System Ready. Awaiting Bluetooth Commands...");
  Serial.println("Commands: 1=Device1 ON, 0=Device1 OFF, 3=Device2 ON, 2=Device2 OFF, 5=Device3 ON, 4=Device3 OFF, 7=Device4 ON, 6=Device4 OFF");
}


void loop() {
 
  if (BTSerial.available()) {
    incomingCommand = BTSerial.read(); 

    Serial.print("Received Command: ");
    Serial.println(incomingCommand);

    if (incomingCommand == '1') {
      digitalWrite(relayPin1, HIGH); 
      isDevice1On = true;
      Serial.println("Device 1 (Lamp) is ON");
    }
    else if (incomingCommand == '0') {
      digitalWrite(relayPin1, LOW);  
      Serial.println("Device 1 (Lamp) is OFF");
    }

    
    else if (incomingCommand == '3') {
      digitalWrite(relayPin2, HIGH);  
      isDevice2On = true;
      Serial.println("Device 2 (Fan) is ON");
    }
    else if (incomingCommand == '2') {
      digitalWrite(relayPin2, LOW);  
      isDevice2On = false;
      Serial.println("Device 2 (Fan) is OFF");
    }

    
    else if (incomingCommand == '5') {
      digitalWrite(relayPin3, HIGH);  
      isDevice3On = true;
      Serial.println("Device 3 (Air Conditioner) is ON");
    }
    else if (incomingCommand == '4') {
      digitalWrite(relayPin3, LOW);  
      isDevice3On = false;
      Serial.println("Device 3 (Air Conditioner) is OFF");
    }

    else if (incomingCommand == '7') {
      digitalWrite(relayPin4, HIGH); 
      isDevice4On = true;
      Serial.println("Device 4 (Heater) is ON");
    }
    else if (incomingCommand == '6') {
      digitalWrite(relayPin4, LOW);  
      isDevice4On = false;
      Serial.println("Device 4 (Heater) is OFF");
    }

    
    else {
      Serial.println("Invalid command received. Please send a valid command.");
    }

  
    displayDeviceStates();
  }

}

void displayDeviceStates() {
  Serial.print("Device 1 (Lamp) is ");
  Serial.println(isDevice1On ? "ON" : "OFF");

  Serial.print("Device 2 (Fan) is ");
  Serial.println(isDevice2On ? "ON" : "OFF");

  Serial.print("Device 3 (Air Conditioner) is ");
  Serial.println(isDevice3On ? "ON" : "OFF");

  Serial.print("Device 4 (Heater) is ");
  Serial.println(isDevice4On ? "ON" : "OFF");
}