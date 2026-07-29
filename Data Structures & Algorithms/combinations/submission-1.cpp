class Solution {
public:
    // T.C.- O( k * C(n,k))
    //
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

        // applying combination formula
        // we move in range from 1 to n
        // for each j we move from j+1 to n, then i++;
        // 
        for(int j = i; j <= n; j++){
            temp.push_back(j);
            solve(j+1, temp, n, k, combinations);
            temp.pop_back();
        }

    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> temp;

        solve(1, temp, n, k, combinations);

        return combinations;
    }
};