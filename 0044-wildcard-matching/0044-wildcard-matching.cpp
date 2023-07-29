class Solution {
public:

    bool solve(string &s, string &p, int m, int n,vector<vector<int>>&dp)
    {
        //base case
        if(n<=0 && m>0)
        return false;

        if(n==0 && m==0)
        return true; 

        if(m<=0 && n>0)
        {
            for(int i=0;i<n;i++)
            {
                if(p[i]!='*')
                return false;
            }
            return true;
        }

        if(dp[m][n]!=-1)
        return dp[m][n];
        //main code
        if((s[m-1]==p[n-1]) || p[n-1]=='?')
        return dp[m][n]= solve(s,p,m-1,n-1,dp);
        else if(p[n-1]=='*')
        {
          return dp[m][n]= (solve(s,p,m,n-1,dp) || solve(s,p,m-1,n,dp));
        }
       

    return dp[m][n]=false;

    }

    bool isMatch(string s, string p) {
        
        
        if(s==p)return true;
        int m=s.length();
        int n=p.length();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));

        dp[0][0]=true;
        for(int i=1;i<=m;i++)
        {
            dp[i][0]=false;
        }

        for(int j=1;j<=n;j++)
        {
            bool flag=true;
    
            if(p[j-1]!='*')
            {
                flag=false;
                break;
            }
            
            dp[0][j]=flag;
        
        }
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((s[i-1]==p[j-1]) || p[j-1]=='?')
                dp[i][j]= dp[i-1][j-1];
                else if(p[j-1]=='*')
                dp[i][j]= (dp[i][j-1] || dp[i-1][j]);
                else
                dp[i][j]=false;
            }
        }

        return dp[m][n];
    }
};