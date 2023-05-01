#pragma once
#include <bernstein_polynomial/bernstein_util.hpp>

struct ObjectState{
    float px;   // position x,y,z
    float py;
    float pz;
    float vx;   // velocity x,y,z
    float vy;
    float vz;
    float rx;   // radius x,y,z (ellipsoid)
    float ry;
    float rz;
    float time_stamp;
};

struct DroneState{
    float px;   // position x,y,z
    float py;
    float pz;
    float vx;   // velocity x,y,z
    float vy;
    float vz;
    float ax;   // acceleration x,y,z
    float ay;
    float az;
    float rh; // horizontal radius
    float rv; // vertical radius (due to downwash effect)
};

struct StatePoly{
    BernsteinPoly px;
    BernsteinPoly py;
    BernsteinPoly pz;
    float rx;
    float ry;
    float rz;
};