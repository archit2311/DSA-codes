class Solution {
public:
    // int mincoin(vector<int>& coins, int amount, int n, vector<vector<int>>&dp)
    // {

    //     if(ind == 0){
    //     if(amount%coins[0]==0)
    //         return amount/coins[0];
    //         else
    //         return 1e9;
    //     }
    // }
    //     if(dp[n][amount]!=-1)
    //     return dp[n][amount];
    //     int notTake=0+mincoin(coins,amount,n-1,dp);
    //     int take=INT_MAX;
    //     if(amount>=coins[n])
    //     take=1+mincoin(coins,amount-coins[n],n,dp);
    //     return dp[n][amount]= min(take,notTake);
       
    // }

    int coinChange(vector<int>& coins, int amount) {
       
        int n=coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1));

        for(int i=0;i<=amount; i++){
         if(i%coins[0]==0)
            dp[0][i]=i/coins[0];
            else
            dp[0][i]=1e9;
        
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
            int notTake=0+dp[i-1][j];
            int take=INT_MAX;;
            if(j>=coins[i])
            take=1+dp[i][j-coins[i]];
            dp[i][j]= min(take,notTake); 
            }
        }
        
        return (dp[n-1][amount]!=1e9)?dp[n-1][amount]:-1;
    }
};