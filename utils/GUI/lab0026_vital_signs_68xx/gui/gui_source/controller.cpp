#include "controller.h"

controller::controller()
{
    rb = new robot();
    current_angle = 75;
    rb->rotate(current_angle);
}

bool controller::check_rotate()
{
    qDebug()<<"check rotate";
    if (abs(gt-hr_est)*1.0/gt < 0.05) {
        return true;
    }
    return false;
}

void controller::add_data(double d)
{
    qDebug()<<"add data";
    if(current_length == 64) {
        data_window.pop_front();
        data_window.push_back(d);
        if(mode == 1) {
            stable_frames++;
            if(stable_frames==64) {
         //       rb->rotate();
                stable_frames=0;
                data_window.clear();
                current_length = 0;
            }
        } else if (mode == 2) {
            check_counter++;
            if(check_counter == 20) {
                check_counter = 0;
            }
            if (check_counter==0) {
                bool r = check_rotate();
                if(!r) {
            //        rb->rotate();
                    data_window.clear();
                    current_length = 0;
                    check_counter = 0;
                }
            }
        }
    } else {
        data_window.push_back(d);
        current_length = current_length + 1;
    }
}

void controller::update_data(int g, int e)
{
    gt = g;
    hr_est = e;
}

void controller::set_range_parameters(double size, double start, int nb)
{
    num_rangebin = nb;
    rangebin_size = size;
    rangebin_start = start;
}

bool controller::check_reflection(QVector<double> rp)
{
    int argmax = 0;
    double max = 0;
    for(int i = 0; i < num_rangebin; i ++) {
        if(rp[i] > max) {
            max = rp[i];
            argmax = i;
        }
    }
    qDebug()<<argmax;
    qDebug()<<rangebin_start + rangebin_size*argmax;
    if(rangebin_start + rangebin_size*argmax > 0.4 && rangebin_start + rangebin_size*argmax < 0.6){
        if(argmax == last_argmax)
            return true;
    }
    return false;
}

int controller::get_argmax(QVector<double> rp)
{
    int argmax = 0;
    double max = 0;
    double total_intensity = 0;
    for(int i = 0; i < num_rangebin; i ++) {
        total_intensity = total_intensity + rp[i];
        if(rp[i] > max) {
            max = rp[i];
            argmax = i;
        }
    }
    return argmax;
}
double controller::compute_error(QVector<double> rp)
{

    int argmax = 0;
    double max = 0;
    double total_intensity = 0;
    for(int i = 0; i < num_rangebin; i ++) {
        total_intensity = total_intensity + rp[i];
        if(rp[i] > max) {
            max = rp[i];
            argmax = i;
        }
    }

    if(rangebin_start + rangebin_size*argmax > 0.4 && rangebin_start + rangebin_size*argmax < 0.6){

        return (total_intensity/num_rangebin)/max;
    }
    return 1000000;
}

string controller::calculate_next(QVector<double> rpc)
{
    stable_frames++;
    if(stable_frames < 20) return "none";
    stable_frames = 0;
    QVector<double> rp(num_rangebin);
    for (unsigned int indexRangeBin = 0; indexRangeBin < num_rangebin; indexRangeBin ++)
    {
        rp[indexRangeBin] = sqrt(rpc[2*indexRangeBin]*rpc[2*indexRangeBin]+ rpc[2*indexRangeBin + 1]*rpc[2*indexRangeBin + 1]);
    }
    if(!check_reflection(rp)) {
        if(stable == true){
            qDebug()<<"change stable state";
            last_error = 1000000;
            current_angle = 75;
            rb->rotate(current_angle);
            stable = false;
            return "stop";
        }
        stable = false;
    }
    if(stable == true) return "none";
    double error = compute_error(rp);
    qDebug()<<error;
    std::string returninfo = "none";
    if(error <= last_error) {
        current_angle = current_angle + 1;
        if (current_angle > 105) current_angle = 75;
        last_error = error;
    } else {
        current_angle = current_angle - 1;
        if (current_angle < 75) current_angle = 105;
        last_error = error;
        stable = true;
        last_argmax = get_argmax(rp);
        returninfo = "start";
        qDebug()<<"sensor stabled";
    }
    qDebug()<<"rotating";

    rb->rotate(current_angle);
    return returninfo;
}

void controller::set_mode(int m)
{
    mode = m;
}
