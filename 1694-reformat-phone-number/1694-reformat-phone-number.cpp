class Solution {
public:
    string reformatNumber(string number) {

       string num="";
       string ans="";
       for(auto x:number)
       {
           if(x!=' '&&  x!='-')
           num+=x;
       } 
       
       int n=num.length();
       int n1=num.length();

        int pos=0;
       while(n>4)
       {
           string part=num.substr(pos,3);
           ans+=part+'-';
           pos=pos+3;
           n=n-3;
       }

       if (n == 3) {
            ans += num.substr(n1 - 3, 3) + '-';
            n = n - 3;
        }

        if (n == 4) {
            ans += num.substr(n1 - 4, 2) + '-';
            ans += num.substr(n1 - 2, 2) + '-';
            n = n - 4;
        }

        if (n == 2) {
            ans += num.substr(n1 - 2, 2) + '-';
            n = n - 2;
        }

        ans.pop_back();

        return ans;
    }
};