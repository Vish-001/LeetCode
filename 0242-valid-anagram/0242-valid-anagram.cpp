class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int a=0;
        if(s.size()==t.size())
        {
            multiset<char>st;
            for(int i=0;i<s.size();i++)
            {
                char temp=s.at(i);
                st.insert(temp);
            }
            for(int i=0;i<t.size();i++)
            {
                char key=t.at(i);
                auto iter=st.find(key);
                if(iter==st.end())
                {
                    a++;
                    break;
                }
                st.erase(iter);
            }   
        
            if(a<=0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

    }
};