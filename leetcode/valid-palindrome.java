class Solution {
    public boolean isPalindrome(String s) {
        int start = 0;
        int end = s.length() - 1;
        s = s.toLowerCase();

        while(start < end){
            if(!isAlphabetOrDigit(s.charAt(start))){
                start ++;
            } else if (!isAlphabetOrDigit(s.charAt(end))){
                end --;
            } else{
                if(s.charAt(start) != s.charAt(end)){
                    return false;
                }
                start ++;
                end --;
            }
        }

        return true;
    }

    public boolean isAlphabetOrDigit(Character c){
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
}