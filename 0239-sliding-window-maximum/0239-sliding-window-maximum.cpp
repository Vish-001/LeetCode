#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<int> st; // To maintain elements in the current window
        vector<int> ans;

        // Initialize the first window
        for (int i = 0; i < k; i++) 
        {
            st.insert(nums[i]);
        }

        // Add the maximum of the first window to the result
        ans.push_back(*st.rbegin());

        // Slide the window
        for (int i = k; i < nums.size(); i++) 
        {
            st.erase(st.find(nums[i - k])); // Remove the element that's sliding out of the window
            st.insert(nums[i]); // Add the new element to the window
            ans.push_back(*st.rbegin()); // Add the maximum of the current window
        }

        return ans;
    }
};
