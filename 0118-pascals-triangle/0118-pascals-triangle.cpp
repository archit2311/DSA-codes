class Solution {
public:
    
    vector<int> generateRow(int row)
    {
        vector<int>v;
        v.push_back(1);
        long long res=1;
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
        
        for(int i=1;i<=n;i++)
        {
            ans.push_back(generateRow(i));
        }
        return ans;
        
    }
};