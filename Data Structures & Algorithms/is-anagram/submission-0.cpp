class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;

        for(auto ch : s){
            m1[ch]++;
        }
        for(auto ch : t){
            m2[ch]++;
        }
        if(m1 == m2){
            return true;
        }
        return false;
    }
};
