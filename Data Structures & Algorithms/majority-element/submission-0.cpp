class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        int n = nums.size();
        for(auto x : nums){
            umap[x]++;
        }


        int max = n/2;
        for(auto x : umap){
            int num = x.second;
            if(max < num){
                return x.first;
            }
        }
    }
};