class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> mp;
        for (auto c : hand) {
            mp[c]++;
        }

        // Use min-heap instead of max-heap
        priority_queue<int, vector<int>, greater<int>> pq;  // Min heap
        for (auto& c : mp) {
            pq.push(c.first);
        }

        while (!pq.empty()) {
            int prev = -1;
            vector<int> temp;

            for (int i = 0; i < groupSize; i++) {
                if (pq.empty()) return false;  // Not enough elements for a group

                int t = pq.top();
                pq.pop();

                if (prev != -1 && prev + 1 != t) return false;  // Must be consecutive

                mp[t]--;
                if (mp[t] > 0) {
                    temp.push_back(t);  // Store for reinsertion
                } else {
                    mp.erase(t);  // Clean up map
                }

                prev = t;
            }

            // Reinsert remaining elements back into the heap
            for (auto c : temp) {
                pq.push(c);
            }
        }
        return true;
    }
};
