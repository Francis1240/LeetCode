#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int leftD[n];
        int rightD[n];

        int maxi = 0;
        int distL = -1, distR = -1; //-1: edge, 0: seated, n: distance
        for(int i = 0; i < n; i++){
            if(seats[i]){
                distL = 0;
            }else if(distL != -1){
                distL ++;
            }
            leftD[i] = distL;
            
            if(seats[n-i-1]){
                distR = 0;
            }else if(distR != -1){
                distR ++;
            }
            rightD[n-i-1] = distR;
        }
        for(int i = 0; i < n; i++){
            int tempMax = -1;
            if(leftD[i] == -1){
                tempMax = rightD[i];
            }else if(rightD[i] == -1){
                tempMax = leftD[i];
            }else{
                tempMax = min(leftD[i], rightD[i]);
            }
            maxi = tempMax>maxi?tempMax:maxi;
        }

        return maxi;

    }
};