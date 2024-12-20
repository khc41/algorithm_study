import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int sco : scoville){
            pq.add(sco);
        }

        while(!pq.isEmpty()){
            if(pq.size() > 1){
                int first = pq.poll();
                int second = pq.poll();
                if(first >= K){
                    return answer;
                }
                pq.add(first + second * 2);
                answer++;
            } else {
                if(pq.poll() >= K){
                    return answer;
                }
            }
        }
        String.

        return -1;
    }
}