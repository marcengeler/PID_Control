# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

To start with the PID controller, I fixed the values to

Kp = 0.5
Ki = 0.005
Kd = 5.0

However, the output showed a lot of oscillations. This cna be due to many facts. First of all, the control output of the PID control is unlimited, however the steering signal is limited to a range of -25° to 25°. This means that reducing the overall gain of the controller will lower it's signal and thus overshooting and oscillations.

Kp = 0.4
Ki = 0.006
Kd = 3

Because there were still a lot of oscillations, The increase of Kd can help to dampen the system.

Kp = 0.2
Ki = 0.005
Kd = 21

This helped a lot, however the controller showed large deviations from time to time. Because the control imnput reached maximum value as well, an anti-windup control was tested, however didn't work out without proper tuning out of the box.
That's why the integral part was reduced a bit to countermeasure.

Kp = 0.15
Ki = 0.00015
Kd = 12

The result looked fine after the tuning.
