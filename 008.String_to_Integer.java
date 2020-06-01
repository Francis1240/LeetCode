class Solution {
    public int myAtoi(String str) {
        int i = 0;
        boolean negative = false;
        boolean o = false;
        while(i+1 < str.length() && str.charAt(i) == ' ') i++;
        if(i < str.length() && !Character.isDigit(str.charAt(i))){
            switch(str.charAt(i)){
                case '-':
                    negative = true;
                    i++;
                    break;
                case '+':
                    i++;
                    break;
                default: 
                    return 0;
            }
        }
        long result = 0;
        while(i < str.length() && Character.isDigit(str.charAt(i))){
            if(result > Long.MAX_VALUE/100L){
                result = Integer.MAX_VALUE;
                o = true;
                break;
            }
            result *= 10;
            result += (short)str.charAt(i) - 48;
            i++;
        }
        result *= negative?-1:1;
        
        if(result < Integer.MIN_VALUE || (o&&negative)){
            return Integer.MIN_VALUE;
        }
        if(result > Integer.MAX_VALUE){
            return Integer.MAX_VALUE;
        }
        
        return (int)result;
    }
}