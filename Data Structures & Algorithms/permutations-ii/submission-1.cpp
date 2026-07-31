class Solution {
public:
    // Approach : 2 - swaping of i with idx
    vector<vector<int>> result;
    int n;

    void solve(int idx, vector<int>& nums){
        //base case 
        if(idx == n){
            result.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for(int i = idx; i < n; i++){
            if(st.find(nums[i]) != st.end()){
               //if already in set ignore
               continue;
            }
                st.insert(nums[i]);
                //swap i with idx values
                swap(nums[i], nums[idx]);

                solve(idx+1, nums);

                swap(nums[i], nums[idx]);
                
            //no need to erase from set because each time we are creating a new set beacuse of recursion
        }

    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        result.clear();

        //  (idx, array)
        solve(0, nums);

        return result;
    }
};