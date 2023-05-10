class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans;
        int arr[n][n];
    int left=0,right=n-1,top=0,bottom=n-1;
     int k=1;
     while(top<=bottom && left<=right)
     {

         for(int i=left; i<=right; i++)
         {
             arr[top][i]=k;
             k++;
         }
         top++;

         for(int i=top;i<=bottom;i++)
         {
             arr[i][right]=k;
             k++;
         }
         right--;

         for(int i=right;i>=left; i--)
         {
             arr[bottom][i]=k;
             k++;
         }
         bottom--;

         for(int i=bottom;i>=top;i--)
         {
             arr[i][left]=k;
             k++;
         }
         left++;

     }
     for(int i=0;i<n;i++)
        {
            vector<int>v;
            for(int j=0;j<n;j++)
            {
                v.push_back(arr[i][j]);
            }
            ans.push_back(v);
        }
        return ans;

    }
};