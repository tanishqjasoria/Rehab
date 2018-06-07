#include <Wire.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

#define PI 3.143

long t=0,t1=0,t2=0;
long diff=0;



//IMU Variables
const int G_SENS=131;          //a division factor that directly gives omega calculated
const int MPU=0x68;                  //address of the IMU sensor

float y_old_theta=0,y_theta=0;
float x_old_theta=0,x_theta=0;
float dt=0;

int GYRY=0, GYRX=0, GYRZ=0;
float pitch = 0, roll = 0;

typedef struct
{
  int id; // id
  int accX; // angle
  int accY;
  int accZ;
  int gryX;
  int gryY;
  int gryZ;
  int mgtX;
  int mgtY;
  int mgtZ;
} data1;

typedef struct
{
  int id; // id
  int accX; // angle
  int accY;
  int accZ;
  int gryX;
  int gryY;
  int gryZ;
  int mgtX;
  int mgtY;
  int mgtZ;
} data2;

data1 temp; 
data2 thigh1 ,thigh2, knee1 ,knee2, ankle1 ,ankle2;

RF24 radio(48,53);
const uint64_t pipes[6] = { 0xF0F0F0F0E0LL ,0xF0F0F0F0E1LL, 0xF0F0F0F0E2LL, 0xF0F0F0F0E3LL ,0xF0F0F0F0E4LL ,0xF0F0F0F0E5LL };


void get_imu_data()
{ 
  Wire.beginTransmission(MPU);                                                        //starting the communication again
  Wire.write(0x3B);                                                                  //start with this register address (its the first data register
  Wire.endTransmission(false);                                                        //continue to read data
  Wire.requestFrom(MPU,14,true);                                                     //request the slave to send the 14 byte data
  
  int16_t acc_x=Wire.read()<<8|Wire.read();                                                //acc_x is 16 bit data .the data is automatically read sequently from 0x3B
  int16_t acc_y=Wire.read()<<8|Wire.read();                                                 //all the data is sequently stored in registers in IMU....hence we can read it sequently only by specifying the starting address .
  int16_t acc_z=Wire.read()<<8|Wire.read();
  int16_t tmp=Wire.read()<<8|Wire.read();                                              //each quantity has 16 bit data..however the wire.read reads only 8 bit at a time.first H register and then L register
  int16_t gyr_x=Wire.read()<<8|Wire.read();
  int16_t gyr_y=Wire.read()<<8|Wire.read();
  int16_t gyr_z=Wire.read()<<8|Wire.read();
  Wire.endTransmission();                                                                  //end the transmission
  
  double ACCY=atan2((double)acc_x,(double)acc_z)*180/PI+90;
  double ACCX=atan2((double)acc_y,(double)acc_z)*180/PI+90; 
                                                                                                       //ACCY is the theta about y axis calculated from accelerometer data
  GYRX=(float)gyr_x/G_SENS;
  GYRY=-(float)gyr_y/G_SENS;      //GYRY is the omega about y axis          
  GYRZ=(float)gyr_z/G_SENS;                                                                                             //G_SENS is factor that directly gives the omega from raw data of gyroscope in IMU          
  dt=0.01;
  
  y_theta=0.85*(y_old_theta+GYRY*dt)+0.15*(ACCY);            //complimentary filter 
  x_theta=0.85*(x_old_theta+GYRX*dt)+0.15*(ACCX);
   
  y_old_theta=y_theta;
  x_old_theta=x_theta;

  pitch = y_theta;
  roll = x_theta;

  if(pitch>180 || pitch<-180)
  {
    if(pitch>180)
    {
      pitch = pitch-360;
    }
    else if(pitch<-180)
    {
      pitch = pitch+360;
    }
    else 
      pitch = 180;
  }

  if(roll>180 || roll<-180)
  {
    if(roll>180)
    {
      roll = roll-360;
    }
    else if(roll<-180)
    {
      roll = roll+360;
    }
    else 
      roll = 180;
  }

  if(pitch<0)
  {
    pitch=pitch+360;
  }

  if(roll<0)
  {

    roll=roll+360;
  }

  if(GYRX<0)
  {
    GYRX=GYRX+500;
  }

  if(GYRY<0)
  {
    GYRY=GYRY+500;
  }

  if(GYRZ<0)
  {
    GYRZ=GYRZ+500;
  }
}

