class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int i = 0;
        for (auto x : s) {
            nums[i++] = x;
        }
        return s.size();
    }
};