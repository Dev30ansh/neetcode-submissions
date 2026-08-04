class Solution {
public:
    // Apprach : 1
    vector<vector<string>> result;
    int N;

    bool isSafe(vector<string> &board, int row, int col){
        //CHECK upward : if queen is present
        for(int i = row - 1; i >= 0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        // CHECK UP RIGHT DIAGONAL
        for(int i = row - 1, j = col + 1; i >= 0 && j < N; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // CHECK UP LEFT DIAGONAL
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0 ; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        // if cell is valid: return true
        return true;
    }

    void solve(vector<string> &board, int row){
        if(row >= N){
            result.push_back(board);
            return;
        }

        //for current row , check for all cols
        for(int col = 0; col < N; col++){
        // check if current row, col position is not under attack from other queens and is Safe
            if(isSafe(board, row, col)){
                //if Yes: place queen
                board[row][col] = 'Q';

                //explore: for next place for queen
                solve(board, row+1);
                
                //undo
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        result.clear();

        // create board:  (size, (row-size, initial val->'.'))
        vector<string> board(n, string(n,'.'));   //->>{"....", "....", "....", "...."}

        solve(board, 0); // row = 0

        return result;
    }
};
