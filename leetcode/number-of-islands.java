class Solution {
    int[][] dir = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1}
    };

    public int numIslands(char[][] grid) {
        int result = 0;
        int y = grid.length;
        int x = grid[0].length;
        boolean[][] isVisited = new boolean[y][x];
        Queue<Pair> queue = new LinkedList<>();

        for(int i = 0; i < y; i++){
            for(int j = 0; j < x; j++){
                if(isVisited[i][j] || grid[i][j] == '0'){
                    continue;
                }
                result++;
                isVisited[i][j] = true;
                queue.offer(new Pair(i, j));
                bfs(grid, isVisited, queue, y, x);
            }
        }
        return result;
    }

    public void bfs(char[][] grid, boolean[][] isVisited, Queue<Pair> queue, int y, int x) {
        while(!queue.isEmpty()){
            Pair cur = queue.poll();
            for(int k = 0; k < 4; k++){
                int curY = cur.getY() + dir[k][0];
                int curX = cur.getX() + dir[k][1];
                if(curY < 0 || curY >= y || curX < 0 || curX >= x){
                    continue;
                }
                if(!isVisited[curY][curX] && grid[curY][curX] != '0'){
                    isVisited[curY][curX] = true;
                    queue.offer(new Pair(curY, curX));
                }
            }
        }
    }

    public class Pair {
        public int x;
        public int y;

        public Pair(int y, int x) {
            this.x = x;
            this.y = y;
        }

        public int getX(){
            return x;
        }

        public int getY(){
            return y;
        }
    }
}