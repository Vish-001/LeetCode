class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        if(hand.size()%groupSize!=0) return false;

        unordered_map<int,int>mp;
        for(auto c:hand)
        {
            mp[c]++;
        }

        priority_queue<int>pq;
        for(auto& c:mp)
        {
            pq.push(c.first);
        }

        while(!pq.empty())
        {
            int prev=-1;
            vector<int>temp;
            for(int i=0;i<groupSize;i++)
            {
                if(pq.empty()) return false;
                int t=pq.top();
                mp[t]--;
                temp.push_back(t);
                cout<<prev<<"  "<<t<<endl;
                if(prev!=-1 && prev!=t+1) return false;
                prev=t;
                pq.pop();
            }

            for(auto c:temp)
            {
                if(mp[c]!=0)
                {
                    pq.push(c);
                }
            }
        }
        return true;
    }
};