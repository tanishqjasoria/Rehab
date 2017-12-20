#include <Wire.h>
#define PI 3.14159265
#include "HX711.h"

#define calibration_factor -23000.0 //found out exp increase or decrease for matching using std weights
#define DOUT1 2
#define CLK1 3

#define DOUT2 5
#define CLK2 4

#define DOUT3 12
#define CLK3 11

//Load Sensor Behaviour
HX711 scale1(DOUT1, CLK1);
HX711 scale2(DOUT2, CLK2);
HX711 scale3(DOUT3, CLK3);

float data1=0,data2=0,data3=0,t_t;

//IMU Variables
const int G_SENS=131;          //a division factor that directly gives omega calculated
const int MPU=0x68;                  //address of the IMU sensor
float dt = 0;
float y_old_theta=0,y_theta=0;
float x_old_theta=0,x_theta=0;
float pitch = 0, roll = 0;

int GYRY=0, GYRX=0, GYRZ=0;

typedef struct
{
  int id; // id
  int pitch; // angle
  int roll;
  int gyrx;
  int gyry;
  int gyrz;
  int forceSens1;
  int forceSens2;
  int forceSens3;
  int forceSens4;
  int forceSens5;
  int forceSens6;
  int forceSens7;
  int forceSens8;
} data;


data Data;

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

//-180 to 180 to 0 to 360 Conversion

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
  GYRX=GYRX+250;
}

  
if(GYRY<0)
{
  GYRY=GYRY+250;
}

if(GYRZ<0)
{
  GYRZ=GYRZ+250;
}
  
  //Serial.println(y_theta);
}

void setup(void) 
{
  Serial.begin(115200);                                                                    //data send by IMU is too fast
  Serial2.begin(115200);                                                                   //For rx tx between mega and nano
  Wire.begin();                                                                            //start with I2C transmission
  Wire.beginTransmission(MPU);                                                                      //transmission with this address
  Wire.write(0x6B);                                                                        //first specifies power management address of MCU to be given command 
  Wire.write(0);                                                                           //awakes MCU by sending 0 to above register address
  Wire.endTransmission(true);
 
  Data.id = 4;
  
  scale1.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale1.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0

  scale2.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale2.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0

  scale3.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale3.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0


}

void loop(void)
{ 
  get_imu_data();

  data1=scale1.get_units();
  if(data1<0)
    data1=0;
    
  data2=scale2.get_units();
  if(data2<0)
    data2=0;
  
  data3=scale3.get_units();
  if(data3<0)
    data3=0;
  
  Data.pitch = int(pitch*100);
  Data.roll = int(roll*100);
  Data.gyrx = GYRX;
  Data.gyry = GYRY;
  Data.gyrz = GYRZ;
  Data.forceSens6=(int)(data1*100.0);
  Data.forceSens7=(int)(data2*100.0);
  Data.forceSens8=(int)(data3*100.0);
  //Serial.println("Data Sent");
  _print();
}

void _print()
{
  float a = Data.forceSens6/100.00;
  float b = Data.forceSens7/100.00;
  float c = Data.forceSens8/100.00;
  t_t=millis()/1000.0;
  Serial.print("time =");Serial.print(t_t,2);
  Serial.print(" pitch =");Serial.print(pitch);
  Serial.print("  roll =");Serial.print(roll);
  Serial.print("  gyrx =");Serial.print(Data.gyrx);
  Serial.print("  gyry =");Serial.print(Data.gyry);
  Serial.print("  gyrz =");Serial.print(Data.gyrz);
  Serial.print("  F6 =");Serial.print(a);
  Serial.print("  F7 =");Serial.print(b);
  Serial.print("  F8 =");Serial.println(c);
  Serial.println();
}
