/* *
 * Title: Two Sum
 * 
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * */

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int count = nums.size();
        map<int,int> M;
        for(int i = 0; i < count ; i ++){
            M[nums[i]] ++;
            M[target-num[i]]--;
        }
        for(int i = 0; i < count ; i ++){
            if (M[nums[i]] == 0){
                vector<int> result;
                result[0] = i;
                
                return 
            }
        }
    }
}