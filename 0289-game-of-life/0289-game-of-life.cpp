class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
    for(int r=0;r<m;r++)
    {
        for(int c=0;c<n;c++)
        {
            int cnt=0;
            for(int i=-1;i<=1;i++)
            {
            for(int j=-1;j<=1;j++)
            {
                if(r+i>=0 && r+i<m && c+j>=0 && c+j<n && board[r+i][c+j]==1)
                {
                   cnt++; 
                }
            }
            }
            if(board[r][c]==0)
            {
                if(cnt==3)
                ans[r][c]=1;
            }
            else{
                if(cnt<3 || cnt>4)
                ans[r][c]=0;
                else
                ans[r][c]=1;
            }
        }
    }
    board=ans;
        
    }
};