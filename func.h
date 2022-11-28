#include <ESP32Servo.h>

// SERVOS: -----------------------------------
Servo neck_S;

// PINS: -------------------------------------
int neck      = 13;
int arms      = 12;

// DEGS: -------------------------------------
int look_deg  =  50;
int z_deg     =  90;

// SPEEDS: -----------------------------------
double look_t = 300;

// TIMERS: -----------------------------------
int look_delay  = 1000;
int pause_time  = 30000;
int chop_time   = 30000;

double started_chopping;

// BOOL: -------------------------------------
bool chopping;

// FUNCS: ------------------------------------

void servo_mover(Servo aServo, double angle, double duration_ms){
  double to_delay = duration_ms/angle;
  if (angle >= 0){
    for (int i = z_deg; i < z_deg + angle; i++){
      aServo.write(i);
      delay(to_delay);
    }
  }else {
    for (int i = z_deg; i >= z_deg + angle; i--){
      aServo.write(i);
      delay(to_delay);
    }
  }
}

void servo_remover(Servo aServo, double angle, double duration_ms){
  double to_delay = duration_ms/angle;
  if (angle >= 0){
    for (int i = z_deg + angle; i >= z_deg; i--){
      aServo.write(i);
      delay(to_delay);
    }
  } else {
    for (int i = z_deg + angle; i < z_deg; i++){
      aServo.write(i);
      delay(to_delay);
    }
  }
}
