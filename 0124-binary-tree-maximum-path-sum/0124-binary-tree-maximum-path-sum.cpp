class Solution {
public:
    int HeightSum(TreeNode* temp, int& maxi) {
        if (temp == nullptr) return 0;

        int Ls = max(0, HeightSum(temp->left, maxi));
        int Rs = max(0, HeightSum(temp->right, maxi));

        int currentMax = max({temp->val, Ls + temp->val, Rs + temp->val, Ls + Rs + temp->val});
        maxi = max(maxi, currentMax);

        return max(Ls, Rs) + temp->val;
    }

    int maxPathSum(TreeNode* root) {
        if (!root) return 0; // Edge case: empty tree

        int maxi = INT_MIN;
        HeightSum(root, maxi); // Fix: This now updates maxi correctly

        return maxi;
    }
};
