/*
  MFRC522.h - Library for MFRC522 RFID reader.
  Created by Colin Faulkingham, August 5, 2013.
  
  Original Code From,
  文 件 名：RFID.pde
  创 建 者：Dr.Leong   ( WWW.B2CQSHOP.COM )
  创建日期：2011.09.19
  修 改 者：
  修改日期：
  功能描述：Mifare1 寻卡→防冲突→选卡→读写 接口 Description: Mifare1 find cards anticollision → → → reader interface option card
*/

#ifndef MFRC522_h
#define MFRC522_h

#include "Arduino.h"

#define	uchar	unsigned char
#define	uint	unsigned int

//数组最大长度 Maximum length of the array
//#define MAX_LEN 16

//MF522命令字 command word
#define PCD_IDLE              0x00               //NO action;取消当前命令 Cancel the current command
#define PCD_AUTHENT           0x0E               //验证密钥 Authentication Key
#define PCD_RECEIVE           0x08               //接收数据 Receive Data
#define PCD_TRANSMIT          0x04               //发送数据 Transmit data
#define PCD_TRANSCEIVE        0x0C               //发送并接收数据 Transmit and receive data
#define PCD_RESETPHASE        0x0F               //复位 Reset
#define PCD_CALCCRC           0x03               //CRC计算 calculation

//Mifare_One卡片命令字 Mifare_One card command word
#define PICC_REQIDL           0x26               //寻天线区内未进入休眠状态 Find the antenna area does not enter hibernation
#define PICC_REQALL           0x52               //寻天线区内全部卡 Antenna area to find all cards
#define PICC_ANTICOLL         0x93               //防冲撞 Anti-collision
#define PICC_SElECTTAG        0x93               //选卡 Selection card
#define PICC_AUTHENT1A        0x60               //验证A密钥 A key authentication
#define PICC_AUTHENT1B        0x61               //验证B密钥 Authentication Key B
#define PICC_READ             0x30               //读块 Read Block
#define PICC_WRITE            0xA0               //写块 Write block
#define PICC_DECREMENT        0xC0               //扣款 Debit
#define PICC_INCREMENT        0xC1               //充值 Recharge
#define PICC_RESTORE          0xC2               //调块数据到缓冲区 Transfer block data to the buffer
#define PICC_TRANSFER         0xB0               //保存缓冲区中数据 Save the data in the buffer
#define PICC_HALT             0x50               //休眠 Dormancy


//和MF522通讯时返回的错误代码 And MF522 communication error code returned
#define MI_OK                 0
#define MI_NOTAGERR           1
#define MI_ERR                2

class MFRC522
{
  public:
    MFRC522(int PinSelect, int PinReset);
    void Halt(void);
    uchar Write(uchar blockAddr, uchar *writeData);
    uchar Read(uchar blockAddr, uchar *recvData);
    uchar Auth(uchar authMode, uchar BlockAddr, uchar *Sectorkey, uchar *serNum);
    uchar SelectTag(uchar *serNum);
    uchar Anticoll(uchar *serNum);
    uchar Request(uchar reqMode, uchar *TagType);
    void Init(void);
    void Reset(void);
    
  private:
    uchar MFRC522_ToCard(uchar command, uchar *sendData, uchar sendLen, uchar *backData, uint *backLen);
    void CalulateCRC(uchar *pIndata, uchar len, uchar *pOutData);
    void AntennaOff(void);
    void AntennaOn(void);
    void ClearBitMask(uchar reg, uchar mask);
    void SetBitMask(uchar reg, uchar mask);
    uchar Read_MFRC522(uchar addr);
    void Write_MFRC522(uchar addr, uchar val);

    int _pinReset;
    int _pinSelect;

};

#endif