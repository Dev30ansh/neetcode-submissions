class Solution {
   public:
    int characterReplacement(string s, int k) {
        //valid substing if
        // (len of window - maxcount of value )< k

        unordered_map<char, int> umap;
        int res = 0;
        int l = 0;
        int maxCount = 0;

        for (int r = 0; r < s.size(); r++) {
            //counts the max value of a character
            umap[s[r]]++;
            maxCount = max(maxCount, umap[s[r]]);
            while ((r - l + 1) - maxCount > k) {
                umap[s[l]]--;
                l++;
            }

            res = max(res, (r - l + 1));
        }
        return res;
    }
};
