class Solution {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s;

        char[][] a = new char[numRows][(numRows-1)*((s.length())/(2*numRows-2)+1)];
        boolean direction_down = true;
        int count = 0, r = 0, c = 0;
        while(count < s.length()){
            a[r][c] = s.charAt(count);
            count ++;
            if(direction_down){
                if(r == numRows-1){
                    direction_down = false;
                    r --;
                    c ++;
                    continue;
                }
                r++;
                continue;
            }
            if(r == 0){
                direction_down = true;
                r++;
                continue;
            }
            r--;
            c++;
        }
        String result = new String();

        for(char[] row : a){
            for(char col: row){
                if(col != '\u0000'){
                    result += col;
                }
            }
        }
        return result;
    }
}