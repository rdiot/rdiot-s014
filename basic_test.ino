/* Keyes Infrared Receiver Module (KY-022) [S014] : http://rdiot.tistory.com/165 [RDIoT Demo] */

#include "U8glib.h"
#include "IRremote.h"
 
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
int receiver = 11; // pin 1 of IR receiver to Arduino digital pin 11
 
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'
String str_hex = "";
String str_value = "";
 
void setup() {
  Serial.begin(9600);
  Serial.println("IR Receiver Raw Data + Button Decode Test");
  irrecv.enableIRIn(); // Start the receiver
}
 
void loop(void) { 
  if (irrecv.decode(&results)) // have we received an IR signal?
  {
  // Serial.println(results.value, HEX);  UN Comment to see raw values
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
 
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  //delay(500);
}
 
void draw(void) {
  u8g.setFont(u8g_font_9x15B);
  u8g.setPrintPos(0, 12); 
  u8g.println("IR-VS1838B");
 
  u8g.setFont(u8g_font_helvB14);
  u8g.setPrintPos(0,40);
  u8g.print("hex="+str_hex);
 
  u8g.setFont(u8g_font_helvB14);
  u8g.setPrintPos(0,60);
  u8g.print("str="+str_value); 
}
 
/*-----( Declare User-written Functions )-----*/
void translateIR() // takes action based on IR code received
// describing Car MP3 IR codes  
{
 
  switch(results.value)
  {
 
  case 0xFFA25D:  
    Serial.println(" CH-            "); 
    str_hex = "0xFFA25D";
    str_value = "CH-";
    break;
 
  case 0xFF629D:  
    Serial.println(" CH             "); 
    str_hex = "0xFFA25D";
    str_value = "CH-";
    break;
 
  case 0xFFE21D:  
    Serial.println(" CH+            "); 
    str_hex = "0xFFE21D";
    str_value = "CH+";
    break;
 
  case 0xFF22DD:  
    Serial.println(" PREV           "); 
    str_hex = "0xFF22DD";
    str_value = "PREV";
    break;
 
  case 0xFF02FD:  
    Serial.println(" NEXT           "); 
    str_hex = "0xFF02FD";
    str_value = "NEXT";
    break;
 
  case 0xFFC23D:  
    Serial.println(" PLAY/PAUSE     "); 
    str_hex = "0xFFC23D";
    str_value = "PLAY/PAUSE";
    break;
 
  case 0xFFE01F:  
    Serial.println(" VOL-           "); 
    str_hex = "0xFFE01F";
    str_value = "VOL-";
    break;
 
  case 0xFFA857:  
    Serial.println(" VOL+           "); 
    str_hex = "0xFFA857";
    str_value = "VOL+";
    break;
 
  case 0xFF906F:  
    Serial.println(" EQ             "); 
    str_hex = "0xFF906F";
    str_value = "EQ";
    break;
 
  case 0xFF6897:  
    Serial.println(" 0              "); 
    str_hex = "0xFF6897";
    str_value = "0";
    break;
 
  case 0xFF9867:  
    Serial.println(" 100+           "); 
    str_hex = "0xFF9867";
    str_value = "100+";
    break;
 
  case 0xFFB04F:  
    Serial.println(" 200+           "); 
    str_hex = "0xFFB04F";
    str_value = "200+";
    break;
 
  case 0xFF30CF:  
    Serial.println(" 1              "); 
    str_hex = "0xFF30CF";
    str_value = "1";
    break;
 
  case 0xFF18E7:  
    Serial.println(" 2              "); 
    str_hex = "0xFF18E7";
    str_value = "2";
    break;
 
  case 0xFF7A85:  
    Serial.println(" 3              "); 
    str_hex = "0xFF7A85";
    str_value = "3";
    break;
 
  case 0xFF10EF:  
    Serial.println(" 4              "); 
    str_hex = "0xFF10EF";
    str_value = "4";
    break;
 
  case 0xFF38C7:  
    Serial.println(" 5              "); 
    str_hex = "0xFF38C7";
    str_value = "5";
    break;
 
  case 0xFF5AA5:  
    Serial.println(" 6              "); 
    str_hex = "0xFF5AA5";
    str_value = "6";
    break;
 
  case 0xFF42BD:  
    Serial.println(" 7              "); 
    str_hex = "0xFF42BD";
    str_value = "7";
    break;
 
  case 0xFF4AB5:  
    Serial.println(" 8              "); 
    str_hex = "0xFF4AB5";
    str_value = "8";
    break;
 
  case 0xFF52AD:  
    Serial.println(" 9              "); 
    str_hex = "0xFF52AD";
    str_value = "9";
    break;
 
  default: 
    Serial.println(" other button   ");
    str_hex = "NONE";
    str_value = "NONE";
 
  } 
  delay(500);
 
} //END translateIR
