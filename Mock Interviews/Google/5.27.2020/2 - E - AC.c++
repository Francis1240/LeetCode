#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (name[i] != '\0' && typed[j] != '\0'){
            char n = name[i];
            char m = typed[j];
            if(n!=m){
                return false;
            }
            i++;
            j++;
            int count = 1;
            while(name[i] == n){
                count ++;
                i++;
            }
            int count2 = 1;
            while(typed[j] == m){
                count2 ++;
                j++;
            }

            if(count>count2)
                return false;
            
        }

        if(name[i] != typed[j]){
            return false;
        }
        return true;
    }
};