#include <string>
#include <ctime>
using namespace std;

class Solution {
public:
    string DoW[7] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };
    string dayOfTheWeek(int day, int month, int year) {
        time_t t;
        time(&t);
        tm * tt = localtime(&t);
        tt->tm_year = year - 1900;
        tt->tm_mon = month-1;
        tt->tm_mday = day;
        mktime(tt);
        return DoW[tt->tm_wday];
    }
};