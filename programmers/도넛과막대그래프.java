import java.util.HashMap;
import java.util.Map;

class 도넛과막대그래프 {
    public int[] solution(int[][] edges) {
        int[] answer = new int[4];

        Map<Integer, Integer> in = new HashMap<>();
        Map<Integer, Integer> out = new HashMap<>();

        for(int[] edge: edges){
            out.put(edge[0], out.getOrDefault(edge[0], 0) + 1);
            in.put(edge[1], in.getOrDefault(edge[1], 0) + 1);
        }

        for(int node: out.keySet()){
            if(out.get(node) > 1){
                if(!in.containsKey(node)){
                    answer[0] = node;
                } else {
                    answer[3] += 1;
                }
            }
        }

        for(int node: in.keySet()){
            if(!out.containsKey(node)){
                answer[2] += 1;
            }
        }
        answer[1] = out.get(answer[0]) - answer[3] - answer[2];

        return answer;
    }

}