class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid){
        
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            //traverse in the neighbours and mark them visiting
            for(int delrow=-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    if(abs(delrow)==abs(delcol)) continue;       //ONLY CATCH IS HERE
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
    }
};
// class Solution {
// public:

//     void bfs(vector<vector<char>>& grid, int row,int col, vector<vector<int>>&vis, int drow[], int dcol[])
//     {
//         int m=grid.size();
//         int n=grid[0].size();
//         vis[row][col]=1;
//        queue<pair<int,int>>q;
//        q.push({row,col});

//        while(!q.empty())
//        {
//            int row=q.front().first;
//            int col=q.front().second;
//            q.pop();

//            for(int i=0;i<4;i++)
//            {
//                    int nrow=row+drow[i];
//                    int ncol=col+dcol[i];
//                    if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1')
//                    {
//                        vis[nrow][ncol]=1;
//                        q.push({nrow,ncol});

//                    }
//                }
//            }
//        }
    

//     int numIslands(vector<vector<char>>& grid) {
       
//         int m=grid.size();
//         int n=grid[0].size();
//         int drow[]={0,1,0,-1};
//         int dcol[]={1,0,-1,0};
//         vector<vector<int>>vis(m, vector<int>(n,0));
//         int ans=0;
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(!vis[i][j] && grid[i][j]=='1')
//                 {
//                     ans++;
//                     bfs(grid,i,j,vis,drow,dcol);
//                 }
//             }
//         }
//         return ans;

//     }
// };