class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int high=INT_MIN;
        
        for(int i=0;i<piles.size();i++)
        {
         high=max(high,piles[i]);  
        }
      
        int ans=INT_MAX;
        int low=1; 
        while(low<=high)
        {
            int mid= low + (high - low) / 2;
            long long sum=0;
             for(int pile: piles){
                sum += ceil(pile*1.0/mid);
            }
            // for(int i=0;i<piles.size();i++)
            // {
            //     if(piles[i]<=mid)
            //     sum+=1;
            //     else{
            //     sum+= (piles[i]/mid) +1;
            //     }
            // }

            if(sum<=h)
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            low=mid+1;
        }

        return ans;
    }
};