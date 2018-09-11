intredLed=12;    //insert redled +ve wire in 12 port
intgreenLed=11;  //insert greenled +ve wire in 11 port
intbuzzer=10;    //insert buzzer +ve wire in 10 port
intsmokeA0=A5;   //insert SENSOR +ve wire in A5 port
intsensorThres=400;   //Yourthresholdvalue
voidsetup()
{
pinMode(redLed,OUTPUT);  //redled set as output
pinMode(greenLed,OUTPUT); //greenled set as output
pinMode(buzzer,OUTPUT);   //buzzer as output
pinMode(smokeA0,INPUT);   //sensor is set as input
Serial.begin(9600);      //9600 bits per second
}
voidloop()
{
int analogSensor=analogRead(smokeA0); //reading sensor input
  Serial.print("PinA0:");    
  Serial.println(analogSensor);

if(analogSensor>sensorThres) //comparing threshold and analog input  
{  
   digitalWrite(redLed,HIGH); 
   digitalWrite(greenLed,LOW);
   tone(buzzer,1000,200); 
} 
else 
{ digitalWrite(redLed,LOW); 
  digitalWrite(greenLed,HIGH); 
  noTone(buzzer); 
} 

delay(100); 

}