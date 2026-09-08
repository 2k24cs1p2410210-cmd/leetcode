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
    int level = 0;
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr)
        return nullptr;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*>nodes;
            int size  = q.size();
            for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            nodes.push_back(node);
            if(node->left!=nullptr)
            q.push(node->left);
            if(node->right!=nullptr)
            q.push(node->right);
            }
            if(level%2==1){
            int i=0;
            int j=nodes.size()-1;
            while(i<j){
                swap(nodes[i]->val,nodes[j]->val);
                i++;
                j--;
            }
        }
        level++;
        }
       
        return root;

    }
};