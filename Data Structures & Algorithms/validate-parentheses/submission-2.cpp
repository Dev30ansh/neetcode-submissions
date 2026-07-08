class Solution {
   public:
    bool isValid(string s) {
        vector<int> stack_;

        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack_.push_back(ch);
            } else {
                if (stack_.empty()) {
                    return false;
                }
                int popped = stack_.back();
                stack_.pop_back();

                if (ch == ')' && popped != '(') {
                    return false;
                }
                if (ch == '}' && popped != '{') {
                    return false;
                }
                if (ch == ']' && popped != '[') {
                    return false;
                }
            }
        }
        return stack_.empty();
    }
};