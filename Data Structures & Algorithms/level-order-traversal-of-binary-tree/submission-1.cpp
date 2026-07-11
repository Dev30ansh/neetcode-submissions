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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> que;

        //push first  node in queue
        if(root){
            que.push(root);
        }

        //run untill queue is empty
        while(!que.empty()){

            vector<int> level;
            int len = que.size();

            //run for each level
            for(int i = 0; i < len; i++){
                //take front element from queue and pop it 
                TreeNode* curr = que.front();
                que.pop();

                level.push_back(curr->val);

                //check if it has left or right child, if YES push in queue
                if(curr->left){
                    que.push(curr->left);
                }
                if(curr->right){
                    que.push(curr->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
