class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(int idx, vector<int>& nums){
        //base case- when idx = n->store ans
        if(idx == n){
            result.push_back(nums);
            return;
        }

        for(int i = idx; i < n; i++){
            //swap index idx with i
            swap(nums[idx], nums[i]);

            solve(idx+1, nums);
            
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        n = nums.size();

        solve(0, nums);

        return result;
    }
};
