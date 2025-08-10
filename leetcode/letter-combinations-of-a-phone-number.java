class Solution {
    Map<Character, String> digitMap = Map.of(
            '2', "abc",
            '3', "def",
            '4', "ghi",
            '5', "jkl",
            '6', "mno",
            '7', "pqrs",
            '8', "tuv",
            '9', "wxyz"
    );

    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if (digits.isEmpty()) return result;
        press("", digits, result);
        return result;
    }

    public void press(String cur, String digits, List<String> result) {
        int depth = cur.length();
        if (depth >= digits.length()) {
            result.add(cur);
            return;
        }
        String letters = digitMap.get(digits.charAt(depth));
        for (char c : letters.toCharArray()) {
            press(cur + c, digits, result);
        }
    }
}