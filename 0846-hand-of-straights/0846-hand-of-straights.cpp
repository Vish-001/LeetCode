class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) 
    {
        if(hand.size()%gs!=0) return false;
        map<int,int>mp;
        for(auto c:hand)
        {
            mp[c]++;
        }
        while(!mp.empty())
        {
            int curr=mp.begin()->first;
            for(int i=0;i<gs;i++)
            {
                if(mp.find(curr+i)==mp.end())
                {
                    return false;
                }
                mp[curr+i]--;
                if(mp[curr+i]==0)
                {
                    mp.erase(curr+i);
                }
            }
        }
        return true;
    }
};