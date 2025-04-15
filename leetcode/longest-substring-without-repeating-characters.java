class Solution {
    public int lengthOfLongestSubstring(String s) {
        int result = 0;
        int start = 0;
        Map<Character, Integer> map = new HashMap<>();

        for(int end = 0; end < s.length(); end++){
            char current = s.charAt(end);
            if(map.containsKey(current)){
                start = Math.max(map.get(current) + 1, start);
            }

            map.put(current, end);
            result = Math.max(result, end - start + 1);
        }
        return result;
    }
}