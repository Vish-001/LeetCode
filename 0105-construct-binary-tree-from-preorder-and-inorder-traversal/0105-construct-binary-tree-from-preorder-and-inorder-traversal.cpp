/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Build(vector<int>& preorder, int sidx, int eidx, map<int, int>& mp, int& preIndex) {
        if (sidx > eidx) return nullptr;
        
        TreeNode* node = new TreeNode(preorder[preIndex++]);
        int inorderIdx = mp[node->val];

        node->left = Build(preorder, sidx, inorderIdx - 1, mp, preIndex);
        node->right = Build(preorder, inorderIdx + 1, eidx, mp, preIndex);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i; // Store indices of inorder elements
        }

        int preIndex = 0; // Global index for preorder traversal
        return Build(preorder, 0, inorder.size() - 1, mp, preIndex);
    }
};
