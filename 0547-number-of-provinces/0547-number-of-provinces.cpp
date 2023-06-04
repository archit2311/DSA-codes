class Solution {
public:

    void dfs(vector<int>adj[], int visited[], int source)
    {
        visited[source]=1;
        for(auto child: adj[source])
        {
            if(visited[child]==0)
            dfs(adj,visited,child);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                
            }
        }

        int visited[n];
        int count=0;
        for(int i=0; i<n;i++)
        {
            visited[i]=0;
        }

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(adj,visited,i);
            }
           
        }
        return count;


    }
};