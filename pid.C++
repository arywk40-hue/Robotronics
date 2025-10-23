// Simple Car Speed PID Controller
double carSpeedPID(double desired_speed, double current_speed) {
    // PID Gains (you need to tune these)
    double Kp = 0.8;  // Proportional
    double Ki = 0.2;  // Integral  
    double Kd = 0.05; // Derivative
    
    static double prev_error = 0;
    static double total_error = 0;
    
    // Calculate error
    double error = desired_speed - current_speed;
    
    // PID Terms
    double P = Kp * error;                    // Current error
    double I = Ki * total_error;              // Past errors
    double D = Kd * (error - prev_error);     // Future error prediction
    
    // Update for next cycle
    total_error += error;
    prev_error = error;
    
    // Final control signal (throttle/brake)
    return P + I + D;
}

// Usage in main loop
void main() {
    double target_speed = 5.0; // 5 km/h
    
    while(true) {
       // double current_speed = readSpeedSensor(); // Get actual speed
        
       // double throttle = carSpeedPID(target_speed, current_speed);
        
        // Apply to car (positive = accelerate, negative = brake)
       // setThrottle(throttle);
        
       // delay(100); // Wait before next reading
    }
}

// I've learned that PID acts like the robot's automatic steering system. While BFS is the GPS that
// plans the route, PID is what actually keeps the car on the road.

// It constantly makes small adjustments - if the robot starts drifting left, PID gently steers it right;
//  if it's moving too fast into a turn, PID slows it down smoothly. 
//  The three parts work together: P for immediate reactions, I for fixing steady errors, and D for preventing overshoot.

// This means the robot doesn't jerk around or bump into walls - it glides through the maze like a skilled driver,
//  making real-time corrections while following the planned path. 
//  PID handles the "how to drive" while BFS handles the "where to go."

// Increasing Kp makes the robot react more aggressively to errors - it turns harder when off-center but may start oscillating. 
// Increasing Ki eliminates steady-state error - it gradually corrects small persistent deviations but can cause overshoot if too high. 
// Increasing Kd dampens oscillations - it predicts future errors to smooth movements but can make the robot sluggish if overdone. 
// Start with Kp alone, add small Ki for precision, then minimal Kd for stability, testing after each adjustment.