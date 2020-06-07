#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int max = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                max = max > (prices[j]-prices[i])? max: prices[j]-prices[i];
            }
        }
        return max;

    }
};