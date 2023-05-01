#pragma once
#include "object_state/ObjectState.hpp"
#include <vector>
#include <bernstein_polynomial/bernstein_util.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/point_types_conversion.h>


using namespace std;
class ObstacleManager{
private:
    vector<StatePoly> structured_obstacle_list;
    float time_interval[2];
    float time_horizon;
    pcl::PointCloud<pcl::PointXYZ> unstructured_obstacle;
public:
    ObstacleManager(float time_horizon_){time_horizon=time_horizon_;};
    void SetTimeHorizon(const float & time_horizon_){time_horizon=time_horizon_;};
    void SetStructuredObstacle(const vector<ObjectState> &structured_obstacle_list_);
    void SetTimeInterval(const float & time_init_){time_interval[0]=time_init_;time_interval[1]=time_init_+time_horizon;};
    void SetUnstructuredObstacle(const pcl::PointCloud<pcl::PointXYZ>&unstructured_obstacle_){unstructured_obstacle.clear(); unstructured_obstacle.points = unstructured_obstacle_.points;};
    float* GetTimeInterval(){return time_interval;};
    float GetTimeHorizon(){return time_horizon;};
    pcl::PointCloud<pcl::PointXYZ> GetPointCloud(){return this->unstructured_obstacle;};
    vector<StatePoly> GetStructuredObstacle(){return this->structured_obstacle_list;};
};
