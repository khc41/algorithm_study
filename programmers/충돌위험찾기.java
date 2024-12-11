import java.util.*;
import java.util.stream.Collectors;

class Solution {
    public int solution(int[][] points, int[][] routes) {
        int answer = 0;

        Robots robots = new Robots(points, routes);

        answer += robots.getWarningCount();
        while (!robots.isEnd()) {
            robots.move();
            answer += robots.getWarningCount();
        }

        return answer;
    }
}

class Robots {
    private List<Robot> robots = new ArrayList<>();

    Robots(int[][] points, int[][] routes) {
        for (int[] route : routes) {
            List<int[]> path = Arrays.stream(route)
                    .mapToObj(point -> points[point - 1])
                    .collect(Collectors.toList());
            robots.add(new Robot(path));
        }
    }

    public void move() {
        robots.forEach(Robot::move);
    }

    public boolean isEnd() {
        robots.removeIf(Robot::isEnd);
        return robots.isEmpty();
    }

    public int getWarningCount() {
        Map<List<Integer>, Integer> map = new HashMap<>();
        robots.forEach(robot -> map.put(robot.currentPos(), map.getOrDefault(robot.currentPos(), 0) + 1));
        return (int) map.values().stream().filter(value -> value >= 2).count();
    }

}

class Robot {
    private int r;
    private int c;
    private List<int[]> path;
    private int currentTarget = 1;

    Robot(List<int[]> path) {
        this.path = path;
        int[] start = path.get(0);
        r = start[0];
        c = start[1];
    }

    public void move() {
        if (isEnd()) {
            return;
        }
        int[] target = path.get(currentTarget);
        if (r != target[0]) {
            r += (r < target[0]) ? 1 : -1;
        } else if (c != target[1]) {
            c += (c < target[1]) ? 1 : -1;
        }

        if (r == target[0] && c == target[1]) {
            currentTarget++;
        }
    }

    public boolean isEnd() {
        return currentTarget >= path.size();
    }

    public List<Integer> currentPos() {
        List<Integer> pos = new ArrayList<>();
        pos.add(r);
        pos.add(c);
        return pos;
    }

}