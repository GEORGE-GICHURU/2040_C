#include <iostream>
using namespace std;

class Autopilot
{
private:
    double altitude;
    double heading;
    double airspeed;

public:
    Autopilot()
    {
        altitude = 0;
        heading = 0;
        airspeed = 0;
    }

    void setAltitude(double alt)
    {
        altitude = alt;
    }

    void setHeading(double hdg)
    {
        heading = hdg;
    }

    void setAirspeed(double spd)
    {
        airspeed = spd;
    }
};