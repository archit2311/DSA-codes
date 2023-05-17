//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool mycmp(const pair<int,int>&a, const pair<int,int>&b)
    {
        // if(a.second==b.second)
        // return a.first<b.first;
        // else
        return a.second<b.second;
        
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        int ans=1;
        
        vector<pair<int,int>>meet;
        for(int i=0;i<n;i++)
        {
            meet.push_back({start[i],end[i]});
        }
        
        
        sort(meet.begin(),meet.end(),mycmp);
        int endtime=meet[0].second;
        for(int i=1;i<meet.size();i++)
        {
            if(meet[i].first>endtime){
            ans++;
            endtime=meet[i].second;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends