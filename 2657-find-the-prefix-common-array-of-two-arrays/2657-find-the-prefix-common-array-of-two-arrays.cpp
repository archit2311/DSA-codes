class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
       int n=A.size();
       int freq[n+1];
       for(int i=0;i<=n;i++)
       {
           freq[i]=0;
       }
       vector<int>C(n,0);
       for(int i=0;i<n;i++)
       {
           if(freq[A[i]]==1)
           {
               
               C[i]++; 
           }
           freq[A[i]]++;
           if(freq[B[i]]==1)
           {
             
               C[i]++; 
           }
             freq[B[i]]++;
             if(i>0)
             C[i]=C[i]+C[i-1];
       }
       return C;
    }
};