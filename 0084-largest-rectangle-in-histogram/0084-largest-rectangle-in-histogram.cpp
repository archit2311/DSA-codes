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
};