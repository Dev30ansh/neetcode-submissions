class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& subsets){
        //base case - if i out of bound - push temp in result and return;
        if(i >= nums.size()){
            subsets.push_back(temp);
            return;
        }
        
        // include i
        temp.push_back(nums[i]);
        solve(nums, i+1, temp, subsets);

        //check for duplicates
        int idx = i + 1;
        while(idx < nums.size() and nums[idx] == nums[idx-1]){
            idx++;
        }

        //exclude i
        temp.pop_back();
        solve(nums, idx, temp, subsets);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 1. sort array
        sort(nums.begin(), nums.end());

        vector<vector<int>> subsets;
        vector<int> temp;

        // 2. calculate subsets
        solve(nums, 0, temp, subsets);

        return subsets;
    }
};
