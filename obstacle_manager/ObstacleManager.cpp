#include "ObstacleManager.hpp"

void ObstacleManager::SetStructuredObstacle(vector<ObjectState> structured_obstacle_list_)
{
    structured_obstacle_list.clear();
    if(structured_obstacle_list_.empty()){
        SetTimeInterval(structured_obstacle_list_[0].time_stamp);
        StatePoly temp_state;
        temp_state.px.SetTimeInterval(this->time_interval);
        temp_state.py.SetTimeInterval(this->time_interval);
        temp_state.pz.SetTimeInterval(this->time_interval);
        temp_state.px.SetDegree(3);
        temp_state.py.SetDegree(3);
        temp_state.pz.SetDegree(3);
        float temp_x[4] = {0.0f, 0.0f, 0.0f, 0.0f};
        float temp_y[4] = {0.0f, 0.0f, 0.0f, 0.0f};
        float temp_z[4] = {0.0f, 0.0f, 0.0f, 0.0f};
        for (int i = 0; i < structured_obstacle_list_.size(); i++){
            temp_state.rx = structured_obstacle_list_[i].rx;
            temp_state.ry = structured_obstacle_list_[i].ry;
            temp_state.rz = structured_obstacle_list_[i].rz;
            for (int j = 0; j < 4; j++){
                temp_x[i] = structured_obstacle_list_[i].px + 0.333333333f * (float)j * (time_interval[1] - time_interval[0]) * structured_obstacle_list_[i].vx;
                temp_y[i] = structured_obstacle_list_[i].py + 0.333333333f * (float)j * (time_interval[1] - time_interval[0]) * structured_obstacle_list_[i].vy;
                temp_z[i] = structured_obstacle_list_[i].pz + 0.333333333f * (float)j * (time_interval[1] - time_interval[0]) * structured_obstacle_list_[i].vz;
            }
            temp_state.px.SetBernsteinCoeff(temp_x);
            temp_state.py.SetBernsteinCoeff(temp_y);
            temp_state.pz.SetBernsteinCoeff(temp_z);
            structured_obstacle_list.push_back(temp_state);
        }
    }
    

}
