class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string>wl(wordList.begin(),wordList.end());
        if(wl.find(endWord)==wl.end()) return 0;
        queue<string>q;
        q.push(beginWord);
        int ans=1;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string T=q.front();
                q.pop();
                if(T==endWord)
                {
                    return ans;
                }
                for(int j=0;j<T.size();j++)
                {
                    for(char ch='a';ch<='z';ch++)
                    {
                        char c=T[j];
                        T[j]=ch;
                        if(wl.find(T)!=wl.end())
                        {
                            wl.erase(T);
                            q.push(T);
                        }
                        T[j]=c;
                    }
                }
            }
            ans++;
        }

        return 0;
    }
};