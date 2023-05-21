// class Solution {
// public:

//     void dfs(int row, int col, vector<vector<int>>& grid,int dr[], int dc[],vector<vector<int>>&vis,  priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>&pq)
//     {
//         int n=grid.size();
       
//         pq.push({0,{row,col}});
//         vis[row][col]=1;

//         for(int i=0; i<4; i++)
//         {
//             int nrow=row+dr[i];
//             int ncol=col+dc[i];
//             if(nrow<n && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]==1 && vis[nrow][ncol]==0)
//             {
//                 dfs(nrow,ncol,grid,dr,dc,vis,pq);
//             }
//         }
//     }

//     int shortestBridge(vector<vector<int>>& grid) {
        
//         int n=grid.size();
//         int dr[4]={1,0,-1,0};
//         int dc[4]={0,1,0,-1};
//         vector<vector<int>>vis(n,vector<int>(n,0));
    
//      priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
//         //{dist,{row,col}}
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++){
//             if(grid[i][j]==1)
//             {
//                 dfs(i,j,grid,dr,dc,vis,pq);
//                 break;
//             }
//             }
//             break;
//         }


//         //SECOND PART
//         int ans=-1;
//         while(!pq.empty())
//         {
//             auto it=pq.top();
//             int r=it.second.first;
//             int c=it.second.second;
//             int dist= it.first;
//             pq.pop();

//             for(int i=0;i<4;i++)
//             {
//            int nrow=r+dr[i];
//            int ncol=c+dc[i];
//            if(nrow<n && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]==0 && vis[nrow][ncol]==0)
//            {
//                vis[nrow][ncol]=1;
//                pq.push({dist+1,{nrow,ncol}});
//            }
//            else if(nrow<n && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
//                return dist;
            
//            } 
//         }
//         }
//         return ans;


        

//     }
// };

class Solution
{
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    void change(vector<vector<int>> &grid, int x, int y)
    {
        q.push({x, y});
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y] = 2;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1)
            {
                change(grid, nx, ny);
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        bool f = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    change(grid, i, j);
                    f = true;
                    break;
                }
            }
            if (f)
                break;
        }
        int ans = 0;
        while (q.size())
        {
            int total = q.size();
            ans++;
            while (total--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                    {
                        if (grid[nx][ny] == 1)
                            return ans - 1;
                        else if (grid[nx][ny] == 0)
                        {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return ans;
    }
};