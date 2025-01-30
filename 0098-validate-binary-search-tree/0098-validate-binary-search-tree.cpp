class Solution {
public:
    bool Inorder(TreeNode* root, TreeNode*& prev) 
    {
        if (root == nullptr) 
        {
            return true;
        }

        if (!Inorder(root->left, prev)) 
        {
            return false;
        }

        if (prev != nullptr && root->val <= prev->val) 
        {
            return false;
        }

        prev = root;

        return Inorder(root->right, prev);
    }

    bool isValidBST(TreeNode* root) 
    {
        TreeNode* prev = nullptr;
        return Inorder(root, prev);
    }
};
