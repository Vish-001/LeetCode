class Solution {
public:
    void Func(int i,string s,string &digits,map<int,string>&mp,vector<string>&ans)
    {
        if(i==digits.size())
        {
            ans.push_back(s);
            return;
        }
        for(auto c:mp[digits[i]-'0'])
        {
            Func(i+1,s+c,digits,mp,ans);
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";

        vector<string>ans;
        if(digits=="") return ans;
        Func(0,"",digits,mp,ans);
        return ans;
    }
};