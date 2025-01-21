class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st; // Stack to store elements
        int n = nums.size();
        vector<int> result(n, -1); // Initialize result with -1
        
        // Pre-insert the array into the stack from back
        for (int i = n - 1; i >= 0; i--) {
            st.push(nums[i]);
        }

        // Traverse the array from back to front, simulating circular behavior
        for (int i = n - 1; i >= 0; i--) {
            // Remove elements from the stack that are smaller or equal to the current element
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // If stack is not empty, the top element is the next greater element
            if (!st.empty()) {
                result[i] = st.top();
            }

            // Push the current element into the stack
            st.push(nums[i]);
        }

        return result;
    }
};
