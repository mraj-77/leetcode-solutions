class Solution {
public:
    int search(vector<int>& nums, int target) {
         int mid;
        int first = 0;
        int last = nums.size() - 1;
        while(first <= last) {
            mid = first + (last - first) / 2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                first = mid + 1;
            }
            else {
                last = mid - 1;
            }
        }
        return -1;
    }
};