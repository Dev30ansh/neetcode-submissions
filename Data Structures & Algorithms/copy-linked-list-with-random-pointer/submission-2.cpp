class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node* curr = head;
        
        //1. Insert new nodes in the original LL
        while(curr){
            //original- A->B->C
            Node* currNext = curr->next;        //store B
            curr->next = new Node(curr->val);   //A->x
            curr->next->next = currNext;         //A->x->B

            //curr ko B pr le jao
            curr = currNext;
        }

        //2. Deep Copy Random pointer
        curr = head;
        //curr only points to original list nodes
        while(curr && curr->next){
            if(curr->random == NULL){
                curr->next->random = NULL;
            }
            else{
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // 3. Seperate original and new LL
        curr = head;
        Node* newHead = head->next;
        Node* newcurr = newHead;

        while(curr){
            curr->next = (curr->next == NULL) ? NULL : curr->next->next;
            newcurr->next = (newcurr->next == NULL) ? NULL : newcurr->next->next;

            curr = curr->next;
            newcurr = newcurr->next;
        }
        return newHead;
    }
};