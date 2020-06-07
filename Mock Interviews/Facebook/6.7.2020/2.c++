#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        
        int l = 1, r = 1;
        for(int i = 1; i < nums.size(); i++){
            l*=nums[i-1];
            result[i]*=l;
        }
        for(int i = nums.size()-2; i >= 0; i--){
            r*=nums[i+1];
            result[i]*=r;
        }
        return result;
    }
};