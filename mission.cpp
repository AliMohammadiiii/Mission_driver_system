#include "mission.hpp"

Mission::Mission(int set_mission_id, int set_start_time, int set_end_time, int set_reward, int set_type)
    : mission_id(set_mission_id),
    start_time(set_start_time),
    end_time(set_end_time),
    reward(set_reward),
    type(set_type)
{
    status = false;
    actual_end_time = 0;
}
float Mission :: is_it_my_id(int id)
{
    return mission_id == id;
}
int Mission :: get_my_type()
{
    return type;
}
void Mission :: set_done(int actual_end_timestamp)
{
    if (end_time < actual_end_timestamp || actual_end_timestamp < start_time)
    {
        return;
    }
    actual_end_time = actual_end_timestamp;
    status = true;
}
string Mission :: get_abstract_info()
{
    stringstream info;
    info << "mission: " << mission_id << endl;
    info << "start timestamp: " << start_time << endl;
    info << "end timestamp: " << actual_end_time << endl;
    info << "reward: " << reward << endl << endl;
    return info.str();
}
string Mission :: get_info()
{
    stringstream info;
    info << "mission: " << mission_id << endl;
    info << "start timestamp: " << start_time << endl;
    info << "end timestamp: " << actual_end_time << endl;
    info << "reward: " << reward << endl;
    if (status)
        info << "status: completed" << endl << endl;
    else
        info << "status: ongoing" << endl << endl;
    
    return info.str();
}
float Mission :: get_status()
{
    return status;
}

Time_mission::Time_mission(int set_mission_id, int set_start_time, int set_end_time, int set_goal_time, int set_reward, int set_type)
    : Mission(set_mission_id, set_start_time, set_end_time, set_reward, set_type),
    goal_time(set_goal_time)
{
}
int Time_mission :: get_my_goal()
{
    return goal_time;
}

Distance_mission::Distance_mission(int set_mission_id, int set_start_time, int set_end_time, int set_goal_distance, int set_reward, int set_type)
    : Mission(set_mission_id, set_start_time, set_end_time, set_reward, set_type),
    goal_distance(set_goal_distance)
{
}
int Distance_mission :: get_my_goal()
{
    return goal_distance;
}

Number_of_travel_mission::Number_of_travel_mission(int set_mission_id, int set_start_time, int set_end_time, int set_goal_number, int set_reward, int set_type)
    : Mission(set_mission_id, set_start_time, set_end_time, set_reward, set_type),
    goal_number(set_goal_number)
{
}
int Number_of_travel_mission :: get_my_goal()
{
    return goal_number;
}
