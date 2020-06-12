#include <cmath>

class Solution {
public:
    bool check(int N){
        int digits = log10(N)+1;
        short dig[digits];
        bool dif = false;
        for(int i = 0; i < digits; i++){
            dig[i] = N%10;
            N/=10;
            switch (dig[i])
            {
            case 0:
            case 1:
            case 8:
                break;
            case 2: 
            case 5:
            case 6:
            case 9:
                dif = true;
                break;
            default:
                return false;
                break;
            }
        }
        return dif;
    }

    int rotatedDigits(int N) {
        int count = 0;
        for(int i = 1; i <= N; i++){
            if(check(i))
             count ++;
        }

        return count;

    }
};