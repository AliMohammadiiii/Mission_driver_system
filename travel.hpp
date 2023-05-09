#ifndef travel_hpp_
#define travel_hpp_
#include "general.hpp"
class Travel
{
private:
    int start_time;
    int end_time;
    int driver_id;
    int travled_distance;
public:
    Travel(int set_start_time, int set_end_time, int set_driver_id, int set_travled_distance);
    int get_duration();
    int get_distance();
    float is_it_my_driver_id(int id);
};
#endif