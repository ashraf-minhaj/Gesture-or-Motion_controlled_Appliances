/** Gesture / Motion Controlled Appliance - automatic Light !! **
 * by Ashraf Minhaj. 
 * for any query ashraf_minhaj@yahoo.com
 * Tutorial on http://ashrafminhajfb.blogspot.com
 * my youtube channel https://youtube.com/c/fusebatti
 */

int s = 12;     //PIR outPin on digital 10
int led1 = 4;   //led1 on 4
int led2 = 9;   //led2 on 9

void setup()       // put your setup code here, to run once:
{
 pinMode(s,INPUT);        //Setting Sensor as Input
 pinMode(led1,OUTPUT);  
 pinMode(led2,OUTPUT);    //LED pin as output
 
 Serial.begin(9600);      //initialize Serial Monitor- for debugging(else not mandatory)
}

void loop() 
{
  digitalWrite(led1,LOW);    //By default lights off
  digitalWrite(led2,LOW);
  delay(60000);               //1 minute delay so that the PIR gets enough hot to function
  Serial.println("Start");   //Shows a start message
  
  goto off;           //going to off 
 
ON:                  //the ON statement
{
  Serial.println("ON is running");
  digitalWrite(led1,HIGH);   
  digitalWrite(led2,HIGH);      
  
  
  if((digitalRead(s)))   //if Again sensor input has been read - switch off
  {
    digitalWrite(led1,LOW);    //switch off
    digitalWrite(led2,LOW);      
  
    delay(6500);        //around 7 seconds delay
       /* PIR needs at least 5 seconds to function again*/
    goto off;
  }
  
  else           //Else just Be ON
  { 
    goto ON;
  }
}

off:              //OFF statement
{
  Serial.println("OFF is running");

  digitalWrite(led1,LOW);   
  digitalWrite(led2,LOW);      
  
  if((digitalRead(s)))       //if again sensor input has been read - switch ON
  {
    digitalWrite(led1,HIGH);    //switch on
    digitalWrite(led2,HIGH);    
    delay(6500);           /* PIR needs at least 5 seconds to function again*/
    goto ON;
  }
  
  else        //just be off
  { 
    goto off; 
  }
}

}

