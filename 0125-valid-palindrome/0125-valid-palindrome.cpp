class Solution {
public:
    bool isPalindrome(string s) {
        
        string temp = "";

        // Remove extra characters
        for(int i = 0; i < s.size(); i++){
            if((s[i] >= 'a' && s[i] <= 'z') ||
               (s[i] >= 'A' && s[i] <= 'Z') ||
               (s[i] >= '0' && s[i] <= '9')){

                temp.push_back(tolower(s[i]));
            }
        }

        // Check Palindrome
        int st = 0;
        int ed = temp.size() - 1;

        while(st < ed){
            if(temp[st] != temp[ed]){
                return false;
            }

            st++;
            ed--;
        }

        return true;
    }
};