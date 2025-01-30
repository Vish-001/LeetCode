class Solution {
public:
    int min1(TreeNode* temp) 
    {
        if (temp == nullptr) return INT_MAX;
        while (temp->left != nullptr) 
        {
            temp = temp->left;
        }
        return temp->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if (root == nullptr) return nullptr; 

        if (key < root->val) 
        {
        
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) 
        {
            root->right = deleteNode(root->right, key); 
        } 
        else 
        { 
            if (root->left == nullptr && root->right == nullptr) 
            {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr) 
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else 
            {
                int mini1 = min1(root->right); 
                root->val = mini1; 
                root->right = deleteNode(root->right, mini1); 
            }
        }
        return root;
    }
};
