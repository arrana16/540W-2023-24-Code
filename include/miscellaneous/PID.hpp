#include "main.h"

class PID {
private: 
  double m_kP = 0;
  double m_kD = 0;
  double m_kI = 0;
  bool m_slew = false;
  double m_sRate = 0;
  
  
  okapi::Timer m_timer;
  double m_error = 0;
  double m_lastError = 0;
  double m_lastTime = 0;
  double m_derivative = 0;
  double m_integral = 0;
  double m_output = 0;
  double m_lastOutput = 0;
  
public:
  PID(double kP, double kD, double kI, bool max, double maxRate);
  double calculateErr(double);
  double calculate(double, double);
  double getError();
  double getTime();
  void reset();
};