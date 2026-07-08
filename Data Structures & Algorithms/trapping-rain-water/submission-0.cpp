class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        
        if(n == 0){
            return 0;
        }

        for(int i = 0; i < n; i++){
            int maxLeft = height[i];
            int maxRight = height[i];

            for(int j = 0; j < i; j++){
                maxLeft = max(maxLeft, height[j]);
            }
            for(int j = i+1; j < n; j++){
                maxRight = max(maxRight, height[j]);
            }

            res += min(maxLeft, maxRight) - height[i];
        }
        return res;
    }
};
