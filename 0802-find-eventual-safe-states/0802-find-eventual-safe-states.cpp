class Solution {
public:

    bool dfs(int node,vector<vector<int>>& graph, vector<int>&vis, vector<int>&pathVis, vector<int>&mark)
    {
        vis[node]=1;
        pathVis[node]=1;
        mark[node]=0;
        for(auto u:graph[node])
        {
            if(vis[u]==0){
            if(dfs(u,graph,vis,pathVis,mark)==true)
            return true;
            }
            else if(pathVis[u]==1)
            {
                return true;
            }
        }
        pathVis[node]=0;
        mark[node]=1;
        return false;

    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V=graph.size();
        vector<int>vis(V,0);
        vector<int>pathVis(V,0);
        vector<int>mark(V,0);
        vector<int>safeNodes;
        for(int i=0; i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,graph,vis,pathVis,mark);
            }
        }

        for(int i=0; i<V;i++)
        {
            if(mark[i]==1)
            safeNodes.push_back(i);
        }

        return safeNodes;

    }
};