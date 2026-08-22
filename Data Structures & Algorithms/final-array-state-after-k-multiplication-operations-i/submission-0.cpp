class Solution {
   public:
    typedef pair<int, int> P;

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while (k != 0) {
            int num = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            num = num * multiplier;
            nums[idx] = num;

            pq.push({num, idx});

            k--;
        }
        return nums;
    }
};