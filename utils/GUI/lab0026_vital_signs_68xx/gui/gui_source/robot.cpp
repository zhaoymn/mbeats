#include "robot.h"

robot::robot()
{
    for(int i = 75; i <= 105; i++) {
        angles[i-75] = i;
    }
    current_angle = 75;
    ss = new serial_sender();
    ss->serial_connect();
    qDebug()<<"serial started";
    //ss->send_command(75);
}

void robot::rotate(int angle){
    assert(angle >= 75 && angle <= 105);
    ss->send_command(angle);
}
