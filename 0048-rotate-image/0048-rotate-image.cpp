class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();

        for(int i=0; i<r; i++)
        {
            for(int j=i+1; j<c; j++)
            {
                
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            
                
            }
        }

        for(int i=0;i<r;i++)
        {
            int l=0,h=c-1;
            while(l<=h)
            {
                int temp=matrix[i][l];
                matrix[i][l]=matrix[i][h];
                matrix[i][h]=temp;
                l++;
                h--;
            }
        }
    }
};