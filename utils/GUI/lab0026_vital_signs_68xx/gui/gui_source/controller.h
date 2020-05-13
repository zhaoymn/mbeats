#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <robot.h>
#include <deque>
#include <QFile>
#include <string>

class controller
{
public:
    controller();
    QFile stablefile;
    bool stable = false;
    int mode = 0; //1 for collecting training data, 2 for testing
    int stable_frames = 0;
    robot * rb;
    deque<double> data_window;
    int current_length = 0;
    int check_counter = 0;
    int gt;
    int hr_est;
    int num_rangebin = 0;
    int last_argmax = 0;
    double rangebin_size = 0;
    double rangebin_start = 0;
    int current_angle;
    double last_error = 1000000;
    void set_mode(int);
    bool check_rotate();
    void add_data(double d);
    void update_data(int, int);
    void set_range_parameters(double, double, int);
    bool check_reflection(QVector<double> rp);
    double compute_error(QVector<double> rp);
    std::string calculate_next(QVector<double>);
    int get_argmax(QVector<double>);
};

#endif // CONTROLLER_H
