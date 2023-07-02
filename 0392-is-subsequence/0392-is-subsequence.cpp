class Solution {
public:
  

    bool isSubsequence(string s, string t) {
         int m=s.length();
        int n=t.length();
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            j++;
        }
        return i==m;
//         int m=s.length();
//         int n=t.length();
        
//         int dp[n+1][m+1];

//         for(int i=0;i<=n;i++)
//         {
//             dp[i][0]=0;
//         }
//         for(int i=0;i<=m;i++)
//         {
//             dp[0][i]=0;
//         }

//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=m;j++)
//             {
//                 if(t[i-1]==s[j-1])
//                 {
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else
//                 {
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         if(dp[n][m]==s.length())
//         return true;
//         else
//         return false;
        
        
    }
};