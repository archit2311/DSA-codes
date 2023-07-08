class Solution {
public:

    bool checkSemi(string str)
    {
        int n=str.length();
    int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(str[i]==str[i+1])
            cnt++;
        }
        if(cnt<=1)
        return true;
        else
        return false;
    }

    int longestSemiRepetitiveSubstring(string s) {
        int n=s.length();
        if(n==1)
        return 1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string str="";
            for(int j=i;j<n;j++)
            {
                str+=s[j];
                if(checkSemi(str)==true)
                {
                    if(str.length()>ans)
                    ans=str.length();
                }
               
            }
        }
        return ans;
        
    }
};