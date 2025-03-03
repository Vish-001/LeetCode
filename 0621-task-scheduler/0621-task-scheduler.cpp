class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (auto c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        int ans = 0;
        while (!pq.empty()) 
        {
            vector<int> temp;
            int cnt = 0; 
            for (int i = 0; i <= n; i++) 
            { 
                if (!pq.empty()) 
                {
                    int fq = pq.top();
                    pq.pop();
                    if (fq > 1) 
                    {
                        temp.push_back(fq - 1);
                    }
                    cnt++;
                }
            }

            for (auto c : temp) 
            {
                pq.push(c);
            }

            if (!pq.empty()) 
            {
                ans += n + 1;
            } 
            else 
            {
                ans += cnt;
            }
        }

        return ans;
    }
};