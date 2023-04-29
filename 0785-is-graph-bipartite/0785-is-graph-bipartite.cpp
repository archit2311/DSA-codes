class Solution {
public:

    bool dfs(int node,vector<vector<int>>& graph,int color,int col[])
    {
        col[node]=color;

        for(auto u:graph[node])
        {
            if(col[u]==-1)
            {
                if(dfs(u,graph,!color,col)==false)
                    return false;
            }
            else if(col[u]==color)
            {
               return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        //0-green
        //1-red

        int n=graph.size();
        int col[n];
        for(int i=0;i<n;i++)
        col[i]=-1;

        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(dfs(i,graph,0,col)==false)
                return false;
            }
        }
        return true;
    }
};