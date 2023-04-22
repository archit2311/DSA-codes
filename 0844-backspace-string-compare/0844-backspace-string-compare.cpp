class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char>st1;
        stack<char>st2;
        
        for(auto x:s)
        {
            if(x!='#')
                st1.push(x);
            else if(!st1.empty()&&x=='#')
                st1.pop();
        }
        
         for(auto x:t)
        {
            if(x!='#')
                st2.push(x);
            else if(!st2.empty()&&x=='#')
                st2.pop();
        }
        
        return st1==st2;
    }
};