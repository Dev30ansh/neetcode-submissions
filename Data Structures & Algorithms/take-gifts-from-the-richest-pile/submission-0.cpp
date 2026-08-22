class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long sum = 0;

        for(auto & gift : gifts){
            pq.push(gift);
            sum += gift;
        }

        while(k--){
            int maxEl = pq.top();
            pq.pop();
            int root = sqrt(maxEl);
            pq.push(root);

            sum -= (maxEl - root);
        }
        return sum;
    }
};