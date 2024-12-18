import java.util.*;

class Solution {
    public int solution(int[][] maps) {
        Queue<Point> queue = new LinkedList<>();

        boolean[][] visited = new boolean[maps.length][maps[0].length];
        int goalX = maps[0].length - 1;
        int goalY = maps.length - 1;

        queue.offer(new Point(0, 0, 1));
        visited[0][0] = true;

        while(!queue.isEmpty()){
            Point pos = queue.poll();
            for(int i = 0; i < 4; i++){
                Point newPos = pos.move(i);
                if(newPos.isOut(goalX, goalY, maps)){
                    continue;
                }
                if(!newPos.canMove(maps)){
                    continue;
                }
                if(newPos.isGoal(goalX, goalY)){
                    return newPos.getDistance();
                }
                if(!newPos.isVisited(visited)){
                    visited[newPos.getY()][newPos.getX()] = true;
                    queue.offer(newPos);
                }
            }
        }

        return -1;
    }

}

class Point {
    private int x;
    private int y;
    private int distance;

    int[] dirX = {1, -1, 0, 0};
    int[] dirY = {0, 0, 1, -1};

    Point (int y, int x, int distance){
        this.x = x;
        this.y = y;
        this.distance = distance;
    }

    public Point move(int i){
        return new Point(this.y + dirY[i], this.x + dirX[i], this.distance + 1);
    }

    public boolean isVisited(boolean[][] visited){
        return visited[y][x];
    }

    public boolean isGoal(int goalX, int goalY){
        return this.x == goalX && this.y == goalY;
    }

    public boolean isOut(int goalX, int goalY, int[][] maps){
        return this.x > goalX || this.y > goalY || this.x < 0 || this.y < 0;
    }

    public boolean canMove(int [][] maps){
        return maps[this.y][this.x] == 1;
    }

    public int getX(){
        return this.x;
    }

    public int getY(){
        return this.y;
    }

    public int getDistance(){
        return this.distance;
    }
}