class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // If s1 is longer than s2, s2 can never contain a permutation of s1
        if (n > m) {
            return false;
        }

        /* Frequency arrays for characters 'a' to 'z'
        'a'->0
        'b'->1
        'c'->2 */
        vector<int> s1_freq(26, 0);
        vector<int> s2_freq(26, 0);

        //  s1 frequency count
        for (auto ch : s1) {
            s1_freq[ch - 'a']++;
        }

        int l = 0;  // left pointer of sliding window
        int r = 0;  // right pointer of sliding window

        while (r < m) {
            // increse freq. of s[r] in s2_freq array
            s2_freq[s2[r] - 'a']++;

            // If window size becomes larger than s1, shrink from the left
            if ((r - l + 1) > n) {
                s2_freq[s2[l] - 'a']--;
                l++;
            }

            // If frequencies match, current window is a permutation of s1
            if (s1_freq == s2_freq) {
                return true;
            }
            
            r++;
        }
        // No matching window found
        return false;
    }
};