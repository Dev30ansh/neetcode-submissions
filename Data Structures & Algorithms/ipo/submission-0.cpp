class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> vec(n);

        for(int i = 0; i < n; i++){
            vec[i] = {capital[i], profits[i]};
        }

        sort(begin(vec), end(vec));

        int i = 0;  // for vector traversal
        priority_queue<int> pq; // maintains heap on the basis of profit

        // while we do k projects - run
        while(k--){

            while(i < n and vec[i].first <= w){
                // affordable projects
                pq.push(vec[i].second);
                i++;
            }

            if(pq.empty())
                break;
            
            // project done add profit to w
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};