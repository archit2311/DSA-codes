class Solution {
public:

    // int maxF()
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int ans=INT_MIN;
        int s=0,cntF=0;
        for(int e=0;e<n;e++)
        {
            if(cntF<k && answerKey[e]=='F')
            {
                cntF++;
            }
            else if(answerKey[e]=='F' && cntF==k){
                ans=max(ans,e-s);
                while(s<n && answerKey[s]=='T')
                s++;

                s=s+1;
                // cntF--;
            }
            
        }
        ans=max(ans,n-s);

        //make false

         int ansF=INT_MIN;
        int s1=0,cntT=0;
        for(int e=0;e<n;e++)
        {
            if(cntT<k && answerKey[e]=='T')
            {
                cntT++;
            }
            else if(answerKey[e]=='T' && cntT==k){
                ansF=max(ansF,e-s1);
                while(s1<n && answerKey[s1]=='F')
                s1++;

                s1=s1+1;
                // cntF--;
            }
            
        }
        ansF=max(ansF,n-s1);
        cout<<ans<<" "<<ansF;
        return max(ans,ansF);
    }
};