//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
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
                if(text1[j-1]==text2[i-1])
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


    int minimumNumberOfDeletions(string str) { 
        // code here
        int n=str.length();
        string str1=str;
    reverse(str.begin(),str.end());
    string str2=str;
  int common=lcs(str1,str2);
  int ans=n-common;
  return ans;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends