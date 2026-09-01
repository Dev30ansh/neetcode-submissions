class Solution {
   public:
   bool hasCycle;
    
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<int> &visited, stack<int> &st, vector<int> &inRecursion)
    {
        visited[u] = true;
        inRecursion[u] = true;

        for(auto & v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited, st, inRecursion);
            }
            if(inRecursion[v] == true){
                // in  current recursion v has been visited once --> cycle
                hasCycle = true;
                return;
            }
        }
        // pehele mere bacho(v) ko dalo bad me mujhe(u) dalo
        st.push(u);
        inRecursion[u] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<int> inRecursion(numCourses, false);
        vector<int> visited(numCourses, false);
        stack<int> st;
        hasCycle = false;

        // populate indegree and adj
        for (auto& vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);
        }

        // only call dfs for those who are not visited
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                DFS(adj, i, visited, st, inRecursion);
            }
        }
        if(hasCycle == true){
            return {};
        }

        // pop from stack and fill in result
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};
