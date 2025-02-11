class Solution {
public:
    string removeOccurrences(string s, string part) 
    {
        // Edge-case: if part is empty, simply return s.
        if(part.empty()) return s;
        
        int n = part.size();
        char last = part[n - 1];
        stack<char> st;

        for(auto c : s)
        {
            if(st.size() < n - 1 || c != last)
            {
                st.push(c);
            }
            else
            {
                int i = n - 2;
                string t = "";
                
                while(i >= 0 && !st.empty() && st.top() == part[i])
                {
                    t.insert(t.begin(), st.top());
                    st.pop();
                    i--;
                }
                
                if(t + last != part)
                {
                    t.push_back(last);
                    for(auto ch : t)
                    {
                        st.push(ch);
                    }
                }
            }
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans)
        return ans;
    }
};
