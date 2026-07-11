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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        queue<TreeNode*> que;

        if(root){
            que.push(root);
        }

        // while traversing BFS in BT increase the depth at each level and return it.
        while(!que.empty()){
            int len = que.size();

            for(int i = 0; i < len; i++){
                TreeNode* curr = que.front();
                que.pop();

                if(curr->left){
                    que.push(curr->left);
                }
                if(curr->right){
                    que.push(curr->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
