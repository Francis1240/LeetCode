#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {
        int n = S.length();
        int level = 0, ri = 0;
        char rst[n+1];
        for(int i = 0; i < n; i++){
            if(S[i] == '('){
                if(level != 0){
                    rst[ri] = '(';
                    ri++;
                }
                level++;
                continue;
            }
            if(level != 1){
                rst[ri]=')';
                ri++;
            }
            level--;
        }
        rst[ri] = '\0';
        string result(rst);
        return result;
    }
};