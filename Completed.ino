#include <LiquidCrystal.h>
/* Create object named lcd of the class LiquidCrystal */
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 2);  /* For 8-bit mode */
//LiquidCrystal lcd(13, 12, 11, 6, 5, 4, 3);  /* For 4-bit mode */

unsigned char Character1[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F }; /* Custom Character 1 */
unsigned char Character2[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 }; /* Custom Character 2 */

const int lm35_pin = A1;  /* LM35 O/P pin */
int motor = 3;
 int speed1;
int ir1;
int count=0;
int Count=0;
void setup() 
{
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
 pinMode(A0,INPUT);
 pinMode(A1,INPUT);
  lcd.begin(16,2);  /* Initialize 16x2 LCD */

  lcd.print("AUTOMATIC SPEED ");
  lcd.setCursor(0,1); 
  lcd.print("CONTROL OF FAN");
  delay(2400);
  lcd.clear();
 
}

void loop() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);  /* Read Temperature */
  temp_val = (temp_adc_val * 4.88); /* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10); /* LM35 gives output of 10mv/°C */
  delay(500);
  Serial.print("Temperature = ");
  Serial.print(temp_val);
 // Serial.print(" Degree Celsius\n");
  
  ir1=analogRead(A0);
  speed1=(temp_val*3);
  if(temp_val>=27)
  {
    //Serial.print("FAN IS Running at ");
   // Serial.println(speed1);
    Serial.println(analogRead(A0));
    lcd.setCursor(0,0); /* Set cursor to column 0 row 0 */
  lcd.print("Temperature:"); 
  lcd.print(temp_val);
  if(ir1>900 || ir1 ==0)
  {Serial.println("Fan IS Not Running");
    }
    
  
  lcd.setCursor(0,1);
  lcd.print("Fan Speed: ");
  lcd.print(speed1);
  
   analogWrite(3,speed1);
  } 
  else
  {
    Serial.println("FAN IS OFF");
     lcd.print("0");
    }
 }
