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

    void engage()
    {
        cout << "Autopilot engaged." << endl;
    }

    void disengage()
    {
        cout << "Autopilot disengaged." << endl;
    }

    void update()
    {
        // code to update autopilot based on sensors and inputs
        cout << "Autopilot is updated." << endl;
    }
};

int main()
{
    Autopilot ap;
    ap.setAltitude(10000);
    ap.setHeading(270);
    ap.setAirspeed(250);
    ap.engage();
    ap.update();
    ap.disengage();
    return 0;
}