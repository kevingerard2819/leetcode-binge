class Solution {
public:
   bool isPalindrome(int x) 
    {
        if(x<0)
        {
            return false;
        }

        long long reversed =0;
        long long t = x;

        while(t!=0)
        {
            int digit = t%10;
            reversed = reversed * 10 + digit;
            t /= 10;
        }

        return(reversed == x);


        
    }
};