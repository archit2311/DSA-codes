class Solution {
public:
    int numTilings(int n) {

        int md=1e9+7;
        long long dp[1001]={0};
        
        
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;


        if(n>=4)
        {
        for(int i=4; i<=n; i++)
        {
            dp[i]=(2*dp[i-1]+dp[i-3])%md;
        }
        }
        return dp[n];
    }
};
