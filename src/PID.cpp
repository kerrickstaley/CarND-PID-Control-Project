#include <cmath>
#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  this->p_error = NAN;
  this->i_error = 0;
  this->d_error = NAN;
  this->prev_cte = NAN;
  this->total_error = 0;
}

void PID::UpdateError(double cte) {
  if (isnan(prev_cte)) {
    prev_cte = cte;
  }

  p_error = cte;
  i_error += cte;
  d_error = cte - prev_cte;
  total_error += fabs(cte);
}

double PID::TotalError() {
  return total_error;
}

