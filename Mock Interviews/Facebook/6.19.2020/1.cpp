#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> num;
    NumArray(vector<int>& nums) {
        num = nums;
    }
    
    int sumRange(int i, int j) {
        int count = 0;
        for(int ind = i; ind <= j; ind++){
            count += num[ind];
        }
        return count;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */