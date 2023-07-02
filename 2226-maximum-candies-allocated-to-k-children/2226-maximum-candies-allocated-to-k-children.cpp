class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

     long long int total=0;
      int high=INT_MIN;
      for(auto x:candies){
        high=max(high,x);
        total+=x;
      }

      if(total<k)
      return 0;

      int low=1;
      int ans=INT_MIN;
      while(low<=high)
      {
        int mid=(high-low)/2 + low;
        long long int child=0;
        for(int i=0;i<candies.size();i++)
        {
            child+=candies[i]/mid;
        }
        if(child>=k)
        {
            ans=max(mid,ans);
            low=mid+1;
        }
        else
        high=mid-1;
      }  

      return ans;
    }
};