//byte packet[136];
//void Send_Packet()
//{
//   uint32_t temp=0;
//  
// packet[0]=0;
//
// temp=(uint32_t)(thigh1.pitch*100.0);
//// packet[1]=((temp >> 16) & 0xff);//High 
// packet[1]=((temp >> 8) & 0xff);//mid 
// packet[2]=temp & 0xff;//Low
// //Serial.print(temp);
// 
// temp=(uint32_t)(thigh1.roll*100.0);
//// packet[2]=((temp >> 16) & 0xff);//High 
// packet[3]=((temp >> 8) & 0xff);//mid 
// packet[4]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
// temp=(uint32_t)(thigh1.gyrx*100.0);
//// packet[7]=((temp >> 16) & 0xff);//High 
// packet[5]=((temp >> 8) & 0xff);//mid 
// packet[6]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(thigh1.gyry*100.0);
//// packet[10]=((temp >> 16) & 0xff);//High 
// packet[7]=((temp >> 8) & 0xff);//mid 
// packet[8]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(thigh1.gyrz*100.0);
//// packet[13]=((temp >> 16) & 0xff);//High 
// packet[9]=((temp >> 8) & 0xff);//mid 
// packet[10]=temp & 0xff;//Low
//// Serial.print("   ");Serial.println(temp);
//
//
////**************Thigh Id =1*********//*****************************************************
//temp=(uint32_t)(thigh2.pitch*100.0);
// //packet[16]=((temp >> 16) & 0xff);//High 
// packet[11]=((temp >> 8) & 0xff);//mid 
// packet[12]=temp & 0xff;//Low
// //Serial.print(temp);
// 
// temp=(uint32_t)(thigh2.roll*100.0);
// //packet[19]=((temp >> 16) & 0xff);//High 
// packet[13]=((temp >> 8) & 0xff);//mid 
// packet[14]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
// temp=(uint32_t)(thigh2.gyrx*100.0);
//// packet[22]=((temp >> 16) & 0xff);//High 
// packet[15]=((temp >> 8) & 0xff);//mid 
// packet[16]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(thigh2.gyry*100.0);
//// packet[25]=((temp >> 16) & 0xff);//High 
// packet[17]=((temp >> 8) & 0xff);//mid 
// packet[18]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(thigh2.gyrz*100.0);
//// packet[28]=((temp >> 16) & 0xff);//High 
// packet[19]=((temp >> 8) & 0xff);//mid 
// packet[20]=temp & 0xff;//Low
//// Serial.print("   ");Serial.println(temp);
//
//
////Knee 1*****************************************************
//
//temp=(uint32_t)(knee1.pitch*100.0);
// //packet[31]=((temp >> 16) & 0xff);//High 
// packet[21]=((temp >> 8) & 0xff);//mid 
// packet[22]=temp & 0xff;//Low
// //Serial.print(temp);
// 
// temp=(uint32_t)(knee1.roll*100.0);
//// packet[34]=((temp >> 16) & 0xff);//High 
// packet[23]=((temp >> 8) & 0xff);//mid 
// packet[24]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
// temp=(uint32_t)(knee1.gyrx*100.0);
// //packet[37]=((temp >> 16) & 0xff);//High 
// packet[25]=((temp >> 8) & 0xff);//mid 
// packet[26]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(knee1.gyry*100.0);
//// packet[40]=((temp >> 16) & 0xff);//High 
// packet[27]=((temp >> 8) & 0xff);//mid 
// packet[28]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(knee1.gyrz*100.0);
// //packet[43]=((temp >> 16) & 0xff);//High 
// packet[29]=((temp >> 8) & 0xff);//mid 
// packet[30]=temp & 0xff;//Low
//// Serial.print("   ");Serial.println(temp);
//
////knee2 ***************************************************************
//temp=(uint32_t)(knee2.pitch*100.0);
// //packet[46]=((temp >> 16) & 0xff);//High 
// packet[31]=((temp >> 8) & 0xff);//mid 
// packet[32]=temp & 0xff;//Low
// //Serial.print(temp);
// 
// temp=(uint32_t)(knee2.roll*100.0);
//// packet[49]=((temp >> 16) & 0xff);//High 
// packet[33]=((temp >> 8) & 0xff);//mid 
// packet[34]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
// temp=(uint32_t)(knee2.gyrx*100.0);
//// packet[52]=((temp >> 16) & 0xff);//High 
// packet[35]=((temp >> 8) & 0xff);//mid 
// packet[36]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(knee2.gyry*100.0);
//// packet[55]=((temp >> 16) & 0xff);//High 
// packet[37]=((temp >> 8) & 0xff);//mid 
// packet[38]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(knee2.gyrz*100.0);
// //packet[58]=((temp >> 16) & 0xff);//High 
// packet[39]=((temp >> 8) & 0xff);//mid 
// packet[40]=temp & 0xff;//Low
//// Serial.print("   ");Serial.println(temp);
//
////********Ankle 1*******************************//
//temp=(uint32_t)(ankle1.pitch*100.0);
// //packet[41]=((temp >> 16) & 0xff);//High 
// packet[41]=((temp >> 8) & 0xff);//mid 
// packet[42]=temp & 0xff;//Low
// //Serial.print(temp);
// 
// temp=(uint32_t)(ankle1.roll*100.0);
//// packet[64]=((temp >> 16) & 0xff);//High 
// packet[43]=((temp >> 8) & 0xff);//mid 
// packet[44]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
// temp=(uint32_t)(ankle1.gyrx*100.0);
//// packet[67]=((temp >> 16) & 0xff);//High 
// packet[45]=((temp >> 8) & 0xff);//mid 
// packet[46]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(ankle1.gyry*100.0);
////packet[70]=((temp >> 16) & 0xff);//High 
// packet[47]=((temp >> 8) & 0xff);//mid 
// packet[48]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(ankle1.gyrz*100.0);
//// packet[73]=((temp >> 16) & 0xff);//High 
// packet[49]=((temp >> 8) & 0xff);//mid 
// packet[50]=temp & 0xff;//Low
//// Serial.print("   ");Serial.println(temp);
//
//
//temp=(uint32_t)(ankle1.forceSens1*100.0);
// //packet[76]=((temp >> 16) & 0xff);//High 
// packet[51]=((temp >> 8) & 0xff);//mid 
// packet[52]=temp & 0xff;//Low
//
//
// temp=(uint32_t)(ankle1.forceSens2*100.0);
// //packet[79]=((temp >> 16) & 0xff);//High 
// packet[53]=((temp >> 8) & 0xff);//mid 
// packet[54]=temp & 0xff;//Low
//
//
// temp=(uint32_t)(ankle1.forceSens3*100.0);
//// packet[82]=((temp >> 16) & 0xff);//High 
// packet[55]=((temp >> 8) & 0xff);//mid 
// packet[56]=temp & 0xff;//Low
//
// temp=(uint32_t)(ankle1.forceSens4*100.0);
// //packet[85]=((temp >> 16) & 0xff);//High 
// packet[57]=((temp >> 8) & 0xff);//mid 
// packet[58]=temp & 0xff;//Low
//
//  temp=(uint32_t)(ankle1.forceSens5*100.0);
//// packet[88]=((temp >> 16) & 0xff);//High 
// packet[59]=((temp >> 8) & 0xff);//mid 
// packet[60]=temp & 0xff;//Low
//
//
//// //Ankle 2***************************************************************
//
// 
//temp=(uint32_t)(ankle2.pitch*100.0);
//// packet[91]=((temp >> 16) & 0xff);//High 
// packet[61]=((temp >> 8) & 0xff);//mid 
// packet[62]=temp & 0xff;//Low
// //Serial.print(temp);
// 
// temp=(uint32_t)(ankle2.roll*100.0);
//// packet[94]=((temp >> 16) & 0xff);//High 
// packet[63]=((temp >> 8) & 0xff);//mid 
// packet[64]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
// temp=(uint32_t)(ankle2.gyrx*100.0);
//// packet[97]=((temp >> 16) & 0xff);//High 
// packet[65]=((temp >> 8) & 0xff);//mid 
// packet[66]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(ankle2.gyry*100.0);
// //packet[100]=((temp >> 16) & 0xff);//High 
// packet[67]=((temp >> 8) & 0xff);//mid 
// packet[68]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(ankle2.gyrz*100.0);
// //packet[103]=((temp >> 16) & 0xff);//High 
// packet[69]=((temp >> 8) & 0xff);//mid 
// packet[70]=temp & 0xff;//Low
//// Serial.print("   ");Serial.println(temp);
//
//
//temp=(uint32_t)(ankle2.forceSens1*100.0);
//// packet[106]=((temp >> 16) & 0xff);//High 
// packet[71]=((temp >> 8) & 0xff);//mid 
// packet[72]=temp & 0xff;//Low
//
//
// temp=(uint32_t)(ankle2.forceSens2*100.0);
//// packet[109]=((temp >> 16) & 0xff);//High 
// packet[73]=((temp >> 8) & 0xff);//mid 
// packet[74]=temp & 0xff;//Low
//
//
// temp=(uint32_t)(ankle2.forceSens3*100.0);
// //packet[112]=((temp >> 16) & 0xff);//High 
// packet[75]=((temp >> 8) & 0xff);//mid 
// packet[76]=temp & 0xff;//Low
//
// temp=(uint32_t)(ankle2.forceSens4*100.0);
//// packet[115]=((temp >> 16) & 0xff);//High 
// packet[77]=((temp >> 8) & 0xff);//mid 
// packet[78]=temp & 0xff;//Low
//
//  temp=(uint32_t)(ankle2.forceSens5*100.0);
// //packet[118]=((temp >> 16) & 0xff);//High 
// packet[79]=((temp >> 8) & 0xff);//mid 
// packet[80]=temp & 0xff;//Low
//
//
////Main Board****************************************************
//
//temp=(uint32_t)(pitch*100.0);
// //packet[121]=((temp >> 16) & 0xff);//High 
// packet[81]=((temp >> 8) & 0xff);//mid 
// packet[82]=temp & 0xff;//Low
// //Serial.print(temp);
// 
// temp=(uint32_t)(roll*100.0);
//// packet[124]=((temp >> 16) & 0xff);//High 
// packet[83]=((temp >> 8) & 0xff);//mid 
// packet[84]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
// temp=(uint32_t)(GYRX*100.0);
//// packet[127]=((temp >> 16) & 0xff);//High 
// packet[85]=((temp >> 8) & 0xff);//mid 
// packet[86]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(GYRY*100.0);
// //packet[130]=((temp >> 16) & 0xff);//High 
// packet[87]=((temp >> 8) & 0xff);//mid 
// packet[88]=temp & 0xff;//Low
//// Serial.print("   ");Serial.print(temp);
//
//
// temp=(uint32_t)(GYRZ*100.0);
// //packet[133]=((temp >> 16) & 0xff);//High 
// packet[89]=((temp >> 8) & 0xff);//mid 
// packet[90]=temp & 0xff;//Low
//// Serial.print("   ");Serial.println(temp);
//
////for(int i=0;i<16;i++)
////{
////  Serial.println(packet[i]);
////}
////Serial.println("Complete");
//
//
// Serial3.write(packet,91);
//// delay(10);
//}


