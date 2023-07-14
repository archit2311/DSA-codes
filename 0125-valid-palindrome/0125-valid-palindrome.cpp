class Solution {
public:

    bool isValid(char ch)
    {
        if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
        return true;
        else
        return false;
    }

    bool isPalindrome(string s) {
        
        string str="";
         for(int i=0;i<s.length(); i++)
        {
           if(isValid(s[i]))
           str.push_back(s[i]);
        }
        for(int i=0;i<str.length(); i++)
        {
            if(str[i]>='A' && str[i]<='Z')
            str[i]=str[i]-'A'+'a';
        }

       
        int low=0,high=str.length()-1;
        while(low<=high)
        {
            if(str[low]!=str[high])
            return false;
            low++;
            high--;
        }
        return true;
    }
};