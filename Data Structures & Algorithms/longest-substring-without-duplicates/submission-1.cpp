class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //we will iterate(r) to  every element in s;
        //if found in set, remove the s[l] and increment l;
        //else : insert in set and compute the maxLen b/w l,r

        int l = 0;
        int maxLen = 0;
        unordered_set<char> set;
        
        for(int r = 0; r < s.size(); r++){
            //remove element until s[r] is in set
            while(set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
            }

            set.insert(s[r]);
            maxLen = max(maxLen, (r - l + 1));
        }
        return maxLen;
    }
};
