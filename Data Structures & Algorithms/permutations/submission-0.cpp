class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> st;

    void solve(vector<int>& temp, vector<int>& nums){
        if(temp.size() ==  nums.size()){
            result.push_back(temp);
            return ;
        }
        
        for(int i = 0; i < nums.size(); i++){
            // if i pair me alread nahi present ho tabhi add karenge varna ignore...
            // to avoid duplucation
            if(st.find(nums[i]) == st.end()){
                //do
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                //explore
                solve(temp, nums);
                //undo
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        result.clear();

        // index NOT passed because we start from 0 again each iteration
        solve(temp, nums);

        return result;
    }
};
