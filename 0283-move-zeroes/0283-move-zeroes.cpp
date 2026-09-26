class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;

        // Saare non-zero numbers ko aage le aao
        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            }
        }

        // Baaki positions ko 0 kar do
        while(index < nums.size()) {
            nums[index] = 0;
            index++;
        }
    }
};