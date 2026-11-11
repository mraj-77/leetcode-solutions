class Solution {
    void merge(vector<int>& arr, int start, int mid, int end) {

        vector<int> temp(end - start + 1);

        int left = start;
        int right = mid + 1;
        int index = 0;

        while(left <= mid && right <= end) {

            if(arr[left] <= arr[right]) {
                temp[index] = arr[left];
                index++;
                left++;
            }
            else {
                temp[index] = arr[right];
                index++;
                right++;
            }
        }

        while(left <= mid) {
            temp[index] = arr[left];
            index++;
            left++;
        }

        while(right <= end) {
            temp[index] = arr[right];
            index++;
            right++;
        }

        // Copy temp into original array
        for(int i = 0; i < temp.size(); i++) {
            arr[start + i] = temp[i];
        }
    }

    void mergesort(vector<int>& arr, int start, int end) {

        if(start >= end) {
            return;
        }

        int mid = start + (end - start) / 2;

        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }

public:
    vector<int> sortArray(vector<int>& nums) {

        mergesort(nums, 0, nums.size() - 1);

        return nums;
    }
};