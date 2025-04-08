#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
    int hours, minutes, seconds;
public:
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) { setTime(h, m, s); }
    void setTime(int h, int m, int s)
    {
        setHours(h);
        setMinutes(m);
        setSeconds(s);
    }
    void setHours(int h)
    {
        if (h >= 0 && h < 24) hours = h;
        else
        {
            cout << "Error set hour. Defaulting to 0." << endl;
            hours = 0;
        }
        
    }
    void setMinutes(int m)
    {
        if (m >= 0 && m < 60) minutes = m;
        else
        {
            cout << "Error set minute. Defaulting to 0." << endl;
            minutes = 0;
        }
    }
    void setSeconds(int s)
    {
        if (s >= 0 && s < 60) seconds = s;
        else
        {
            cout << "Error set second. Defaulting to 0." << endl;
            seconds = 0;
        }
    }

    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
    void printTimeFull() const {
        cout << hours << " hours " << minutes << " minutes " << seconds << " seconds" << endl;
    }
    void printTimeShort() const
    {
        int shortHours = (hours % 12 == 0) ? 12 : hours % 12;
        string period = (hours < 12) ? "a.m." : "p.m.";
        cout << shortHours << " " << period << " " << minutes << " minutes " << seconds << " seconds" << endl;
    }
};

int main()
{
    Time t1;
    t1.printTimeFull();
    t1.printTimeShort();

    int h, m, s;
    cout << "Input hours, minutes and seconds: ";
    cin >> h >> m >> s;
    Time t2(h, m, s);
    t2.printTimeFull();
    t2.printTimeShort();
    t1.setHours(23);
    t1.setMinutes(59);
    t1.setSeconds(59);
    t1.printTimeFull();
    t1.printTimeShort();
    t1.setHours(25);
    t1.setMinutes(61);
    t1.setSeconds(-5);
    t1.printTimeFull();
    return 0;
}