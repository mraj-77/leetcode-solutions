class Solution {
public:
    string reverseWords(string s) {

        string ans = "";
        string word = "";

        for(int i = s.length() - 1; i >= 0; i--) {

            if(s[i] != ' ') {
                word += s[i];
            }
            else {

                if(word != "") {

                    reverse(word.begin(), word.end());

                    if(ans != "")
                        ans += " ";

                    ans += word;
                    word = "";
                }
            }
        }

        // Last word
        if(word != "") {

            reverse(word.begin(), word.end());

            if(ans != "")
                ans += " ";

            ans += word;
        }

        return ans;
    }
};