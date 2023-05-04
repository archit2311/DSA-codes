class Solution {
public:
    string predictPartyVictory(string senate) {
        
       queue<int>q1,q2;
       int n=senate.length();
       for(int i=0;i<n;i++)
       {
           if(senate[i]=='R')
           q1.push(i);
           else
           q2.push(i);
       }

       while(!q1.empty() && !q2.empty())
       {
           int curr1=q1.front();
           int curr2=q2.front();
           q1.pop();
           q2.pop();
           if(curr1<curr2)
           q1.push(curr1+n);
           else
           q2.push(curr2+n);
       }

       return (q1.size()>q2.size())?"Radiant":"Dire";
        
    }
};