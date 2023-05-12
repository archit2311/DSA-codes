class Solution {
public:
    
    vector<int> generateRows(int row)
    {
        vector<int>v;
        v.push_back(1);
        int res=1;
        for(int col=1;col<row;col++)
        {
            res=res*(row-col);
            res=res/col;
            v.push_back(res);
        }
        return v;
    }
    
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        
        for(int row=1;row<=n;row++)
        {
            ans.push_back(generateRows(row));
        }
        return ans;
    }
};