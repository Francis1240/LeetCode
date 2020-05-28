#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int x = n * n;
        vector<vector<int>> result;
        for(int i = 0; i < n; i++){
            vector<int> row;
            for(int j = 0; j < n; j++){
                row.push_back(0);
            }
            result.push_back(row);
        }

        int direction =0, r = 0, c = 0, count = 0;

        //0 >
        //1 v
        //2 <
        //3 ^
        while(count < x){
            count ++;
            result[r][c] = count;

            switch (direction){
            case 0:
                c ++;
                if(c+1>n-1 || result[r][c+1] != 0){
                    direction = 1;
                }
                break;
            case 1:
                r ++;
                if(r+2>n || result[r+1][c] != 0){
                    direction = 2;
                }
                break;
            case 2:
                c--;
                if(c-1<0 || result[r][c-1] != 0){
                    direction = 3;
                }
                break;
            case 3:
                r--;
                if(r-1<0 || result[r-1][c] != 0){
                    direction = 0;
                }
                break;
            default:
                break;
            }
        }
        return result;

    }
};