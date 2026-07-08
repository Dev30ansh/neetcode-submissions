class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;

        //list every element in the umap with its frquency
        for(auto x : nums){
            umap[x]++;
        }

        //insert into an arrayy interchanging their [num,freq] place-i.e. [freq, num],
            //because sort function will arrange freq in descending order of its freq., 
            //so we can easily find top k freq elements
        vector<pair<int, int>> arr;
        for(auto& [num, freq] : umap){
            arr.push_back({freq, num});
        }
        //sort in descending order
        sort(arr.begin(), arr.end(), greater<pair<int,int>>());

        //insert into vector<int> ans
        vector<int> ans;
        for(int i = 0; i< k; i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};
