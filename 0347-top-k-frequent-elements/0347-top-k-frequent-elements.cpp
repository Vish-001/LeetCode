#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Calculate the frequency of each element
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_set<int>st;
        for (auto& it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > k) 
            {
                auto t=pq.top();
                st.insert(t.second);
                pq.pop(); 
            }
        }

        vector<int> ans;
        for(auto c:nums)
        {
            if(st.find(c)==st.end())
            {
                ans.push_back(c);
                st.insert(c);
            }
        }

        return ans;
    }
};