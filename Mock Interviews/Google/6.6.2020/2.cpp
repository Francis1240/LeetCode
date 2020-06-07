#include <vector> 
#include <iostream>


using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        int x = -1, y = -1, l = 0, xc = 0, yc = 0;
        int max = 0;
        for(int i = 0; i < n; i++){
            //start
            int t = tree[i];
            if(x == -1){
                x = t;
                xc ++;
                continue;
            }
            if(y == -1){
                if(t == x){
                    xc++;
                    continue;
                }else{
                    y = t;
                    yc ++;
                    xc = 0;
                }
                continue;
            }

            // =x/=y
            if(t == x){
                yc = 0; 
                xc ++;
                continue;
            }
            if(t == y){
                xc = 0;
                yc ++;
                continue;
            }

            //not x/y
            max = max>(i-l)? max : (i-l);
            l = xc>0?i-xc: i-yc;
            
            if(tree[l] == x){
                y = t;
                xc = 0;
                yc = 1;
            }else{
                x = t;
                xc = 1;
                yc = 0;
            }

        }

        return max>(n-l)?max:n-l;
    }
};