class Solution {
public:

    int solve(string s, string t, int i, int j,vector<vector<int>>&dp)
    {
        if(j<0)
        return 1;
        if(i<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j]=solve(s,t,i-1,j-1,dp) + solve(s,t,i-1,j,dp);
        }
        else{
            return dp[i][j]=solve(s,t,i-1,j,dp);
        }
    }

    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=solve(s,t,m-1,n-1,dp);

        return dp[m-1][n-1];
    }
};