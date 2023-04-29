class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>& grid, int dr[], int dc[],vector<vector<int>>&vis,int &res)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[row][col]=1;
        res=res+grid[row][col];
        
        for(int i=0;i<4;i++)
        {
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]>0 && vis[nrow][ncol]==0)
            {
                dfs(nrow,ncol,grid,dr,dc,vis,res);
            }
        }
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0 && vis[i][j]==0)
                {
                    int res=0;
                    dfs(i,j,grid,dr,dc,vis,res);
                    ans=max(ans,res);
                }
            }
        }
        return ans;
        
    }
};