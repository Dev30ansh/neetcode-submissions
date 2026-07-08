class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            if (numbers[l] + numbers[r] > target) {
                r--;
            } else if (numbers[l] + numbers[r] < target) {
                l++;
            } else {
            //+1 to l and r bcz, it is 1 indexed, i.e. array starts from index 1 not 0
                return vector<int>{l + 1, r + 1};  
            }
        }
        return vector<int>{};
    }
};
