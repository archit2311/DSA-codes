class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ans=INT_MAX;
        int m=maze.size();
        int n=maze[0].size();
        int dr[4]={1,0,-1,0};
        int dc[4]={0,1,0,-1};
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>>q;

        //{steps,{row,col}}

        q.push({0,{entrance[0],entrance[1]}});
        dist[entrance[0]][entrance[1]]=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int steps=it.first;
            int row=it.second.first;
            int col=it.second.second;


            for(int i=0;i<4;i++)
            {
                int nrow=row+dr[i];
                int ncol=col+dc[i];

                if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && maze[nrow][ncol]=='.' && dist[nrow][ncol]>steps+1)
                {
                    dist[nrow][ncol]=steps+1;
                    q.push({steps+1,{nrow,ncol}});
                }
            }
        }
         dist[entrance[0]][entrance[1]]=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(dist[0][i]<ans)
            ans=dist[0][i];
        }

        for(int i=0;i<m;i++)
        {
            if(dist[i][0]<ans)
            ans=dist[i][0];
        }

        for(int i=0; i<n;i++)
        {
            if(dist[m-1][i]<ans)
            ans=dist[m-1][i];
        }

        for(int i=0;i<m;i++)
        {
            if(dist[i][n-1]<ans)
            ans=dist[i][n-1];
        }


        return ans==INT_MAX?-1:ans;
    }
};