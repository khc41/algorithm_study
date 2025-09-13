import java.util.*;

class Solution {
    public int[] solution(int[] fees, String[] records) {
        Map<String, Integer> park = new HashMap<>();
        for (String record : records) {
            String[] word = record.split(" ");
            int time = getTime(word[0]);
            if ("IN".equals(word[2])) {
                time *= -1;
            }
            Integer value = park.getOrDefault(word[1], 0);
            park.put(word[1], value + time);
        }
        int[] answer = new int[park.size()];
        Map<String, Integer> sortedMap = new TreeMap<>(park);
        int index = 0;
        for (Integer time : sortedMap.values()) {
            int price = fees[1];
            if (time <= 0) {
                time += getTime("23:59");
            }
            if (time > fees[0]) {
                price += Math.ceil((double) (time - fees[0]) / fees[2]) * fees[3];
            }
            answer[index++] = price;
        }
        return answer;
    }

    public int getTime(String word) {
        String[] time = word.split(":");
        return Integer.valueOf(time[0]) * 60 + Integer.valueOf(time[1]);
    }
}