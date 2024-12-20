import java.util.*;

class Solution {
    public int solution(int[][] land) {
        int answer = 0;
        int n = land.length;
        int m = land[0].length;

        int[][] landId = new int[n][m];
        int currentId = 1;

        Map<Integer, Integer> sizeMap = new HashMap<>();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1 && landId[i][j] == 0){
                    int size = bfs(land, landId, currentId, i, j);
                    sizeMap.put(currentId++, size);
                }
            }
        }

        for(int j = 0; j < m; j++){
            Set<Integer> oil = new HashSet<>();
            for(int i = 0; i < n; i++){
                if(landId[i][j] != 0){
                    oil.add(landId[i][j]);
                }
            }
            int currentOil = 0;
            for(Integer id: oil){
                currentOil += sizeMap.get(id);
            }
            answer = Math.max(answer, currentOil);
        }

        return answer;
    }

    public int bfs(int[][] land, int[][] landId, int currentId, int y, int x) {
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        int n = land.length;
        int m = land[0].length;

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{x, y});
        landId[y][x] = currentId;
        int size = 0;

        while(!queue.isEmpty()){
            int[] current = queue.poll();
            size++;
            for(int i = 0; i < 4; i++){
                int cx = current[0] + dx[i];
                int cy = current[1] + dy[i];
                if(cx >= 0 && cy >= 0 && cx < m && cy < n &&
                        land[cy][cx] == 1 && landId[cy][cx] == 0){
                    queue.add(new int[]{cx, cy});
                    landId[cy][cx] = currentId;
                }
            }
        }

        return size;
    }
}