class Solution {
   public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> result;

        // create an array which has index of each task included in it
        // ->> {arrival_time, duration_time, index}
        vector<array<int, 3>> sortedTasks;

        for (int i = 0; i < n; i++) {
            int arival_time = tasks[i][0];
            int duration_time = tasks[i][1];
            int index = i;

            sortedTasks.push_back({arival_time, duration_time, index});
        }

        // sort the tasks
        sort(begin(sortedTasks), end(sortedTasks));

        // create min_heap of pair<int,int>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        long long curr_time = 0;
        int idx = 0;

        while (idx < n || !pq.empty()) {
            // initialize the curr_time with the first task arival_time
            if (pq.empty() and sortedTasks[idx][0] > curr_time) {
                curr_time = sortedTasks[idx][0];
            }

            // push in pq if curr_time > task's arrival_time
            while (idx < n and curr_time >= sortedTasks[idx][0]) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            pair<int, int> curr_task = pq.top();
            pq.pop();

            curr_time += curr_task.first;
            result.push_back(curr_task.second);
        }
        return result;
    }
};