#include "main.h"

using namespace okapi;

PID::PID(double kP, double kI, double kD, bool slew, double sRate) :
m_kP(kP), m_kD(kD), m_kI(kI), m_slew(slew), m_sRate(sRate) {
  m_lastTime = m_timer.millis().convert(millisecond);
}

double PID::calculateErr(double ierror) {
  m_error = ierror;
  //abort if dt is too small
  
  //calculate derivative
  m_derivative = (m_lastError-m_error);

  m_integral += m_error;
  
  //calculate output
  if (((m_output - m_lastOutput) > m_sRate) and m_slew) {
    m_output += m_slew;
  } else {
    m_output = (m_error * m_kP) + (m_integral*m_kI) +(m_derivative * m_kD);
  }
  //save values
  m_lastError = m_error;
  m_lastOutput = m_output;
  
  return m_output;
}

double PID::calculate(double target, double current) {
  return calculateErr(target - current);
}

double PID::getError() {
  return m_error;
}

void PID::reset() {
  m_error = 0;
  m_lastError = 0;
  m_lastTime = m_timer.millis().convert(millisecond);
  m_derivative = 0;
  m_output = 0;
}
