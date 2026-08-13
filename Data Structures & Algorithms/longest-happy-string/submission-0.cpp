class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        // max-heap
        priority_queue<pair<int, char>> pq;

        if (a > 0) {
            pq.push({a, 'a'});
        }
        if (b > 0) {
            pq.push({b, 'b'});
        }
        if (c > 0) {
            pq.push({c, 'c'});
        }
        string result = "";

        while (!pq.empty()) {
            // take the maximum freq char first
            int currFreq = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            // check if the two prev char in result is not same as curr_char
            // if yes- take next top char and put in result
            int n = result.length();

            if (n >= 2 and result[n - 1] == currChar and result[n - 2] == currChar) {
                if (pq.empty()) break;

                int nextFreq = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextFreq--;

                if (nextFreq > 0) 
                    pq.push({nextFreq, nextChar});
            } 
            else {
                // if two prev char != curr_char : cur_char push in result
                result.push_back(currChar);
                currFreq--;
            }
            if (currFreq > 0) {
                pq.push({currFreq, currChar});
            }
        }
        return result;
    }
};