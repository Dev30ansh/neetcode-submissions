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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> que;

        //to track right node at each level
        TreeNode* rightside = nullptr;
        
        if(root){
            que.push(root);
        }

        while(!que.empty()){
            int len = que.size();

            for(int i = 0; i < len; i++){

                TreeNode* curr = que.front();
                que.pop();

                rightside = curr;

                if(curr->left){
                    que.push(curr->left);
                }
                if(curr->right){
                    que.push(curr->right);
                }
            }
            //once you go to that last node in a level - push it into queue
            res.push_back(rightside->val);
        }
        return res;
    }
};
