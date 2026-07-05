class Solution {
public:
    bool isPalindrome(int x) {
        long long pal = 0;
        long long  dup = x;

        if( x < 0){
            return false;
        }

        while (x != 0){
            int ld = x % 10;

            

            if (pal > INT_MAX/10 || (pal == INT_MAX/10 && ld > 7 )){
                return 0;
            } 

            if (pal < INT_MIN/10 || (pal == INT_MIN && ld < -8)){
                return 0;
            }

            pal = (pal * 10) + ld;
            x = x/10;

       }

       if (pal == dup){
        return true;
       }else{
        return false;
       }

    }
};