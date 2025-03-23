class Solution {
public:
    int TreeHeight(TreeNode* temp, bool leftSide) {
        int height = 0;
        while (temp) {
            temp = leftSide ? temp->left : temp->right;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        int Lh = TreeHeight(root->left, true);
        int Rh = TreeHeight(root->right, false);

        if (Lh == Rh) {
            return (1 << (Lh + 1)) - 1;  // Correct full tree formula
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
