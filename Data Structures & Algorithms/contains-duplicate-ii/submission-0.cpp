class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //Use of Hash Set
        //T.C. = O(n)
        //S.C. = O(min(n,k))
        unordered_set<int> set;
        int L = 0;

        for(int R = 0; R < nums.size(); R++){
            if(R - L > k){
                //maintaining the size of window'
                set.erase(nums[L]);
                L += 1;
            }
            //if(set.count(nums[R])){   OR
            if(set.find(nums[R]) != set.end()){
                //if R is already present in the set, 
                //same values- return true;
               return true; 
            }
            //otherwise insert that value in SET
            set.insert(nums[R]);
        }
        return false;
    }
};