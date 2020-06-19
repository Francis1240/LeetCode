#include <vector>
using namespace std;

class Solution {
public:

    int invert(int x){
        return (x+1)%2;
    }

    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rowN = A.size();
        int colN = A[0].size();
        vector<vector<int>> result (rowN);
        for(int i = 0; i < rowN; i++){
            vector<int> temp (colN);
            for(int j = 0; j < colN; j++){
                temp[j] = invert(A[i][colN-j-1]);
            }
            result[i] = temp;
        }

        return result;
    }
};