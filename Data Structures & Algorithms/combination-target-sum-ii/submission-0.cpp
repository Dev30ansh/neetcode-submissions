class Solution {
public:
    vector<vector<int>> result; 

    void solve(int i, int total, vector<int>& temp, vector<int>& candidates, int target) {
        // Base case: combination found
        if (total == target) {
            result.push_back(temp); 
            return;
        }

        // Prune: index out of bounds or sum already exceeds target
        if (i >= candidates.size() || total > target) {
            return;
        }

        // Try each candidate starting from index i
        for (int j = i; j < candidates.size(); j++) {
            // Skip duplicates at the same recursion depth
            // Because array is sorted, duplicates are adjacent
            if (j > i && candidates[j] == candidates[j - 1])
                continue;

            // Choose candidate[j]
            temp.push_back(candidates[j]);
            // Recurse with next index (each element used at most once) and updated total
            solve(j + 1, total + candidates[j], temp, candidates, target);
            // Undo choice (backtrack)
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;               // temporary combination
        sort(candidates.begin(), candidates.end()); // sort to handle duplicates easily
        solve(0, 0, temp, candidates, target);
        return result;
    }
};