class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // brute force: 
        // T.C. = O(n2);
        int maxProfit = 0;

        for(int i = 0; i < prices.size(); i++){
            int profit = 0;
            for(int j = i + 1; j < prices.size(); j++){
                profit = prices[j] - prices[i];
                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }
};
