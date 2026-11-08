class Solution {
public:
    string defangIPaddr(string address) {
        string ans;
        int idx = 0;

        while(idx < address.size()){
            if(address[idx] == '.'){
                ans += "[.]";
            }else{
                ans += address[idx];
            }
            idx++;
        }
        return ans;
    }
};