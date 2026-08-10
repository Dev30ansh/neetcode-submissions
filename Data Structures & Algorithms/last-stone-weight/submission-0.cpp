class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; //max heap

        //push stones in heap
        for(auto & stone : stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            // find two heaviest stones
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            //pushing decreased weights in heap
            pq.push(abs(a-b));
        }

        return pq.top();
    }
};
