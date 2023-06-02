class Solution {
public:

    void dfs(int node, vector<int>adj[], vector<int>&vis,int &cnt)
    {
        vis[node]=1;
        
        for(auto u:adj[node])
        {
            if(vis[u]==0){
            dfs(u,adj,vis,cnt);
            cnt++;
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int ans=INT_MIN;
        int N=bombs.size();
        vector<int>adj[N];
        for(int i=0;i<bombs.size();i++)
        {
            
            for(int j=i+1;j<bombs.size();j++)
            {

                    long long dist = (long long)(bombs[j][0] - bombs[i][0]) * (long long)(bombs[j][0] - bombs[i][0]) + (long long)(bombs[j][1] - bombs[i][1]) * (long long)(bombs[j][1] - bombs[i][1]);
                    long long rr=((long long)bombs[i][2]*(long long)bombs[i][2]);
                    long long rr2=((long long)bombs[j][2]*(long long)bombs[j][2]);
                    if(dist<= rr)
                    {
                        adj[i].push_back(j);
                        
                    }
                    if(dist<=rr2)
                    {
                        adj[j].push_back(i);
                    }
                }
            }

        for(auto x:adj)
        {
            for(auto u:x)
            {
                cout<<u<<" ";
            }
            cout<<endl;
        }
        vector<int>vis;
        for(int i=0;i<N;i++){
            int cnt=1;
            vis=vector(N,0);
            dfs(i,adj,vis,cnt);
            ans=max(ans,cnt);
        }
        return ans;

        }
        
};