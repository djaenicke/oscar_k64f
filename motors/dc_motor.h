/*
 * DCMotor.h
 *
 *  Created on: Jun 7, 2019
 *      Author: Devin
 */

#ifndef MOTORS_DC_MOTOR_H_
#define MOTORS_DC_MOTOR_H_

#include "mbed.h"
#include "io_abstraction.h"

typedef enum {
  UNKNOWN_DIR = 0,
  FORWARD,
  REVERSE
} Direction_T;

typedef enum {
  UNKNOWN_LOC = 0,
  RIGHT_SIDE,
  LEFT_SIDE
} Location_T;

class DC_Motor {
 public:
  explicit DC_Motor(Location_T loc);
  bool stopped = true;
  void SetDirection(Direction_T dir);
  Direction_T GetDirection(void);
  void SetDC(uint8_t percent);
  void Freewheel(void);
  void Stop(void);

 private:
  Location_T loc_ = UNKNOWN_LOC;
  Direction_T direction_ = UNKNOWN_DIR;
};

#endif /* MOTORS_DC_MOTOR_H_ */