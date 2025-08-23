class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Pair<Integer, Integer>> set = new HashSet<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    set.add(new Pair(i, -1));
                    set.add(new Pair(-1, j));
                }
            }
        }

        for (Pair<Integer, Integer> pair : set) {
            if (pair.getKey() == -1) {
                writeHeight(matrix, pair.getValue());
            }
            if (pair.getValue() == -1) {
                writeWidth(matrix, pair.getKey());
            }
        }
    }

    public void writeHeight(int[][] matrix, int value) {
        for (int i = 0; i < matrix.length; i++) {
            matrix[i][value] = 0;
        }
    }

    public void writeWidth(int[][] matrix, int value) {
        for (int i = 0; i < matrix[0].length; i++) {
            matrix[value][i] = 0;
        }
    }
}