class Solution {
public:
    // Approach : 1 - take and not take
    vector<vector<int>> result;
    int n;

    void solve(vector<int>& temp, unordered_map<int, int> mp){

        //base case- if temp size = n ->store ans
        if(temp.size() == n){
            result.push_back(temp);
            return;
        }

        // for each num and count in mp: 
        for(auto& [num, count] : mp){
            //if num -> freq. == 0 then dont take that number(skip)
            if(count == 0){
                continue;
            }

            temp.push_back(num);
            mp[num]--;  //num freq decrease

            solve(temp, mp);

            temp.pop_back();
            mp[num]++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        result.clear();
        n = nums.size();

        //map frequency of each num in nums
        unordered_map<int, int> mp;
        for(auto & num : nums){
            mp[num]++;
        }

        solve(temp, mp);

        return result;
    }
};