class Solution {
public:
    bool isPalindrome(int x) {
        int org = x, rem , ans = 0;
        if(x<0){
            return 0;
        }
        while(org){
            rem = org % 10;
            org /= 10;

            if(ans>INT_MAX/10){
                return 0;
            }
            ans = ans * 10 + rem; 
        }
        if(x == ans){
            return 1;
        }else{
            return 0;
        }
    }
};