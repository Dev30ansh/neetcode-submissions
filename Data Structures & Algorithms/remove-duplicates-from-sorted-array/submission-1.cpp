class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0,r = 0;    //l->marks where to place unique element
                    //r-> scans elements through the nums array
        int n = nums.size();
        while(r < n){
            nums[l] = nums[r];
            while(r < n && nums[l] == nums[r]){
                r++;
            }
            l++;
        }
        return l;
    }
};