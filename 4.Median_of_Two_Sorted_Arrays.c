#include <stdio.h>
#include <stdbool.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    // Binary search - ish
    /**
     * We first find the median in the two arrays. Call them m1, m2. 
     * If m1=m2 -> return it.
     * If m1>m2 -> take the half of array 1 thats smaller than m1, and the part of array 2 thats bigger than m2, recursively do this.
     * The two medians are also included.
     * */



    if (nums1 == nums2){
        return *nums1;
    }



}