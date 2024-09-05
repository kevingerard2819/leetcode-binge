class Solution {
public:
    int reverse(int x) {
        if(x == 0) return x;
        int rev = 0;  
        int temp;     
        bool negative = false;  
        if(x < 0){
            x = abs(x);
            negative = true;
        }
        while(x % 10 == 0){
            x /= 10;
        }
        while ( x != 0)
        {
            if(rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0;
            temp = x % 10;  
            rev = rev * 10 + temp;  
            x /= 10;  
        }
        if(negative) rev = -rev;
        return rev;  
    }
};