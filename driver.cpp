#include "driver.hpp"


Driver::Driver(int set_driver_id)
    : driver_id(set_driver_id)
{
}
void Driver::update_mission(const int distance, const int count_travel, const int time_travel, const int end_timestamp)
{
    int mission_list_size = mission_list.size();
    for (int mission_cursor = 0; mission_cursor < mission_list_size; mission_cursor++)
    {
        Mission* mission = mission_list[mission_cursor];
        int mission_type = mission->get_my_type();
        int goal = mission->get_my_goal();
        if (mission_type == TIMEMISSION)
        {
            if (time_travel >= goal)
                mission->set_done(end_timestamp);
        }
        else if (mission_type == COUNTMISSION)
        {
            if (count_travel >= goal)
                mission->set_done(end_timestamp);
        }
        else if (mission_type == DISTANCEMISSION)
        {
            if (distance >= goal)
                mission->set_done(end_timestamp);
        }
    }
    
}

float Driver::is_it_my_id(int id)
{
    return id == driver_id;
}
float Driver::does_this_mission_exist(Mission * new_mission)
{
    int mission_list_size = mission_list.size();
    for (int mission_cursor = 0; mission_cursor < mission_list_size; mission_cursor++)
    {
        if (mission_list[mission_cursor] == new_mission)
        {
            return true;
        }
    }
    return false;
}
void Driver::add_mission(Mission * new_mission)
{
    if (does_this_mission_exist(new_mission))
        throw DUPLICATEDRIVERMISSIONCODE;
    
    mission_list.push_back(new_mission);
    
}
void Driver::print_completed_mission()
{
    cout << "completed missions for driver " << driver_id << ":" << endl;
    int mission_list_size = mission_list.size();
    for (int mission_cursor = 0; mission_cursor < mission_list_size; mission_cursor++)
    {
        Mission* mission = mission_list[mission_cursor];
        if (mission->get_status())
        {
            cout << mission->get_abstract_info();
        }
    }
}
void Driver::print_mission()
{
    cout << "missions status for driver " << driver_id << ":" << endl;
    int mission_list_size = mission_list.size();
    for (int mission_cursor = 0; mission_cursor < mission_list_size; mission_cursor++)
    {
        Mission* mission = mission_list[mission_cursor];
        cout << mission->get_info();
    }
}

