class Solution {
public:

    bool isSafe(vector<vector<char>>& board,int i, int j, int n)
    {
        int N =board.size();
        for(int k=0;k<N;k++)
        {
            if(board[i][k]==char(n) || board[k][j]==char(n))
            return false;
        }

        int s=sqrt(N);
        int rs= i-i%s;
        int cs=j-j%s;
        for(i=0;i<s;i++)
        {
            for(j=0; j<s;j++)
            {
                if(board[i+rs][j+cs]==n)
                return false;
            }
        }
        return true;
    }



    void solveSudoku(vector<vector<char>>& board) {
        solve(board);  
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char n='1'; n<='9';n++)
                    {
                        if(isSafe(board,i,j,n))
                        {
                            board[i][j]=n;
                            if(solve(board))
                            return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
};