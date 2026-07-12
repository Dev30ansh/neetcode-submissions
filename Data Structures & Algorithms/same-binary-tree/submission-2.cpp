/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);

        while(!q1.empty() and !q2.empty()){
            TreeNode* nodeP = q1.front();
            q1.pop();
            TreeNode* nodeQ = q2.front();
            q2.pop();

            //check if both are null: continue
            if(!nodeP and !nodeQ){
                continue;
            }

            //check if any node is null or value differ: return false
            if(!nodeP || !nodeQ || nodeP->val != nodeQ->val){
                return false;
            }

            //push their left and right childs
            q1.push(nodeP->left);
            q1.push(nodeP->right);
            q2.push(nodeQ->left);
            q2.push(nodeQ->right);
        }
        return true;
    }
};
