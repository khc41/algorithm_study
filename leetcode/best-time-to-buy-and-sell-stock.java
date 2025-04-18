class Solution {
    public int maxProfit(int[] prices) {
        int result = 0;
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < prices.length; i++){
            if(min > prices[i]){
                min = prices[i];
                continue;
            }
            result = Math.max(prices[i] - min, result);
        }
        return result;
    }
}