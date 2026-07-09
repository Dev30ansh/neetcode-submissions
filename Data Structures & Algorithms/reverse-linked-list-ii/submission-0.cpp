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

    // Helper function to reverse a full linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr) {
            ListNode* temp = curr->next; 
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        // prev is the new head of the reversed list
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* dummy = new ListNode(0, head);
        ListNode* before = dummy;

        // Move 'before' to the node just before the sublist starts
        //      1 ->2 ->3 ->4 ->5 ;  l= 3,r=4
        //         (b)
        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        // 'start' is the first node
        ListNode* start = before->next;

        // 'end' is the last node
        ListNode* end = start;

        // Move 'end' to the node at position right
        for (int i = left; i < right; i++) {
            end = end->next;
        }

        //      1 ->2 ->3 ->4 ->5 ;  l= 3,r=4
        //        (b) (s) (e)  (a)
        
        ListNode* after = end->next;
        end->next = NULL;

        before->next = reverseList(start);
        start->next = after;

        return dummy->next;
    }
};
