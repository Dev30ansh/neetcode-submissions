class Solution {
   public:
    vector<string> result;
    unordered_set<string> st;

    void solve(int i, string& temp, string& s) {
        // Base case: we reached the end of the string,
        // so current path forms a valid sentence
        if (i == s.length()) {
            result.push_back(temp);
            return;
        }

        // Try every possible substring starting from index i
        for (int j = i; j < s.length(); j++) {
            string currWord = s.substr(i, j - i + 1);

            // word exists in set
            if (st.count(currWord)) {
                // Save the current state of temp - to undo changes later
                string oldTemp = temp;

                // Add a space only if temp is not empty
                if (!temp.empty()) {
                    temp += " ";
                }
                //do:
                temp += currWord;

                // Explore:
                solve(j + 1, temp, s);

                // undo: Restore temp back to its previous state for the next branch
                temp = oldTemp;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // put wordDuct int a set for faster finding
        for (auto& word : wordDict) {
            st.insert(word);
        }

        string temp = "";

        solve(0, temp, s);  // 0 -> starting index

        return result;
    }
};