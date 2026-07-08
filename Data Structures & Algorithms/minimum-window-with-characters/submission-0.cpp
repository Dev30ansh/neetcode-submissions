class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() == 0){
            return "";
        }

        unordered_map<char, int> window;
        unordered_map<char, int> countT;

        //mapping c to its frequency
        for(auto c : t){
            countT[c]++;
        }

        int have =0;
        int need = countT.size();
        pair<int, int>res = {-1,-1};
        int resLen = INT_MAX;
        int l = 0;

        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                have++;
            }

            while(have == need){
                //update the result
                if((r - l + 1) < resLen){
                    resLen = (r - l + 1);
                    res = {l,r};
                }
                //pop from the left of window
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
