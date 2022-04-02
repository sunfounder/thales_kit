const int button = 14;
const int STcp = 1;//Pin connected to ST_CP of 74HC595
const int SHcp = 2;//Pin connected to SH_CP of 74HC595 
const int DS = 0; //Pin connected to DS of 74HC595 
int datArray[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int dice = 1 ;

void setup ()
{
  //set pins to output
  pinMode(STcp,OUTPUT);
  pinMode(SHcp,OUTPUT);
  pinMode(DS,OUTPUT);
  pinMode(button,OUTPUT);
}
void loop()
{
    if (digitalRead(button)==HIGH){
      dice = random(1,7);
    }
    digitalWrite(STcp,LOW); //ground ST_CP and hold low for as long as you are transmitting
    shiftOut(DS,SHcp,MSBFIRST,datArray[dice]);
    digitalWrite(STcp,HIGH); //pull the ST_CPST_CP to save the data
    delay(100); //wait for a second

}
