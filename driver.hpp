#ifndef driver_hpp_
#define driver_hpp_
#include "general.hpp"
#include "mission.hpp"
class Driver
{
private:
    int driver_id;
    vector <Mission *> mission_list;
    float does_this_mission_exist(Mission * new_mission);
public:
    Driver(int set_driver_id);
    void add_mission(Mission * new_mission);
    float is_it_my_id(int id);
    void update_mission(const int distance, const int count_travel, const int time_travel, const int end_timestamp);
    void print_completed_mission();
    void print_mission();
};
#endif