#ifndef I2CCHARDEV_H
#define I2CCHARDEV_H

#include <linux/ioctl.h>

#define MAGIC_NUM 100

//ioctl functions(sequence number ) for all the sensors in IMU
#define GYRO_X_AXIS_IOR(MAGIC_NUM, 0, int *)
#define GYRO_Y_AXIS_IOR(MAGIC_NUM, 1, int *)
#define GYRO_Z_AXIS_IOR(MAGIC_NUM, 2, int *)
#define COMPASS_X_AXIS_IOR(MAGIC_NUM, 3, int *)
#define COMPASS_Y_AXIS_IOR(MAGIC_NUM, 4, int *)
#define COMPASS_Z_AXIS_IOR(MAGIC_NUM, 5, int *)
#define ACCELEROMETER_X_AXIS_IOR(MAGIC_NUM, 6, int *)
#define ACCELEROMETER_Y_AXIS_IOR(MAGIC_NUM, 7, int *)
#define ACCELEROMETER_Z_AXIS_IOR(MAGIC_NUM, 8, int *)
#define BAROMETER_IOR(MAGIC_NUM,9,int*)

#define DEVICE_FILE_NAME "/dev/imu_char"


#endif