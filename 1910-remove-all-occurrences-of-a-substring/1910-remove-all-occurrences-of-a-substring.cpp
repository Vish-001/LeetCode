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
            // If there are not enough characters in the stack to potentially form "part"
            // or the current character is not equal to the last character of "part",
            // simply push the current character.
            if(st.size() < n - 1 || c != last)
            {
                st.push(c);
            }
            else
            {
                // At this point, st.size() >= n-1 and c equals the last character of part.
                int i = n - 2;
                string t = "";
                
                // Try to match the preceding n-1 characters of part from the stack.
                while(i >= 0 && !st.empty() && st.top() == part[i])
                {
                    // Prepend st.top() to t. (std::string does not support push_front.)
                    t.insert(t.begin(), st.top());
                    st.pop();
                    i--;
                }
                
                // If t concatenated with the current character does not form "part",
                // push the characters back into the stack.
                if(t + last != part)
                {
                    t.push_back(last); // Append the current character.
                    for(auto ch : t)
                    {
                        st.push(ch);
                    }
                }
                // Otherwise, we have matched "part", so we remove it by not pushing anything back.
            }
        }
        
        // Build the final string from the stack.
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
