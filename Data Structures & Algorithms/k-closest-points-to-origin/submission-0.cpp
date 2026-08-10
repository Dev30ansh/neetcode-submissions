class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        
        for(auto & point : points){
            int x = point[0];
            int y = point[1];
            int d = (x*x + y*y);   // distance from origin to point

            pq.push({d, {x,y}});
            //if size > k remove elements
            if( pq.size() > k){
                pq.pop();
            }
            // now - pq will only contain K closest elements only- copy it in result
        }

        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};