
#include "transform.h"

void LP2GP(double lx, double ly, double posx, double posy, double ori, double * gx, double * gy)//X+方向 ori = 0，Y+方向 ori = pi/2，即顺时针为正
{
    const double PI = 3.14159265;
 //此处需完成
//输入： lx,ly为激光坐标系下激光点坐标；posx,posy,ori为机器人当前位姿；
//输出：gx,gy即函数输出的变换后的全局坐标
    double theta = atan(ly/lx);
    double dis = lx / cos(theta);
    *gx = posx + dis * cos(theta+ori-PI/2);
    *gy = posy + dis * sin(theta+ori-PI/2);
}
