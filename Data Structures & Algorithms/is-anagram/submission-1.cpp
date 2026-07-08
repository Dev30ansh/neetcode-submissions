class Solution {
public:
    bool isAnagram(string s, string t) {
         if (s.size() != t.size()){
            return false;
        }

        unordered_map<int, int> m1;
        //unordered_map<int, int> m2;

        for(auto ch : s){
            m1[ch]++;
        }
        for(auto ch : t){
            m1[ch]--;
            if(m1[ch] < 0)
                return false;
        }
        return true;
    }
};
