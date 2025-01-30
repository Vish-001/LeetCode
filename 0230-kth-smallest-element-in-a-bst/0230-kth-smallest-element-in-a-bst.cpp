class Solution {
public:
    void inOrderTraversal(TreeNode* root, int k, int &i, int &ans) {
        if (root == nullptr) return;
        
        inOrderTraversal(root->left, k, i, ans);
        
        i++; // Increase the count
        if (i == k) { // When k-th smallest is found
            ans = root->val;
            return;
        }
        
        inOrderTraversal(root->right, k, i, ans);      
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1; // Initialize to a value that indicates failure
        int i = 0; // Counter for in-order traversal
        inOrderTraversal(root, k, i, ans);
        return ans;
    }
};
