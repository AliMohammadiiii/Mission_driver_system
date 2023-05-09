#include "software.hpp"

void Software :: run()
{
    string command;
    while (cin >> command)
    {
        try
        {
            if (command == ADDTIMEMISSION)
            {
                add_mission(TIMEMISSION);
            }
            else if (command == ADDDISTANCEISSION)
            {
                add_mission(DISTANCEMISSION);
            }
            else if (command == ADDCOUNTMISSION)
            {
                add_mission(COUNTMISSION);
            }
            else if (command == ASSIGNMISSION)
            {
                assign_mission();
            }
            else if (command == RECORDRIDE)
            {
                record_ride();
            }
            else if (command == SHOWMISSIONSTATUS)
            {
                show_missions_status();
            }
            else
            {
                // ToDo add buffer clear
                throw INVALIDCOMMANDCODE;
            }
        }
        catch(int err_code)
        {
            switch (err_code)
            {
            case INVALIDARGUMENTSCODE:
                cout << INVALIDARGUMENTS << endl;
                break;
            case DUPLICATEMISSIONIDCODE:
                cout << DUPLICATEMISSIONID << endl;
                break;
            case DUPLICATEDRIVERMISSIONCODE:
                cout << DUPLICATEDRIVERMISSION << endl;
                break;
            case MISSIONNOTFOUNDCODE:
                cout << MISSIONNOTFOUND << endl;
                break;
            case INVALIDCOMMANDCODE:
                cout << INVALIDCOMMAND << endl;
            default:
                break;
            }
        }
    }
}
int Software :: find_mission_by_id(int id)
{
    int mission_list_size = mission_list.size();
    for (int mission_cursor = 0; mission_cursor < mission_list_size; mission_cursor++)
    {
        if (mission_list[mission_cursor]->is_it_my_id(id))
        {
            return mission_cursor;
        }
    }
    return -1;
}

int Software :: find_driver_by_id(int id)
{
    int driver_list_size = driver_list.size();
    for (int driver_cursor = 0; driver_cursor < driver_list_size; driver_cursor++)
    {
        if (driver_list[driver_cursor]->is_it_my_id(id))
        {
            return driver_cursor;
        }
    }
    return -1;
}

void Software :: add_mission(int type)
{
    int mission_id, start_timestamp, end_timestamp, goal, reward_amount;
    cin >> mission_id >> start_timestamp >> end_timestamp >> goal >> reward_amount;
    if (end_timestamp < start_timestamp)
        throw INVALIDARGUMENTSCODE;
    if (find_mission_by_id(mission_id) != -1)
        throw DUPLICATEMISSIONIDCODE;
    if (end_timestamp < 0 || start_timestamp < 0 || reward_amount < 0 || goal < 0)
        throw INVALIDARGUMENTSCODE;
    Mission* new_mission;
    if (type == TIMEMISSION)
        new_mission = new Time_mission(mission_id, start_timestamp, end_timestamp, goal, reward_amount, type);
    else if (type == DISTANCEMISSION)
        new_mission = new Distance_mission(mission_id, start_timestamp, end_timestamp, goal, reward_amount, type);
    else if (type == COUNTMISSION)
        new_mission = new Number_of_travel_mission(mission_id, start_timestamp, end_timestamp, goal, reward_amount, type);
    mission_list.push_back(new_mission);
    cout << OK << endl;
}

void Software :: assign_mission()
{
    int mission_id, driver_id;
    cin >> mission_id >> driver_id;
    int driver_cursor = find_driver_by_id(driver_id);
    if (driver_cursor == -1)
    {
        driver_list.push_back(new Driver(driver_id));
        driver_cursor = driver_list.size() - 1;
    }
    int mission_cursor = find_mission_by_id(mission_id);
    if (mission_cursor == -1)
        throw MISSIONNOTFOUNDCODE;
    
    driver_list[driver_cursor]->add_mission(mission_list[mission_cursor]);
    cout << OK << endl;
}

void Software :: update_missions(int driver_id, int end_timestamp)
{
    int travel_list_size = travel_list.size();
    int distance = 0;
    int count_travel = 0;
    int time_travel = 0;
    for (int travel_cursor = 0; travel_cursor < travel_list_size; travel_cursor++)
    {
        if (travel_list[travel_cursor]->is_it_my_driver_id(driver_id))
        {
            distance += travel_list[travel_cursor]->get_distance();
            count_travel ++;
            time_travel += travel_list[travel_cursor]->get_duration();
        }
    }
    int driver_cursor = find_driver_by_id(driver_id);
    driver_list[driver_cursor]->update_mission(distance, count_travel, time_travel, end_timestamp);
}

void Software :: record_ride()
{
    int start_timestamp, end_timestamp, driver_id, distance;
    cin >> start_timestamp >> end_timestamp >> driver_id >> distance;
    if (start_timestamp > end_timestamp)
        throw INVALIDARGUMENTSCODE;
    travel_list.push_back(new Travel(start_timestamp, end_timestamp, driver_id, distance));
    update_missions(driver_id, end_timestamp);
    int driver_cursor = find_driver_by_id(driver_id);
    driver_list[driver_cursor]->print_completed_mission();
}

void Software :: show_missions_status()
{
    int driver_id;
    cin >> driver_id;

    int driver_cursor = find_driver_by_id(driver_id);
    driver_list[driver_cursor]->print_mission();
}
