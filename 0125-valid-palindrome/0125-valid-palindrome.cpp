class Solution {
public:
    bool isPalindrome(string s) {

        int st = 0;
        int ed = s.size() - 1;

        while(st < ed){

            if(!isalnum(s[st])){
                st++;
            }
            else if(!isalnum(s[ed])){
                ed--;
            }
            else if(tolower(s[st]) != tolower(s[ed])){
                return false;
            }
            else{
                st++;
                ed--;
            }
        }

        return true;
    }
};