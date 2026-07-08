class Solution {
public:
    // Merge 2 sorted linked lists into 1 sorted linked list
    ListNode* mergeTwoSortedLists(ListNode* l1, ListNode* l2) {
        // If one list is empty, return the other list
        if (!l1) return l2;
        if (!l2) return l1;

        // Pick the smaller node as the head of the merged list
        if (l1->val <= l2->val) {
            // Recursively merge the rest of l1 with l2
            l1->next = mergeTwoSortedLists(l1->next, l2);
            return l1;
        } else {
            // Recursively merge l1 with the rest of l2
            l2->next = mergeTwoSortedLists(l1, l2->next);
            return l2;
        }
    }

    // Recursively divide the lists into smaller parts and merge them
    ListNode* partitionAndMerge(int start, int end, vector<ListNode*>& lists) {
        // If range is invalid, there are no lists to merge
        if (start > end) {
            return NULL;
        }

        // If only one list remains, return it directly
        if (start == end) {
            return lists[start];
        }

        // Find the middle index
        int mid = start + (end - start) / 2;

        // Recursively merge the left half
        ListNode* L1 = partitionAndMerge(start, mid, lists);

        // Recursively merge the right half
        ListNode* L2 = partitionAndMerge(mid + 1, end, lists);

        // Merge the two merged halves
        return mergeTwoSortedLists(L1, L2);
    }

    // Main function: merge all k sorted lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        // Start divide-and-conquer on the full range
        return partitionAndMerge(0, k - 1, lists);
    }
};