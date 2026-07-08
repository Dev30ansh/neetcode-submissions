class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            // non-alphanumeric means exclude spaces, symbols
            // skip non-alphanumeric on the left
            while (l < r && !isalnum(s[l])) {
                l++;
            }
            // skip non-alphanumeric on the right
            while (l < r && !isalnum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};