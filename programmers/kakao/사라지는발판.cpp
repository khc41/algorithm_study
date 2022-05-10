#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M;

bool safe(int x, int y) {
    return y >= 0 && x >= 0 && x < M && y < N;
}

bool cant_move(vector<vector<int>>& board, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (safe(nx, ny) && board[ny][nx]) return false;
    }
    return true;
}

pair<bool, int> solve(vector<vector<int>>& board, int x1, int y1, int x2, int y2) {
    if (cant_move(board, x1, y1)) return { false, 0 };
    if (y1 == y2 && x1 == x2) return { true, 1 };

    bool can_win = false;
    int min_turn = 1e9, max_turn = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x1 + dir[i][0];
        int ny = y1 + dir[i][1];
        if (!safe(nx, ny) || !board[ny][nx]) continue;

        board[y1][x1] = 0;
        pair<bool, int> res = solve(board, x2, y2, ny, nx);
        board[y1][x1] = 1;

        if (!res.first) {
            can_win = true;
            min_turn = min(min_turn, res.second);
        }
        else if(!can_win) {
            max_turn = max(max_turn, res.second);
        }
   }

    int turn = can_win ? min_turn : max_turn;
    return { can_win, 1 + turn };
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size(), M = board[0].size();
    return solve(board, aloc[1], aloc[0], bloc[1], bloc[0]).second;
}

int main() {
   vector<vector<int>> board = { {1, 1, 1}, {1, 1, 1},{1, 1, 1} };
   vector<int> aloc = { 1, 0 };
   vector<int> bloc = { 1,2 };
   cout << solution(board, aloc, bloc);
}