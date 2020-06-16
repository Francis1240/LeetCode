#include <vector>

using namespace std;


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }
        if(nums[n-1] > nums[n-2]){
            return n-1;
        }
        int i = 1, j = n-2;
        while (i<j){
            int mid = (i+j)/2;
            int d = nums[mid+1]-nums[mid];
            if(d>0){
                if((i+j)%2==1){
                    i = mid+1; continue;
                }
                i = mid; continue;
            }
            j = mid;
        }
        
        return i;


    }
};