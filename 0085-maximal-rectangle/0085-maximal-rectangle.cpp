class Solution {
public:
    
    void nextSmall(vector<int>& heights, vector<int>&next)
    {
      int n=heights.size();
         stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!=-1 && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            next[i]=st.top();
            st.push(i);
        }
    }

    void prevSmall(vector<int>& heights, vector<int>&prev)
    {
         int n=heights.size();
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++)
        {
            while(st.top()!=-1 && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            prev[i]=st.top();
            st.push(i);
        }
    }


    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;
        int n=heights.size();
        vector<int>next(n,-1);
        vector<int>prev(n,-1);

        nextSmall(heights,next);
        prevSmall(heights,prev);

        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            if(next[i]==-1)
            next[i]=n;
            int b=next[i]-prev[i]-1;
            int area=l*b;
            maxArea=max(area,maxArea);
        }

        return maxArea;
    }

    //main code
    int maximalRectangle(vector<vector<char>>& matrix) {

     int m=matrix.size();
     int n=matrix[0].size();
   
    
    vector<int>heights(n,0);
    
    int ans=INT_MIN;
  
     for(int i=0;i<m;i++)
     {
         for(int j=0;j<n;j++)
         {
            if(matrix[i][j]=='1')
            heights[j]=heights[j]+1;
            else
            heights[j]=0;
         }
         for(auto x:heights)
         cout<<x<<" ";
         cout<<endl;
         int currArea=largestRectangleArea(heights);
         ans=max(ans,currArea);
     }

     return ans;

    }
};