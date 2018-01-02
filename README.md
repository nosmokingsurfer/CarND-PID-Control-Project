# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

---

# Reflection
 
# Describe the effect each of the P, I, D components had in your implementation
Proportional component is responsible for main input into the steering. It is just proportional to the cross track error. If I use only the P component in PID controller there will be lot of oscillations with constant amplitude. If to make the analogy with point mass motion — the P component acts like elastic spring — there is no damping in absolutely elastic spring force so the point will oscillate around the fixed point with amplitude which depends on the initial condition.
 
The Differential component is responsible for damping the steering — if the car approaches the target trajectory i.e. the CTE changes with high rate the D component increases and counteracts to the P component. If to make the analogy to the point mass motion — the D component is a viscous friction force that is opposite to the direction of point mass motion.
 
The Integral component is responsible for eliminating systematic biases, which are caused by external forces, which cannot be measured or predicted. It accumulates the error over the time and at some moment the I component becomes significant in comparison with P and D components and starts influencing the PID output.
 
# Describe how the final hyper parameters were chosen.
 
I ran a series of experiments and tried different combination of coefficients. I have practical experience of PID controller tuning. I started with the P component. After I got some stable oscillations, I added the D component. At last, I added the I component.
 
The fastest speed of my model is about 40 miles per hour — the car was able to drive several laps without going off the track or popping on the ledges.

