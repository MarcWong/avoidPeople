#include <cmath>
#include <vector>

#define STEER_LEFT_MAX -255
#define STEER_RIGHT_MAX 255
#define SPEED_MIN -50
#define SPEED_MAX 50
#define FORCE_MAX 100.0

struct Coordinate2D {
    double x;
    double y;
    Coordinate2D() { x=0.0, y=0.0; }
    Coordinate2D(double a, double b) { x=a, y=b; }
};

Coordinate2D calcForce(Coordinate2D robot_pos, std::vector<Coordinate2D> coordinate2DVec)
{
    Coordinate2D force(0.0, 0.0);
    for (std::vector<Coordinate2D>::iterator it = coordinate2DVec.begin(); it != coordinate2DVec.end(); it++)
    {
        double dx = robot_pos.x - it->x;
        double dy = robot_pos.y - it->y;
        double dis_squared = dx*dx + dy*dy;
        force.x += dx / dis_squared;
        force.y += dy / dis_squared;
    }
    return force;
}

// robot coordination
void getMotion(Coordinate2D robot_pos, std::vector<Coordinate2D> coordinate2DVec, short &speed, short &steer)
{
    Coordinate2D force = calcForce(robot_pos, coordinate2DVec);
    double force_value = std::sqrt(force.x*force.x + force.y*force.y);
    if (force.x > 0)
        steer = STEER_LEFT_MAX;
    else if (force.x == 0)
        steer = 0;
    else
        steer = STEER_RIGHT_MAX;
    if (force.y >= 0)
        speed = SPEED_MAX * std::min(1, force_value/FORCE_MAX);
    else
        speed = SPEED_MIN * std::min(1, force_value/FORCE_MAX);
}

// global coordination
void getMotion(Coordinate2D robot_pos, double robot_ori, std::vector<Coordinate2D> coordinate2DVec, short &speed, short &steer)
{
    std::vector<Coordinate2D> robot_coordinate2DVec;
    for (std::vector<Coordinate2D>::iterator it = coordinate2DVec.begin(), ; it != coordinate2DVec.end(); it++)
    {
        double dx = robot_pos.x - it->x;
        double dy = robot_pos.y - it->y;
        double dis = std::sqrt(dx*dx + dy*dy);
        robot_coordinate2DVec
    }
}
