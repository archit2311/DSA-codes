class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.length()==1)
        {
            for(int i=0;i<typed.length();i++)
            {
                if(typed[i]!=name[0])
                return false;
            }
        }
        if(name[0]!=typed[0])
        return false;

        int i=1,j=1;

        while(i<name.length() && j<typed.length())
        {
            if(name[i]==typed[j])
            {
                i++;
                j++;
            }
            else if(typed[j]==name[i-1])
            {
                j++;
            }
            else
            {
                return false;
            }
        }

        if(i==name.length())
        {
            while(j<typed.length())
            {
                if(typed[j]!=name[i-1])
                return false;
                j++;
            }
        }

        if(j==typed.length() && i!=name.length())
        return false;

        return true;
    }
};