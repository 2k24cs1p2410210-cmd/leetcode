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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==nullptr)
        return ans;
        q.push(root);
        bool lefttoright = true;
        while(!q.empty()){
            int size = q.size();
            deque<int>dq;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(lefttoright)
                dq.push_back(node->val);
                else{
                    dq.push_front(node->val);
                }
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            vector<int>level(dq.begin(),dq.end());
            ans.push_back(level);
            lefttoright = !lefttoright;
        }
        return ans;
    }
};