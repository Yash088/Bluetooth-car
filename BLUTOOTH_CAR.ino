//Declaring the pins for controlling the motors.
//I have not declared enable pins because I want the motor to run when I turn it on. If you want to turn on the motor manually then you can connect the enable pin ... 
const int leftForward = 8; 
const int leftBackward = 9; 
const int rightForward = 10; 
const int rightBackward = 11;
char data = 0; 
void setup() 
{
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
  
    Serial.begin(9600);   //Sets the baud for serial data transmission  
     pinMode(13, OUTPUT);  //Sets digital pin 13 as output pin
}

void loop()
{
  
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      if(data == '2')              // Checks whether value of data is equal to 1
        {
   digitalWrite(leftForward,HIGH);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightForward,HIGH);
  digitalWrite(rightBackward,LOW);
  } //If value is 1 then LED turns ON
        
      else if(data == '1')  {       //  Checks whether value of data is equal to 0
  digitalWrite(leftForward,LOW);
  digitalWrite(leftBackward,HIGH);
  digitalWrite(rightForward,LOW);
  digitalWrite(rightBackward,HIGH); 
    delay(2000);
   digitalWrite(leftForward,LOW);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(rightBackward,LOW); //If value is 0 then LED turns OFF
 
      }
       else if(data == '3')  {       //  Checks whether value of data is equal to 0
  digitalWrite(leftForward,HIGH);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(rightBackward,HIGH);    //If value is 0 then LED turns OFF
 
      }
       else if(data == '4')  {       //  Checks whether value of data is equal to 0
  digitalWrite(leftForward,LOW);
  digitalWrite(leftBackward,HIGH);
  digitalWrite(rightForward,HIGH);
  digitalWrite(rightBackward,LOW);    //If value is 0 then LED turns OFF
 
      }
      
   }


}    
      
  
