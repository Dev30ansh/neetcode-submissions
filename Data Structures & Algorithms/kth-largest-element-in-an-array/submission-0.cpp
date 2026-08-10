class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // with sorting
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};
