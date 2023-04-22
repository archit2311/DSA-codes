class Solution {
public:

//DOUBT : WHAT IF WE CONCATENATE EACH STACK ELEMENT WITH THE STR STRING.
    string removeStars(string s) {
        string str="";
       stack<char>st;

       for(auto x:s)
       {
           if(x!='*')
           {
               st.push(x);
           }
           else if(!st.empty() && x=='*')
           st.pop();

       }

       while(!st.empty())
       {
          str.push_back(st.top());
          st.pop();
       }

        reverse(str.begin(),str.end());
       return str;
    }
};