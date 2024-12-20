import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        List<String> arrays = Arrays.stream(numbers)
                .mapToObj(Integer::toString)
                .sorted((a, b) -> (b + a).compareTo(a + b))
                .collect(Collectors.toList());
        for(String array : arrays){
            answer += array;
        }
        if(answer.startsWith("0")){
            return "0";
        }
        return answer;
    }
}