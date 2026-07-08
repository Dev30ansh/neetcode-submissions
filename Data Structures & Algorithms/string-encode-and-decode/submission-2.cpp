class Solution {
public:

    string encode(vector<string>& strs) {
        //int_#_s  - format
        string endoded;
        for(auto &s : strs){
            endoded.append(to_string(s.size()));
            endoded.push_back('#');
            endoded.append(s);
        }
        return endoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j - i));

            i = j + 1;
            j = i + length;
            decoded.push_back(s.substr(i, length));
            i = j;
        }
        return decoded;
    }
};