void setup(void) {
  t=millis();
Serial.begin(115200);
//Serial3.begin(57600);
Wire.begin();                                                                            //start with I2C transmission
Wire.beginTransmission(MPU);                                                                      //transmission with this address
Wire.write(0x6B);                                                                        //first specifies power management address of MCU to be given command 
Wire.write(0);                                                                           //awakes MCU by sending 0 to above register address
Wire.endTransmission(true);

radio.begin();
radio.setDataRate(RF24_2MBPS);
radio.setPALevel(RF24_PA_MIN);

radio.openReadingPipe(0, pipes[0]);
radio.openReadingPipe(1, pipes[1]);
radio.openReadingPipe(2, pipes[2]);
radio.openReadingPipe(3, pipes[3]);
radio.openReadingPipe(4, pipes[4]);
radio.openReadingPipe(5, pipes[5]);

//radio.closeReadingPipe(pipes[1]);

radio.startListening();
}

void loop(void)
{
  get_imu_data();
  
  if ( radio.available() )
  {
    //Serial.println("Hello");
    //delay(5);
    radio.read(&temp, sizeof(temp));
    
    switch(temp.id)
    {
      case 0:
      thigh1.id=0;
      thigh1.accX = temp.accX;
      thigh1.accY = temp.accY;
      thigh1.accZ = temp.accZ;
      thigh1.gryX = temp.gryX;
      thigh1.gryY = temp.gryY;
      thigh1.gryZ = temp.gryZ;
      thigh1.mgtX = temp.mgtX;
      thigh1.mgtY = temp.mgtY;
      thigh1.mgtZ = temp.mgtZ;
      break;
      
      case 1:
      thigh2.id=0;
      thigh2.accX = temp.accX;
      thigh2.accY = temp.accY;
      thigh2.accZ = temp.accZ;
      thigh2.gryX = temp.gryX;
      thigh2.gryY = temp.gryY;
      thigh2.gryZ = temp.gryZ;
      thigh2.mgtX = temp.mgtX;
      thigh2.mgtY = temp.mgtY;
      thigh2.mgtZ = temp.mgtZ;
      break;
      
      case 2:
      knee1.id=0;
      knee1.accX = temp.accX;
      knee1.accY = temp.accY;
      knee1.accZ = temp.accZ;
      knee1.gryX = temp.gryX;
      knee1.gryY = temp.gryY;
      knee1.gryZ = temp.gryZ;
      knee1.mgtX = temp.mgtX;
      knee1.mgtY = temp.mgtY;
      knee1.mgtZ = temp.mgtZ;
      break;
      
      case 3:
      knee2.id=0;
      knee2.accX = temp.accX;
      knee2.accY = temp.accY;
      knee2.accZ = temp.accZ;
      knee2.gryX = temp.gryX;
      knee2.gryY = temp.gryY;
      knee2.gryZ = temp.gryZ;
      knee2.mgtX = temp.mgtX;
      knee2.mgtY = temp.mgtY;
      knee2.mgtZ = temp.mgtZ;
      
      break;
      
//      case 4:
//      ankle1.id=4;
//      ankle1.pitch = ((float)temp.pitch)/100;
//      ankle1.roll = ((float)temp.roll)/100;
//      ankle1.gyrx = temp.gyrx;
//      ankle1.gyry = temp.gyry;
//      ankle1.gyrz = temp.gyrz;
//      ankle1.forceSens1 = temp.forceSens1;
//      ankle1.forceSens2 = temp.forceSens2;
//      ankle1.forceSens3 = temp.forceSens3;
//      ankle1.forceSens4 = temp.forceSens4;
//      ankle1.forceSens5 = temp.forceSens5;
//      ankle1.forceSens6 = temp.forceSens6/100.00;
//      ankle1.forceSens7 = temp.forceSens7/100.00;
//      ankle1.forceSens8 = temp.forceSens8/100.00;
//      break;
//      
//      case 5:
//      ankle2.id=5;
//      ankle2.pitch = ((float)temp.pitch)/100;
//      ankle2.roll = ((float)temp.roll)/100;
//      ankle2.gyrx = temp.gyrx;
//      ankle2.gyry = temp.gyry;
//      ankle2.gyrz = temp.gyrz;
//      ankle2.forceSens1 = temp.forceSens1;
//      ankle2.forceSens2 = temp.forceSens2;
//      ankle2.forceSens3 = temp.forceSens3;
//      ankle2.forceSens4 = temp.forceSens4;
//      ankle2.forceSens5 = temp.forceSens5;
//      ankle2.forceSens6 = temp.forceSens6/100.0;
//      ankle2.forceSens7 = temp.forceSens7/100.0;
//      ankle2.forceSens8 = temp.forceSens8/100.0;
//
//      break;
      default:
      break;  
    }  
  }
  else
  {
    //Serial.println("no data available");
  }
 //delay(1);
 //Send_Packet();
 t1=millis();
 diff=t1-t2;
 t2=t1;
 _print();
} 


