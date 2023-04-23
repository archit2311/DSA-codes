class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int currlen=0;
        for(auto x: nums)
        {
            if(x==1){
                currlen++;
            }
      
            else
            {
                ans=max(ans,currlen);
                currlen=0;
                
            }
        }
        ans=max(ans,currlen);
        return ans;
    }
};