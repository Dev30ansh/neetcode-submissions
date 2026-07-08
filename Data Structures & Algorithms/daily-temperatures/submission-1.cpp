class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res(temp.size(), 0);
        stack<pair<int, int>> stack;

        for(int i = 0; i < temp.size(); i++){
            int t = temp[i];
            while(!stack.empty() && t > stack.top().first){
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            stack.push({t,i});
        }
        return res;
    }
};
