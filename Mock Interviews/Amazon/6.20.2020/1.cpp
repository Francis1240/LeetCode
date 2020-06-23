#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute_wiz(int n){
        if(n == 1){
            vector<int> t;
            t.push_back(0);
            vector<vector<int>> result;
            result.push_back(t);
            return result;
        }
        auto prev = permute_wiz(n-1);
        auto prev_size = prev.size();
        vector<vector<int>> curr;
        for(int i = 0; i < prev_size; i++){
            for(int j = 0; j < n; j++){
                auto temp = prev[i];
                temp.insert(temp.begin() + j, n-1);
                curr.push_back(temp);
            }
        }
        return curr;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        auto n = nums.size();
        auto order = permute_wiz(n);
        vector<vector<int>> result;
        for(int i = 0; i < order.size(); i++){
            vector<int> temp;
            for(int j = 0; j < order[0].size(); j++){
                temp.push_back(nums[order[i][j]]);
            }
            result.push_back(temp);
        }
        return result;
    }
};