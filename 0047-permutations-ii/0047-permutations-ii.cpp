class Solution {

    void permut(vector<int>& arr, vector<vector<int>>& ans, int index){

        // Base Case
        if(index == arr.size()){
            ans.push_back(arr);
            return;
        }

        vector<bool> use(21, 0);

        for(int i = index; i < arr.size(); i++){

            if(use[arr[i] + 10] == 0){

                use[arr[i] + 10] = 1;

                swap(arr[i], arr[index]);

                permut(arr, ans, index + 1);

                swap(arr[index], arr[i]);
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;

        permut(nums, ans, 0);

        return ans;
    }
};