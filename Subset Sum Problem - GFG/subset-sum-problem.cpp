//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // bool solve(int idx,int sum,vector<int>arr,vector<vector<bool>>&dp)
    // {
    //     if(sum==0)
    //     return true;
    //     if(idx==0)
    //     return false;
    //     if(dp[idx][sum]!=false)
    //     return dp[idx][sum];
    //     bool pick=false;
    //     if(arr[idx]<=sum)
    //     pick=solve(idx-1,sum-arr[idx],arr,dp);
    //     bool notPick=solve(idx-1,sum,arr,dp);
    //     return dp[idx][sum]= pick||notPick;
    // }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        
       
        for(int i=0;i<n;i++)
        dp[i][0]=true;
        dp[0][arr[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
            bool notPick=dp[i-1][j];
            bool pick=false;
            if(arr[i]<=j)
            pick=dp[i-1][j-arr[i]];
            
            dp[i][j]= pick||notPick;
            }
        }
        
        return dp[n-1][sum];
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends