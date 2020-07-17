class Solution {
    public int reverse(int x) {
        boolean neg = x<0;
        if(x == -2147483648){
            return 0;
        }
        x = x<0?-x:x;
        long result = 0;
        while(x>0){
            result *= 10;
            result += x%10;
            x /= 10;
        }
        result *= neg?-1:1;

        if(result > Integer.MAX_VALUE || result < Integer.MIN_VALUE){
            return 0;
        }
        return (int) result;
    }
}