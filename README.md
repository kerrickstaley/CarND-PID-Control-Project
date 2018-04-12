# Self-Driving Car Nanodegree PID Controller Project
In this project I created a PID controller to steer a simulated car around a track.

The PID controller computes the steering angle for the car, and the throttle is kept at a constant value that maintains
a speed of around 30-35 miles per hour.

At every time step, the cross-track error (CTE, represented below as `error`) is computed as the distance
between the car and the center of the road. The goal of the PID controller is to
minimize average CTE (and also make sure that at no time is CTE so large that the car drives off
the road).

The PID controller sets the steering angle based on Kp, Ki, and Kd coefficients. The exact formula is

    steer = -Kp * error - Ki * error_integ - Kd * error_deriv

where `error_integ` is the time integral of `error` and `error_deriv` is the time derivative of `error`.
The `-Kp * error` term is the principle feedback mechanism, whereby positive (rightwards) errors translate to negative
(leftwards) steering angles. The `-Kd * error_deriv` term prevents the system from oscillating in a fashion where it
repeatedly oversteers. The `-Ki * error_integ` term helps correct for systematic error, but in the case of the simulated
car there is no systematic error so I found that `Ki = 0` produced good results.

In order to find appropriate values for the `Kp` and `Kd` coefficients of the controller I manually tweaked the values
until I got an acceptable result. I first set the `Kp` coefficient to 0.1 and left the other parameters at zero.
With these parameters the car zig-zagged as it moved forward, and the oscillations grew over time until the car drove
off the track. I then increased the `Kd` coefficient until the oscillations stopped. After that the car drove smoothly
for the most part, but it wasn't reacting quickly enough as it approached curves. To fix this I increased both `Kp` and
`Kd` until the car was handling the curves (and wasn't oscillating).

If I had more time I'd use an optimization algorithm like Twiddle to find a better set of parameters that make the car
drive more smoothly. The car currently stays on the track but it nearly veers off at several points and its driving is
generally jerky.
