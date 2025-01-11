class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) 
    {
        int red1=red;
        int blue1=blue;
        int ans1=0;
        int ans2=0;

        for(int i=0;i<50;i++)
        {
            if(i%2==0)
            {
                if((red-i)>=0)
                {
                    ans1++;
                    red=red-i;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if((blue-i)>=0)
                {
                    ans1++;
                    blue=blue-i;
                }
                else
                {
                    break;
                }
            }
        }

        for(int i=0;i<50;i++)
        {
            if(i%2==0)
            {
                if((blue1-i)>=0)
                {
                    ans2++;
                    blue1=blue1-i;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if((red1-i)>=0)
                {
                    ans2++;
                    red1=red1-i;
                }
                else
                {
                    break;
                }
            }
        }

        return max(ans1,ans2)-1;;
    }
};