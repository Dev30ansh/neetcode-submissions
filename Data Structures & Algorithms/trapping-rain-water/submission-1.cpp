class Solution {
public:
    int trap(vector<int>& heights) {
        //optimal solution
        //time complexity: O(n)
        //space complexity: O(1)

        int res = 0;
        int l = 0;
        int r = heights.size()-1;
        int leftMax = heights[l];
        int rightMax = heights[r];

        if (heights.empty()) {
            return 0;
        }

        while(l < r){
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax, heights[l]);
                res += leftMax - heights[l];
            }
            else{
                r--;
                rightMax = max(rightMax, heights[r]);
                res += rightMax - heights[r];
            }
        }
        return res;
    }
};
