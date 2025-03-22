class Solution {
public:
    int Chk(TreeNode* root, int& maxi) {
        if (root == nullptr) return 0;

        // Compute maximum path sum for left and right subtrees
        int L = max(0, Chk(root->left, maxi)); // Ignore negative paths
        int R = max(0, Chk(root->right, maxi)); // Ignore negative paths

        // Update the global maximum path sum
        maxi = max(maxi, L + R + root->val);

        // Return the maximum path sum including the current node as part of the path
        return root->val + max(L, R);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN; 
        Chk(root, maxi);
        return maxi;
    }
};
