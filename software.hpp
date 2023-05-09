#ifndef software_hpp_
#define software_hpp_
#include "general.hpp"
#include "mission.hpp"
#include "driver.hpp"
#include "travel.hpp"
class Software
{
private:
    vector<Mission *> mission_list;
    vector<Driver *> driver_list;
    vector <Travel *> travel_list;
    void add_mission(int type);
    void add_distance_mission();
    int find_mission_by_id(int id);
    int find_driver_by_id(int id);
    void assign_mission();
    void record_ride();
    void update_missions(int driver_id, int end_timestamp);
    void show_missions_status();
public:
    void run();
};
#endif