class Solution {
public:
    
    bool isPalindrome(string s,int i,int j)
    {
        int n=s.length();
   
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
       
         int n=s.length();
        
        if(isPalindrome(s,0,n-1))
            return true;
        int i=0,j=n-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return (isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1));
            }
        }
        return false;
    }
        
        // if(isPalindrome(s))
        //     return true;
        // for(int i=0;i<n;i++)
        // {
        //     string str="";
        //     if(i==0){
        //         str=s.substr(1);
                
        //     }
        //     else if(i==n-1){
        //         str=s.substr(0,n-1);
        
        //     }
        //     else{
        //         str=s.substr(0,i)+s.substr(i+1,n-i-1);
           
        //     }
        //      if(isPalindrome(str))
        //             return true;
        // }
        // return false;
    
};