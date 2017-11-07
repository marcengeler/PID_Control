#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID.Kp = Kp;
	PID.Ki = Ki;
	PID.Kd = Kd;
	
	PID.p_error = 0.0;
	PID.i_error = 0.0;
	PID.d_error = 0.0;
	PID.prev_cte = 0.0;
	PID.i_cte = 0.0;
}

void PID::UpdateError(double cte) {
	PID.i_cte += cte;
	PID.p_error = PID.Kp * cte;
	PID.i_error = PID.Ki * cte;
	PID.d_error = PID.Kd * (cte - PID.prev_cte);
	PID.prev_cte = cte;
}

double PID::TotalError() {
	return PID.p_error + PID.i_error + PID.d_error;
}

