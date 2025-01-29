class Solution {
public:
    TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int& idx,
                    int st, int ed, map<int, int>& mp) 
                    {
        if (st > ed) return nullptr; 

        // Create the current root node
        TreeNode* root = new TreeNode(preorder[idx]);
        int inRoot = mp[preorder[idx]]; // Index of the root in `inorder`
        idx++; // Move to the next root in `preorder`

        // Recursively construct the left and right subtrees
        root->left = Build(preorder, inorder, idx, st, inRoot - 1, mp);
        root->right = Build(preorder, inorder, idx, inRoot + 1, ed, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp; // Map to store indices of elements in `inorder`
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int idx = 0; // Pointer to track the current root in `preorder`
        return Build(preorder, inorder, idx, 0, inorder.size() - 1, mp);
    }
};
