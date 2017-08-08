// Compare sensor value change trough time
// Simulated Values

int i = -1; 
int timeThreshold = 2;      // will define the suddenSensChange() time between first and second reeding in seconds
int maxDeltaT = 4;          //Value change trigger value
int delayTime = 250;        //set loop speed
int simulatedValue1 = 10;   // Simulated sensor value1
int simulatedValue2 = 14;   // Simulated sensor value2

int deltaT;
int timesN = (1000 / delayTime); //Number of loops needed for 1 second to pass
float secondTempValue;

void setup() {
Serial.begin(9600);

}

void ActuateStart(){
  Serial.println("entered ActuateStart");
}

void suddenSensChange(){ 

  if ( i == -1 ){
    firstTempValue = simulatedValue1;
    Serial.println("First sensor reading is " + String(firstTempValue)); 
    i = 0; 
  }
  if ( i < timeThreshold * timesN ){
    i++; 
    delay(delayTime);
    Serial.println(i); 
  }
  else{
    secondTempValue = simulatedValue2; 
    Serial.println("Second sensor reading is " + String(secondTempValue)); 
    deltaT = abs(secondTempValue - firstTempValue);
    Serial.println("Diference in sensor Value is " + String(deltaT));
    if ( deltaT < maxDeltaT ){
      firstTempValue = secondTempValue;
      i = 0;
    }
    else{
      ActuateStart();
    }
  }
}

void loop() {
   suddenSensChange();  
}
