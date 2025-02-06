class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        stack<int> st; // Monotonic increasing stack
        
        for (int i=nums.size()-1;i>=0;i--) 
        {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // Push current element into the stack
            st.push(nums[i]);

            // If we ever have 3 elements, we found a triplet
            if (st.size() >= 3) {
                return true;
            }
        }
        
        return false;
    }
};
