class Solution {
   public:
    vector<int> kahnAlgorithm(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree) {
        vector<int> result;
        queue<int> que;
        int count = 0;

        // push in que whose indegree is 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                result.push_back(i);
                count++;
            }
        }

        while (!que.empty()) {
            int u = que.front();
            que.pop();

            for (auto& v : adj[u]) {
                // decrease the indegree of one whom we have visited
                indegree[v]--;
                if (indegree[v] == 0) {
                    que.push(v);
                    result.push_back(v);
                    count++;
                }
            }
        }
        if (count == n)  // count == n --> visited all nodes-> no loop -> return result
            return result;
        else
            return {};  // loop present
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        // populate indegree and adj
        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return kahnAlgorithm(adj, numCourses, indegree);
    }
};
