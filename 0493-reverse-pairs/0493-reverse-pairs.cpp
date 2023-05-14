class Solution {
public:

    
void merge(vector<int>&arr, int l, int m, int r, int &res)
{

    int jj=m+1;
    for(int i=l;i<=m;i++)
    {
        while(jj<=r && arr[i]>2*(long long)arr[jj])
        jj++;

        res+=jj-(m+1);
    }
    int n1=m-l+1,n2=r-m;
    int left[n1],right[n2];
    int k=l;
   // long long res=0;
    for(int i=0;i<n1;i++)
    left[i]=arr[l+i];
    for(int i=0;i<n2;i++)
    {
        right[i]=arr[m+1+i];
    }
    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(left[i]<right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    //return res;

}

int mergeSort(vector<int>&arr, int l,int r)
{
    int res=0;
    
    if(l<r)
    {
        int m=l+(r-l)/2;
        res+=mergeSort(arr,l,m);
        res+=mergeSort(arr,m+1,r);
        merge(arr,l,m,r,res);
    }
    return res;
}


    int reversePairs(vector<int>& nums) {
        int ans= mergeSort(nums,0,nums.size()-1);
        return ans;
    }
};