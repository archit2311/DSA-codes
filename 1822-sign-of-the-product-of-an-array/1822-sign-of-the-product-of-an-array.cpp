class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int neg=0,pos=0,zero=0;
        for(auto x:nums)
        {
            if(x>0)
            pos++;
            else if(x<0)
            neg++;
            else
            zero++;

        }
        
        if(neg%2!=0 && zero==0)
        return -1;
        else if(neg%2==0 && zero==0)
        return 1;
        else return 0;
    }
};