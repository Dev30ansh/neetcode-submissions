class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // stores the cords of the cell
        queue<pair<int, int>> que;
        int freshFruits = 0;     // also count the number of fresh fruits

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    que.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshFruits++;
                }
            }
        }

        if(freshFruits == 0){
            return 0;   // all oranges are already rotten
        }

        int minutes = 0;

        while(!que.empty()){
            int size = que.size();

            // multiple cells me same time frame me call karna hai, is liye ek bar me que me jitne 
            // elements hai , use nikal ke process karenge.
            while(size--){
                auto curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto & dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i >= 0 && new_j >= 0 && new_i < m && new_j < n && grid[new_i][new_j] == 1){
                        // 1. if i_ and j_ are in bound AND the neighbour is fresh_fruit --> rottem it
                        // 2. then push in queue
                        grid[new_i][new_j] = 2;
                        que.push({new_i, new_j});
                        freshFruits--;
                    }
                }
            }
            minutes++;
        }

        return freshFruits == 0 ? (minutes-1) : -1;
    }
};
