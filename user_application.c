
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>              /* open */
#include <unistd.h>             /* exit */
#include <stdint.h>
#include <sys/ioctl.h>          /* ioctl */
#include "i2cchardev.h"


uint16_t data;

//ioctl functions for all the IMU sensors in respective axis

int ioctl_gyro_x_axis(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_gyro_x_axis failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}
int ioctl_gyro_y_axis(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_gyro_y_axis failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}
int ioctl_gyro_z_axis(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_gyro_z_axis failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}
int ioctl_compass_x_axis(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_compass_x_axis failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}
int ioctl_compass_y_axis(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_compass_y_axis failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}
int ioctl_compass_z_axis(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_compass_z_axis failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}
int ioctl_accelerometer_x_axis(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_accelerometer_x_axis failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}
int ioctl_accelerometer_y_axis(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_accelerometer_y_axis failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}
int ioctl_accelerometer_z_axis(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_accelerometer_z_axis failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}





int ioctl_barometer(int file_desc, int req)
{
    int ret_val;
    ret_val = ioctl(file_desc, req);
    if (ret_val < 0) {
        printf("ioctl_barometer failed:%d\n", ret_val);
        exit(-1);
    }
    return 0;
}

void decimal_to_binary(uint16_t n){
  int binaryNum[16];
  int i = 0;
  while (n > 0) {
      binaryNum[i] = n % 2;
      n = n / 2;
      i++;
  }
  printf("This number in binary is:");
  for (int j = i - 1; j >= 0; j--){
      printf("%d", binaryNum[j]);
     }
    printf("\n");
}


/*
 * Main - Call the ioctl functions
 */
int main()
{
    int file_desc, ret_val;
    int req;
    file_desc = open(DEVICE_FILE_NAME, 0);
    if (file_desc < 0) {
        printf("Can't open device file: %s\n", DEVICE_FILE_NAME);
        exit(-1);
    }
    printf("Enter the Request number:");
    scanf("%d", &req);
    if(req <0 || req>9) {
      printf("Invalid Selection of request no.\n");
      exit(-1);
    }
    if(req==0)
    	ioctl_gyro_x_axis( file_desc, req);
    elseif(req==1)
    	ioctl_gyro_y_axis( file_desc,  req);
    elseif(req==2)
    	ioctl_gyro_z_axis( file_desc,  req);
    elseif(req==3)
    	ioctl_compass_x_axis( file_desc,  req);
    elseif(req==4)
    	ioctl_compass_y_axis( file_desc,  req);
    elseif(req==5)
    	ioctl_compass_z_axis( file_desc,  req);
    elseif(req==6)
    	ioctl_accelerometer_x_axis( file_desc, req);
    elseif(req==7)
    	ioctl_accelerometer_y_axis( file_desc, req);
    elseif(req==8)
    	ioctl_accelerometer_z_axis( file_desc,  req);
    else
    	ioctl_barometer( file_desc,  req);

   
    if(read(file_desc,&data,sizeof(data))){
      if(align == 'l'){
          decimal_to_binary(data);
          data = data/64;
          printf("The actual decimal number is: %u --", data);
          decimal_to_binary(data);
      }
      else{
        printf("DATA read by the user is:%u --", data);
        decimal_to_binary(data);
      }
    }
    close(file_desc);
    return 0;
}
