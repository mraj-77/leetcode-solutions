class Solution {
private:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int> output, int index) {

        // base case
        if(output.size() == nums.size()){
            ans.push_back(output);
            return;
        }

        for(int i = 0; i < nums.size(); i++){

            // check if element is already used
            if(find(output.begin(), output.end(), nums[i]) == output.end()){

                output.push_back(nums[i]);

                solve(nums, ans, output, index + 1);

                output.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solve(nums, ans, output, index);

        return ans;
    }
};