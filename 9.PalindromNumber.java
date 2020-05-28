class Solution {
    public boolean isPalindrome(int x) {
        String s = Integer.toString(x);
        int l = s.length();
        for(int i = 0; i < l/2; i++){
            if(s.charAt(i) != s.charAt(l-i-1)){
                return false;
            }
        }
        return true;
    }
}