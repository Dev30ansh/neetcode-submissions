class Solution {
    int target, n;

   public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0) return false;

        target = total / k;
        n = nums.size();
        sort(nums.rbegin(), nums.rend());
        return backtrack(nums, 0, k, 0, (1 << n) - 1);
    }

   private:
    bool backtrack(vector<int>& nums, int i, int k, int subsetSum, int mask) {
        if (k == 0) return true;
        if (subsetSum == target) return backtrack(nums, 0, k - 1, 0, mask);
        for (int j = i; j < nums.size(); j++) {
            if ((mask & (1 << j)) == 0 || subsetSum + nums[j] > target) continue;
            if (backtrack(nums, j + 1, k, subsetSum + nums[j], mask ^ (1 << j))) {
                return true;
            }
            if (subsetSum == 0) return false;
        }
        return false;
    }
};
