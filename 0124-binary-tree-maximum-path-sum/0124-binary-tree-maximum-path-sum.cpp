class Solution {
public:
    int computeBranchSum(TreeNode* root, int& maxSum) {
        if (!root) return 0;

        int leftBranchSum = root->val + computeBranchSum(root->left, maxSum);
        int rightBranchSum = root->val + computeBranchSum(root->right, maxSum);

        maxSum = max({maxSum,root->val,leftBranchSum,rightBranchSum,leftBranchSum + rightBranchSum - root->val});

        return max({leftBranchSum, rightBranchSum, root->val});
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        computeBranchSum(root, maxSum);
        return maxSum;
    }
};
