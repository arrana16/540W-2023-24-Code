#include "main.h"  // Include the necessary header file(s) for the program

using namespace okapi;  // Use the okapi namespace for convenience

// Define the constructor for the PID class
PID::PID(double kP, double kI, double kD, bool slew, double sRate) :
m_kP(kP), m_kD(kD), m_kI(kI), m_slew(slew), m_sRate(sRate) {
  m_lastTime = m_timer.millis().convert(millisecond);  // Initialize the last time variable
}

// Calculate the error for the PID controller
double PID::calculateErr(double ierror) {
  m_error = ierror;  // Set the error value
  
  // Abort if the time difference is too small
  
  // Calculate the derivative
  m_derivative = (m_lastError - m_error);
  
  m_integral += m_error;  // Update the integral value
  
  // Calculate the output
  if (((m_output - m_lastOutput) > m_sRate) && m_slew) {
    m_output += m_slew;
  } else {
    m_output = (m_error * m_kP) + (m_integral * m_kI) + (m_derivative * m_kD);
  }
  
  // Save the current values for the next iteration
  m_lastError = m_error;
  m_lastOutput = m_output;
  
  return m_output;  // Return the calculated output
}

// Calculate the error for the PID controller using the target and current values
double PID::calculate(double target, double current) {
  return calculateErr(target - current);
}

// Get the current error value
double PID::getError() {
  return m_error;
}

// Reset the PID controller
void PID::reset() {
  m_error = 0;
  m_lastError = 0;
  m_lastTime = m_timer.millis().convert(millisecond);
  m_derivative = 0;
  m_output = 0;
}
