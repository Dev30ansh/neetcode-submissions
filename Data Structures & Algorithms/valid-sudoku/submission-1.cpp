class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for row
        for (int row = 0; row < 9; row++) {
            unordered_set<int> s;
            for (int i = 0; i < 9; i++) {
                if (board[row][i] == '.') {
                    continue;
                }
                if (s.count(board[row][i])) {
                    return false;
                }
                s.insert(board[row][i]);
            }
        }
        // for column
        for (int col = 0; col < 9; col++) {
            unordered_set<int> s;
            for (int i = 0; i < 9; i++) {
                if (board[i][col] == '.') {
                    continue;
                }
                if (s.count(board[i][col])) {
                    return false;
                }
                s.insert(board[i][col]);
            }
        }
        // for 3x3 suare matrix
        for (int square = 0; square < 9; square++) {
            unordered_set<int> s;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') {
                        continue;
                    }
                    if (s.count(board[row][col])){
                        return false;
                    }
                    s.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
