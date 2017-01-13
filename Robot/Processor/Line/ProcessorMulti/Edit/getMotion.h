#include <cmath>
#include <vector>
using namespace std;
#define STEER_LEFT_MAX -255
#define STEER_RIGHT_MAX 255
#define SPEED_MIN -50
#define SPEED_MAX 50
#define FORCE_MAX 250.0
#define FORCE_INIT 140.0
#define PI 3.1415926
#define turn_underhold 30.0
struct Coordinate2D {
    double x;
    double y;
    Coordinate2D() { x=0.0, y=0.0; }
    Coordinate2D(double a, double b) { x=a, y=b; }
};

Coordinate2D calcForce(Coordinate2D robot_pos, std::vector<Coordinate2D> coordinate2DVec)
{
    Coordinate2D force(0.0, FORCE_INIT);
    for (vector<Coordinate2D>::iterator it = coordinate2DVec.begin(); it != coordinate2DVec.end(); it++)
    {
        double dx = robot_pos.x - it->x;
        double dy = robot_pos.y - it->y;
        double dis_squared = dx*dx + dy*dy;
        double force_value = 1/dis_squared;

        //if(force > thres)
        //{
        force.x += dx / sqrt(dis_squared) * force_value;
        force.y += dy / sqrt(dis_squared) * force_value;
        //}
        }
    return force;
}

// robot coordination
void getMotion(vector<Coordinate2D> coordinate2DVec, short &speed, short &steer)
{
    Coordinate2D force = calcForce(Coordinate2D(0.0, 0.0), coordinate2DVec);
    double force_value = sqrt(force.x*force.x + force.y*force.y);
    double angle = fabs(atan(force.y/force.x));
    if (force.x > turn_underhold)
        steer = STEER_RIGHT_MAX * angle /PI * 2;
    else if (force.x < -turn_underhold)
        steer = STEER_LEFT_MAX * angle /PI * 2;
    else
        steer = 0;

    double speed_underhold = max(0.4,force_value/FORCE_MAX);
    if (force.y >= 0)
        speed = SPEED_MAX * min(1.0, speed_underhold);
    else
        speed = SPEED_MIN * min(1.0, speed_underhold);
}

// global coordination
/*
 * void getMotion(Coordinate2D robot_pos, double robot_ori, std::vector<Coordinate2D> coordinate2DVec, short &speed, short &steer)
{
    std::vector<Coordinate2D> robot_coordinate2DVec;
    for (std::vector<Coordinate2D>::iterator it = coordinate2DVec.begin(), ; it != coordinate2DVec.end(); it++)
    {
        double dx = robot_pos.x - it->x;
        double dy = robot_pos.y - it->y;
        double dis = std::sqrt(dx*dx + dy*dy);
        Coordinate2D local;
    }
}
*/
