#include <string>
using namespace std;

class Solution {
private: 
    bool isValid(unsigned short time[4]){
        if(time[2] > 5){
            return false;
        }
        if(time[0]> 2 || (time[0] == 2 && time[1] > 3 )){
            return false;
        }
        return true;
    }
    unsigned short timeDiffInMinute(unsigned short time1[4], unsigned short time2[4]){
        int diff = 60 * (10 * (time1[0] - time2[0]) + time1[1] - time2[1]) + 10 * (time1[2] - time2[2]) + time1[3] - time2[3];
        if(diff <= 0){
            diff += 1440;
        }
        return diff;
    }
    string toTimeString(unsigned short time[4]){
        string s = "";
        s = s + (char)(time[0] + 48) + (char)(time[1] + 48) + ':' + (char)(time[2] + 48) + (char)(time[3] + 48);
        return s;
    }

public:
    string nextClosestTime(string time) {
        unsigned short oldTime[4], newTime[4], resultTime[4];
        oldTime[0] = time[0] - 48; // ASCII
        oldTime[1] = time[1] - 48;
        oldTime[2] = time[3] - 48; // ASCII
        oldTime[3] = time[4] - 48;
    

        unsigned short minDiff = 65535;


        for(unsigned short x1 = 0; x1 < 4; x1++){
            for(unsigned short x2 = 0; x2 < 4; x2++){
                for(unsigned short x3 = 0; x3 < 4; x3++){
                    for(unsigned short x4 = 0; x4 < 4; x4++){
                        if(x1 == 0 && x2 == 1 && x3 == 2 && x4 == 3)continue;
                        newTime[0] = oldTime[x1];
                        newTime[1] = oldTime[x2];
                        newTime[2] = oldTime[x3];
                        newTime[3] = oldTime[x4];
                        if(isValid(newTime)){
                            unsigned short diff = timeDiffInMinute(newTime, oldTime);
                            if(diff < minDiff){
                                minDiff = diff;
                                for(unsigned short i = 0; i < 4; i++){
                                    resultTime[i] = newTime[i];
                                }
                            }
                        }
                    }
                }
            }
        }    

        return toTimeString(resultTime);    
    }
};