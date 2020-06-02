#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string result = "";
        int max[4];
        for(int i = 0; i < 4; i++){
            max[i] = -1;
        }
        for(int i = 0; i < 4; i++){
            if(A[i] > 2) continue;
            for(int j = 0; j < 4; j++){
                if(j == i || (A[i]==2 && A[j] >3)) continue;
                for(int k = 0; k < 4; k++){
                    if(k == i || k == j || (A[k]>=6)) continue;
                    for(int l = 0; l < 4; l++){
                        if(l!= i && l != j && l != k ){
                            if( max[0]<A[i] || ( max[0]==A[i] && ( max[1] < A[j] || (max[1]==A[j] && (max[2]<A[k] || (max[2]==A[k] && max[3] < A[l])))) ) ){
                                max[0] = A[i];
                                max[1] = A[j];
                                max[2] = A[k];
                                max[3] = A[l];
                            }
                        }
                    }
                }
            }
        }

        if(max[0]==-1){
            return "";
        }

        result.push_back(max[0]+48);
        result.push_back(max[1]+48);
        result.push_back(':');
        result.push_back(max[2]+48);
        result.push_back(max[3]+48);


        return result;
    }

};