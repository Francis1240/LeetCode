#include <string>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int initn = s.size();
        int n = initn;
        if(n == 1){
            return false;
        }
        
        vector<int> poss;
        for(int i = 1; i < 0.5 * initn + 1; i++){
            if(n%i == 0){
                poss.push_back(i);
            }
        }
        n = initn;
        for(int i = 0; i < poss.size();i++){
            bool temp = true;
            for(int j = 0; j < n; j++){
                int ind = j%poss[i];
                if(s[ind] != s[j]){
                    temp = false;
                    break;
                }
            }
            if(temp){
                return true;
            }
        }
        return false;
        
    }
};