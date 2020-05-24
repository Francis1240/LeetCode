#include <stdio.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char * s){
    //First setup a ASCII string array.
    bool A[256];
    for(int i = 0; i < 256; i++){
        A[i] = false;
    }
    int max = 0;
    int count = 0;

    int i = 0, j = 0;
    while (s[i]!= '\0'){
        if(A[s[i]]){
            max = count>max?count:max;
            do {
                A[s[j]] = false;
                j ++;
                count --;
            } while (s[i] != s[j-1]);
        } 
        A[s[i]] = true;
        count ++;
        i++;
    }
    max = count>max?count:max;


    return max;
}