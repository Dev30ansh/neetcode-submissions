/*
Story Points :- 
1. when new element comes nums[i], make space for it (window size can't be greater than k) 
   (remove elements that are <= (i - k))

2. Now, when nums[i] comes, there is no need to keep smaller elements in the deque

3. Now push i in the deque -> for nums[i]

4. If (i > k - 1) , then deq.front() is our answer for that window
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> result;
        
        for(int i = 0; i < n; i++){
            //step:1
            if(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }

            //step:2
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }

            //step:3
            deq.push_back(i);

            //step:4
            if(i >= k - 1){
                result.push_back(nums[deq.front()]);
            }
        }
        return result;
    }
};
