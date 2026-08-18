class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        stack<TreeNode*> currentLevel;
        stack<TreeNode*> nextLevel;

        currentLevel.push(root);

        bool lefttoright = true;

        while (!currentLevel.empty()) {

            vector<int> level;

            while (!currentLevel.empty()) {

                TreeNode* node = currentLevel.top();
                currentLevel.pop();

                level.push_back(node->val);

                if (lefttoright) {

                    if (node->left)
                        nextLevel.push(node->left);

                    if (node->right)
                        nextLevel.push(node->right);

                } else {

                    if (node->right)
                        nextLevel.push(node->right);

                    if (node->left)
                        nextLevel.push(node->left);
                }
            }

            ans.push_back(level);

           
            swap(currentLevel, nextLevel);

           
            lefttoright = !lefttoright;
        }

        return ans;
    }
};