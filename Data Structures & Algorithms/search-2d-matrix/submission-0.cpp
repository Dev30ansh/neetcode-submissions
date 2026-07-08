class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int l = 0;
        int r = ROWS*COLS - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            int row = mid / COLS;
            int col = mid % COLS;

            if(target > matrix[row][col]){
                l = mid + 1;
            }
            else if(target < matrix[row][col]){
                r = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
