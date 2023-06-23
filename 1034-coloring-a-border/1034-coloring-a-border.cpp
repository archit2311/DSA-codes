class Solution {
public:

    void dfs(int row, int col, queue<pair<int,int>>&q,int dr[],int dc[], vector<vector<int>>&vis,vector<vector<int>>& grid,int clri)
    {
        int m=grid.size();
        int n=grid[0].size();

        vis[row][col]=1;
        q.push({row,col});

        for(int i=0;i<4;i++)
        {
            int nrow=row+dr[i];
            int ncol=col+dc[i];

            if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]==clri && vis[nrow][ncol]==0)
            {
                
                dfs(nrow,ncol,q,dr,dc,vis,grid,clri);
            }
        }
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

        vector<vector<int>>ans;
        ans=grid;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        // vis[row][col]=1;
        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};
        queue<pair<int,int>>q;
        int clri=grid[row][col];
        dfs(row,col,q,dr,dc,vis,grid,clri);
        cout<<q.size();
        vector<vector<int>>vis1(m,vector<int>(n,0));
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            if(it.first==m-1||it.first==0 || it.second==n-1 || it.second==0)
            ans[it.first][it.second]=color;
            else{
            for(int i=0;i<4;i++)
            {
                int nrow=it.first+dr[i];
                int ncol=it.second+dc[i];

                if(nrow<m && nrow>=0 && ncol<n && ncol>=0)
                {
                    
                    if(grid[nrow][ncol]!=clri)
                    {
                       ans[it.first][it.second]=color;
                        
                    }
                    
                }
            }
            }
        }
       
       return ans; 
    }
};