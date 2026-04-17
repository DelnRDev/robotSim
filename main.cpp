/*
- a flat floor
- robot starts at some point
- each update step changes its state

e.g
start at (0,0)
face right
speed = 2
after 1 sec move to (2,0)

*/

#include <iostream>
#include <cmath>
#include <vector>

class Robot{
public:
    double x;
    double y;
    double theta;
    double v; //speed of center of mass
    double vR;
    double vL;
    double omega;
    double L;
 
    Robot(double x_i, double y_i, double vL_i, double vR_i, double theta_i, double L_i){
        x = x_i;
        y = y_i;
        theta = theta_i;
        L = L_i;
        //omega = omega_i;
        vL = vL_i;
        vR = vR_i;
        v = 0.0;
        omega = 0.0; 
    }

    void printState(){
        std::cout << "Position (x,y) = (" << x << "m," << y << "m)\n";
        std::cout << "Heading angle = " << theta << " rad\n";
        std::cout << "Left wheel velocity : " << vL << " m/s\n";
        std::cout << "right wheel velocity : " << vR << "m/s\n";
        std::cout << "Speed: " << v << "m/s\n";
        std::cout << "Angular speed:" << omega << " rad/s\n";
        std::cout << "-----------------------------\n";
        
    }

    void update(double dt){
        v = (vL + vR)/2;
        omega = (vR - vL)/L;
        x += v * cos(theta) * dt;
        y += v * sin(theta) * dt;
        theta += omega * dt;
    }
};

int main(){

    Robot robot1(0.0, 0.0, 1.5, 2.0 ,0.0, 0.5);

    double dt = 0.1;

    std::vector<double> pathX;
    std::vector<double> pathY;

    for(int n = 0; n < 100; n++){
        robot1.update(dt);
        robot1.printState();
        pathX.push_back(robot1.x);
        pathY.push_back(robot1.y);
    }

    for(int n = 0; n < 100; n++){
        std::cout << "(" << pathX[n] << "," << pathY[n] << ")\n" ;
    }

    return 0;
}
