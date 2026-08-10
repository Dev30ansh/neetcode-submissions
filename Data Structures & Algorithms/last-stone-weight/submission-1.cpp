class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // create a max-heap and initializes it with every value in stones.
        priority_queue<int> pq(stones.begin(), stones.end());
        
        while(pq.size() > 1){
            // find two heaviest stones
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            //pushing decreased weights in heap
            pq.push(a-b);
        }

        return pq.top();
    }
};
