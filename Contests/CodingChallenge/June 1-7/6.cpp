#include <vector>
using namespace std;

class Solution {

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> queue(n);
        sort(people.begin(), people.end(), 
            [](vector<int> p1, vector<int> p2) {
                return p1[0]<p2[0];
            }
        );
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j <= people[i][1] + count; j++){
                if(queue[j].size() == 0||queue[j][0] >= people[i][0]) continue;
                count ++;
            }
            queue[people[i][1]+count] = people[i];
        }

        return queue;

    }
};