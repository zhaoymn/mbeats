#ifndef ROBOT_H
#define ROBOT_H
#include <serial_sender.h>
#include <QDebug>

class robot
{

public:
    int current_angle;
    serial_sender *ss;
    int angles[31]; // ={90,89,91,88,92,87,93,86,94,85,95,84,96,83,97,82,98,81,99,80,100,79,101,78,102,77,103,76,104,75,105};
    robot();
    void rotate(int);

};

#endif // ROBOT_H
