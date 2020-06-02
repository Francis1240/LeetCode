#include <vector>
using namespace std;


class NumArray {
public:
    NumArray(vector<int>& nums) {
        k = nums;
    }
    
    void update(int i, int val) {
        k[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int index = i; index <= j; index ++){
            sum += k[index];
        }
        return sum;
    }
private:
    vector<int> k;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */