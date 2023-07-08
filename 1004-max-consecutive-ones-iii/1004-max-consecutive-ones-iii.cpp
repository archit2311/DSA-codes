class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int n=nums.size();
        int ans=INT_MIN;
      int s=0,cntZero=0; 

      for(int e=0;e<n;e++)
      {
          if(nums[e]==0 && cntZero<k)
          {
              cntZero++;
          }
          else if(nums[e]==0 && cntZero==k)
          {
              ans=max(ans,e-s);
              
              while(nums[s]!=0)
              s++;

              s=s+1;
          }
      }

      ans=max(ans,n-s); 
      
      return ans;
    }
};