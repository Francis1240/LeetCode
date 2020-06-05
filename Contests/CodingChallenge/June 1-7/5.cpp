#include <vector>
using namespace std;

class Solution {
public:
    int n, total;
    vector<int> p;
    Solution(vector<int>& w) {
        n = w.size();
        p.reserve(n);
        total = w[0];
        p[0] =w[0];
        for(int i = 1 ; i < n; i++ ){
            total += w[i];
            p[i] = total ;
        }
    }
    
    int pickIndex() {
        int r = rand() % total;
        for(int i = 0; i < n; i++){
            if(p[i]>r){
                return i;
            }
        }
        return n;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */