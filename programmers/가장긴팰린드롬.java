class Solution
{
    public int solution(String s)
    {
        int answer = 0;

        if(s.length() == 1){
            return 1;
        }

        for(int i = 0; i < s.length(); i++){
            int count = palindrome(i - 1, i + 1, s);
            answer = Math.max(answer, count * 2 + 1);

            if(i + 1 < s.length() && s.charAt(i) == s.charAt(i + 1)){
                count = palindrome(i - 1, i + 2, s);
                answer = Math.max(answer, count * 2 + 2);
            }
        }

        return answer;
    }

    public int palindrome(int left, int right, String s){
        int count = 0;
        while(left >= 0 && right < s.length()){
            if(s.charAt(left) == s.charAt(right)){
                count++;
                left--;
                right++;
            } else {
                break;
            }
        }
        return count;
    }
}