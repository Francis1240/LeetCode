class Solution {
    public int maxArea(int[] height) {
        int max = 0;
        int n = height.length;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j ++){
                int lower = height[i]>height[j]?height[j]:height[i];
                if(lower * (j-i) > max)
                    max = lower * (j-i);
            }
        }

        return max;
    }
}