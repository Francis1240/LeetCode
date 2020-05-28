#include <vector>
using namespace std;
class Solution {
public:
    bool canRot(vector<vector<int>> grid){
        for(int i = 1; i < grid.size()-1; i++){
            for(int j = 1; j < grid[0].size()-1; j++){
                if(grid[i][j] == 1 && (grid[i-1][j] == 2 || grid[i+1][j] == 2 || grid[i][j-1]==2 || grid[i][j+1] == 2)){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasFresh(vector<vector<int>> grid){
        for(int i = 1; i < grid.size()-1; i++){
            for(int j = 1; j < grid[0].size()-1; j++){
                if(grid[i][j] == 1) return true;
            }
        }
        return false;
    }
    int orangesRotting(vector<vector<int>> grid) {
        bool canRot = false;
        int n = grid.size();
        int m = grid[0].size();    
        int t = 0;
        
        //set up sentinels
        vector<vector<int>> gridWithS;
        vector<int> empty1 (m+2, 0);
        vector<int> empty2 (m+2, 0);

        gridWithS.push_back(empty1);
        for(int i = 0; i < n; i++){
            vector<int> row;
            row.push_back(0);
            for(int j = 0; j < m; j++){
                row.push_back(grid[i][j]);
            }
            row.push_back(0);
            gridWithS.push_back(row);
        }
        gridWithS.push_back(empty2);
        
        while(Solution::canRot(gridWithS)){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(gridWithS[i][j] == 1 && (gridWithS[i-1][j] == 2 || gridWithS[i+1][j] == 2 || gridWithS[i][j-1] == 2 || gridWithS[i][j+1] == 2)){
                        gridWithS[i][j] = 3;
                    }
                }
            }
            for(int i = 1; i < n+1; i++){
                for(int j = 1; j < m+1; j++){
                    if(gridWithS[i][j] == 3){
                        gridWithS[i][j] = 2;
                    }
                }
            }
            t++;
        }

        if(Solution::hasFresh(gridWithS))
            return -1;

        return t; 
    }
};