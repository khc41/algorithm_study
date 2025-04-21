class Solution {
    public int[][] dir = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
    };

    public boolean exist(char[][] board, String word) {
        if (!isSearchPossible(board, word)) {
            return false;
        }

        boolean[][] visited = new boolean[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] != word.charAt(0)) {
                    continue;
                }
                if (dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean isSearchPossible(char[][] board, String word) {
        Map<Character, Integer> boardFreq = new HashMap<>();
        for (char[] row : board) {
            for (char c : row) {
                boardFreq.put(c, boardFreq.getOrDefault(c, 0) + 1);
            }
        }

        Map<Character, Integer> wordFreq = new HashMap<>();
        for (char c : word.toCharArray()) {
            wordFreq.put(c, wordFreq.getOrDefault(c, 0) + 1);
        }

        for (char c : word.toCharArray()) {
            if (boardFreq.getOrDefault(c, 0) < wordFreq.get(c)) {
                return false;
            }
        }
        return true;
    }

    public boolean dfs(char[][] board, String word, int y, int x, int depth, boolean[][] visited) {
        if (depth == word.length()) {
            return true;
        }
        if (y < 0 || y >= board.length || x < 0 || x >= board[0].length) {
            return false;
        }
        if (visited[y][x] || board[y][x] != word.charAt(depth)) {
            return false;
        }

        visited[y][x] = true;
        for (int k = 0; k < 4; k++) {
            int ny = y + dir[k][0];
            int nx = x + dir[k][1];

            if (dfs(board, word, ny, nx, depth + 1, visited)) {
                return true;
            }
        }
        visited[y][x] = false;
        return false;
    }
}