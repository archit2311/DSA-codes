class Solution {
public:

    bool solve(int i, string s, unordered_set<string>&st, int n,vector<int>&dp)
    {
        
        if(i==n)return true;
        if(dp[i]!=-1)return dp[i];
        for(int k=i;k<n;k++)
        {
            string temp=s.substr(i,k-i+1);
           
            if(st.find(temp)!=st.end())
            {
                if(solve(k+1,s,st,n,dp))
               return dp[i]= true;
            }

        }
        return dp[i]= false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string>st;
        for(auto x:wordDict)
        st.insert(x);
        vector<int>dp(n,-1);
        
        return solve(0,s,st,n,dp);
        

       
    }
};