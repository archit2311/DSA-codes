class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;
        //{row,col}

        vector<vector<int>>dist(m,vector<int>(n,1e9));

        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0){
                dist[i][j]=0;
                q.push({i,j});
                }
                
            }
        }

        

        while(!q.empty())
        {
            auto it=q.front();
            
            int r=it.first;
            int c=it.second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nrow=r+dr[i];
                int ncol=c+dc[i];

                if(nrow<m && nrow>=0 && ncol<n && ncol>=0)
                {
                    if(dist[nrow][ncol]>dist[r][c]+1)
                    {
                        dist[nrow][ncol]=dist[r][c]+1;
                        q.push({nrow,ncol});
                    }
                    
                }
                
        
            }
        }

        return dist;

    }
};