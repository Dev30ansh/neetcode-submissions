class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // maintain a arra for freq.
        vector<int> mp(26, 0);  // size- 26 initialized with 0

        for(auto &ch : tasks){
            mp[ch - 'A']++;     // increase the freq of each char
        }

        int time = 0;
        priority_queue<int> pq; // max heap
        
        // copy the freq of char in in heap
        for(int i = 0; i < 26; i++){
            if(mp[i] > 0){
                pq.push(mp[i]);
            }
        }

        // do the task
        while(!pq.empty()){
            vector<int> temp;

            // at start take n + 1 task to do
            for(int i = 1; i <= n+1; i++){
                // check if there are n+1 task left to do
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(auto & f : temp){
                if(f > 0)   //if freq > 0 then only push
                    pq.push(f);
            }

            // add time each time
            if(pq.empty()){
                // at last ineration
                time += temp.size();
            }
            else{   // rest n+1 iteration
                time += n+1;
            }
        }
        return time;
    }
};
