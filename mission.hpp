#ifndef mission_hpp_
#define mission_hpp_
#include "general.hpp"
class Mission
{
private:
    int mission_id;
    int start_time;
    int end_time;
    int actual_end_time;
    int reward;
    float status;
    int type;
public:
    Mission(int set_mission_id, int set_start_time, int set_end_time, int set_reward, int set_type);
    float is_it_my_id(int id);
    int get_my_type();
    void set_done(int actual_end_timestamp);
    virtual int get_my_goal() = 0;
    string get_abstract_info();
    string get_info();
    float get_status();
};


class Time_mission : public Mission
{
private:
    int goal_time;
public:
    Time_mission(int set_mission_id, int set_start_time, int set_end_time, int goal_time, int set_reward, int set_type);
    int get_my_goal();
};

class Distance_mission : public Mission
{
private:
    int goal_distance;
public:
    Distance_mission(int set_mission_id, int set_start_time, int set_end_time, int set_goal_distance, int set_reward, int set_type);
    int get_my_goal();
};

class Number_of_travel_mission : public Mission
{
private:
    int goal_number;
public:
    Number_of_travel_mission(int set_mission_id, int set_start_time, int set_end_time, int set_goal_number, int set_reward, int set_type);
    int get_my_goal();
};
#endif