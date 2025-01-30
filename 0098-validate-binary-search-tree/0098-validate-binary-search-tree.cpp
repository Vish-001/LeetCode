class Solution {
public:
    bool Build(TreeNode* temp, long long low, long long high) {
        if (temp == nullptr) return true; // Base case: empty subtree is valid
        if (temp->val >= high || temp->val <= low) return false; // Node value is out of valid range

        // Recursively check the left and right subtrees
        bool L = Build(temp->left, low, temp->val);
        bool R = Build(temp->right, temp->val, high);

        return L && R;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        long long low = LLONG_MIN; // Use LLONG_MIN for long long type
        long long high = LLONG_MAX; // Use LLONG_MAX for long long type
        return Build(root, low, high);
    }
};
