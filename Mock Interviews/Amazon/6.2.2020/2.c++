#include<vector>

using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        vector<vector<int>> memory;
        memory.push_back(cells);

        
        for(int i = 0; i < N; i++){
            vector<int> newCells(8);
            if(i == 0){
                newCells[0] = 0;
                newCells[7] = 0;
            }
            for(int cell = 1; cell < 7; cell ++){
                if(cells[cell-1] == cells[cell+1]){
                    newCells[cell] = 1;
                }else {
                    newCells[cell] = 0;
                }
            }
            for(int j = 0; j < memory.size(); j++){
                bool t = true;
                for(int k = 0; k < 8; k++){
                    if(memory[j][k] != newCells[k]){
                        t = false;
                        break;
                    }
                }
                if(t){
                    int cycle = memory.size()-j;
                    int x = j + ((N - j) % cycle);
                    return memory[x];
                }
            }
            memory.push_back(newCells);
            cells = newCells;
        }

        return cells;
    }
};