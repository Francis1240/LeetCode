#include <string>
using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int i = 0;
        char result[n+1];
        while(i < n){
            if(i + k > n){
                int j;
                for(j = i; j < n; j++){
                    result[j] = s[n- (j-i) - 1];
                }
                i = j;
                break;
            }
            int j;
            for(j = i; j < i + k; j++){
                result[j] = s[i+k-1-(j-i)];
            }
            i = j;
            if(i+k>n){
                for(;i<n;i++){
                    result[i] = s[i];
                }
                break;
            }
            for(;j<i+k; j++){
                result[j] = s[j];
            }
            i=j;
        }
        result[i] = '\0';
        string rslt(result);
        return rslt;
    }
};