class Solution {
public:
    // Approach : 2     "optimized take not take"

    vector<string> result;

    void solve(string &temp, int n, int open, int close){
        // base case - if temp.size() == 2*n
        if(temp.size() == 2*n){
            //already a valid parentheses string
            result.push_back(temp);
            return;
        }

        //insert "(" - if open < n
        if(open < n){   
            temp.push_back('(');
            solve(temp, n, open+1, close);
            temp.pop_back();
        }

        // insert ")" - if close < open
        if(close < open){
            temp.push_back(')');
            solve(temp, n, open, close+1);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string temp;

        solve(temp, n, 0, 0);

        return result;
    }
};
