class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& allSubsets){
        //base case- if 'i' is out of bound - push temp in result and return
        if(i >= nums.size()){
            allSubsets.push_back(temp);
            return;
        }

        //include i
        temp.push_back(nums[i]);
        solve(nums, i+1, temp, allSubsets);

        //exclude i
        temp.pop_back();
        solve(nums, i+1, temp, allSubsets);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> temp;

        solve(nums, 0, temp, allSubsets);

        return allSubsets;
    }
};
