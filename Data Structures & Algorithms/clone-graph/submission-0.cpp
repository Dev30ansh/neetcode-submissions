/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Approach:1 using DFS
    
    void dfs(Node* node, Node* clone_node, unordered_map<Node*, Node*>& mp){
        
        for(auto& n : node->neighbors){
            //check if n is already made or not
            if(mp.find(n) == mp.end()){
                // n is not made -> make it
                Node* clone = new Node(n->val);
                mp[n] = clone;

                // now push clone in neighbor of clone_node
                clone_node->neighbors.push_back(clone);
                dfs(n, clone, mp);
            }
            else{
                // n found in mp -> we have mad n's clone already
                auto cloned_node = mp[n];
                clone_node->neighbors.push_back(cloned_node);
            }
        }
    }

    Node* cloneGraph(Node* node) {

        if(!node){
            return NULL;
        }

        // it stores the mapping of old_node --> new clone_node
        //   <original_node, clone_node>
        unordered_map<Node*, Node*> mp;

        // first create a new clone_node for the given node 
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;

        /*
        - node clone its neighbors and recursivel their neighbors
        - but if a node reappears, then we need to access the cloned node(not create new node)
        - so we maintain a map of <Node*, Node*> which is old_node --> new_clone_node
        */

        dfs(node, clone_node, mp);
        return clone_node;
    }
};
