class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int r=matrix.size();
        int c=matrix[0].size();

        int top=0,bottom=r-1,left=0,right=c-1;

        while(top<=bottom && left<=right)
        {
            //top row
            for(int i=left;i<=right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            //last column
            for(int i=top; i<=bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            //row reverse
            if(top<=bottom){
            for(int i=right; i>=left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            }

            if(left<=right){

            //col reverse
            for(int i=bottom; i>=top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        return ans;
    }
};