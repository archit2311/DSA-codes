//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int lcs(string text1, string text2) {

        int n=text1.length();
        int m=text2.length();
        int dp[text2.length()+1][text1.length()+1];
        for(int i=0; i<=text1.length(); i++)
        {
            dp[0][i]=0;
        }
        for(int i=0; i<=text2.length(); i++)
        {
            dp[i][0]=0;
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(text1[j-1]==text2[i-1] && i!=j)
                {
                    dp[i][j]=dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    
    
		int LongestRepeatingSubsequence(string str){
		    
		  
		  
          int ans=lcs(str, str);
            return ans;
    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends