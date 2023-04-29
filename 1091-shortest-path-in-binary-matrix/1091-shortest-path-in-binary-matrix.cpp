class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)
        return -1;
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1 && grid[0][0]==0)return 1;
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        queue<pair<pair<int,int>,int>>q;

        q.push({{0,0},1});

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first.first;
            int col=it.first.second;
            int dis=it.second;

            for(int i=-1;i<=1;i++)
            {
                int nrow=row+i;
                for(int j=-1;j<=1;j++)
                {
                    int ncol=col+j;
                    if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]==0 && dist[nrow][ncol]>dis+1)
                    {
                    q.push({{nrow,ncol},dis+1});
                    dist[nrow][ncol]=dis+1;
                    }
                }

                
            }
        }
        if(dist[m-1][n-1]==1e9)
        return -1;
        else
        return dist[m-1][n-1];
    }
};