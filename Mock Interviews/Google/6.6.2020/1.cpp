#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
private:
    string addressProcess(string before){
        int n = before.size();
        char c[n+1];
        strcpy(c, before.c_str());
        char cc[n+1];
        int i = 0, index = 0;
        while(i < n){
            if(c[i] == '@'){
                break;
            }
            if(c[i] == '.'){
                i++;
                continue;
            }
            if(c[i] == '+'){
                while(c[i] != '@'){
                    i++;
                }
                break;
            }
            cc[index] = c[i];
            i++;
            index++;
        }
        while(c[i]!='\0'){
            cc[index] = c[i];
            index ++;
            i++;
        }
        cc[index] = c[i];
        return string(cc);
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        int n = emails.size();
        set<string> addresses;
        for(int i = 0; i < n; i++){
            addresses.insert(addressProcess(emails[i]));
        }
        return addresses.size();
    }
};