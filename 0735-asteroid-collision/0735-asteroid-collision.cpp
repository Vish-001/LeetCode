class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) 
    {
        stack<int>st;
        vector<int>ans;
        for(auto c:a)
        {
            if(c>=0)
            {
                st.push(c);
            }
            else
            {
                while(!st.empty() && abs(c)>st.top() && st.top()>0)
                {
                    st.pop();
                }
                if(!st.empty() && abs(c)==st.top())
                {
                    st.pop();
                }
                else
                {
                    if(st.empty() || st.top()<0)
                        st.push(c);
                }
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};