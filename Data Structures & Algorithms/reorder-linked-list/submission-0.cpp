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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prevSlow = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;
            prevSlow = slow;
            slow = slow->next;
        }

        if (prevSlow) {
            prevSlow->next = nullptr;
        }

        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);

        while (l1 && l2) {
            // Step 1: Save next pointers
            ListNode* nextL1 = l1->next;
            ListNode* nextL2 = l2->next;

            // Step 2: Insert l2 after l1
            l1->next = l2;

            // Step 3: Connect l2 back to l1->next
            if (nextL1) {
                l2->next = nextL1;
            }

            // Step 4: Move pointers
            l1 = nextL1;
            l2 = nextL2;
        }
    }
};