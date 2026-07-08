class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int l = 0;
        int r= 0;
        int temp = 0;

        while(r < nums.size()){
            temp += nums[r];
            while(temp >= target){
                res = min(res, (r-l + 1));
                temp -= nums[l];
                l++;
            }
            r++;
        }
        return res == INT_MAX ? 0 : res;
    }
};