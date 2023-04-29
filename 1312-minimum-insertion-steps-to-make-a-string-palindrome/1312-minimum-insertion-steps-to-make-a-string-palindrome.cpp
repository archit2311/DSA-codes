class Solution {
public:


    int minInsertions(string s) {
        
        // 1- LCS of s and its reverse
        //2 -length-lcs 
        string s1=s;
        int m=s.length();
        reverse(s.begin(),s.end());
        string s2=s;
        int n=s2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<n;i++)
        {
            dp[0][i]=0;
            dp[i][0]=0;
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int ans= m-dp[m][n];
return ans;
    }
};