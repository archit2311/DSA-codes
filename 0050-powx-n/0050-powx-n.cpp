class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || n == 1)
            return n == 0 ? 1 : x;
        // -ve power
        if(n == -1)
            return 1 / x;
        double ans=myPow(x,n/2);
            if(n%2==0)
            {
                ans=ans*ans;
            }
            else
            {
                if(n>0)
                ans=ans*ans*x;
                else
                ans=ans*ans*(1/x);
            }
        

         return ans;
    }
};