class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>>mp;

        for(auto & item : items){
            int id    = item[0];
            int score = item[1];

            mp[id].push(score);
        }

        vector<vector<int>> result;
        for(auto& [id, scores] : mp){
            int sum = 0;

            for(int i = 0; i < 5; i++){
                sum += scores.top();
                scores.pop();
            }
            result.push_back({id, sum/5});
        }
        return result;
    }
};
