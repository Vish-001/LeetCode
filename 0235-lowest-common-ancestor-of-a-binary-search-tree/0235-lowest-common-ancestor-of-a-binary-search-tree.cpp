class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        // Ensure p is the node with the smaller value
        if (p->val > q->val) {
            std::swap(p, q);
        }
        
        // Check if current node is one of p or q
        if (root == p || root == q) {
            return root;
        }
        
        int low = p->val;
        int high = q->val;
        TreeNode* temp = root;
        
        while (temp != nullptr) {
            if (temp->val > low && temp->val < high) {
                // Current node is between p and q, hence LCA
                break;
            } else if (temp->val == low || temp->val == high) {
                // Current node is p or q, which is the LCA
                return temp;
            } else if (temp->val > high) {
                // Both nodes are in the left subtree
                temp = temp->left;
            } else {
                // Both nodes are in the right subtree
                temp = temp->right;
            }
        }
        
        return temp;
    }
};