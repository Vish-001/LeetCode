#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<int> st; 
        vector<int> ans;

        for (int i = 0; i < k; i++) 
        {
            st.insert(nums[i]);
        }

        ans.push_back(*st.rbegin());

        for (int i = k; i < nums.size(); i++) 
        {
            st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            ans.push_back(*st.rbegin()); 
        }

        return ans;
    }
};
