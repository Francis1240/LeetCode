#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length();
        int m = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != '-' && k<n){
                m++;
            }
        }
        int re = m%k;
        int d = m/k + (re==0)?0:1;
        vector<char> str;
        int i = 0;
        for(; i < re; i++){
            if(s[i]=='-'){
                re++; continue;
            }
            str.push_back(s[i]);
        }
        if(i!=0){
            str.push_back('-');
        }
        int c = 0;
        
        while(i<n){
            if(s[i]=='-'){
                i++;
                continue;
            }
            if(c == k){
                str.push_back('-');
                c = 0;
            }
            str.push_back(s[i]);
            i++;
            c++;
        }
        int newN = str.size();
        char tempResult[newN+1];
        for(i = 0; i < newN; i++){
            tempResult[i] = str[i];
            if(tempResult[i]>='a' &&tempResult[i]<='z'){
                tempResult[i] -= 32; 
            }
        }
        tempResult[newN] = '\0';
        string a = string(tempResult);
        return a;
    }
};