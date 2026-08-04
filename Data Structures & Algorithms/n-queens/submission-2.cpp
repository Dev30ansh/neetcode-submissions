class Solution {
   public:
    // Approach : 2 - using hash Set
    vector<vector<string>> result;
    int N;

    // unordered sets for trackig queen's position
    unordered_set<int> column;
    unordered_set<int> diagonal;
    unordered_set<int> antiDiagonal;

    void solve(vector<string>& board, int row) {
        //reached end of row
        if (row == N) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++) {

            int diagConst = row + col;  // up right diagnal
            int antiDiagConst = row - col;  // up left diagnal

            // find if invalid cell to put queen ->> continue to next cell
            if (column.find(col) != column.end() or diagonal.find(diagConst) != diagonal.end() or
                antiDiagonal.find(antiDiagConst) != antiDiagonal.end()) {
                continue;
            }

            // found good cell to keep queen
            board[row][col] = 'Q';
            column.insert(col);     // ->> insert this cell as under attack
            diagonal.insert(diagConst); // ->>make diagonals w.r.t. this cell as under attack
            antiDiagonal.insert(antiDiagConst); // ->>make Anti diagonals w.r.t. this cell as under attack

            // explore
            solve(board, row + 1);

            // undo : if not a valid cell to place queen undo
            board[row][col] = '.';
            column.erase(col);
            diagonal.erase(diagConst);
            antiDiagonal.erase(antiDiagConst);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        result.clear();

        // create board:
        vector<string> board(n, string(n, '.'));

        solve(board, 0);

        return result;
    }
};
