class Solution {
public:
    // T.C.- O( k * 2^n)
    
    void solve(int i,vector<int> temp, int n, int k,  vector<vector<int>>& combinations){
        //base case - when size array size is of k , push in ans;
        if(temp.size() == k){
            combinations.push_back(temp);
            return;
        }

        //if reached out of bound and didn't get size k array - return
        if(i > n){
            return;
        }

        //include i
        temp.push_back(i);
        solve(i+1, temp, n, k, combinations);

        //exclude i
        temp.pop_back();
        solve(i+1, temp, n, k, combinations);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> temp;

        solve(1, temp, n, k, combinations);

        return combinations;
    }
};