class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        
        set <string> s;

        for(auto x: nums)s.insert(x);
        for(int i = 0;i < pow(2,n);i++){
            int left = n;
            int x = i;
            string p = "";
            while(x > 0){
                p += (char)('0' + x%2);
                x /= 2;
                left--;
            }
            while(left--){
                p += '0';
            }
            reverse(p.begin(),p.end());
            
            if(s.find(p) == s.end())return p;
        }

        return "";
    }
};