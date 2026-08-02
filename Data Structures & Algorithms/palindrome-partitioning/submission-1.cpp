class Solution {
   public:
    vector<vector<string>> result;
    int n;

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    // Backtracking helper
    // temp stores the current partition being built
    // idx is the starting index of the remaining substring to process
    void solve(string& s, vector<string>& temp, int idx) {
        // Base case: processed the whole string, save this partition
        if (idx == n) {
            result.push_back(temp);
            return;
        }

        // Try every possible ending index i for a substring starting at idx
        for (int i = idx; i < n; i++) {
            // Only split here if s[idx...i] is a palindrome
            if (isPalindrome(s, idx, i)) {
                // Choose: add this palindrome substring to the current partition
                temp.push_back(s.substr(idx, i - idx + 1));

                // Recurse on the rest of the string after i
                solve(s, temp, i + 1);

                // Undo the choice (backtrack)
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> temp;

        solve(s, temp, 0);

        return result;
    }
};