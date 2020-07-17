#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        bool P[1002][1002];//P[a][b] refers to string [a,b)
        int n = s.length();
        string result;
        int max = 0;

        for(int i = 0; i < n; i++){
            P[i][i+1] = true;
        }
        for(int i = 0; i < n-1; i++){
            P[i][i+2] = ((s[i]==s[i+1])?true:false);
        }
        for(int i = 1; i < n-1; i++){//odd
            for(int j = 1; i+j < n && i-j >= 0; j++){
                if(!P[i-j+1][i+j]) P[i-j][i+j+1] = false;
                else {
                    P[i-j][i+j+1] = ((s[i-j] == s[i+j])? true : false);
                }
            }
        }
        for(int i = 1; i < n-2; i++){//even, i is left of center
            for(int j = 2; i+1-j >=0 && i +j < n; j++){
                if(!P[i-j+1+1][i+j]) P[i-j+1][i+j+1] = false;
                else {
                    P[i-j+1][i+j+1] = ((s[i-j+1] == s[i+j])? true : false);
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j <=n; j++){
                if(j-i>max && P[i][j]){
                    max = j-i;
                    string temp (s, i, j-i);
                    result = temp;
                }
            }
        }
        return result;
    }
};