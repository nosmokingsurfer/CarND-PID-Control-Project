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

    this->cte_prev = 0;
}

void PID::UpdateError(double cte) {


    this->p_error = cte;
    this->i_error += cte;
    this->d_error = cte - this->cte_prev;

    this->cte_prev = cte;
}

double PID::TotalError() {
}

