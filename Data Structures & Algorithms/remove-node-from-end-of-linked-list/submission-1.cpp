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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int size =0;

        while(curr){
            size++;
            curr = curr->next;
        }
        
        if(size == 0 or size == n){
            return head->next;
        }

        curr = head;

        for(int i = 0; i < size-n-1; i++){
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;
        return head;
    }
};
