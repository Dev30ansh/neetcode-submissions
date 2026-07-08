class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // use of fast and slow pointers for detecting duplicate
        int slow = 0;
        int fast = 0;
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(fast == slow){
                break;
            }
        }
        
        int slow2 = 0;
        while(true){
            slow2 = nums[slow2];
            slow = nums[slow];

            if(slow == slow2){
                return slow;
            }
        }
    }
};
