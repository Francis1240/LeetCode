#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<short> m;
        int n = s.length();
        for(int i = 0; i < n; i++){
            switch(s[i]){
                case '(':
                    m.push(0);
                    break;
                case '[':
                    m.push(1);
                    break;
                case '{':
                    m.push(2);
                    break;
                case ')':
                    if(m.size() == 0 || m.top() != 0 )
                        return false;
                    m.pop();
                    break;
                case ']':
                    if(m.size() == 0 || m.top() != 1)
                        return false;
                    m.pop();
                    break;
                case '}':
                    if(m.size() == 0 || m.top() != 2)
                        return false;
                    m.pop();
                    break;
                default: return false;
            }
        }
        return m.size() == 0;
    }
};