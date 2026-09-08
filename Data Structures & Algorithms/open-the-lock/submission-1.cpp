class Solution {
public:
    void fillNeighbors(queue<string> &que, string curr, unordered_set<string> & st){
        for(int i = 0; i < 4; i++){
            char ch = curr[i];

            // increment 1 slot of curr digit 
            int inc = ch == '9' ? '0' : ch+1;
            // decrement 1 slot of curr digit 
            int dec = ch == '0' ? '9' : ch-1;

            // 1. first increase
            curr[i] = inc;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                que.push(curr);
            }

            // 2. second decrease
            curr[i] = dec;
            if(st.find(curr) == st.end()){
                st.insert(curr);
                que.push(curr);
            }

            // reverse the changes bac to original- for next ith element
            curr[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(begin(deadends), end(deadends));
        queue<string> que;
        int level = 0;
        string start = "0000";

        if(st.find(start) != st.end()){
            return -1;  // not possible to find answer
        }

        que.push(start);

        while(!que.empty()){
            int size = que.size();

            while(size--){
                auto curr = que.front();
                que.pop();

                if(curr == target){
                    return level;
                }

                // find all the neighbors of current "curr" state
                fillNeighbors(que, curr, st);
            }
            // increase level - as we are done with 1 loot
            level ++;
        }
        return-1;
    }
};