class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) 
    {
        pushLeft(root);
    }
    
    void pushLeft(TreeNode* node) 
    {

        while (node != nullptr) 
        {
            st.push(node);
            node = node->left;
        }
    }
    
    int next() 
    {
        auto node = st.top();
        st.pop();
        int result = node->val;

        if (node->right != nullptr) 
        {
            pushLeft(node->right);
        }
        return result;
    }
    
    bool hasNext() 
    {
        return !st.empty();
    }
};
