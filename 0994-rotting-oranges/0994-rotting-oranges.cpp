class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                q.push({i,j});
            }
        }
        
        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty())
        {
            int size=q.size();
            
            while(size>0)
            {
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nrow=row+dr[i];
                    int ncol=col+dc[i];

                    if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]==1)
                    {
                    grid[nrow][ncol]=2;
                    q.push({nrow,ncol});
                    }
                }
                size--;
            }
            ans++;
            
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                cnt++;
            }
        }
        if(cnt==n*m)return 0;


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return ans-1;
    }
};