class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                int index;
                if (leftToRight) {
                    index = i;
                } else {
                    index = size - 1 - i;
                }

                level[index] = current->val;

                if (current->left != NULL) {
                    q.push(current->left);
                }

                if (current->right != NULL) {
                    q.push(current->right);
                }
            }

            result.push_back(level);
            leftToRight = !leftToRight;
        }

        return result;
    }
};
