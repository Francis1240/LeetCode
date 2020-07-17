#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0){
            return "";
        }
        int pre = 0;
        int minLength = 0;
        int index = 0;
        bool diff = false;
        while(true){
            if(strs[0].length()<=index){
                return pre != 0? strs[0].substr(0,pre): "";
            }
            char c = strs[0][index];
            for(int i = 0; i < n; i++){
                if(index >= strs[i].length() || c != strs[i][index]){
                    return pre != 0? strs[0].substr(0,pre): "";
                }
            }
            pre ++;
            index ++;
        }
        return "";
    }
};
