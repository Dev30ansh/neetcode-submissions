/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;
        unordered_map<Node* , Node*> mp;

        while(curr){
            Node* temp = new Node(curr->val);
            
            //storing corresponding nodes reference in map
            mp[curr] = temp;

            //if newhead is empty point it to first new node created(temp)
            if(newHead == NULL){
                newHead = temp;
                prev = temp;
            }
            else{
                //else point prev pointer next to new node
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }

        //now filling random pointer
        curr = head;
        Node* newcurr = newHead;

        while(curr){
            if(curr->random == NULL){
                newcurr->random = NULL;
            }
            else{
                newcurr->random = mp[curr->random];
            }
            curr = curr->next;
            newcurr = newcurr->next;
        }

        return newHead;

    }
};
