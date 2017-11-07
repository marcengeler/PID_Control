#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;
	
	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;
	prev_cte = 0.0;
	i_cte = 0.0;
}

void PID::UpdateError(double cte) {
	AntiWindup();
	i_cte += cte;
	p_error = Kp * cte;
	i_error = Ki * cte;
	d_error = Kd * (cte - prev_cte);
	
	prev_cte = cte;
}

double PID::TotalError() {
	return p_error + i_error + d_error;
}

double PID::AntiWindup() {
	double control = p_error + i_error + d_error;
	if (control > 0) {
		double dcontrol = 25 - control;
	} else {
		double dcontrol = -25 - control;
	}
	
    d_windup += d_error;
	i_windup = 0.5 * dcontrol;
	
	i_error += 0.5 * i_windup;
	d_error -= d_windup;
	
	return p_error + i_error + 0.5 * d_error;
}

