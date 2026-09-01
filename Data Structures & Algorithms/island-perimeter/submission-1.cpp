class Solution {
public:
    int m;
    int n;
    int perimeter;

    void dfs(vector<vector<int>>& grid, int i, int j){
        // out of bound ho gaya yato water aa gaya --> boundary count (perimeter ++)
        if(i < 0 or i >= m or j < 0 or j >= n or  grid[i][j] == 0){
            perimeter += 1;
            return;
        }
        // cell already visited hai
        if(grid[i][j] == -1){
            return;
        }

        // visited nahi hai --> ab visited mark kardo
        grid[i][j] = -1;

        // cell ke left, right , top, bottom me search karo
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        perimeter = 0;

        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(grid[i][j] == 1){
                    dfs(grid, i , j);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};