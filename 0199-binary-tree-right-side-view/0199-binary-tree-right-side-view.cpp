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
      
        vector<int>temp;
          if(root==nullptr)
          return temp;
        queue<TreeNode*>q;
        TreeNode* node;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
             node = q.front();
            q.pop();
              if(n == 0)
              temp.push_back(node->val);
            if(node->left!=nullptr)
            q.push(node->left);
            if(node->right!=nullptr)
            q.push(node->right);
            }
            
        }
        return temp;
    }
};