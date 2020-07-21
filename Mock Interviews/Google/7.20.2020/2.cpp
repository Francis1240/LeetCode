#include <vector>
using namespace std;
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        int n = bulbs.size();
        bool state[n];
        for(int i = 0; i < n; i++){
            state[i] = 0;
            bulbs[i] --;
        }
        int min = n, max = -1;
        for(int i = 0; i < n; i++){
            int x = bulbs[i];
            state[x] = true;
            if(min < x){
                bool check = true;
                for(int count = 1; count < K+1; count ++){
                    if(x-count < 0 || state[x-count]){
                        check = false;
                        break;
                    }
                }
                if(x-K-1 >= 0 && state[x-K-1]){
                    if(check){
                        return i+1;
                    }
                }
            }else{
                min = x;
            }
            if(max > x){
                bool check = true;
                for(int count = 1; count < K+1; count ++){
                    if(x+count >= n || state[x+count]){
                        check = false;
                        break;
                    }
                }
                
                if(x+K+1 < n && state[x+K+1]){
                    if(check){
                        return i+1;
                    }
                }
            }else{
                max = x;
            }
        }
        return -1;
    }
};