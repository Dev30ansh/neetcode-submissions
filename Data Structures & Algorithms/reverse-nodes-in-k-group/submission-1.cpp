/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* getKth(ListNode* curr, int k){
        while(curr and k > 0){

            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while(true){
            ListNode* kth = getKth(groupPrev, k);
            //if node length is less than K- exit the loop
            if(!kth){
                break;
            }

            ListNode* groupNext = kth->next;
            
            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;

            //Reverse the LL
            while(curr != groupNext){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // move the groupPrev to point to kth element
            // groupPrev(dummy)-> 2-> 1->3
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
            // dummy-> 2-> 1(groupPrev)->3
        }
        return dummy->next;
    }
};
