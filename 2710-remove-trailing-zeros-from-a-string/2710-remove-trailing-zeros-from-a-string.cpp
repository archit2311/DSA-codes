class Solution {
public:
    string removeTrailingZeros(string num) {
        
        string num1=num;
        int count=0;
        for(int i=num.length()-1;i>=0;i--)
        {
            if(num[i]!='0')
                break;
            else
            {
                count++;
            }
        }
        int pos=num.length()-count;
        num1.erase(pos,count);
        
        return num1;
        
    }
};