class Solution {
public:

    // int solve(int index,vector<int>&prices,int fee,int buy)
    // {
    //     int n=prices.size();
    //     if(index==n)
    //     return 0;
    //     int ans=0;
    //     if(buy==1)
    //     {
    //         ans=max(-prices[index]-fee+solve(index+1,prices,fee,0), solve(index+1,prices,fee,1));
    //     }
    //     else{
    //         ans=max(prices[index]+solve(index+1,prices,fee,1) , solve(index+1,prices,fee,0));
    //     }
    //     return ans;
    // }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        //0-sell
        //1-buy
        vector<vector<int>>dp(n+1,vector<int>(2,0));
      
        //int profit=solve(0,prices,fee,1);
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                if(j==0)
                {
                    dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }
                else
                {
                    dp[i][j]=max(-prices[i]-fee+dp[i+1][0],dp[i+1][1]);
                }
                
            }
        }
        return dp[0][1];
    }
};