class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int area = 0;
        int ans = 0;

        while (l < r) {
            int breath = r - l;
            int mini = min(heights[l],heights[r]);

            area = mini * breath;
            ans = max(ans, area);
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};
