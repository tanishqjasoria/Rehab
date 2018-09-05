#include <Wire.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "MPU9250.h"
int status;
#define PI 3.143
MPU9250 IMU(Wire,0x68);

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
} data;


data Data;

RF24 radio(9,10);
const uint64_t pipes[6] = { 0xF0F0F0F0E0LL ,0xF0F0F0F0E1LL, 0xF0F0F0F0E2LL, 0xF0F0F0F0E3LL , 0xF0F0F0F0E4LL ,0xF0F0F0F0E5LL };
void mpu_init()
{
  status = IMU.begin();
  if (status < 0) {
  Serial.println("IMU initialization unsuccessful");
  Serial.println("Check IMU wiring or try cycling power");
  Serial.print("Status: ");
  Serial.println(status);
  while(1) {}
  }
  // setting the accelerometer full scale range to +/-8G 
  IMU.setAccelRange(MPU9250::ACCEL_RANGE_8G);
  // setting the gyroscope full scale range to +/-500 deg/s
  IMU.setGyroRange(MPU9250::GYRO_RANGE_500DPS);
  // setting DLPF bandwidth to 20 Hz
  IMU.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
  // setting SRD to 19 for a 50 Hz update rate
  IMU.setSrd(19);
}
void getIMU_9250()
{
  IMU.readSensor();
  Data.accX = IMU.getAccelX_mss()*100;
  Data.accY = IMU.getAccelY_mss()*100;
  Data.accZ = IMU.getAccelZ_mss()*100;
  Data.gryX = IMU.getGyroX_rads()*100;
  Data.gryY = IMU.getGyroY_rads()*100;
  Data.gryZ = IMU.getGyroZ_rads()*100;
  Data.mgtX = IMU.getMagX_uT()*100;
  Data.mgtY = IMU.getMagY_uT()*100;
  Data.mgtZ = IMU.getMagZ_uT()*100;
}

void setup(void) 
{
Serial.begin(115200);                                                                    //data send by IMU is too fast
mpu_init();

Data.id = 2;

radio.begin();
radio.setDataRate(RF24_2MBPS);
radio.setPALevel(RF24_PA_MIN);
radio.openWritingPipe(pipes[Data.id]);
}

void loop(void)
{  
  getIMU_9250();
  radio.write(&Data, sizeof(Data));
  _print();
}

void _print()
{
  Serial.print("accX =");Serial.print(Data.accX);
  Serial.print("  accY =");Serial.print(Data.accY);
  Serial.print("  accZ =");Serial.print(Data.accZ);
  Serial.print("  gyrX =");Serial.print(Data.gryX);
  Serial.print("  gyrY =");Serial.print(Data.gryY);
  Serial.print("  gyrZ =");Serial.print(Data.gryZ);
  Serial.print("  mgtX =");Serial.print(Data.mgtX);
  Serial.print("  mgtY =");Serial.print(Data.mgtY);
  Serial.print("  mgtZ =");Serial.println(Data.mgtZ);
}
