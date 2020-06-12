#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        int max = 0;
        int sum[n+1];
        sum[0] = 0;

        for(int i = 1; i <=n; i++){
            sum[i] = sum[i-1] + nums[i-1]; 
        }


        for(int l = n; l > 0; l--){
            for(int i = 0; i < n-l+1; i++){
                if(sum[i+l]-sum[i] == k){
                    max = max > l? max: l;
                }
            }
        }
        
        return max;

    }
};