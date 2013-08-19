#include <MFRC522.h>
#include <SPI.h>

#define	uchar	unsigned char
#define	uint	unsigned int
#define MAX_LEN 16
//#define PICC_REQIDL 0x26
uchar serNum[5];

// Setup the MFRC522 reader object
MFRC522 rfid(10,5);

void setup() {
  // Initialize rfid reader
  rfid.Init();
  Serial.begin(9600);
}

void loop() {
  uchar i,tmp;
  uchar status;
  uchar str[MAX_LEN];
  uchar RC_size;
  uchar blockAddr; //选择操作的块地址0～63 Select an action block address 0-63
  String mynum = "";
  
  //寻卡，返回卡类型 Find cards, return card type
  
  status = rfid.Request(0x26, str);

   if(status == MI_OK){
      Serial.println("Card detected");
      Serial.print(str[0],BIN);
      Serial.print(" , ");
      Serial.print(str[1],BIN);
      Serial.println(" ");
    }
    //Serial.println("second here");
    
    //防冲撞，返回卡的序列号 4字节 Anti-collision, return card serial number 4 bytes
    status = rfid.Anticoll(str);
    memcpy(serNum, str, 5);
    if(status == 0){
      if(serNum[0] == 93){
        for(int i = 0; i <512; i++){
//          clockwise();
        }
        Serial.println("Hello Colin");
      }
      else if(serNum[0] == 205){
        Serial.println("Hello David");
      }
      delay(3000);
    }
    //Command card into hibernation   
    rfid.Halt();
}