void _print()
{
 Serial.print("t1: ");Serial.print(" accX=");Serial.print(thigh1.accX);Serial.print(" accY=");Serial.print(thigh1.accY);Serial.print(" accZ=");Serial.print(thigh1.accZ);Serial.print(" gryX=");Serial.print(thigh1.gryX);Serial.print(" gryY=");Serial.print(thigh1.gryY);Serial.print(" gryZ=");Serial.print(thigh1.gryZ);Serial.print(" mgtX=");Serial.print(thigh1.mgtX);Serial.print(" mgtY=");Serial.print(thigh1.mgtY);Serial.print(" mgtZ=");Serial.print(thigh1.mgtZ);   
 Serial.print("t2: ");Serial.print(" accX=");Serial.print(thigh2.accX);Serial.print(" accY=");Serial.print(thigh2.accY);Serial.print(" accZ=");Serial.print(thigh2.accZ);Serial.print(" gryX=");Serial.print(thigh2.gryX);Serial.print(" gryY=");Serial.print(thigh2.gryY);Serial.print(" gryZ=");Serial.print(thigh2.gryZ);Serial.print(" mgtX=");Serial.print(thigh2.mgtX);Serial.print(" mgtY=");Serial.print(thigh2.mgtY);Serial.print(" mgtZ=");Serial.print(thigh2.mgtZ);   
 Serial.print("k1: ");Serial.print(" accX=");Serial.print(knee1.accX);Serial.print(" accY=");Serial.print(knee1.accY);Serial.print(" accZ=");Serial.print(knee1.accZ);Serial.print(" gryX=");Serial.print(knee1.gryX);Serial.print(" gryY=");Serial.print(knee1.gryY);Serial.print(" gryZ=");Serial.print(knee1.gryZ);Serial.print(" mgtX=");Serial.print(knee1.mgtX);Serial.print(" mgtY=");Serial.print(knee1.mgtY);Serial.print(" mgtZ=");Serial.print(knee1.mgtZ);   
 Serial.print("k2: ");Serial.print(" accX=");Serial.print(knee2.accX);Serial.print(" accY=");Serial.print(knee2.accY);Serial.print(" accZ=");Serial.print(knee2.accZ);Serial.print(" gryX=");Serial.print(knee2.gryX);Serial.print(" gryY=");Serial.print(knee2.gryY);Serial.print(" gryZ=");Serial.print(knee2.gryZ);Serial.print(" mgtX=");Serial.print(knee2.mgtX);Serial.print(" mgtY=");Serial.print(knee2.mgtY);Serial.print(" mgtZ=");Serial.print(knee2.mgtZ);   
 //Serial.print("  a1: ");Serial.print(" pit=");Serial.print(ankle1.pitch);Serial.print(" roll=");Serial.print(ankle2.roll);Serial.print("\tF1 =");Serial.print(ankle1.forceSens6);Serial.print("\tF2 =");Serial.print(ankle1.forceSens7);Serial.print("\tF3 =");Serial.println(ankle1.forceSens8);//Serial.print("\tF4 =");Serial.print(Data.forceSens4);Serial.print("\tF5 =");Serial.println(Data.forceSens5);
 //Serial.print("  a2: ");Serial.print(" pit=");Serial.print(ankle2.pitch);Serial.print(" roll=");Serial.print(ankle2.roll);Serial.print("\tF1 =");Serial.print(ankle2.forceSens6);Serial.print("\tF2 =");Serial.print(ankle2.forceSens7);Serial.print("\tF3 =");Serial.print(ankle2.forceSens8);//Serial.print("\tF4 =");Serial.print(ankle2.forceSens4);Serial.print("\tF5 =");Serial.println(ankle2.forceSens5);
 Serial.print("  T: ");Serial.print(" pit=");Serial.print(pitch);Serial.print(" roll=");Serial.print(roll);Serial.print("  time");Serial.println(diff);
 //Serial.println();
}
