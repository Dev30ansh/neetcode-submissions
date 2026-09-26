class Solution {
   public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;

    // Marks all 'O' cells connected to (row, col) as visited.
    // This DFS is started only from border 'O' cells, so every
    // visited cell belongs to a region that cannot be surrounded.
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
        vis[row][col] = 1;

        for (auto& dir : directions) {
            int nextRow = row + dir[0];
            int nextCol = col + dir[1];

            // Continue DFS if:
            // 1. The next cell is inside the board.
            // 2. It is not visited.
            // 3. Board contains an 'O'.
            if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n &&
                !vis[nextRow][nextCol] && board[nextRow][nextCol] == 'O') {
                dfs(nextRow, nextCol, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        // vis[i][j] == 1 means it is connected to the border
        // and therefore must not be captured.
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // first and last rows.
        for (int col = 0; col < n; col++) {
            if (board[0][col] == 'O' && !vis[0][col]) {
                dfs(0, col, vis, board);
            }

            if (board[m - 1][col] == 'O' && !vis[m - 1][col]) {
                dfs(m - 1, col, vis, board);
            }
        }

        // first and last columns.
        for (int row = 0; row < m; row++) {
            if (board[row][0] == 'O' && !vis[row][0]) {
                dfs(row, 0, vis, board);
            }

            if (board[row][n - 1] == 'O' && !vis[row][n - 1]) {
                dfs(row, n - 1, vis, board);
            }
        }

        // Any remaining unvisited 'O' cannot reach the border,
        // so it belongs to a surrounded region and should be captured.
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == 'O' && !vis[row][col]) {
                    board[row][col] = 'X';
                }
            }
        }
    }
};