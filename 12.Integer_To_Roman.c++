#include <string>
using namespace std;

class Solution {
public:
    int power10(int i){
        return i <= 0?1:10*power10(i-1);
    }
    string intToRoman(int num) {
        string s;

        int digits = 0;
        int temp = num;
        while(temp > 0){
            temp/=10;
            digits ++;
        }

        for(int i = 0; i < digits; i ++){
            int x = num/power10(digits-i-1);
            num %= power10(digits-i-1);
            if(x == 4 || x == 9){
                if(x == 4){
                    switch(digits-i){
                        case 1: s.append("IV");
                        break;
                        case 2: s.append("XL");
                        break;
                        case 3: s.append("CD");
                        break;
                    }
                } else {
                    switch(digits-i){
                        case 1: s.append("IX");
                        break;
                        case 2: s.append("XC");
                        break;
                        case 3: s.append("CM");
                        break;
                    }
                }
            }else{
                char c;
                if(x >= 5){
                    switch(digits-i){
                        case 1: c = 'V';
                        break;
                        case 2: c = 'L';
                        break;
                        case 3: c = 'D';
                        break;
                    }
                    s.push_back(c);
                    x-=5;
                }                    
                switch(digits-i){
                    case 1: c = 'I';
                    break;
                    case 2: c = 'X';
                    break;
                    case 3: c = 'C';
                    break;
                    case 4: c = 'M';
                    break;
                }
                for(int k = 0; k < x; k ++){
                    s.push_back(c);
                } 
            }
        }


        
        return s;
    }
};