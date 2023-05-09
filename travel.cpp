#include "travel.hpp"
Travel::Travel(int set_start_time, int set_end_time, int set_driver_id, int set_travled_distance)
    : start_time(set_start_time),
    end_time(set_end_time),
    driver_id(set_driver_id),
    travled_distance(set_travled_distance)
{
}
float Travel :: is_it_my_driver_id(int id)
{
    return id == driver_id;
}
int Travel :: get_duration()
{
    return end_time - start_time;
}
int Travel :: get_distance()
{
    return travled_distance;
}
