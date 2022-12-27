class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks){
        int n=capacity.size();
        int rocksLeft=additionalRocks;
        vector<int>left(n,0);
        int count=0;
        for(int i=0;i<capacity.size();i++)
        {
            left[i]=capacity[i]-rocks[i];
        }
        sort(left.begin(),left.end());

        for(int i=0; i<capacity.size(); i++)
        {
            if(rocksLeft>=left[i])
            {
                rocksLeft=rocksLeft-left[i];
                count++;
            }
        }
        return count;
    }
        
};
