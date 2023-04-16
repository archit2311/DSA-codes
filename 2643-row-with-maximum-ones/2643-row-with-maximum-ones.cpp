class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int>v;
        int pos=0;
        int maxcount=0;
        
        for(int i=0;i<mat.size();i++)
        {
            int count=0;
            for(auto x:mat[i])
            {
                if(x==1)
                    count++;
            }
            if(count>maxcount)
            {
                maxcount=count;
                pos=i;
            }
        }
        
        v.push_back(pos);
        v.push_back(maxcount);
        return v;
    }
};