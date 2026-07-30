class Solution {
public:

    vector<string> result;
    
    void solve(int idx, string& digits, string& temp, unordered_map<char, string>& mp)
    {
        // base case - when idx goes out of the range of digits
        if(idx >= digits.length()){
            result.push_back(temp);
            return;
        }

        // find first number of digits
        char number = digits[idx];
        //find its mapping 
        string str = mp[number];
        
        // iterate through all characters of num.
        for(int i = 0; i < str.length(); i++){
            temp.push_back(str[i]);
            solve(idx+1, digits, temp, mp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }

        //create a map for number-words mapping
        unordered_map<char, string> mp;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        result.clear();
        string temp = "";

        //starting idx = 0
        solve(0, digits, temp, mp);
        return result;
    }
};
