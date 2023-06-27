/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int low=0;
        int high=n-1;
       
        //int br=-1;
        int ans=-1;
          while(low < high){
            int mid = low + (high - low)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) 
            low=mid+1 ;
            else 
            high = mid;
        }
        int br=low;
        while(low<=high)
        {
            int mid=(low+high)/2;
          
            if((mid==0 || mountainArr.get(mid-1)<=mountainArr.get(mid)) && (mid==n-1 || mountainArr.get(mid)>=mountainArr.get(mid+1)))
            {
                br=mid;
                break;
            }

            if(mid>0 && mountainArr.get(mid)<=mountainArr.get(mid-1))
            high=mid-1;
            else
            low=mid+1;
        }
        if(ans!=-1)
        return ans;
        int low1=0,high1=br;
        while(low1<=high1)
        {
            int mid1=low1+(high1-low1)/2;
            if(mountainArr.get(mid1)==target)
            {
            ans=mid1;
            break;
            }
            else if(mountainArr.get(mid1)>target)
            {
                high1=mid1-1;
            }
            else
            low1=mid1+1;
        }
        if(ans!=-1)
        return ans;
        else{

        int low2=br+1,high2=n-1;
        while(low2<=high2)
        {
            int mid2=low2+(high2-low2)/2;
            if(mountainArr.get(mid2)==target)
            {
            ans=mid2;
            break;
            }
            else if(mountainArr.get(mid2)>target)
            {
                low2=mid2+1;
            }
            else
            high2=mid2-1;
        }
        }

        return ans;
    }
    
};