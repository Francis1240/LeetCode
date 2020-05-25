#include <stdio.h>
#include <stdbool.h>

double findMedianSortedArrayModified(int* nums1, int nums1Start, int nums1End, int* nums2, int nums2Start, int nums2End);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    return findMedianSortedArrayModified(nums1, 0, nums1Size, nums2, 0, nums2Size);
}

double findMedianSortedArrayModified(int* nums1, int nums1Start, int nums1End, int* nums2, int nums2Start, int nums2End){
    // Binary search - ish
    /**
     * We first find the median in the two arrays. Call them m1, m2. 
     * If m1=m2 -> return it.
     * If m1>m2 -> take the half of array 1 thats smaller than m1, and the part of array 2 thats bigger than m2, recursively do this.
     * The two medians are also included.
     * */


    // Exiting Cases
    if (nums1Start == nums1End && nums2Start == nums2End){
        return ((double) (nums1[nums1Start] + nums2[nums2Start]))/2.0;
    }

    int count1 = nums1End - nums1Start;
    int count2 = nums2End - nums2Start;
    
    int m1i, m2i;

    m1i = nums1Start + count1/2;
    m2i = nums2Start + count2/2;
    
    double m1 = (count1 % 2 == 0)?(nums1[m1i] + nums1[m1i - 1])/2.0:nums1[m1i];
    double m2 = (count2 % 2 == 0)?(nums2[m2i] + nums2[m2i - 1])/2.0:nums2[m2i];

    if(m1 == m2){
        return m1;
    } else if (m1 > m2){
        return findMedianSortedArrayModified(nums1, nums1Start, count1%2==0? m1i:m1i+1, nums2, m2i, nums2End);
    } else {
        return findMedianSortedArrayModified(nums1, nums1Start, count1%2==0? m1i:m1i+1, nums2, m2i, nums2End);
    }



    return 0;
}
